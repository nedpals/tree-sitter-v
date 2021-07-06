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

const hex_digit = /[0-9a-fA-F]/;
const octal_digit = /[0-7]/;
const decimal_digit = /[0-9]/;
const binary_digit = /[01]/;

const hex_digits = seq(hex_digit, repeat(seq(optional("_"), hex_digit)));
const octal_digits = seq(octal_digit, repeat(seq(optional("_"), octal_digit)));
const decimal_digits = seq(
  decimal_digit,
  repeat(seq(optional("_"), decimal_digit))
);
const binary_digits = seq(
  binary_digit,
  repeat(seq(optional("_"), binary_digit))
);

const hex_literal = seq("0", choice("x", "X"), optional("_"), hex_digits);
const octal_literal = seq(
  "0",
  optional(choice("o", "O")),
  optional("_"),
  octal_digits
);
const decimal_literal = choice(
  "0",
  seq(/[1-9]/, optional(seq(optional("_"), decimal_digits)))
);
const binary_literal = seq("0", choice("b", "B"), optional("_"), binary_digits);

const int_literal = choice(
  binary_literal,
  decimal_literal,
  octal_literal,
  hex_literal
);

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

const pub_keyword = "pub";
const const_keyword = "const";
const fn_keyword = "fn";
const mut_keyword = "mut";
const global_keyword = "__global";

module.exports = grammar({
  name: "v",

  rules: {
    source_file: ($) => repeat(seq($._top_level_statement, token(terminator))),

    _top_level_statement: ($) =>
      choice($.function_declaration, $.const_declaration),

    _expression: ($) => choice($._single_line_expression),

    _single_line_expression: ($) => choice($.int_literal, $._string_literal),

    escape_sequence: ($) =>
      token(
        prec(
          1,
          seq(
            "\\",
            choice(
              /u[a-fA-F\d]{4}/,
              /U[a-fA-F\d]{8}/,
              /x[a-fA-F\d]{2}/,
              /\d{3}/,
              /\r?\n/,
              /['"abfrntv\$\\]/
            )
          )
        )
      ),

    int_literal: ($) => token(int_literal),

    _string_literal: ($) => choice($.interpreted_string_literal),

    interpreted_string_literal: ($) => quoted_string($, $.string_interpolation),

    string_interpolation: ($) =>
      choice(
        seq("${", $._expression, optional($.format_specifier), "}"),
        seq("$", $._single_line_expression)
      ),

    format_flag: ($) => token(/[gGeEfFcdoxXpsSc]/),

    format_specifier: ($) =>
      seq(
        token(":"),
        choice(
          $.format_flag,
          seq(
            optional(token(/[+-0]/)),
            $.int_literal,
            optional(seq(token("."), $.int_literal)),
            optional($.format_flag)
          )
        )
      ),

    identifier: ($) => seq(letter, repeat(choice(letter, unicode_digit))),

    parameter_declaration: ($) =>
      seq(field("name", $.identifier), field("type", $._type)),

    parameter_list: ($) => seq("(", comma_sep($.parameter_declaration), ")"),

    _type: ($) => $.type_identifier,

    type_identifier: ($) => choice(...primitive_types),

    block: ($) => seq("{", "}"),

    function_declaration: ($) =>
      seq(
        fn_keyword,
        field("name", $.identifier),
        $.parameter_list,
        field("result", optional($._type)),
        field("body", optional($.block))
      ),

    const_declaration: ($) =>
      seq(
        optional(pub_keyword),
        "const",
        choice(
          $.const_spec,
          seq("(", repeat(seq($.const_spec, terminator)), ")")
        )
      ),

    const_spec: ($) =>
      seq(field("name", $.identifier), "=", field("value", $._expression)),
  },
});

function comma_sep1(rules) {
  return seq(rules, repeat(seq(",", rules)));
}

function comma_sep(rule) {
  return optional(comma_sep1(rule));
}

function quoted_string($, rule) {
  return choice(
    ...["'", '"'].map((quote) =>
      seq(
        quote,
        repeat(
          choice(token.immediate(prec(1, /[^$'\\]+/)), $.escape_sequence, rule)
        ),
        quote
      )
    )
  );
}
