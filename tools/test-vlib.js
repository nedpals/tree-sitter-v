const Parser = require('tree-sitter');
const V = require('../bindings/node');
const glob = require('glob');
const path = require('path');
const fs = require('fs');
const { promisify } = require('util');
const chalk = require('chalk');

const vFolder = process.argv[2] || null;
const hideRanges = process.argv[3] == '--hideRanges' || false; 
const parser = new Parser();
parser.setLanguage(V);

if (!vFolder) {
  throw Error('V folder not found!');
}

const vlibFolder = path.join(vFolder, 'vlib');

// skip test files for now
const filesToParse = glob.sync(path.join(vlibFolder, '!(tests|js)', '!(*_test|*.js).v'));
const longestLen =  Math.max(...filesToParse.map(f => path.relative(vFolder, f).length));

function walkAndReportErrors(node, file) {
  let errors = [];
  const cursor = node.walk();

  do {
    const currentNode = cursor.currentNode;
    if (currentNode.hasError()) {
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
  return walkAndReportErrors(rootNode, path.relative(vFolder, file));
}

console.log('==============================================');
console.log(`V folder: ${vFolder}`);
console.log(`vlib folder: ${vlibFolder}`);
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
        process.stderr.write(`${chalk.green`[Pass ]`} file: ${(path.relative(vFolder, filesToParse[i])).padEnd(longestLen)} | errors: ${errors.length}\n`);
      }
    });

    console.log('==============================================\n\nSummary:')
    console.log(`${errorCount} files were not parsed properly by the Tree-sitter parser.`);

    // 1 if true, 0 if false
    process.exit(+hasErrors); 
  });