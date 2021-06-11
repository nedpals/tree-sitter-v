const Parser = require('tree-sitter');
const V = require('../bindings/node');
const glob = require('glob');
const path = require('path');
const fs = require('fs');
const { promisify } = require('util');

const vFolder = process.argv[2] || null;
const hideRanges = process.argv[3] == '--hideRanges' || false; 
const parser = new Parser();
parser.setLanguage(V);

if (!vFolder) {
  throw Error('V folder not found!');
}

const vlibFolder = path.join(vFolder, 'vlib');

// skip test files for now
const filesToParse = glob.sync(path.join(vlibFolder, '*', '!(tests)', '!(*_test).v'));
const longestLen =  Math.max(...filesToParse.map(f => path.relative(vFolder, f).length));

function walkAndReportErrors(node, file) {
  let errors = [];
  const cursor = node.walk();

  do {
    const currentNode = cursor.currentNode;
    if (currentNode.hasError()) {
      errors.push({ 
        file: file, 
        range: [currentNode.startIndex, currentNode.endIndex] 
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

Promise.all(filesToParse.map(parseAndReportErrors))
  .then(collection => {
    let hasErrors = false;
    let errorCount = 0;

    collection.forEach(errors => {
      if (!hasErrors && errors.length != 0) {
        hasErrors = true;
      }

      if (errors.length != 0) {
        errorCount++;

        process.stderr.write(`[Error] file: ${errors[0].file.padEnd(longestLen)} | errors: ${errors.length}\n`);
        if (!hideRanges) {
          process.stderr.write(errors.map((e, i) => `[${e.range.join(', ')}]` + ((i < 4)  ? ' ' : (i % 5 == 0) ? '\n' : ' ')).join(''));
          process.stderr.write('\n\n');
        }
      }
    });

    console.log('==============================================\n\nSummary:')
    console.log(`${errorCount} files were not parsed properly by the Tree-sitter parser.`);

    // 1 if true, 0 if false
    process.exit(+hasErrors); 
  });