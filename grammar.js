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
  overloadable_operators = ['+', '-', '*', '/', '%', '<', '>', '==', '!=', '<=', '>='],

  pub_keyword = 'pub',
  mut_keyword = 'mut',
  global_keyword = '__global';

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

  // NOTE: Reduce conflicts as much as possible
  // to avoid parsing errors
  conflicts: $ => [
    [$._simple_type, $._expression],
    [$._simple_type, $.qualified_type],
    [$._simple_type, $.generic_type],
    [$.qualified_type, $._expression],
    [$.generic_type, $._expression],
    [$.fixed_array_type, $._expression],
    [$.fn_literal, $.function_type],
    [$.call_expression, $.binary_expression],
    [$.call_expression, $.unary_expression, $.binary_expression],
    [$.labeled_statement, $.empty_labeled_statement]
  ],

  supertypes: $ => [
    $._expression,
    $._type,
    $._simple_type,
    $._statement,
    $._simple_statement,
    $._expression_with_blocks
  ],

  rules: {
    source_file: $ => repeat(seq(
      choice(
        $._top_level_declaration,
        $._statement,
        // NOTE: might remove it later
        $._expression_with_blocks
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
      field('platform', optional($.identifier)),
      field('flag', optional(seq('-', letter))),
      field('value', token(prec(-1, repeat1(/.|\\\r?\n/))))
    ),

    c_define_clause: $ => seq(
      '#define',
      field('name', $.identifier),
      field('value', token(prec(-1, repeat1(/.|\\\r?\n/))))
    ),

    // Module
    module_clause: $ => seq(
      field('attributes', optional($.attribute_list)),
      'module',
      $._module_identifier
    ),

    // Import
    import_declaration: $ => prec.right(seq(
      'import',
      field('path', $.import_path),
      optional(choice(
        field('alias', $.import_alias),
        field('symbols', $.import_symbols)
      )),
    )),

    import_path: $ => prec.right(seq(
      $.identifier, 
      repeat(seq('.', $.identifier))
    )),

    import_symbols: $ => seq('{', $.import_symbols_list,'}'),

    import_symbols_list: $ => commaSep1($.identifier),

    import_alias: $ => seq('as', field('name', $._module_identifier)),

    // Globals
    global_var_declaration: $ => seq(
      global_keyword,
      choice(
        $._global_var_spec,
        $.global_var_type_initializer,
        seq(
          '(',
          repeat(seq(
            choice(
              $._global_var_spec, 
              $.global_var_type_initializer,
            ),
            terminator)),
          ')'
        )
      ),
    ),

    _global_var_spec: $ => alias($.const_spec, $.global_var_spec),

    global_var_type_initializer: $ => seq(
      field('name', $.identifier),
      field('type', $._type)
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
    attribute_spec: $ => prec(8, choice(
      choice(
        alias('unsafe', $.identifier),
        $.identifier,
      ),
      seq(
        field('name', choice(
          alias('unsafe', $.identifier),
          $.identifier,
        )),
        ':',
        field('value', choice($._string_literal, $.identifier))
      )
    )),

    attribute_declaration: $ => seq(
      '[',
      seq(
        $.attribute_spec,
        repeat(seq(';', $.attribute_spec)),
      ),
      ']'
    ),

    attribute_list: $ => repeat1(seq(
      $.attribute_declaration,
      optional(terminator)
    )),

    _function_identifier: $ => prec(1, choice(
      seq(
        field('name', $.identifier),
        field('type_parameters', optional($.type_parameters)),
      ),
      ...overloadable_operators.map(o => field('name', alias(o, $.identifier)))
    )),

    // Function / Method
    function_declaration: $ => prec.right(1, seq(
      field('attributes', optional($.attribute_list)),
      optional(pub_keyword),
      'fn',
      field('receiver', optional($.parameter_list)),
      field('language', optional($.language_spec)),
      $._function_identifier,
      field('parameters', $.parameter_list),
      field('result', optional($._type)),
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
      field('name', choice($.identifier, $._mutable_identifier)),
      field('type', choice($._type, $.variadic_type))
    ),

    // Type Declaration
    type_declaration: $ => seq(
      optional(pub_keyword),
      'type',
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
      $.multi_return_type
    ),

    option_type: $ =>  prec.right(seq('?', optional(choice(
      $._simple_type,
      $.multi_return_type
    )))),

    multi_return_type: $ => seq('(', commaSep1($._simple_type), ')'),

    _simple_type: $ => prec.left(-1, choice(
      prec.dynamic(-1, $._type_identifier),
      $.binded_type,
      $.qualified_type,
      $.pointer_type,
      $.array_type,
      $.fixed_array_type,
      $.map_type,
      $.function_type,
      $.generic_type,
      $.channel_type
    )),

    type_parameters: $ => prec(1, seq(
      '<',
      commaSep1($._type),
      '>'
    )),

    channel_type: $ => seq('chan', field('value', $._simple_type)),
    
    generic_type: $ => seq(
      choice($.qualified_type, $._type_identifier),
      $.type_parameters
    ),

    binded_type: $ => prec.right(-1, seq(
      field('language', $.language_spec),
      field('name', $._type_identifier)
    )),

    language_spec: $ => seq(
      field('language', choice('C', 'JS')),
      '.'
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

    expression_with_blocks_list: $ => commaSep1($._expression_with_blocks),

    identifier_list: $ => prec.right(1, commaSep1(choice(
      $.imaginary_literal,
      $._mutable_identifier,
      $.identifier,
    ))),

    // Enum
    enum_declaration: $ => seq(
      optional($.attribute_list),
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

    enum_identifier: $ => seq(
      '.',
      field('field_name', $.identifier)
    ),

    // Struct
    struct_declaration: $ => seq(
      field('attributes', optional($.attribute_list)),
      optional(pub_keyword),
      'struct',
      prec.dynamic(-1, choice($.binded_type, $._type_identifier, $.generic_type)),
      $.struct_field_declaration_list,
    ),

    struct_field_scope: $ => seq(
      choice(
        pub_keyword,
        mut_keyword,
        seq(pub_keyword, mut_keyword),
        global_keyword
      ), 
      ':'
    ),

    struct_field_declaration_list: $ => seq(
      '{',
      optional(repeat(seq(
        choice(
          $.struct_field_scope, 
          $.struct_field_declaration
        ), 
        optional(terminator),
      ))),
      '}'
    ),

    struct_field_declaration: $ => prec.right(choice(
      seq(
        field('name', $._field_identifier),
        field('type', $._type),
        field('attributes', optional($.attribute_declaration)),
        optional(seq(
          '=',
          field('default_value', $._expression)
        )),
        optional(terminator)
      ),
      field(
        'type',
        choice($._type_identifier, $.qualified_type),
        optional(terminator)
      )
    )),

    interface_declaration: $ => seq(
      field('attributes', optional($.attribute_list)),
      optional(pub_keyword),
      'interface',
      prec.dynamic(-1, $._type_identifier),
      $.interface_spec_list
    ),

    interface_spec_list: $ => seq(
      '{',
      optional(repeat(seq(
        choice(
          $.struct_field_declaration, 
          $.interface_spec, 
          $.interface_field_scope
        ),
        optional(terminator),
      ))),
      '}'
    ),

    interface_field_scope: $ => seq(mut_keyword + ':'),

    interface_spec: $ => prec.right(seq(
      field('name', $._field_identifier),
      field('parameters', $.parameter_list),
      field('result', optional($._type))
    )),

    map_type: $ => seq(
      'map[',
      field('key', $._simple_type),
      ']',
      field('value', $._type),
    ),

    function_type: $ => prec.right(seq(
      'fn',
      field('parameters', $.parameter_list),
      field('result', optional($._type))
    )),

    block: $ => seq(
      '{',
      optional($._statement_list),
      '}'
    ),

    _statement_list: $ => seq(
      choice(
        $._statement,
        $._expression_with_blocks
      ),
      repeat(seq(terminator, choice(
        $._statement,
        $._expression_with_blocks
      ))),
      optional(terminator)
    ),

    _top_level_declaration: $ => choice(
      $.module_clause,
      $._c_directive,
      $.import_declaration,
      $.const_declaration,
      $.type_declaration,
      $.struct_declaration,
      $.interface_declaration,
      $.enum_declaration,
      $.function_declaration,
      $.global_var_declaration
    ),

    _statement: $ => choice(
      $._simple_statement,
      $.return_statement,
      $.go_statement,
      $.defer_statement,
      $.for_statement,
      $.comptime_for_statement,
      $.break_statement,
      $.continue_statement,
      $.block,
      $.empty_statement,
      $.asm_statement,
      $.assert_statement,
      $.goto_statement,
      $.labeled_statement,
      $.empty_labeled_statement,
      $.send_statement
    ),

    asm_statement: $ => seq(
      'asm',
      $.identifier,
      $._content_block
    ),

    empty_statement: $ => ';',

    _simple_statement: $ => choice(
      $._expression,
      $.inc_statement,
      $.dec_statement,
      $.assignment_statement,
      $.short_var_declaration,
    ),

    inc_statement: $ => seq(
      $._expression,
      '++'
    ),

    dec_statement: $ => seq(
      $._expression,
      '--'
    ),

    send_statement: $ => prec(PREC.unary, seq(
      field('channel', $._expression),
      '<-',
      field('value', $._expression)
    )),

    assignment_statement: $ => seq(
      field('left', $.expression_list),
      field('operator', choice(...assignment_operators)),
      field('right', alias(commaSep1(choice(
        $._expression,
        $._expression_with_blocks
      )), $.expression_list))
    ),

    short_var_declaration: $ => seq(
      field('left', $.identifier_list),
      ':=',
      field('right', alias(commaSep1(choice(
        $._expression,
        $._expression_with_blocks
      )), $.expression_list))
    ),

    break_statement: $ => prec.left(seq('break', optional(alias($.identifier, $.label_name)))),

    continue_statement: $ => prec.left(seq('continue', optional(alias($.identifier, $.label_name)))),

    return_statement: $ => prec.left(seq('return', optional(choice(
      $.expression_list,
      $.expression_with_blocks_list
    )))),

    go_statement: $ => seq('go', $._expression),

    defer_statement: $ => seq('defer', $.block),
    
    assert_statement: $ => seq('assert', $._expression),

    unsafe_expression: $ => seq('unsafe', $.block),

    goto_statement: $ => seq('goto', alias($.identifier, $.label_name)),
    
    labeled_statement: $ => prec.right(1, seq(
      field('label', alias($.identifier, $.label_name)),
      ':',
      $._statement
    )),

    empty_labeled_statement: $ => seq(
      field('label', alias($.identifier, $.label_name)),
      ':'
    ),

    if_expression: $ => seq(
      'if',
      choice(
        field('condition', $._expression),
        field('initializer', $.short_var_declaration)
      ),
      field('consequence', $.block),
      optional(seq(
        'else',
        field('alternative', choice($.block, $.if_expression))
      ))
    ),

    comptime_block: $ => seq(
      '{',
      optional(seq(
        choice(
          $._statement,
          $._expression_with_blocks,
          $._c_directive
        ),
        repeat(seq(terminator, choice(
          $._statement,
          $._expression_with_blocks,
          $._c_directive
        ))),
        optional(terminator)
      ),),
      '}'
    ),

    comptime_if_expression: $ => seq(
      '$if',
      field('condition', seq(
        $._expression,
        optional('?')
      )),
      field('consequence', alias($.comptime_block, $.block)),
      optional(seq(
        '$else',
        field('alternative', choice(alias($.comptime_block, $.block), $.comptime_if_expression))
      ))
    ),

    for_statement: $ => seq(
      'for',
      optional(choice(
        $.for_in_operator,
        $._expression, 
        $.cstyle_for_clause
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

    for_in_operator: $ => seq(
      field('left', $.identifier_list), 
      'in',
      field('right', choice(
        $._expression, 
        alias($._range, $.range
      )))
    ),

    comptime_for_statement: $ => seq(
      '$for',
      $.for_in_operator,
      field('body', $.block)
    ),

    match_expression: $ => seq(
      'match',
      field('condition', choice(
        $._expression, $._mutable_identifier,
      )),
      '{',
      repeat($.expression_case),
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

    select_expression: $ => seq(
      'select',
      '{',
        repeat($.select_branch),
        $.select_default_branch,
      '}'
    ),

    select_branch: $ => seq($._statement, $.block),

    select_default_branch: $ => seq(
      choice(
        prec(PREC.unary, seq('>', $._expression)),
        'else'
      ),
      $.block
    ),

    // NOTE: this should be put into a separate grammar
    // to avoid any "noise" (i guess)
    sql_expression: $ => seq(
      'sql',
      optional($._expression),
      $._content_block
    ),

    // TODO: loosely check sql/asm block for now
    _content_block: $ => seq('{', token.immediate(prec(1, /[^{}]+/)), '}'),

    _expression: $ => choice(
      $.type_cast_expression,
      $.as_type_cast_expression,
      $.unary_expression,
      $.binary_expression,
      $.selector_expression,
      $.slice_expression,
      $.index_expression,
      $.call_expression,
      $.identifier,
      $.enum_identifier,
      $._string_literal,
      $.fn_literal,
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
      $.pseudo_comptime_identifier,
      $.relational_operator,
      $.binded_identifier,
    ),

    _expression_with_blocks: $ => choice(
      $.if_expression,
      $.comptime_if_expression,
      $.match_expression,
      $.sql_expression,
      $.unsafe_expression,
      $.select_expression,
      $.lock_expression
    ),

    binded_identifier: $ => seq($.language_spec, $.identifier),

    relational_operator: $ => prec(PREC.comparative, seq(
      field('left', $._expression),
      field('operator', choice('!is', 'is', '!in', 'in')),
      field('right', choice(
        $.identifier,
        $.array,
        $.selector_expression,
        $.index_expression,
        $._string_literal,
        $.slice_expression,
        $.index_expression
      ))
    )),

    _range: $ => prec.right(PREC.multiplicative, seq(
      field('start', optional($._expression)), 
      '..', 
      field('end', optional($._expression))
    )),

    lock_expression: $ => seq(
      choice('lock', 'rlock'),
      field('locked_variables', optional($.expression_list)),
      field('body', $.block)
    ),

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

    as_type_cast_expression: $ => prec(PREC.primary, seq(
      field('expr', $._expression),
      'as',
      field('type', $._simple_type)
    )),

    call_expression: $ => prec.right(PREC.primary, seq(
      field('function', choice(
        $._expression, 
        $.comptime_identifier
      )),
      field('type_parameters', optional($.type_parameters)),
      field('arguments', $.argument_list),
      optional($.option_propagator)
    )),

    option_propagator: $ => prec.right(choice(
      token('?'),
      $.or_block
    )),

    or_block: $ => seq(
      'or',
      $.block
    ),

    decomposed_element: $ => prec.right(seq(
      '...',
      $._expression,
    )),

    _mutable_identifier: $ => seq(mut_keyword, $.identifier),

    argument_list: $ => seq(
      '(',
      optional(commaSep1(choice(
        $._mutable_identifier,
        $._expression, 
        $.decomposed_element
      ))),
      ')'
    ),

    selector_expression: $ => prec(PREC.primary, seq(
      field('operand', $._expression),
      '.',
      field('field', choice(
        $.identifier, 
        $.comptime_identifier, 
        $.comptime_selector_expression
      ))
    )),
      
    comptime_identifier: $ => compTime($.identifier),
    comptime_selector_expression: $ => compTime(seq('(', $.selector_expression,')')),
  
    index_expression: $ => prec.right(PREC.primary, seq(
      field('operand', $._expression),
      '[',
      field('index', $._expression),
      ']',
      optional($.option_propagator)
    )),

    slice_expression: $ => prec(PREC.primary, seq(
      field('operand', $._expression),
      '[',
      $._range,
      ']'
    )),

    fixed_array_indicator: $ => token.immediate('!'),

    // TODO: revisit this later
    array: $ => prec(PREC.composite_literal, choice(
      '[]',
      seq(
        '[',
        field('values', repeat(
          seq(
            $._expression,
            optional(',')
          )
        )),
        ']',
        optional($.fixed_array_indicator)
      ))
    ),

    type_initializer: $ => prec(PREC.composite_literal, seq(
      field('type', choice(
        $._type_identifier,
        $.binded_type,
        $.qualified_type,
        $.pointer_type,
        $.array_type,
        $.fixed_array_type,
        $.map_type,
        $.generic_type,
        $.channel_type
      )),
      field('body', $.literal_value)
    )),

    literal_value: $ => seq(
      '{',
      optional(
        repeat(seq(
          choice(
            $.keyed_element, 
            alias($._element, $.element), 
            $.decomposed_element
          ),
          optional(choice(',', terminator))
        )
      )),
      '}'
    ),

    keyed_element: $ => seq(
      // NOTE: expand list of expressions
      // that can be used as keys.
      prec(1, seq(choice(
        $._field_identifier,
        $.interpreted_string_literal,
        $.int_literal
      ), ':')),
      $._element
    ),

    _element: $ => choice(
      $._expression,
      $.unsafe_expression,
      $.if_expression,
      $.match_expression,
      $.lock_expression,
      $.sql_expression,
      $.comptime_if_expression
    ),

    fn_literal: $ => seq(
      'fn',
      field('parameters', $.parameter_list),
      field('result', optional($._type)),
      field('body', $.block)
    ),

    unary_expression: $ => prec(PREC.unary, seq(
      field('operator', choice('+', '-', '!', '~', '^', '*', '&', '<-')),
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
    )),

    pseudo_comptime_identifier: $ => seq('@', $.identifier),
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

    raw_string_literal: $ => stringQuotes1('r', $),

    c_string_literal: $ => choice(
      seq('c\'', repeat(token.immediate(prec(1, /[^$']+/))), '\''),
      seq('c"', repeat(token.immediate(prec(1, /[^$"]+/))), '"')
    ),

    interpreted_string_literal: $ => stringQuotes($, $.string_interpolation),

    string_interpolation: $ => choice(
      seq('${', $._expression,'}'),
      seq('$', $._expression),
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
            /['"abfrntv\$\\]/
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
  return seq('$', rule)
}

function stringQuotes1(prefix, $) {
  return choice(
    seq(
      prefix + '\'',
      repeat(choice(
        token.immediate(prec(1, /[^'\\]+/)),
        $.escape_sequence,
      )),
      '\''
    ),
    seq(
      prefix + '"',
      repeat(choice(
        token.immediate(prec(1, /[^"\\]+/)),
        $.escape_sequence,
      )),
      '"'
    )
  )
}

function stringQuotes($, rule) {
  return choice(
    seq(
      '\'',
      repeat(choice(
        token.immediate(prec(1, /[^$'\\]+/)),
        $.escape_sequence,
        rule,
      )),
      '\''
    ),
    seq(
      '"',
      repeat(choice(
        token.immediate(prec(1, /[^$"\\]+/)),
        $.escape_sequence,
        rule
      )),
      '"'
    )
  )
}
