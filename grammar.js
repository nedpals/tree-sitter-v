const
  PREC = {
    primary: 7,
    unary: 6,
    multiplicative: 5,
    additive: 4,
    comparative: 3,
    and: 2,
    or: 1,
    composite_literal: -1,
  },

  multiplicative_operators = ['*', '/', '%', '<<', '>>', '&', '&^'],
  additive_operators = ['+', '-', '|', '^'],
  comparative_operators = ['==', '!=', '<', '<=', '>', '>='],
  assignment_operators = multiplicative_operators.concat(additive_operators).map(operator => operator + '=').concat('='),

  unicodeLetter = /[a-zA-Zα-ωΑ-Ωµ]/,
  unicodeDigit = /[0-9]/,
  unicodeChar = /./,
  unicodeValue = unicodeChar,
  letter = choice(unicodeLetter, '_'),

  newline = '\n',
  terminator = newline,

  hexDigit = /[0-9a-fA-F]/,
  octalDigit = /[0-7]/,
  decimalDigit = /[0-9]/,
  binaryDigit = /[01]/,

  hexDigits = seq(hexDigit, repeat(seq(optional('_'), hexDigit))),
  octalDigits = seq(octalDigit, repeat(seq(optional('_'), octalDigit))),
  decimalDigits = seq(decimalDigit, repeat(seq(optional('_'), decimalDigit))),
  binaryDigits = seq(binaryDigit, repeat(seq(optional('_'), binaryDigit))),

  hexLiteral = seq('0', choice('x', 'X'), optional('_'), hexDigits),
  octalLiteral = seq('0', optional(choice('o', 'O')), optional('_'), octalDigits),
  decimalLiteral = choice('0', seq(/[1-9]/, optional(seq(optional('_'), decimalDigits)))),
  binaryLiteral = seq('0', choice('b', 'B'), optional('_'), binaryDigits),

  intLiteral = choice(binaryLiteral, decimalLiteral, octalLiteral, hexLiteral),

  decimalExponent = seq(choice('e', 'E'), optional(choice('+', '-')), decimalDigits),
  decimalFloatLiteral = choice(
    seq(decimalDigits, '.', decimalDigits, optional(decimalExponent)),
    seq(decimalDigits, decimalExponent),
    seq('.', decimalDigits, optional(decimalExponent)),
  ),

  hexExponent = seq(choice('p', 'P'), optional(choice('+', '-')), decimalDigits),
  hexMantissa = choice(
    seq(optional('_'), hexDigits, '.', optional(hexDigits)),
    seq(optional('_'), hexDigits),
    seq('.', hexDigits),
  ),
  hexFloatLiteral = seq('0', choice('x', 'X'), hexMantissa, hexExponent),

  floatLiteral = choice(decimalFloatLiteral, hexFloatLiteral),

  imaginaryLiteral = seq(choice(decimalDigits, intLiteral, floatLiteral), 'i')

