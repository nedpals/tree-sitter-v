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

  imaginaryLiteral = seq(choice(decimalDigits, intLiteral, floatLiteral), 'i'),

  builtinTypes = ['string', 'int', 'byte', 'bool', 'float', 'chan', 'char', 'f32', 'f64', 'i64', 'i32', 'i8', 'u16', 'u32', 'u64', 'voidptr', 'ustring', 'size_t', 'float_literal', 'int_literal', 'thread', 'any']

  pub_keyword = 'pub',
  mut_keyword = 'mut',
  global_keyword = '__global',
  scopes = [pub_keyword, mut_keyword, global_keyword]

module.exports = grammar({
  name: 'v',

  extras: $ => [
    $.comment,
    /\s/
  ],

  inline: $ => [
    $._type,
    $._module_identifier,
    $._field_identifier,
    $._type_identifier,
    $._string_literal,
  ],

  word: $ => $.identifier,

  conflicts: $ => [
    [$._simple_type, $._expression],
    [$.in_operator, $._expression],
    // [$.function_type, $._simple_type],
    [$._simple_type, $.qualified_type],
    [$.map_type, $.type_identifier],
    [$._statement, $._expression],
    [$.array_type, $._expression],
    [$._simple_type, $._expression],
    [$.qualified_type, $._expression],
    [$.binded_type, $._expression],
    // [$.fn_literal, $.function_type],
    [$.parameter_declaration, $._simple_type],
    [$.fixed_array_type, $._expression],
    // TODO:
    [$.call_expression],
    [$.index_expression],
    [$.array_initializer],
    [$.block, $.keyed_literal_value],
    [$.literal_value, $.keyed_literal_value]
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
        $._c_directive,
        $._top_level_declaration,
      ),
      optional(terminator)
    )),

    // C Directives (include/flag/define)
    _c_directive: $ => choice(
      $.c_include_clause,
      $.c_flag_clause,
      $.c_define_clause
    ),

    c_include_clause: $ => seq(
      '#include',
      field('path', choice(
        $.interpreted_string_literal,
        $.c_include_path_string
      ))
    ),

    // Taken from: https://github.com/tree-sitter/tree-sitter-c/blob/master/grammar.js#L937
    c_include_path_string: $ => seq(
      '<', 
      token(seq(
        repeat(choice(/[^>\n]/, '\\>')),
      )), 
      '>'
    ),

    c_flag_clause: $ => seq(
      '#flag',
      optional(field('platform', $.identifier)),
      field('flag', optional(seq('-', letter))),
      field('value', token(repeat(
        choice('-', letter, unicodeDigit, / /, '@', '$')
      )))
    ),

    c_define_clause: $ => seq(
      '#define',
      $.identifier,
      / /,
      $.c_define_value
    ),
    
    c_define_value: $ => token(repeat(/[^\n]/)),

    // Module
    module_clause: $ => seq(
      'module',
      $._module_identifier
    ),

    // Import
    import_declaration: $ => seq(
      'import',
      $.import_spec
    ),

    import_path: $ => seq($.identifier, repeat(seq('.', $.identifier))),

    import_symbols: $ => seq('{', commaSep1($.identifier),'}'),

    import_alias: $ => seq('as', field('alias', $._module_identifier)),

    import_spec: $ => seq(
      field('path', $.import_path),
      optional($.import_alias),
      optional($.import_symbols)
    ),

    // Consts
    const_declaration: $ => seq(
      optional(pub_keyword),
      'const',
      choice(
        $.const_spec,
        seq(
          '(',
          repeat(seq($.const_spec, terminator)),
          ')'
        )
      ),
    ),

    const_spec: $ => prec.left(seq(
      field('name', $.identifier),
      '=',
      field('value', $._expression)
    )),

    // Attributes
    attribute_spec: $ => choice(
      $.identifier,
      seq(
        field('name', $.identifier),
        ':',
        field('value', choice($._string_literal, $.identifier))
      )
    ),

    attribute_declaration: $ => seq(
      '[',
      seq(
        $.attribute_spec,
        repeat(seq(';', $.attribute_spec)),
      ),
      ']'
    ),

    // Function / Method
    function_declaration: $ => prec.right(seq(
      // optional(field('attribute', $.attribute_declaration)),
      optional(pub_keyword),
      'fn',
      optional(field('receiver', $.parameter_list)),
      field('name', $.identifier),
      field('parameters', $.parameter_list),
      field('result', optional(choice($._simple_type, $.option_type, $.option_void_type, $.multi_return_type))),
      field('body', optional($.block))
    )),

    parameter_list: $ => seq(
      '(',
      optional(seq(
        commaSep($.parameter_declaration),
        optional(',')
      )),
      ')'
    ),

    parameter_declaration: $ => seq(
      optional(mut_keyword),
      field('name', $.identifier),
      field('type', choice($._type, $.variadic_type))
    ),

    // Type Declaration
    type_declaration: $ => seq(
      optional(pub_keyword),
      'type',
      choice(
        $.type_spec,
      )
    ),

    type_spec: $ => seq(
      field('name', $._type_identifier),
      '=',
      field('type', seq(
        $._type,
        repeat(seq('|', $._type))
      ))
    ),

    _type: $ => choice(
      $.option_type,
      $._simple_type,
    ),

    option_type: $ => seq('?', $._type),

    option_void_type: $ => token('?'),

    multi_return_type: $ => seq('(', commaSep1($._simple_type), ')'),

    _simple_type: $ => choice(
      prec.dynamic(-1, $._type_identifier),
      $.builtin_type,
      $.binded_type,
      $.qualified_type,
      $.pointer_type,
      $.array_type,
      $.fixed_array_type,
      $.map_type,
      // $.function_type
    ),
    
    binded_type: $ => seq(
      field('language', choice('C', 'JS')),
      '.',
      field('name', $._type_identifier)
    ),

    pointer_type: $ => prec(PREC.unary, seq('&', $._simple_type)),

    array_type: $ => seq(
      '[]',
      field('element', $._simple_type)
    ),

    fixed_array_type: $ => seq(
      '[',
      field('limit', choice($.identifier, $.int_literal)),
      ']',
      field('element', $._simple_type)
    ),

    variadic_type: $ => seq(
      '...',
      $._simple_type
    ),
    
    expression_list: $ => commaSep1($._expression),

    // Enum
    enum_declaration: $ => seq(
      optional(pub_keyword),
      'enum',
      prec.dynamic(-1, $._type_identifier),
      $.enum_member_declaration_list
    ),

    enum_member_declaration_list: $ => seq(
      '{',
      optional(seq(
        repeat(seq(
          $.enum_member, 
          optional(terminator)
        ))
      )),
      '}'
    ),

    enum_member: $ => seq(
      field('name', $.identifier),
      optional(seq(
        '=',
        field('value', $.int_literal)
      ))
    ),

    // enum_identifier: $ => prec.right(seq(
    //   optional(choice(
    //     $._module_identifier,
    //     $.qualified_type
    //   )),
    //   '.',
    //   field('field_name', $.identifier)
    // )),

    // Struct
    struct_declaration: $ => seq(
      optional(pub_keyword),
      'struct',
      prec.dynamic(-1, choice($.binded_type, $._type_identifier)),
      $.struct_field_declaration_list,
    ),

    struct_field_scope: $ => seq(
      choice(
        pub_keyword,
        seq(pub_keyword, mut_keyword),
        global_keyword
      ), 
      ':'
    ),

    struct_field_declaration_list: $ => seq(
      '{',
      optional(repeat(seq(
        choice($._type_identifier, $.qualified_type),
        optional(terminator)
      ))),
      optional(repeat(seq(
        choice(
        $.struct_field_scope, 
        $.struct_field_declaration
        ), 
        optional(terminator),
      ))),
      '}'
    ),

    struct_field_declaration: $ => prec(1, seq(
      field('name', $._field_identifier),
      field('type', $._type),
      optional(field('attributes', $.attribute_declaration)),
      optional(seq(
        '=',
        field('default_value', $._expression)
      ))
    )),

    interface_declaration: $ => seq(
      optional(pub_keyword),
      'interface',
      prec.dynamic(-1, $._type_identifier),
      $.interface_spec_list
    ),

    interface_spec_list: $ => seq(
      '{',
      optional(seq(
        choice($._type_identifier, $.qualified_type),
        optional(terminator)
      )),
      optional(seq(
        choice($.interface_spec, $.interface_field_scope),
        repeat(seq(terminator, choice($.interface_spec, $.interface_field_scope))),
        optional(terminator)
      )),
      '}'
    ),

    interface_field_scope: $ => seq(mut_keyword + ':'),

    interface_spec: $ => seq(
      field('name', $._field_identifier),
      field('parameters', $.parameter_list),
      field('result', optional(choice($.multi_return_type, $._simple_type, $.option_type, $.option_void_type)))
    ),

    map_type: $ => seq(
      'map',
      '[',
      field('key', $._simple_type),
      ']',
      field('value', $._type),
    ),

    // function_type: $ => seq(
    //   'fn',
    //   field('parameters', $.parameter_list),
    //   field('result', optional(choice($.parameter_list, $._simple_type, $.option_type)))
    // ),

    block: $ => seq(
      '{',
      optional($._statement_list),
      '}'
    ),

    _statement_list: $ => choice(
      seq(
        $._statement,
        repeat(seq(terminator, $._statement)),
        optional(terminator)
      )
    ),

    _top_level_declaration: $ => choice(
      $.import_declaration,
      $.const_declaration,
      $.type_declaration,
      $.struct_declaration,
      $.interface_declaration,
      $.enum_declaration,
      $.function_declaration
    ),

    _statement: $ => choice(
      $._simple_statement,
      $.return_statement,
      $.go_statement,
      $.defer_statement,
      $.unsafe_statement,
      $.if_statement,
      $.comptime_if_statement,
      $.for_statement,
      $.comptime_for_statement,
      // $.match_statement,
      $.break_statement,
      $.continue_statement,
      $.block,
      $.empty_statement
    ),

    empty_statement: $ => ';',

    _simple_statement: $ => choice(
      $._expression,
      $.inc_statement,
      $.dec_statement,
      $.assignment_statement,
      $.short_var_declaration,
    ),

    // receive_statement: $ => seq(
    //   optional(seq(
    //     field('left', $.expression_list),
    //     choice(token('='), token(':='))
    //   )),
    //   field('right', $._expression)
    // ),

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
      field('left', $.expression_list),
      ':=',
      field('right', $._expression)
    ),

    break_statement: $ => seq('break', optional(alias($.identifier, $.label_name))),

    continue_statement: $ => seq('continue', optional(alias($.identifier, $.label_name))),

    return_statement: $ => seq('return', optional($.expression_list)),

    go_statement: $ => seq('go', $._expression),

    defer_statement: $ => seq('defer', $.block),

    unsafe_statement: $ => seq('unsafe', $.block),

    if_statement: $ => seq(
      'if',
      field('condition', $._expression),
      field('consequence', $.block),
      optional(seq(
        'else',
        field('alternative', choice($.block, $.if_statement))
      ))
    ),

    comptime_if_statement: $ => seq(
      '$if',
      field('condition', $._expression),
      field('consequence', $.block),
      optional(seq(
        '$else',
        field('alternative', choice($.block, $.comptime_if_statement))
      ))
    ),

    for_statement: $ => seq(
      'for',
      optional(choice(
        $._expression, 
        $.in_operator, 
        $.cstyle_for_clause, 
        $.range
      )),
      field('body', $.block)
    ),

    cstyle_for_clause: $ => prec.right(seq(
      field('initializer', optional($._simple_statement)),
      ';',
      field('condition', optional($._expression)),
      ';',
      field('update', optional($._simple_statement))
    )),

    in_operator: $ => seq(
      commaSep1($.identifier), 
      'in',
      choice($._expression, $.range)
    ),

    comptime_for_statement: $ => seq(
      '$for',
      $.in_operator,
      field('body', $.block)
    ),

    // match_statement: $ => seq(
    //   'match',
    //   field('condition', $._expression),
    //   '{',
    //   repeat(choice($.expression_case)),
    //   $.default_case,
    //   '}'
    // ),

    expression_case: $ => seq(
      field('value', $.expression_list),
      field('consequence', $.block)
    ),

    default_case: $ => seq(
      'else',
      field('consequence', $.block)
    ),

    _expression: $ => choice(
      $.type_cast_expression,
      $.as_type_cast_expression,
      $.unary_expression,
      $.binary_expression,
      $.selector_expression,
      $.array_type,
      $.slice_expression,
      $.index_expression,
      $.call_expression,
      $.identifier,
      // $.enum_identifier,
      // $.composite_literal,
      $._string_literal,
      // $.match_statement,
      // $.if_statement,
      // $.fn_literal,
      $.array,
      $.type_initializer,
      $.int_literal,
      $.float_literal,
      $.imaginary_literal,
      $.rune_literal,
      $.none,
      $.true,
      $.false,
      $.parenthesized_expression,
    ),

    range: $ => prec.right(24, seq(field('start', optional($._expression)), '..', field('end', optional($._expression)))),

    parenthesized_expression: $ => seq(
      '(',
      $._expression,
      ')'
    ),

    type_cast_expression: $ => prec.dynamic(-1, seq(
      field('type', $._type),
      '(',
      field('operand', $._expression),
      ')'
    )),

    as_type_cast_expression: $ => prec.dynamic(-1, seq(
      field('expr', $._expression),
      'as',
      field('type', $._simple_type)
    )),

    call_expression: $ => prec(PREC.primary, seq(
      field('function', $._expression),
      field('arguments', $.argument_list),
      optional($.option_propagator)
    )),

    option_propagator: $ => prec.right(choice(
      token('?'),
      $.or_expression
    )),

    or_expression: $ => seq(
      'or',
      $.block
    ),

    decompose_expression: $ => prec.right(seq(
      '...',
      $._expression,
    )),

    argument_list: $ => seq(
      '(',
      optional(commaSep1(seq(
        optional(mut_keyword),
      ))),
      ')'
    ),

    selector_expression: $ => prec(PREC.primary, seq(
      field('operand', $._expression),
      '.',
      field('field', $.identifier)
    )),

    index_expression: $ => prec(PREC.primary, seq(
      field('operand', $._expression),
      '[',
      field('index', $._expression),
      ']',
      optional($.option_propagator)
    )),

    slice_expression: $ => prec(PREC.primary, seq(
      field('operand', $._expression),
      '[',
      field('start', optional($._expression)), 
      '..', 
      field('end', optional($._expression)),
      ']'
    )),

    array: $ => prec(-1, seq(
      '[',
      field('values', repeat(seq(
        $._expression,
        optional(',')
      ))),
      ']',
      optional(alias('!', $.fixed_array_indicator))
    )),

    type_initializer: $ => prec(-1, seq(
      field('type', choice(
        alias('map', $.type_identifier),
        $._type_identifier,
        $.builtin_type,
        $.binded_type,
        $.qualified_type,
        $.pointer_type,
        $.array_type,
        $.fixed_array_type,
        $.map_type
      )),
      field('body', $.literal_value)
    )),

    literal_value: $ => seq(
      '{',
      optional(
        repeat(seq(
          choice($.element, $.keyed_element, $.decomposed_element),
          optional(choice(',', terminator))
        )
      )),
      '}'
    ),

    keyed_element: $ => seq(
      choice(
        seq($._expression, ':'),
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

    // fn_literal: $ => seq(
    //   'fn',
    //   field('parameters', $.parameter_list),
    //   field('result', optional(choice($.parameter_list, $._simple_type, $.option_type))),
    //   field('body', $.block)
    // ),

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

    builtin_type: $ => token(choice(
      ...builtinTypes
    )),

    identifier: $ => token(seq(
      letter,
      repeat(choice(letter, unicodeDigit)),
    )),

    blank_identifier: $ => '_',
    _type_identifier: $ => alias($.identifier, $.type_identifier),
    _module_identifier: $ => alias($.identifier, $.module_identifier),
    _field_identifier: $ => alias($.identifier, $.field_identifier),

    // String/int/float literals
    _string_literal: $ => choice(
      $.raw_string_literal,
      $.c_string_literal,
      $.interpreted_string_literal
    ),

    raw_string_literal: $ => seq(
      'r',
      choice('\'', '"'),
      repeat(choice(
        token.immediate(prec(1, /[^$"'\n\\]/)),
        $.escape_sequence,
      )),
      choice('\'', '"')
    ),

    c_string_literal: $ => seq(
      'c',
      choice('\'', '"'),
      repeat(token.immediate(prec(1, /[^$"'\n\\]/))),
      choice('\'', '"')
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

function commaSep1(rules) {
  return seq(rules, repeat(seq(',', rules)))
}

function commaSep(rule) {
  return optional(commaSep1(rule))
}

function compTime(rule) {
  return seq(optional('$'), rule)
}