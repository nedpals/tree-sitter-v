# tree-sitter-v
V language grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter)

[![build/test](https://github.com/nedpals/tree-sitter-v/actions/workflows/ci.yml/badge.svg)](https://github.com/nedpals/tree-sitter-v/actions/workflows/ci.yml)

## Existing grammars
This grammar is heavily derived from the following language grammars:

- [tree-sitter-go](https://github.com/tree-sitter/tree-sitter-go)
- [tree-sitter-ruby](https://github.com/tree-sitter/tree-sitter-ruby/)
- [tree-sitter-c](https://github.com/tree-sitter/tree-sitter-c/)

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

## Usage with V [v-tree-sitter (soon)]
```v
// TODO:
import treesitter
import tree_sitter_v.bindings.v

fn main() {
  mut parser := treesitter.new_parser()
  parser.set_language(v.language)
}
```

## Node Support (Checked means already been verified and tested)
- [x] AliasTypeDecl (`type_declaration`)
- [ ] AnonFn
- [ ] ArrayDecompose
- [x] ArrayFixed (`array_initializer`)
- [x] ArrayInit (`array_initializer`)
- [x] AsCast (`as_type_cast_expression`)
- [ ] AsmAddressing
- [ ] AsmAlias
- [ ] AsmClobbered
- [ ] AsmDisp
- [ ] AsmIO
- [ ] AsmRegister
- [ ] AsmStmt
- [ ] AsmTemplate
- [ ] AssertStmt
- [ ] AssignStmt
- [ ] Assoc
- [ ] AtExpr
- [ ] Attr
- [x] Block (`block`)
- [x] BoolLiteral (`true` / `false`)
- [ ] BranchStmt
- [ ] CallArg
- [ ] CallExpr
- [x] CastExpr (`type_cast_expression`)
- [ ] Chan
- [ ] ChanInit
- [ ] CharLiteral
- [ ] Comment
- [ ] CompFor
- [ ] ComptimeCall
- [ ] ComptimeSelector
- [ ] ConcatExpr
- [x] ConstDecl (`const_declaration`)
- [x] ConstField (`const_spec`)
- [x] DeferStmt (`defer_statement`)
- [ ] DumpExpr
- [ ] Embed
- [ ] EmbeddedFile
- [x] EnumDecl (`enum_declaration`)
- [x] EnumField (`enum_member`)
- [ ] EnumVal
- [ ] ExprStmt
- [ ] FloatLiteral
- [x] FnDecl (`function_declaration`)
- [ ] FnTypeDecl
- [ ] ForCStmt
- [ ] ForInStmt
- [ ] ForStmt
- [ ] GenericStructInst
- [ ] GlobalDecl
- [ ] GlobalField
- [ ] GoExpr
- [ ] GotoLabel
- [ ] GotoStmt
- [ ] HashStmt (Currently supported: `c_include_clause`, `c_flag_clause`,  `c_define_clause`)
- [x] Ident (`identifier`)
- [ ] IdentFn
- [ ] IdentVar
- [ ] IfBranch
- [ ] IfExpr
- [ ] IfGuardExpr
- [x] Import (`import_declaration`)
- [x] ImportSymbol (`import_symbol`)
- [ ] IndexExpr
- [ ] InfixExpr
- [x] IntegerLiteral (`int_literal`)
- [ ] Interface
- [ ] InterfaceDecl
- [ ] InterfaceEmbedding
- [ ] Likely
- [ ] LockExpr
- [x] MapInit (`map_initializer`)
- [ ] MatchBranch
- [ ] MatchExpr
- [x] Module (`module_clause`)
- [ ] MultiReturn
- [x] NodeError (`[ERROR]`)
- [x] None (`none`)
- [ ] OffsetOf
- [ ] OrExpr
- [ ] Param
- [ ] ParExpr
- [ ] PostfixExpr
- [ ] PrefixExpr
- [ ] RangeExpr
- [ ] Return
- [ ] SelectBranch
- [ ] SelectExpr
- [ ] SelectorExpr
- [ ] SizeOf
- [ ] SqlExpr
- [ ] SqlStmt
- [ ] SqlStmtLine
- [ ] StringInterLiteral
- [ ] StringLiteral
- [x] StructDecl (`struct_declaration`)
- [x] StructField (`struct_field_declaration`)
- [ ] StructInit
- [ ] StructInitEmbed
- [ ] StructInitField
- [x] SumTypeDecl (`type_declaration`)
- [x] TypeNode (`type_identifier`)
- [ ] TypeOf
- [ ] TypeSymbol
- [x] UnsafeExpr (`unsafe_statement` (name not finalized))
