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
- [x] ArrayDecompose (`decomposed_element`)
- [x] ArrayFixed (`array_initializer`)
- [x] ArrayInit (`array` / `type_initializer`)
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
- [x] AssignStmt (`assignment_statement`, `short_var_declaration`)
- [ ] Assoc
- [ ] AtExpr
- [ ] Attr (`attribute_declaration`)
- [x] Block (`block`)
- [x] BoolLiteral (`true` / `false`)
- [ ] BranchStmt
- [ ] CallArg (`argument_list`)
- [ ] CallExpr (`call_expression`)
- [x] CastExpr (`type_cast_expression`)
- [ ] Chan
- [ ] ChanInit
- [ ] CharLiteral (`rune_literal`)
- [x] Comment (`comment`)
- [ ] CompFor
- [ ] ComptimeCall
- [ ] ComptimeSelector
- [ ] ConcatExpr
- [x] ConstDecl (`const_declaration`)
- [x] ConstField (`const_spec`)
- [x] DeferStmt (`defer_statement`)
- [ ] DumpExpr (`call_expression`)
- [ ] EmbeddedFile
- [x] EnumDecl (`enum_declaration`)
- [x] EnumField (`enum_member`)
- [ ] EnumVal
- [ ] ExprStmt
- [x] FloatLiteral (`float_literal`)
- [x] FnDecl (`function_declaration`)
- [ ] FnTypeDecl
- [ ] ForCStmt (`for_statement`: `cstyle_for_clause`)
- [ ] ForInStmt (`for_statement`: `in_operator`)
- [ ] ForStmt (`for_statement`)
- [ ] GlobalDecl
- [ ] GlobalField
- [ ] GoExpr (`go_expression`)
- [ ] GotoLabel
- [ ] GotoStmt
- [ ] HashStmt (Currently supported: `c_include_clause`, `c_flag_clause`,  `c_define_clause`)
- [x] Ident (`identifier`)
- [ ] IfBranch
- [ ] IfExpr
- [ ] IfGuardExpr
- [x] Import (`import_declaration`)
- [x] ImportSymbol (`import_symbol`)
- [ ] IndexExpr
- [ ] InfixExpr
- [x] IntegerLiteral (`int_literal`)
- [ ] InterfaceDecl (`interface_declaration`)
- [ ] InterfaceEmbedding
- [ ] Likely
- [ ] LockExpr
- [x] MapInit (`type_initializer`)
- [ ] MatchBranch
- [ ] MatchExpr
- [x] Module (`module_clause`)
- [ ] MultiReturn (`multi_return_type`)
- [x] NodeError (`[ERROR]`)
- [x] None (`none`)
- [ ] OffsetOf
- [ ] OrExpr (`or_block`)
- [x] Param (`parameter_declaration`)
- [x] ParExpr (`parenthesized_expression`)
- [ ] PostfixExpr
- [ ] PrefixExpr
- [ ] RangeExpr
- [ ] Return
- [ ] SelectBranch
- [ ] SelectExpr
- [ ] SelectorExpr
- [ ] SizeOf (`call_expression`)
- [ ] SqlExpr
- [ ] SqlStmt
- [ ] SqlStmtLine
- [x] StringInterLiteral (`interpreted_string_literal`)
- [x] StringLiteral (`_string_literal`)
- [x] StructDecl (`struct_declaration`)
- [x] StructField (`struct_field_declaration`)
- [x] StructInit (`type_initializer`)
- [x] StructInitEmbed (`decomposed_element`)
- [x] StructInitField (`literal_value`)
- [x] SumTypeDecl (`type_declaration`)
- [x] TypeNode (`type_identifier`)
- [ ] TypeOf (`call_expression`)
- [x] UnsafeExpr (`unsafe_statement` (name not finalized))
