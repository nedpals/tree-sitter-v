const PREC = {
  attributes: 8,
  primary: 7,
  unary: 6,
  multiplicative: 5,
  additive: 4,
  comparative: 3,
  and: 2,
  or: 1,
  resolve: 1,
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
const overloadable_operators = [
  "+",
  "-",
  "*",
  "/",
  "%",
  "<",
  ">",
  "==",
  "!=",
  "<=",
  ">=",
].map((operator) => token(operator));

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
const go_keyword = "go";
const asm_keyword = "asm";
const return_keyword = "return";
const type_keyword = "type";
const for_keyword = "for";
const in_keyword = "in";
const struct_keyword = "struct";
const enum_keyword = "enum";
const interface_keyword = "interface";

const fixed_array_symbol = "!";

module.exports = grammar({
  name: "v",

  extras: ($) => [$.comment, /\s/],

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
      choice(
        $.const_declaration,
        $.global_var_declaration,
        $.function_declaration,
        $.type_declaration,
        $.struct_declaration,
        $.enum_declaration,
        $.interface_declaration
      ),

    _expression: ($) =>
      choice(
        $._single_line_expression,
        $.type_initializer,
        $.array,
        $.unary_expression,
        $.binary_expression,
        $.as_type_cast_expression,
        $.call_expression,
        $.fn_literal,
        $._expression_with_blocks
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

    call_expression: ($) =>
      prec.right(
        PREC.comparative,
        seq(
          field("function", choice($.identifier)),
          field("type_parameters", optional($.type_parameters)),
          field("arguments", $.argument_list),
          optional($.option_propagator)
        )
      ),

    option_propagator: ($) => prec.right(choice(token("?"), $.or_block)),

    or_block: ($) => seq("or", $.block),

    _expression_with_blocks: ($) => choice($.if_expression),

    _single_line_expression: ($) =>
      prec.left(
        PREC.resolve,
        choice(
          $.identifier,
          $.int_literal,
          $._string_literal,
          $.none,
          $.true,
          $.false
        )
      ),

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: ($) =>
      token(
        choice(seq("//", /.*/), seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/"))
      ),

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

    none: ($) => "none",
    true: ($) => "true",
    false: ($) => "false",

    type_initializer: ($) =>
      prec(
        PREC.composite_literal,
        seq(
          field(
            "type",
            choice(
              $._type_identifier,
              // $.binded_type,
              $.qualified_type,
              // $.pointer_type,
              $.array_type,
              // $.fixed_array_type,
              $.map_type,
              $.channel_type
            )
          ),
          field("body", $.literal_value)
        )
      ),

    literal_value: ($) =>
      seq(
        "{",
        optional(seq($.keyed_element, repeat(seq(",", $.keyed_element)))),
        "}"
      ),

    keyed_element: ($) =>
      seq(choice($._field_identifier, $._string_literal), ":", $._element),

    _element: ($) => choice($._expression),

    fixed_array_indicator: ($) => token(fixed_array_symbol),

    array: ($) =>
      prec(
        PREC.composite_literal,
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
        )
      ),

    array_type: ($) => seq("[]", field("element", $._simple_type)),

    variadic_type: ($) => seq("...", $._simple_type),

    pointer_type: ($) => prec(PREC.unary, seq("&", $._simple_type)),

    map_type: ($) =>
      seq("map[", field("key", $._simple_type), "]", field("value", $._type)),

    channel_type: ($) => seq("chan", field("value", $._simple_type)),

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

    identifier: ($) =>
      token(seq(letter, repeat(choice(letter, unicode_digit)))),

    _mutable_identifier: ($) => seq(mut_keyword, $.identifier),

    identifier_list: ($) =>
      comma_sep1(choice($.identifier, $._mutable_identifier)),

    expression_list: ($) => comma_sep1(choice($._expression)),

    parameter_declaration: ($) =>
      seq(
        field("name", choice($.identifier, $._mutable_identifier)),
        field("type", choice($._type, $.variadic_type))
      ),

    parameter_list: ($) => seq("(", comma_sep($.parameter_declaration), ")"),

    argument_list: ($) => seq("(", comma_sep($._expression), ")"),

    _type: ($) => choice($._simple_type, $.option_type, $.multi_return_type),

    option_type: ($) =>
      prec.right(
        seq("?", optional(choice($._simple_type, $.multi_return_type)))
      ),

    multi_return_type: ($) => seq("(", comma_sep1($._simple_type), ")"),

    _simple_type: ($) =>
      choice(
        $._type_identifier,
        $.qualified_type,
        $.pointer_type,
        $.array_type,
        $.function_type
      ),

    type_parameters: ($) =>
      prec(
        PREC.resolve,
        seq(token.immediate("<"), comma_sep1($._type), token.immediate(">"))
      ),

    qualified_type: ($) =>
      seq(
        field("module", $._module_identifier),
        ".",
        field("name", $._type_identifier)
      ),

    _type_identifier: ($) => alias($.identifier, $.type_identifier),

    _module_identifier: ($) => alias($.identifier, $.module_identifier),

    _field_identifier: ($) =>
      prec(PREC.resolve, alias($.identifier, $.field_identifier)),

    _statement_list: ($) =>
      seq(
        $._statement,
        repeat(seq(optional(terminator), $._statement)),
        optional(terminator)
      ),

    _statement: ($) =>
      choice(
        $._simple_statement,
        $.assert_statement,
        $.return_statement,
        $.asm_statement,
        $.go_statement,
        $.goto_statement,
        $.labeled_statement,
        $.empty_labeled_statement,
        $.for_statement
      ),

    _simple_statement: ($) =>
      choice(
        $._expression,
        $.inc_statement,
        $.dec_statement,
        $.assignment_statement,
        $.short_var_declaration
      ),

    inc_statement: ($) => seq($._expression, "++"),

    dec_statement: ($) => seq($._expression, "--"),

    short_var_declaration: ($) => assignment_statement_support($, ":="),

    assignment_statement: ($) =>
      assignment_statement_support($, choice(...assignment_operators)),

    assert_statement: ($) => seq(assert_keyword, $._expression),

    block: ($) => seq("{", optional($._statement_list), "}"),

    overloadable_operator: ($) => choice(...overloadable_operators),

    function_declaration: ($) =>
      prec.right(
        seq(
          field("attributes", optional($.attribute_list)),
          optional(pub_keyword),
          fn_keyword,
          field("receiver", optional($.parameter_list)),
          field("name", choice($.identifier, $.overloadable_operator)),
          field("type_parameters", optional($.type_parameters)),
          field("parameters", $.parameter_list),
          field("result", optional($._type)),
          field("body", optional($.block))
        )
      ),

    function_type: ($) =>
      prec.right(
        seq(
          "fn",
          field("parameters", $.parameter_list),
          field("result", optional($._type))
        )
      ),

    fn_literal: ($) =>
      seq(
        "fn",
        field("parameters", $.parameter_list),
        field("result", optional($._type)),
        field("body", $.block)
      ),

    global_var_declaration: ($) =>
      seq(
        global_keyword,
        choice(
          $._global_var_spec,
          $.global_var_type_initializer,
          seq(
            "(",
            repeat(
              seq(
                choice($._global_var_spec, $.global_var_type_initializer),
                terminator
              )
            ),
            ")"
          )
        )
      ),

    _global_var_spec: ($) => alias($.const_spec, $.global_var_spec),

    global_var_type_initializer: ($) =>
      seq(field("name", $.identifier), field("type", $._type)),

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

    return_statement: ($) =>
      prec.left(seq(return_keyword, optional(choice($._expression)))),

    type_declaration: ($) =>
      seq(
        optional(pub_keyword),
        type_keyword,
        field("name", $._type_identifier),
        "=",
        field("type", seq($._type, repeat(seq("|", $._type))))
      ),

    go_statement: ($) => seq(go_keyword, $._expression),

    goto_statement: ($) => seq("goto", alias($.identifier, $.label_name)),

    labeled_statement: ($) =>
      prec.right(
        PREC.resolve,
        seq(
          field("label", alias($.identifier, $.label_name)),
          ":",
          $._statement
        )
      ),

    empty_labeled_statement: ($) =>
      seq(field("label", alias($.identifier, $.label_name)), ":"),

    for_statement: ($) =>
      seq(
        for_keyword,
        optional(
          choice(
            $.for_in_operator,
            $._expression, // condition-based for
            $.cstyle_for_clause
          )
        ),
        field("body", $.block)
      ),

    for_in_operator: ($) =>
      prec.right(
        PREC.primary,
        seq(
          field("left", $.identifier_list),
          in_keyword,
          field("right", choice($._expression, alias($._range, $.range)))
        )
      ),

    _range: ($) =>
      prec.right(
        PREC.multiplicative,
        choice(
          seq(field("start", $._expression), "..", field("end", $._expression)),
          seq(
            field("start", $._expression),
            "..",
            field("end", optional($._expression))
          ),
          seq(
            field("start", optional($._expression)),
            "..",
            field("end", $._expression)
          )
        )
      ),

    cstyle_for_clause: ($) =>
      prec.right(
        seq(
          field("initializer", optional($._simple_statement)),
          ";",
          field("condition", optional($._expression)),
          ";",
          field("update", optional($._simple_statement))
        )
      ),

    if_expression: ($) =>
      seq(
        "if",
        choice(
          field("condition", $._expression),
          field("initializer", $.short_var_declaration)
        ),
        field("consequence", $.block),
        optional(
          seq("else", field("alternative", choice($.block, $.if_expression)))
        )
      ),

    attribute_spec: ($) =>
      prec(
        PREC.attributes,
        choice(
          choice(alias("unsafe", $.identifier), $.identifier),
          seq(
            field("name", choice(alias("unsafe", $.identifier), $.identifier)),
            ":",
            field("value", choice($._string_literal, $.identifier))
          )
        )
      ),

    attribute_declaration: ($) =>
      seq("[", seq($.attribute_spec, repeat(seq(";", $.attribute_spec))), "]"),

    attribute_list: ($) =>
      repeat1(seq($.attribute_declaration, optional(terminator))),

    struct_declaration: ($) =>
      seq(
        field("attributes", optional($.attribute_list)),
        optional(pub_keyword),
        struct_keyword,
        $._type,
        $.struct_field_declaration_list
      ),

    struct_field_declaration_list: ($) =>
      seq(
        "{",
        repeat(
          seq(
            choice($.struct_field_scope, $.struct_field_declaration),
            optional(terminator)
          )
        ),
        "}"
      ),

    struct_field_scope: ($) =>
      seq(
        choice(
          pub_keyword,
          mut_keyword,
          seq(pub_keyword, mut_keyword),
          global_keyword
        ),
        ":"
      ),

    struct_field_declaration: ($) =>
      prec.right(
        choice(
          seq(
            field("name", $._field_identifier),
            field("type", $._type),
            field("attributes", optional($.attribute_declaration)),
            optional(seq("=", field("default_value", $._expression))),
            optional(terminator)
          ),
          field(
            "type",
            seq(
              choice($._type_identifier, $.qualified_type),
              optional(terminator)
            )
          )
        )
      ),

    enum_declaration: ($) =>
      seq(
        optional($.attribute_list),
        optional(pub_keyword),
        enum_keyword,
        $._type_identifier,
        $.enum_member_declaration_list
      ),

    enum_member_declaration_list: ($) =>
      seq(
        "{",
        optional(seq(repeat(seq($.enum_member, optional(terminator))))),
        "}"
      ),

    enum_member: ($) =>
      seq(
        field("name", $.identifier),
        optional(seq("=", field("value", $.int_literal)))
      ),

    enum_identifier: ($) => seq(".", field("field_name", $.identifier)),

    interface_declaration: ($) =>
      seq(
        field("attributes", optional($.attribute_list)),
        optional(pub_keyword),
        interface_keyword,
        $._type_identifier,
        $.interface_spec_list
      ),

    interface_spec_list: ($) =>
      seq(
        "{",
        optional(
          repeat(
            seq(
              choice(
                $.struct_field_declaration,
                $.interface_spec,
                $.interface_field_scope
              ),
              optional(terminator)
            )
          )
        ),
        "}"
      ),

    interface_field_scope: ($) => seq(mut_keyword + ":"),

    interface_spec: ($) =>
      prec.right(
        seq(
          field("name", $._field_identifier),
          field("parameters", $.parameter_list),
          field("result", optional($._type))
        )
      ),
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
