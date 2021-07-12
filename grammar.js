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
const unary_operators = ["+", "-", "!", "~", "^", "*", "&", "<-"];

const newline = choice("\n", "\r", "\r\n");
const terminator = token(newline);

const unicode_digit = /[0-9]/;
const unicode_letter = /[a-zA-Zα-ωΑ-Ωµ]/;

const letter = choice(unicode_letter, "_");

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

const pub_keyword = "pub";
const const_keyword = "const";
const mut_keyword = "mut";
const global_keyword = "__global";
const fn_keyword = "fn";
const assert_keyword = "assert";
const as_keyword = "as";
const asm_keyword = "asm";

const fixed_array_symbol = "!";

module.exports = grammar({
  name: "v",

  word: ($) => $.identifier,

  rules: {
    source_file: ($) =>
      choice(
        repeat1(
          seq(
            choice($._top_level_declaration, $._statement),
            optional(terminator)
          )
        )
      ),

    _top_level_declaration: ($) =>
      choice($.const_declaration, $.function_declaration),

    _expression: ($) =>
      choice(
        $._single_line_expression,
        $.array,
        $.unary_expression,
        $.binary_expression,
        $.as_type_cast_expression,
        $.identifier
      ),

    unary_expression: ($) =>
      prec(
        PREC.unary,
        seq(
          field("operator", choice(...unary_operators)),
          field("operand", choice($._expression))
        )
      ),

    binary_expression: ($) => {
      const table = [
        [PREC.multiplicative, choice(...multiplicative_operators)],
        [PREC.additive, choice(...additive_operators)],
        [PREC.comparative, choice(...comparative_operators)],
        [PREC.and, "&&"],
        [PREC.or, "||"],
      ];

      return choice(
        ...table.map(([precedence, operator]) =>
          prec.left(
            precedence,
            seq(
              field("left", $._expression),
              field("operator", operator),
              field("right", $._expression)
            )
          )
        )
      );
    },

    as_type_cast_expression: ($) => seq($._expression, as_keyword, $._type),

    // _expression_with_blocks: $ => choice(),

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

    fixed_array_indicator: ($) => token(fixed_array_symbol),

    array: ($) =>
      choice(
        "[]",
        prec.right(
          seq(
            "[",
            field("values", repeat1(seq($._expression, optional(",")))),
            "]",
            optional($.fixed_array_indicator)
          )
        )
      ),

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

    identifier: ($) =>
      token(seq(letter, repeat(choice(letter, unicode_digit)))),

    identifier_list: ($) => comma_sep1(choice($.identifier)),

    expression_list: ($) => comma_sep1(choice($._expression)),

    parameter_declaration: ($) =>
      seq(field("name", $.identifier), field("type", $._type)),

    parameter_list: ($) => seq("(", comma_sep($.parameter_declaration), ")"),

    _type: ($) => choice($._type_identifier, $.qualified_type),

    qualified_type: ($) =>
      seq(
        field("module", $._module_identifier),
        ".",
        field("name", $._type_identifier)
      ),

    _type_identifier: ($) => alias($.identifier, $.type_identifier),
    _module_identifier: ($) => alias($.identifier, $.module_identifier),

    _statement_list: ($) =>
      seq(
        $._statement,
        repeat(seq(optional(terminator), $._statement)),
        optional(terminator)
      ),

    _statement: ($) =>
      choice(
        $._expression,
        $.short_var_declaration,
        $.assignment_statement,
        $.assert_statement,
        $.asm_statement
      ),

    short_var_declaration: ($) => assignment_statement_support($, ":="),

    assignment_statement: ($) =>
      assignment_statement_support($, choice(...assignment_operators)),

    assert_statement: ($) => seq(assert_keyword, $._expression),

    block: ($) => seq("{", optional($._statement_list), "}"),

    function_declaration: ($) =>
      prec.right(
        seq(
          fn_keyword,
          field("name", $.identifier),
          $.parameter_list,
          field("result", optional($._type)),
          field("body", optional($.block))
        )
      ),

    const_declaration: ($) =>
      seq(
        optional(pub_keyword),
        const_keyword,
        choice(
          $.const_spec,
          seq("(", repeat1(seq($.const_spec, terminator)), ")")
        )
      ),

    const_spec: ($) =>
      seq(field("name", $.identifier), "=", field("value", $._expression)),

    asm_statement: ($) => seq(asm_keyword, $.identifier, $._content_block),

    // Loose checking for asm and sql statements
    _content_block: ($) => seq("{", token.immediate(prec(1, /[^{}]+/)), "}"),
  },
});

function assignment_statement_support($, symbol) {
  return seq(
    field("left", $.identifier_list),
    symbol,
    field("right", $.expression_list)
  );
}

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