module.exports = grammar({
  name: 'v',

  extras: $ => [
    $.comment,
    /\s/
  ],

  inline: $ => [
    $._type,
    $._type_identifier,
    $._field_identifier,
    $._module_identifier,
    $._string_literal,
  ],

  word: $ => $.identifier,

  conflicts: $ => [
    [$._simple_type, $.in_operator, $._expression],
    [$.in_operator, $._expression],
    [$.in_operator, $.casting_expression],
    [$.function_type, $._simple_type],
    [$._simple_type, $.qualified_type],
    [$.if_statement],
    [$._statement, $._expression],
    [$.array_type, $._expression],
    [$.array_type],
    [$._simple_type, $._expression],
    [$.qualified_type, $._expression],
    [$.fn_literal, $.function_type],
    [$.function_type],
    [$.parameter_declaration, $._simple_type],
  ],

  supertypes: $ => [
    $._expression,
    $._type,
    $._simple_type,
    $._statement,
    $._simple_statement,
  ],

  rules: {
    source_file: $ => repeat(seq(
      choice(
        $.module_clause,
        $.function_declaration,
        $.method_declaration,
        $.import_declaration,
        $._c_directive,
        $._declaration
      ),
      optional(terminator)
    )),

    _c_directive: $ => seq(
      '#',
      choice(
        $.c_include_clause,
        $.c_flag_clause,
        $.c_define_clause
      )
    ),

    c_include_clause: $ => seq(
      'include',
      field('path', choice(
        $.interpreted_string_literal,
        seq('<', $.identifier, '.', $.identifier, '>')
      ))
    ),

    c_flag_clause: $ => seq(
      'flag',
      optional(field('platform', choice('linux', 'darwin', 'windows'))),
      field('value', choice(
        token(seq(choice('-', letter, '@'), repeat(choice('-', letter, unicodeDigit, / /, '@')))),
      ))
    ),

    c_define_clause: $ => seq(
      'define',
      $.identifier,
      optional($.identifier)
    ),

    module_clause: $ => seq(
      'module',
      $._module_identifier
    ),

    import_declaration: $ => seq(
      'import',
      $.import_spec
    ),

    import_spec: $ => seq(
      field('path', $.identifier),
      optional('as'),
      optional(field('name', choice(
        $.blank_identifier,
        $._module_identifier
      )))
    ),
    blank_identifier: $ => '_',

    _declaration: $ => choice(
      // $.receive_statement,
      $.const_declaration,
      $.type_declaration,
      $.struct_declaration,
      $.enum_declaration
    ),

    const_declaration: $ => seq(
      optional('pub'),
      'const',
      seq(
        '(',
        repeat(seq($.const_spec, terminator)),
        ')'
      )
    ),

    const_spec: $ => prec.left(seq(
      field('name', commaSep1($.identifier)),
      optional(seq(
        optional(field('type', $._type)),
        '=',
        field('value', $.expression_list)
      ))
    )),

    fn_attribute: $ => seq(
      '[',
      choice('if', 'deprecated', 'inline', 'typedef',),
      ']'
    ),

    function_declaration: $ => prec.right(seq(
      optional(field('attribute', $.fn_attribute)),
      optional('pub'),
      'fn',
      field('name', $.identifier),
      field('parameters', $.parameter_list),
      field('result', optional(choice($.parameter_list, $._simple_type, $.optional_type))),
      field('body', optional($.block))
    )),

    method_declaration: $ => prec.right(seq(
      optional(field('attribute', $.fn_attribute)),
      optional('pub'),
      'fn',
      field('receiver', $.parameter_list),
      field('name', $._field_identifier),
      field('parameters', $.parameter_list),
      field('result', optional(choice($.parameter_list, $._simple_type, $.optional_type))),
      field('body', optional($.block))
    )),

    parameter_list: $ => seq(
      '(',
      optional(seq(
        commaSep(choice($.parameter_declaration, $.variadic_parameter_declaration)),
        optional(',')
      )),
      ')'
    ),

    parameter_declaration: $ => seq(
      field('name', commaSep($.identifier)),
      optional('mut'),
      field('type', $._type)
    ),

    variadic_parameter_declaration: $ => seq(
      field('name', optional($.identifier)),
      '...',
      field('type', $._type)
    ),

    type_alias: $ => seq(
      field('name', $._type_identifier),
      '=',
      field('type', seq(
        $._type,
        repeat(seq('|', $._type))
      ))
    ),

    type_declaration: $ => seq(
      optional('pub'),
      'type',
      choice(
        $.type_spec,
        $.type_alias,
        seq(
          '(',
          repeat(seq(choice($.type_spec, $.type_alias), terminator)),
          ')'
        )
      )
    ),

    type_spec: $ => seq(
      field('name', $._type_identifier),
      field('type', $._type)
    ),

    field_name_list: $ => commaSep1($._field_identifier),

    expression_list: $ => commaSep1($._expression),

    _type: $ => choice(
      $.optional_type,
      $._simple_type,
      $.parenthesized_type
    ),

    optional_type: $ => seq('?', $._type),

    parenthesized_type: $ => seq('(', $._type, ')'),

    _simple_type: $ => choice(
      prec.dynamic(-1, $._type_identifier),
      $.qualified_type,
      $.pointer_type,
      $.array_type,
      $.map_type,
      $.function_type
    ),

    pointer_type: $ => prec(PREC.unary, seq('&', $._type)),

    array_type: $ => seq(
      '[',
      optional(choice(
        field('length', $._expression),
        field('item', commaSep1($._expression))
      )),
      ']',
      optional(field('element', $._type))
    ),

    // array_initializer: $ => seq(
    //   '[',
    //   field('item', repeat(seq(',', $._expression))),
    //   ']',
    // ),

    struct_declaration: $ => seq(
      optional('pub'),
      'struct',
      prec.dynamic(-1, $._type_identifier),
      $.field_declaration_list
    ),

    struct_type: $ => seq(
      'struct',
      prec.dynamic(-1, $._type_identifier),
      $.field_declaration_list
    ),

    enum_declaration: $ => seq(
      optional('pub'),
      'enum',
      prec.dynamic(-1, $._type_identifier),
      $.enum_declaration_list
    ),

    enum_type: $ => seq(
      'enum',
      prec.dynamic(-1, $._type_identifier),
      $.enum_declaration_list
    ),

    enum_declaration_list: $ => seq(
      '{',
      optional(seq(
        $.enum_field,
        repeat(seq(terminator, $.enum_field)),
        optional(terminator)
      )),
      '}'
    ),

    enum_field: $ => seq(
      field('name', commaSep1($.identifier)),
      optional(seq(
        '=',
        field('value', $.expression_list)
      ))
    ),

    field_scopes: $ => choice('mut:', 'pub mut:', '__global:'),

    field_declaration_list: $ => seq(
      '{',
      optional(seq(
        optional($.field_scopes), 
        $.field_declaration,
        repeat(seq(terminator, optional($.field_scopes), $.field_declaration)),
        optional(terminator)
      )),
      '}'
    ),

    field_declaration: $ => prec(1, seq(
      choice(
        seq(
          field('name', commaSep1($._field_identifier)),
          field('type', $._type),
          optional(
            field('tag', seq(
              '[',
                $.identifier,
              ']'
            ))
          )
        ),
        seq(
          optional('*'),
          field('type', choice(
            $._type_identifier,
            $.qualified_type
          )),
          optional(
            field('tag', seq(
              '[',
                $.identifier,
              ']'
            ))
          )
        )
      ),
    )),

    interface_type: $ => seq(
      'interface',
      prec.dynamic(-1, $._type_identifier),
      $.method_spec_list
    ),

    method_spec_list: $ => seq(
      '{',
      optional(seq(
        choice($._type_identifier, $.qualified_type, $.method_spec),
        repeat(seq(terminator, choice($._type_identifier, $.qualified_type, $.method_spec))),
        optional(terminator)
      )),
      '}'
    ),

    method_spec: $ => seq(
      field('name', $._field_identifier),
      field('parameters', $.parameter_list),
      field('result', optional(choice($.parameter_list, $._simple_type, $.optional_type)))
    ),

    map_type: $ => seq(
      'map',
      '[',
      field('key', $._type),
      ']',
      field('value', $._type)
    ),

    function_type: $ => seq(
      optional(field('attribute', $.fn_attribute)),
      'fn',
      field('parameters', $.parameter_list),
      field('result', optional(choice($.parameter_list, $._simple_type, $.optional_type)))
    ),

    block: $ => seq(
      '{',
      optional($._statement_list),
      '}'
    ),

    _statement_list: $ => choice(
      seq(
        $._statement,
        repeat(seq(terminator, $._statement)),
        optional(seq(
          terminator,
          optional(alias($.empty_labeled_statement, $.labeled_statement))
        ))
      ),
      alias($.empty_labeled_statement, $.labeled_statement)
    ),

    _statement: $ => choice(
      $._declaration,
      $._simple_statement,
      $.return_statement,
      $.go_statement,
      $.defer_statement,
      $.if_statement,
      $.for_statement,
      $.match_statement,
      $.labeled_statement,
      $.break_statement,
      $.continue_statement,
      $.goto_statement,
      $.block,
      $.empty_statement
    ),

    empty_statement: $ => ';',

    _simple_statement: $ => choice(
      $._expression,
      $.inc_statement,
      $.dec_statement,
      $.assignment_statement,
      $.short_var_declaration
    ),

    receive_statement: $ => seq(
      optional(seq(
        field('left', $.expression_list),
        choice('=', ':=')
      )),
      field('right', $._expression)
    ),

    inc_statement: $ => seq(
      $._expression,
      '++'
    ),

    dec_statement: $ => seq(
      $._expression,
      '--'
    ),

    assignment_statement: $ => seq(
      field('left', $.expression_list),
      field('operator', choice(...assignment_operators)),
      field('right', $._expression)
    ),

    short_var_declaration: $ => seq(
      // TODO: this should really only allow identifier lists, but that causes
      // conflicts between identifiers as expressions vs identifiers here.
      field('left', choice(
        $.expression_list,
        seq('mut', $.expression_list)
      )),
      ':=',
      field('right', $._expression)
    ),

    labeled_statement: $ => seq(
      field('label', alias($.identifier, $.label_name)),
      ':',
      $._statement
    ),

    empty_labeled_statement: $ => seq(
      field('label', alias($.identifier, $.label_name)),
      ':'
    ),

    break_statement: $ => seq('break', optional(alias($.identifier, $.label_name))),

    continue_statement: $ => seq('continue', optional(alias($.identifier, $.label_name))),

    goto_statement: $ => seq('goto', alias($.identifier, $.label_name)),

    return_statement: $ => seq('return', optional($.expression_list)),

    go_statement: $ => seq('go', $._expression),

    defer_statement: $ => seq('defer', $._expression),

    if_statement: $ => seq(
      optional('$'),
      'if',
      field('condition', $._expression),
      field('consequence', $.block),
      optional(seq(
        optional('$'),
        'else',
        field('alternative', choice($.block, $.if_statement))
      ))
    ),

    for_statement: $ => seq(
      'for',
      optional(choice($._expression, $.for_clause, $.range)),
      field('body', $.block)
    ),

    for_clause: $ => seq(
      field('initializer', optional($._simple_statement)),
      ';',
      field('condition', optional($._expression)),
      ';',
      field('update', optional($._simple_statement))
    ),

    in_operator: $ => seq(
      commaSep1($.identifier), 
      'in',
      choice($._expression, $.range)
    ),

    match_statement: $ => seq(
      'match',
      field('condition', $._expression),
      '{',
      repeat(choice($.expression_case)),
      $.default_case,
      '}'
    ),

    expression_case: $ => seq(
      field('value', $.expression_list),
      field('consequence', $.block)
    ),

    default_case: $ => seq(
      'else',
      field('consequence', $.block)
    ),

    _expression: $ => choice(
      $.unary_expression,
      $.binary_expression,
      $.selector_expression,
      $.array_type,
      $.slice_expression,
      $.index_expression,
      $.call_expression,
      $.type_conversion_expression,
      $.identifier,
      $.composite_literal,
      $._string_literal,
      $.match_statement,
      $.if_statement,
      $.fn_literal,
      $.int_literal,
      $.float_literal,
      $.in_operator,
      $.imaginary_literal,
      $.rune_literal,
      $.none,
      $.true,
      $.false,
      $.parenthesized_expression,
      $.casting_expression
    ),

    range: $ => prec.right(24, seq(field('start', optional($._expression)), '..', field('end', optional($._expression)))),

    parenthesized_expression: $ => seq(
      '(',
      $._expression,
      ')'
    ),

    casting_expression: $ => seq(
      field('expr', $._expression),
      'as',
      field('type', $._type)
    ),

    call_expression: $ => prec(1, choice(
      seq(
        field('function', $._expression),
        field('arguments', alias($.special_argument_list, $.argument_list)),
        field('optional_body', optional($.optional_block))
      ),
      seq(
        field('function', $._expression),
        field('arguments', $.argument_list),
        field('optional_body', optional($.optional_block))
      )
    )),

    optional_block: $ => prec.right(seq(
      'or',
      '{',
      $._statement_list,
      '}'
    )),

    variadic_argument: $ => prec.right(seq(
      $._expression,
      '...'
    )),

    special_argument_list: $ => seq(
      '(',
      $._type,
      optional('mut'),
      repeat(seq(',', $._expression)),
      optional(','),
      ')'
    ),

    argument_list: $ => seq(
      '(',
      optional(seq(
        optional('mut'),
        choice($._expression, $.variadic_argument, $.range),
        repeat(seq(',', optional('mut'), choice($._expression, $.variadic_argument, $.range))),
        optional(',')
      )),
      ')'
    ),

    selector_expression: $ => prec(PREC.primary, seq(
      optional(field('operand', $._expression)),
      '.',
      field('field', $._field_identifier)
    )),

    index_expression: $ => prec(PREC.primary, seq(
      field('operand', $._expression),
      '[',
      field('index', $._expression),
      ']'
    )),

    slice_expression: $ => prec(PREC.primary, seq(
      field('operand', $._expression),
      '[',
      field('start', optional($._expression)), 
      '..', 
      field('end', optional($._expression)),
      ']'
    )),

    type_conversion_expression: $ => prec.dynamic(-1, seq(
      field('type', $._type),
      '(',
      field('operand', $._expression),
      optional(','),
      ')'
    )),

    composite_literal: $ => prec(PREC.composite_literal, seq(
      field('type', choice(
        $.map_type,
        $.struct_type,
        $.enum_type,
        $._type_identifier,
        $.qualified_type
      )),
      field('body', $.literal_value)
    )),

    literal_value: $ => seq(
      '{',
      optional(seq(
        choice($.element, $.keyed_element),
        repeat(seq(',', choice($.element, $.keyed_element))),
        optional(',')
      )),
      '}'
    ),

    keyed_element: $ => seq(
      choice(
        seq($._expression, ':'),
        seq($.literal_value, ':'),
        prec(1, seq($._field_identifier, ':'))
      ),
      choice(
        $._expression,
        $.literal_value
      )
    ),

    element: $ => choice(
      $._expression,
      $.literal_value
    ),

    fn_literal: $ => seq(
      optional(field('attribute', $.fn_attribute)),
      'fn',
      field('parameters', $.parameter_list),
      field('result', optional(choice($.parameter_list, $._simple_type, $.optional_type))),
      field('body', $.block)
    ),

    unary_expression: $ => prec(PREC.unary, seq(
      field('operator', choice('+', '-', '!', '^', '*', '&', '<-')),
      field('operand', $._expression)
    )),

    binary_expression: $ => {
      const table = [
        [PREC.multiplicative, choice(...multiplicative_operators)],
        [PREC.additive, choice(...additive_operators)],
        [PREC.comparative, choice(...comparative_operators)],
        [PREC.and, '&&'],
        [PREC.or, '||'],
      ];

      return choice(...table.map(([precedence, operator]) =>
        prec.left(precedence, seq(
          field('left', $._expression),
          field('operator', operator),
          field('right', $._expression)
        ))
      ));
    },

    qualified_type: $ => seq(
      field('module', $._module_identifier),
      '.',
      field('name', $._type_identifier)
    ),

    identifier: $ => token(seq(
      letter,
      repeat(choice(letter, unicodeDigit)),
      optional(seq(
        '<',
        choice('T', 'U'),
        repeat(seq(',', 'T', 'U')),
        '>'
      ))
    )),

    _compile_time_identifier: $ => alias(seq('$', $.identifier), $.compile_time_identifier),
    _type_identifier: $ => alias($.identifier, $.type_identifier),
    _field_identifier: $ => alias($.identifier, $.field_identifier),
    _module_identifier: $ => alias($.identifier, $.module_identifier),

    _string_literal: $ => choice(
      $.raw_string_literal,
      $.c_string_literal,
      $.interpreted_string_literal
    ),

    raw_string_literal: $ => seq(
      'r\'',
      repeat(choice(
        token.immediate(prec(1, /[^$"'\n\\]/)),
        $.string_interpolation,
        $.escape_sequence,
      )),
      '\''
    ),

    c_string_literal: $ => seq(
      'c\'',
      repeat(token.immediate(prec(1, /[^'\n\\]/))),
      '\''
    ),

    interpreted_string_literal: $ => seq(
      choice('\'', '"'),
      repeat(choice(
        token.immediate(prec(1, /[^$"'\n\\]/)),
        $.string_interpolation,
        $.escape_sequence,
      )),
      choice('\'', '"')
    ),

    string_interpolation: $ => seq(
      '$',
      optional('{'),
      $._expression,
      optional('}')
    ),

    escape_sequence: $ => token(
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
            /['"abfrntv\\]/
          )
        )
      )
    ),

    int_literal: $ => token(intLiteral),

    float_literal: $ => token(floatLiteral),

    imaginary_literal: $ => token(imaginaryLiteral),

    rune_literal: $ => token(seq(
      "`",
      choice(
        /[^'\\]/,
        seq(
          '\\',
          choice(
            seq('x', hexDigit, hexDigit),
            seq(octalDigit, octalDigit, octalDigit),
            seq('u', hexDigit, hexDigit, hexDigit, hexDigit),
            seq('U', hexDigit, hexDigit, hexDigit, hexDigit, hexDigit, hexDigit, hexDigit, hexDigit),
            seq(choice('a', 'b', 'f', 'n', 'r', 't', 'v', '\\', "'", '"'))
          )
        )
      ),
      "`"
    )),

    none: $ => 'none',
    true: $ => 'true',
    false: $ => 'false',

    // http://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: $ => token(choice(
      seq('//', /.*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
        '/'
      )
    ))
  }
})

function commaSep1(rule) {
  return seq(rule, repeat(seq(',', rule)))
}

function commaSep(rule) {
  return optional(commaSep1(rule))
}
