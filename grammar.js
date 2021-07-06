const PREC = {
  primary: 7,
  unary: 6,
  multiplicative: 5,
  additive: 4,
  comparative: 3,
  and: 2,
  or: 1,
  composite_literal: -1,
};

const multiplicative_operators = ["*", "/", "%", "<<", ">>", "&", "&^"];
const additive_operators = ["+", "-", "|", "^"];
const comparative_operators = ["==", "!=", "<", "<=", ">", ">="];
const assignment_operators = multiplicative_operators
  .concat(additive_operators)
  .map((operator) => operator + "=")
  .concat("=");

const newline = "\n";
const terminator = newline;

const unicode_digit = /[0-9]/;
const unicode_char = /./;

const letter = choice(unicode_char, "_");

const primitive_types = [
  "bool",
  "string",
  "i8",
  "i16",
  "int",
  "i64",
  "byte",
  "u16",
  "u32",
  "u64",
  "rune",
  "f32",
  "f64",
  "voidptr",
  "size_t",
  "any",
];

module.exports = grammar({
  name: "v",

  rules: {
    source_file: ($) => repeat(seq($._top_level_statement, token(terminator))),

    _top_level_statement: ($) => choice($.function_declaration),

    identifier: ($) => seq(letter, repeat(choice(letter, unicode_digit))),

    parameter_declaration: ($) =>
      seq(field("name", $.identifier), field("type", $._type)),

    parameter_list: ($) => seq("(", comma_sep($.parameter_declaration), ")"),

    _type: ($) => $.type_identifier,

    type_identifier: ($) => choice(...primitive_types),

    block: ($) => seq("{", "}"),

    function_declaration: ($) =>
      seq(
        "fn",
        field("name", $.identifier),
        $.parameter_list,
        field("result", optional($._type)),
        field("body", optional($.block))
      ),
  },
});

function comma_sep1(rules) {
  return seq(rules, repeat(seq(",", rules)));
}

function comma_sep(rule) {
  return optional(comma_sep1(rule));
}
