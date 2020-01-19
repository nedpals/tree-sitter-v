# tree-sitter-v
V language grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter) based on [tree-sitter-go](https://github.com/tree-sitter/tree-sitter-go) and [tree-sitter-ruby](https://github.com/tree-sitter/tree-sitter-ruby/)

## Installation
```
npm install tree-sitter-v
```

## Usage [(node-tree-sitter)](https://github.com/tree-sitter/node-tree-sitter)
```javascript
const Parser = require('tree-sitter');
const V = require('tree-sitter-v');

const parser = new Parser();
parser.setLanguage(V);
```
