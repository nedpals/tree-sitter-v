const Parser = require('tree-sitter');
const V = require('../bindings/node');
const glob = require('glob');
const path = require('path');
const fs = require('fs');
const { promisify } = require('util');
const chalk = require('chalk');
const argv = require('minimist')(process.argv.slice(2));

const vProject = argv._[0] || null;
const hideRanges = argv.hideRanges || false; 
const parser = new Parser();
parser.setLanguage(V);

if (!vProject) {
  throw Error('V project not found!');
}

// skip test files for now
const filesToParse = glob.sync(path.join('**', '!(*_test|*_bare|*.js).v'), {
  ignore: ['+(tests|js)'],
  cwd: vProject,
  absolute: true
}).filter(filePath => !filePath.includes('tests') && !filePath.includes('js'));
const longestLen =  Math.max(...filesToParse.map(f => path.relative(vProject, f).length));

function walkAndReportErrors(node, file) {
  let errors = [];
  const cursor = node.walk();

  do {
    const currentNode = cursor.currentNode;
    if (currentNode.hasError() && (currentNode.type == 'ERROR' || currentNode.isMissing())) {
      errors.push({ 
        file: file, 
        range: [
          currentNode.startPosition, 
          currentNode.endPosition
        ]
      });
    }
    if (currentNode.childCount != 0) {
      for (const childNode of node.children) {
        errors.push(...walkAndReportErrors(childNode, file));
      }
    }
  } while (cursor.gotoNextSibling());
  return errors;
}

async function parseAndReportErrors(file) {
  const content = await promisify(fs.readFile)(file, { encoding: 'utf-8' });
  const tree = parser.parse(content);
  const rootNode = tree.rootNode;
  return walkAndReportErrors(rootNode, path.relative(vProject, file));
}

console.log('==============================================');
console.log(`V project: ${vProject}`);
console.log('==============================================');

Promise.all(filesToParse.map(parseAndReportErrors))
  .then((collection) => {
    let hasErrors = false;
    let errorCount = 0;

    collection.forEach((errors, i) => {
      if (!hasErrors && errors.length != 0) {
        hasErrors = true;
      }

      if (errors.length != 0) {
        errorCount++;

        if (!hideRanges) {
          const toText = (pos) => `:${pos.row + 1}:${pos.column + 1}`;

          errors.forEach((e) => {
            process.stderr.write(`[Error] file: ${e.file + toText(e.range[0])} - ${toText(e.range[1])}\n`);
          });
          process.stderr.write('\n');
        } else {
          process.stderr.write(`${chalk.red`[Error]`} file: ${errors[0].file.padEnd(longestLen)} | errors: ${errors.length}\n`);
        }
      } else if (hideRanges) {
        process.stderr.write(`${chalk.green`[Pass ]`} file: ${(path.relative(vProject, filesToParse[i])).padEnd(longestLen)} | errors: ${errors.length}\n`);
      }
    });

    console.log('==============================================\n\nSummary:')
    console.log(`${errorCount} files were not parsed properly by the Tree-sitter parser.`);

    // 1 if true, 0 if false
    process.exit(+hasErrors); 
  });