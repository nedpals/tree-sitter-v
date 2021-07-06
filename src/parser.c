#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 139
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 78
#define ALIAS_COUNT 1
#define TOKEN_COUNT 46
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 8
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 10

enum {
  anon_sym_LF = 1,
  sym_escape_sequence = 2,
  sym_int_literal = 3,
  anon_sym_LBRACK_RBRACK = 4,
  anon_sym_LBRACK = 5,
  anon_sym_COMMA = 6,
  anon_sym_RBRACK = 7,
  anon_sym_BANG = 8,
  anon_sym_SQUOTE = 9,
  aux_sym_interpreted_string_literal_token1 = 10,
  anon_sym_DQUOTE = 11,
  anon_sym_DOLLAR_LBRACE = 12,
  anon_sym_RBRACE = 13,
  anon_sym_DOLLAR = 14,
  sym_format_flag = 15,
  anon_sym_COLON = 16,
  aux_sym_format_specifier_token1 = 17,
  anon_sym_DOT = 18,
  aux_sym_identifier_token1 = 19,
  anon_sym__ = 20,
  aux_sym_identifier_token2 = 21,
  anon_sym_LPAREN = 22,
  anon_sym_RPAREN = 23,
  anon_sym_bool = 24,
  anon_sym_string = 25,
  anon_sym_i8 = 26,
  anon_sym_i16 = 27,
  anon_sym_int = 28,
  anon_sym_i64 = 29,
  anon_sym_byte = 30,
  anon_sym_u16 = 31,
  anon_sym_u32 = 32,
  anon_sym_u64 = 33,
  anon_sym_rune = 34,
  anon_sym_f32 = 35,
  anon_sym_f64 = 36,
  anon_sym_voidptr = 37,
  anon_sym_size_t = 38,
  anon_sym_any = 39,
  anon_sym_LBRACE = 40,
  anon_sym_COLON_EQ = 41,
  anon_sym_EQ = 42,
  anon_sym_fn = 43,
  anon_sym_pub = 44,
  anon_sym_const = 45,
  sym_source_file = 46,
  sym__top_level_statement = 47,
  sym__expression = 48,
  sym__single_line_expression = 49,
  sym_array = 50,
  sym__string_literal = 51,
  sym_interpreted_string_literal = 52,
  sym_string_interpolation = 53,
  sym_format_specifier = 54,
  sym_identifier = 55,
  sym_identifier_list = 56,
  sym_parameter_declaration = 57,
  sym_parameter_list = 58,
  sym__type = 59,
  sym_type_identifier = 60,
  sym_block = 61,
  sym__statement_list = 62,
  sym__statement = 63,
  sym_short_var_declaration = 64,
  sym_assignment_statement = 65,
  sym_function_declaration = 66,
  sym_const_declaration = 67,
  sym_const_spec = 68,
  aux_sym_source_file_repeat1 = 69,
  aux_sym_array_repeat1 = 70,
  aux_sym_interpreted_string_literal_repeat1 = 71,
  aux_sym_identifier_repeat1 = 72,
  aux_sym_identifier_list_repeat1 = 73,
  aux_sym_parameter_list_repeat1 = 74,
  aux_sym__statement_list_repeat1 = 75,
  aux_sym_short_var_declaration_repeat1 = 76,
  aux_sym_const_declaration_repeat1 = 77,
  alias_sym_expression_list = 78,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [sym_escape_sequence] = "escape_sequence",
  [sym_int_literal] = "int_literal",
  [anon_sym_LBRACK_RBRACK] = "[]",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [anon_sym_BANG] = "!",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_interpreted_string_literal_token1] = "interpreted_string_literal_token1",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_DOLLAR_LBRACE] = "${",
  [anon_sym_RBRACE] = "}",
  [anon_sym_DOLLAR] = "$",
  [sym_format_flag] = "format_flag",
  [anon_sym_COLON] = ":",
  [aux_sym_format_specifier_token1] = "format_specifier_token1",
  [anon_sym_DOT] = ".",
  [aux_sym_identifier_token1] = "identifier_token1",
  [anon_sym__] = "_",
  [aux_sym_identifier_token2] = "identifier_token2",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_bool] = "bool",
  [anon_sym_string] = "string",
  [anon_sym_i8] = "i8",
  [anon_sym_i16] = "i16",
  [anon_sym_int] = "int",
  [anon_sym_i64] = "i64",
  [anon_sym_byte] = "byte",
  [anon_sym_u16] = "u16",
  [anon_sym_u32] = "u32",
  [anon_sym_u64] = "u64",
  [anon_sym_rune] = "rune",
  [anon_sym_f32] = "f32",
  [anon_sym_f64] = "f64",
  [anon_sym_voidptr] = "voidptr",
  [anon_sym_size_t] = "size_t",
  [anon_sym_any] = "any",
  [anon_sym_LBRACE] = "{",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_EQ] = "=",
  [anon_sym_fn] = "fn",
  [anon_sym_pub] = "pub",
  [anon_sym_const] = "const",
  [sym_source_file] = "source_file",
  [sym__top_level_statement] = "_top_level_statement",
  [sym__expression] = "_expression",
  [sym__single_line_expression] = "_single_line_expression",
  [sym_array] = "array",
  [sym__string_literal] = "_string_literal",
  [sym_interpreted_string_literal] = "interpreted_string_literal",
  [sym_string_interpolation] = "string_interpolation",
  [sym_format_specifier] = "format_specifier",
  [sym_identifier] = "identifier",
  [sym_identifier_list] = "identifier_list",
  [sym_parameter_declaration] = "parameter_declaration",
  [sym_parameter_list] = "parameter_list",
  [sym__type] = "_type",
  [sym_type_identifier] = "type_identifier",
  [sym_block] = "block",
  [sym__statement_list] = "_statement_list",
  [sym__statement] = "_statement",
  [sym_short_var_declaration] = "short_var_declaration",
  [sym_assignment_statement] = "assignment_statement",
  [sym_function_declaration] = "function_declaration",
  [sym_const_declaration] = "const_declaration",
  [sym_const_spec] = "const_spec",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_array_repeat1] = "array_repeat1",
  [aux_sym_interpreted_string_literal_repeat1] = "interpreted_string_literal_repeat1",
  [aux_sym_identifier_repeat1] = "identifier_repeat1",
  [aux_sym_identifier_list_repeat1] = "identifier_list_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
  [aux_sym__statement_list_repeat1] = "_statement_list_repeat1",
  [aux_sym_short_var_declaration_repeat1] = "short_var_declaration_repeat1",
  [aux_sym_const_declaration_repeat1] = "const_declaration_repeat1",
  [alias_sym_expression_list] = "expression_list",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_int_literal] = sym_int_literal,
  [anon_sym_LBRACK_RBRACK] = anon_sym_LBRACK_RBRACK,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_interpreted_string_literal_token1] = aux_sym_interpreted_string_literal_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_DOLLAR_LBRACE] = anon_sym_DOLLAR_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [sym_format_flag] = sym_format_flag,
  [anon_sym_COLON] = anon_sym_COLON,
  [aux_sym_format_specifier_token1] = aux_sym_format_specifier_token1,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym_identifier_token1] = aux_sym_identifier_token1,
  [anon_sym__] = anon_sym__,
  [aux_sym_identifier_token2] = aux_sym_identifier_token2,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_i8] = anon_sym_i8,
  [anon_sym_i16] = anon_sym_i16,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_i64] = anon_sym_i64,
  [anon_sym_byte] = anon_sym_byte,
  [anon_sym_u16] = anon_sym_u16,
  [anon_sym_u32] = anon_sym_u32,
  [anon_sym_u64] = anon_sym_u64,
  [anon_sym_rune] = anon_sym_rune,
  [anon_sym_f32] = anon_sym_f32,
  [anon_sym_f64] = anon_sym_f64,
  [anon_sym_voidptr] = anon_sym_voidptr,
  [anon_sym_size_t] = anon_sym_size_t,
  [anon_sym_any] = anon_sym_any,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_pub] = anon_sym_pub,
  [anon_sym_const] = anon_sym_const,
  [sym_source_file] = sym_source_file,
  [sym__top_level_statement] = sym__top_level_statement,
  [sym__expression] = sym__expression,
  [sym__single_line_expression] = sym__single_line_expression,
  [sym_array] = sym_array,
  [sym__string_literal] = sym__string_literal,
  [sym_interpreted_string_literal] = sym_interpreted_string_literal,
  [sym_string_interpolation] = sym_string_interpolation,
  [sym_format_specifier] = sym_format_specifier,
  [sym_identifier] = sym_identifier,
  [sym_identifier_list] = sym_identifier_list,
  [sym_parameter_declaration] = sym_parameter_declaration,
  [sym_parameter_list] = sym_parameter_list,
  [sym__type] = sym__type,
  [sym_type_identifier] = sym_type_identifier,
  [sym_block] = sym_block,
  [sym__statement_list] = sym__statement_list,
  [sym__statement] = sym__statement,
  [sym_short_var_declaration] = sym_short_var_declaration,
  [sym_assignment_statement] = sym_assignment_statement,
  [sym_function_declaration] = sym_function_declaration,
  [sym_const_declaration] = sym_const_declaration,
  [sym_const_spec] = sym_const_spec,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_array_repeat1] = aux_sym_array_repeat1,
  [aux_sym_interpreted_string_literal_repeat1] = aux_sym_interpreted_string_literal_repeat1,
  [aux_sym_identifier_repeat1] = aux_sym_identifier_repeat1,
  [aux_sym_identifier_list_repeat1] = aux_sym_identifier_list_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
  [aux_sym__statement_list_repeat1] = aux_sym__statement_list_repeat1,
  [aux_sym_short_var_declaration_repeat1] = aux_sym_short_var_declaration_repeat1,
  [aux_sym_const_declaration_repeat1] = aux_sym_const_declaration_repeat1,
  [alias_sym_expression_list] = alias_sym_expression_list,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_int_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_interpreted_string_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [sym_format_flag] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_format_specifier_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_identifier_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_identifier_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_byte] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rune] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_voidptr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_size_t] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_any] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pub] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_const] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__top_level_statement] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym__single_line_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_array] = {
    .visible = true,
    .named = true,
  },
  [sym__string_literal] = {
    .visible = false,
    .named = true,
  },
  [sym_interpreted_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_string_interpolation] = {
    .visible = true,
    .named = true,
  },
  [sym_format_specifier] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier_list] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym__type] = {
    .visible = false,
    .named = true,
  },
  [sym_type_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym__statement_list] = {
    .visible = false,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_short_var_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_function_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_const_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_const_spec] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_array_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_interpreted_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameter_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__statement_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_short_var_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_const_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_expression_list] = {
    .visible = true,
    .named = true,
  },
};

enum {
  field_body = 1,
  field_left = 2,
  field_name = 3,
  field_result = 4,
  field_right = 5,
  field_type = 6,
  field_value = 7,
  field_values = 8,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_left] = "left",
  [field_name] = "name",
  [field_result] = "result",
  [field_right] = "right",
  [field_type] = "type",
  [field_value] = "value",
  [field_values] = "values",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 2},
  [5] = {.index = 7, .length = 2},
  [6] = {.index = 9, .length = 3},
  [7] = {.index = 12, .length = 1},
  [8] = {.index = 13, .length = 2},
  [9] = {.index = 15, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_name, 1},
    {field_result, 3},
  [3] =
    {field_body, 3},
    {field_name, 1},
  [5] =
    {field_name, 0},
    {field_value, 2},
  [7] =
    {field_name, 0},
    {field_type, 1},
  [9] =
    {field_body, 4},
    {field_name, 1},
    {field_result, 3},
  [12] =
    {field_values, 1},
  [13] =
    {field_left, 0},
    {field_right, 2},
  [15] =
    {field_left, 0},
    {field_right, 2},
    {field_right, 3},
};

static TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [8] = {
    [2] = alias_sym_expression_list,
  },
  [9] = {
    [2] = alias_sym_expression_list,
    [3] = alias_sym_expression_list,
  },
};

static uint16_t ts_non_terminal_alias_map[] = {
  sym__expression, 2,
    sym__expression,
    alias_sym_expression_list,
  aux_sym_short_var_declaration_repeat1, 2,
    aux_sym_short_var_declaration_repeat1,
    alias_sym_expression_list,
  0,
};

static inline bool sym_escape_sequence_character_set_1(int32_t c) {
  return (c < 'a'
    ? (c < '$'
      ? (c < '"'
        ? c == '\n'
        : c <= '"')
      : (c <= '$' || (c < '\\'
        ? c == '\''
        : c <= '\\')))
    : (c <= 'b' || (c < 'r'
      ? (c < 'n'
        ? c == 'f'
        : c <= 'n')
      : (c <= 'r' || (c < 'v'
        ? c == 't'
        : c <= 'v')))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(76);
      if (lookahead == '!') ADVANCE(88);
      if (lookahead == '"') ADVANCE(92);
      if (lookahead == '$') ADVANCE(95);
      if (lookahead == '\'') ADVANCE(89);
      if (lookahead == '(') ADVANCE(123);
      if (lookahead == ')') ADVANCE(124);
      if (lookahead == ',') ADVANCE(86);
      if (lookahead == '.') ADVANCE(104);
      if (lookahead == '0') ADVANCE(83);
      if (lookahead == ':') ADVANCE(102);
      if (lookahead == '=') ADVANCE(143);
      if (lookahead == '[') ADVANCE(85);
      if (lookahead == '\\') ADVANCE(65);
      if (lookahead == ']') ADVANCE(87);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == 'a') ADVANCE(39);
      if (lookahead == 'b') ADVANCE(46);
      if (lookahead == 'c') ADVANCE(99);
      if (lookahead == 'f') ADVANCE(97);
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == 'p') ADVANCE(100);
      if (lookahead == 'r') ADVANCE(57);
      if (lookahead == 's') ADVANCE(98);
      if (lookahead == 'u') ADVANCE(14);
      if (lookahead == 'v') ADVANCE(43);
      if (lookahead == '{') ADVANCE(141);
      if (lookahead == '}') ADVANCE(94);
      if (('+' <= lookahead && lookahead <= '/')) ADVANCE(103);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(82);
      if (('E' <= lookahead && lookahead <= 'G') ||
          lookahead == 'S' ||
          lookahead == 'X' ||
          ('d' <= lookahead && lookahead <= 'g') ||
          lookahead == 'o' ||
          lookahead == 'x') ADVANCE(96);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(78);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(77);
      if (lookahead == '!') ADVANCE(88);
      if (lookahead == ',') ADVANCE(86);
      if (lookahead == 'a') ADVANCE(39);
      if (lookahead == 'b') ADVANCE(46);
      if (lookahead == 'f') ADVANCE(17);
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == 'r') ADVANCE(57);
      if (lookahead == 's') ADVANCE(35);
      if (lookahead == 'u') ADVANCE(14);
      if (lookahead == 'v') ADVANCE(43);
      if (lookahead == '{') ADVANCE(141);
      if (lookahead == '}') ADVANCE(94);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3)
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == 'a') ADVANCE(118);
      if (lookahead == 'b') ADVANCE(120);
      if (lookahead == 'f') ADVANCE(111);
      if (lookahead == 'i') ADVANCE(109);
      if (lookahead == 'r') ADVANCE(121);
      if (lookahead == 's') ADVANCE(117);
      if (lookahead == 'u') ADVANCE(110);
      if (lookahead == 'v') ADVANCE(119);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(4)
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '}') ADVANCE(94);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(115);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(5)
      if (lookahead == ',') ADVANCE(86);
      if (lookahead == ':') ADVANCE(113);
      if (lookahead == '=') ADVANCE(143);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(6)
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(116);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == ')') ADVANCE(124);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(107);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 8:
      if (lookahead == '\n') SKIP(8)
      if (lookahead == '(') ADVANCE(123);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 9:
      if (lookahead == '\n') SKIP(9)
      if (lookahead == '=') ADVANCE(143);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 10:
      if (lookahead == '"') ADVANCE(91);
      if (lookahead == '$') ADVANCE(95);
      if (lookahead == '\'') ADVANCE(89);
      if (lookahead == '\\') ADVANCE(65);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0) ADVANCE(91);
      END_STATE();
    case 11:
      if (lookahead == ',') ADVANCE(86);
      if (lookahead == '.') ADVANCE(104);
      if (lookahead == ':') ADVANCE(24);
      if (lookahead == '=') ADVANCE(143);
      if (lookahead == '}') ADVANCE(94);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (('E' <= lookahead && lookahead <= 'G') ||
          lookahead == 'S' ||
          lookahead == 'X' ||
          ('c' <= lookahead && lookahead <= 'g') ||
          lookahead == 'o' ||
          lookahead == 'p' ||
          lookahead == 's' ||
          lookahead == 'x') ADVANCE(96);
      END_STATE();
    case 12:
      if (lookahead == '0') ADVANCE(83);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(12)
      if (('+' <= lookahead && lookahead <= '/')) ADVANCE(103);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(82);
      if (('E' <= lookahead && lookahead <= 'G') ||
          lookahead == 'S' ||
          lookahead == 'X' ||
          ('c' <= lookahead && lookahead <= 'g') ||
          lookahead == 'o' ||
          lookahead == 'p' ||
          lookahead == 's' ||
          lookahead == 'x') ADVANCE(96);
      END_STATE();
    case 13:
      if (lookahead == '1') ADVANCE(22);
      if (lookahead == '6') ADVANCE(20);
      if (lookahead == '8') ADVANCE(127);
      if (lookahead == 'n') ADVANCE(52);
      END_STATE();
    case 14:
      if (lookahead == '1') ADVANCE(23);
      if (lookahead == '3') ADVANCE(16);
      if (lookahead == '6') ADVANCE(21);
      END_STATE();
    case 15:
      if (lookahead == '2') ADVANCE(136);
      END_STATE();
    case 16:
      if (lookahead == '2') ADVANCE(133);
      END_STATE();
    case 17:
      if (lookahead == '3') ADVANCE(15);
      if (lookahead == '6') ADVANCE(19);
      END_STATE();
    case 18:
      if (lookahead == '3') ADVANCE(15);
      if (lookahead == '6') ADVANCE(19);
      if (lookahead == 'n') ADVANCE(144);
      END_STATE();
    case 19:
      if (lookahead == '4') ADVANCE(137);
      END_STATE();
    case 20:
      if (lookahead == '4') ADVANCE(130);
      END_STATE();
    case 21:
      if (lookahead == '4') ADVANCE(134);
      END_STATE();
    case 22:
      if (lookahead == '6') ADVANCE(128);
      END_STATE();
    case 23:
      if (lookahead == '6') ADVANCE(132);
      END_STATE();
    case 24:
      if (lookahead == '=') ADVANCE(142);
      END_STATE();
    case 25:
      if (lookahead == '_') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(79);
      END_STATE();
    case 26:
      if (lookahead == '_') ADVANCE(60);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(80);
      END_STATE();
    case 27:
      if (lookahead == '_') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(81);
      END_STATE();
    case 28:
      if (lookahead == '_') ADVANCE(54);
      END_STATE();
    case 29:
      if (lookahead == 'b') ADVANCE(145);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(47);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(131);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(135);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(28);
      END_STATE();
    case 34:
      if (lookahead == 'g') ADVANCE(126);
      END_STATE();
    case 35:
      if (lookahead == 'i') ADVANCE(59);
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 36:
      if (lookahead == 'i') ADVANCE(30);
      END_STATE();
    case 37:
      if (lookahead == 'i') ADVANCE(41);
      END_STATE();
    case 38:
      if (lookahead == 'l') ADVANCE(125);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 40:
      if (lookahead == 'n') ADVANCE(50);
      END_STATE();
    case 41:
      if (lookahead == 'n') ADVANCE(34);
      END_STATE();
    case 42:
      if (lookahead == 'n') ADVANCE(32);
      END_STATE();
    case 43:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 44:
      if (lookahead == 'o') ADVANCE(38);
      END_STATE();
    case 45:
      if (lookahead == 'o') ADVANCE(40);
      END_STATE();
    case 46:
      if (lookahead == 'o') ADVANCE(44);
      if (lookahead == 'y') ADVANCE(51);
      END_STATE();
    case 47:
      if (lookahead == 'p') ADVANCE(55);
      END_STATE();
    case 48:
      if (lookahead == 'r') ADVANCE(138);
      END_STATE();
    case 49:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 50:
      if (lookahead == 's') ADVANCE(53);
      END_STATE();
    case 51:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 52:
      if (lookahead == 't') ADVANCE(129);
      END_STATE();
    case 53:
      if (lookahead == 't') ADVANCE(146);
      END_STATE();
    case 54:
      if (lookahead == 't') ADVANCE(139);
      END_STATE();
    case 55:
      if (lookahead == 't') ADVANCE(48);
      END_STATE();
    case 56:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 57:
      if (lookahead == 'u') ADVANCE(42);
      END_STATE();
    case 58:
      if (lookahead == 'y') ADVANCE(140);
      END_STATE();
    case 59:
      if (lookahead == 'z') ADVANCE(33);
      END_STATE();
    case 60:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(80);
      END_STATE();
    case 61:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(79);
      END_STATE();
    case 62:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(82);
      END_STATE();
    case 63:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      END_STATE();
    case 64:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(63);
      END_STATE();
    case 65:
      if (sym_escape_sequence_character_set_1(lookahead)) ADVANCE(78);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == 'U') ADVANCE(74);
      if (lookahead == 'u') ADVANCE(70);
      if (lookahead == 'x') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(64);
      END_STATE();
    case 66:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 67:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(81);
      END_STATE();
    case 68:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 69:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(68);
      END_STATE();
    case 70:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(69);
      END_STATE();
    case 71:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(70);
      END_STATE();
    case 72:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(71);
      END_STATE();
    case 73:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(72);
      END_STATE();
    case 74:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(73);
      END_STATE();
    case 75:
      if (eof) ADVANCE(76);
      if (lookahead == '!') ADVANCE(88);
      if (lookahead == '"') ADVANCE(92);
      if (lookahead == '\'') ADVANCE(89);
      if (lookahead == ')') ADVANCE(124);
      if (lookahead == ',') ADVANCE(86);
      if (lookahead == '0') ADVANCE(83);
      if (lookahead == ':') ADVANCE(101);
      if (lookahead == '[') ADVANCE(85);
      if (lookahead == ']') ADVANCE(87);
      if (lookahead == 'a') ADVANCE(39);
      if (lookahead == 'b') ADVANCE(46);
      if (lookahead == 'c') ADVANCE(45);
      if (lookahead == 'f') ADVANCE(18);
      if (lookahead == 'i') ADVANCE(13);
      if (lookahead == 'p') ADVANCE(56);
      if (lookahead == 'r') ADVANCE(57);
      if (lookahead == 's') ADVANCE(35);
      if (lookahead == 'u') ADVANCE(14);
      if (lookahead == 'v') ADVANCE(43);
      if (lookahead == '}') ADVANCE(94);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(75)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(82);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == '_') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == '_') ADVANCE(60);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == '_') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(81);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == '_') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(82);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(26);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(25);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(27);
      if (lookahead == '_') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(79);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_LBRACK_RBRACK);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == ']') ADVANCE(84);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_interpreted_string_literal_token1);
      if (lookahead == '"') ADVANCE(91);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '$' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(91);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_interpreted_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '$' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(91);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_DOLLAR_LBRACE);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '{') ADVANCE(93);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_format_flag);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_format_flag);
      if (lookahead == '3') ADVANCE(15);
      if (lookahead == '6') ADVANCE(19);
      if (lookahead == 'n') ADVANCE(144);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_format_flag);
      if (lookahead == 'i') ADVANCE(59);
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_format_flag);
      if (lookahead == 'o') ADVANCE(40);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_format_flag);
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '=') ADVANCE(142);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym_format_specifier_token1);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '(') ADVANCE(123);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == ')') ADVANCE(124);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(107);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == ',') ADVANCE(86);
      if (lookahead == ':') ADVANCE(113);
      if (lookahead == '=') ADVANCE(143);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '1') ADVANCE(22);
      if (lookahead == '6') ADVANCE(20);
      if (lookahead == '8') ADVANCE(127);
      if (lookahead == 'n') ADVANCE(52);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '1') ADVANCE(23);
      if (lookahead == '3') ADVANCE(16);
      if (lookahead == '6') ADVANCE(21);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '3') ADVANCE(15);
      if (lookahead == '6') ADVANCE(19);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '=') ADVANCE(143);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '=') ADVANCE(142);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == 'a') ADVANCE(118);
      if (lookahead == 'b') ADVANCE(120);
      if (lookahead == 'f') ADVANCE(111);
      if (lookahead == 'i') ADVANCE(109);
      if (lookahead == 'r') ADVANCE(121);
      if (lookahead == 's') ADVANCE(117);
      if (lookahead == 'u') ADVANCE(110);
      if (lookahead == 'v') ADVANCE(119);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '}') ADVANCE(94);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(115);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '_') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(116);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'i') ADVANCE(59);
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'o') ADVANCE(44);
      if (lookahead == 'y') ADVANCE(51);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'u') ADVANCE(42);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_i8);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_i16);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_i64);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_byte);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_u16);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_u32);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_u64);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_rune);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_f32);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_f64);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_voidptr);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_size_t);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_any);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_pub);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_const);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 75},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 3},
  [5] = {.lex_state = 3},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 75},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 75},
  [11] = {.lex_state = 75},
  [12] = {.lex_state = 75},
  [13] = {.lex_state = 75},
  [14] = {.lex_state = 75},
  [15] = {.lex_state = 75},
  [16] = {.lex_state = 75},
  [17] = {.lex_state = 75},
  [18] = {.lex_state = 75},
  [19] = {.lex_state = 75},
  [20] = {.lex_state = 75},
  [21] = {.lex_state = 75},
  [22] = {.lex_state = 75},
  [23] = {.lex_state = 75},
  [24] = {.lex_state = 75},
  [25] = {.lex_state = 75},
  [26] = {.lex_state = 75},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 75},
  [29] = {.lex_state = 75},
  [30] = {.lex_state = 4},
  [31] = {.lex_state = 75},
  [32] = {.lex_state = 4},
  [33] = {.lex_state = 10},
  [34] = {.lex_state = 10},
  [35] = {.lex_state = 5},
  [36] = {.lex_state = 10},
  [37] = {.lex_state = 10},
  [38] = {.lex_state = 10},
  [39] = {.lex_state = 10},
  [40] = {.lex_state = 10},
  [41] = {.lex_state = 10},
  [42] = {.lex_state = 6},
  [43] = {.lex_state = 10},
  [44] = {.lex_state = 10},
  [45] = {.lex_state = 75},
  [46] = {.lex_state = 10},
  [47] = {.lex_state = 5},
  [48] = {.lex_state = 10},
  [49] = {.lex_state = 5},
  [50] = {.lex_state = 10},
  [51] = {.lex_state = 7},
  [52] = {.lex_state = 10},
  [53] = {.lex_state = 10},
  [54] = {.lex_state = 10},
  [55] = {.lex_state = 75},
  [56] = {.lex_state = 7},
  [57] = {.lex_state = 7},
  [58] = {.lex_state = 7},
  [59] = {.lex_state = 7},
  [60] = {.lex_state = 10},
  [61] = {.lex_state = 75},
  [62] = {.lex_state = 10},
  [63] = {.lex_state = 8},
  [64] = {.lex_state = 7},
  [65] = {.lex_state = 8},
  [66] = {.lex_state = 8},
  [67] = {.lex_state = 9},
  [68] = {.lex_state = 9},
  [69] = {.lex_state = 9},
  [70] = {.lex_state = 8},
  [71] = {.lex_state = 8},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 6},
  [74] = {.lex_state = 75},
  [75] = {.lex_state = 11},
  [76] = {.lex_state = 11},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 11},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 11},
  [85] = {.lex_state = 6},
  [86] = {.lex_state = 2},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 12},
  [91] = {.lex_state = 75},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 7},
  [94] = {.lex_state = 6},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 75},
  [97] = {.lex_state = 75},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 11},
  [103] = {.lex_state = 11},
  [104] = {.lex_state = 75},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 11},
  [108] = {.lex_state = 11},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 11},
  [112] = {.lex_state = 75},
  [113] = {.lex_state = 75},
  [114] = {.lex_state = 75},
  [115] = {.lex_state = 2},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 75},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 2},
  [121] = {.lex_state = 2},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 2},
  [126] = {.lex_state = 2},
  [127] = {.lex_state = 2},
  [128] = {.lex_state = 2},
  [129] = {.lex_state = 2},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 75},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 75},
  [135] = {.lex_state = 2},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 2},
  [138] = {.lex_state = 75},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym_int_literal] = ACTIONS(1),
    [anon_sym_LBRACK_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_DOLLAR_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [sym_format_flag] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [aux_sym_format_specifier_token1] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [aux_sym_identifier_token2] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_i8] = ACTIONS(1),
    [anon_sym_i16] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_i64] = ACTIONS(1),
    [anon_sym_byte] = ACTIONS(1),
    [anon_sym_u16] = ACTIONS(1),
    [anon_sym_u32] = ACTIONS(1),
    [anon_sym_u64] = ACTIONS(1),
    [anon_sym_rune] = ACTIONS(1),
    [anon_sym_f32] = ACTIONS(1),
    [anon_sym_f64] = ACTIONS(1),
    [anon_sym_voidptr] = ACTIONS(1),
    [anon_sym_size_t] = ACTIONS(1),
    [anon_sym_any] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_pub] = ACTIONS(1),
    [anon_sym_const] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(136),
    [sym__top_level_statement] = STATE(135),
    [sym_function_declaration] = STATE(135),
    [sym_const_declaration] = STATE(135),
    [aux_sym_source_file_repeat1] = STATE(29),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_fn] = ACTIONS(5),
    [anon_sym_pub] = ACTIONS(7),
    [anon_sym_const] = ACTIONS(9),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(11), 1,
      anon_sym_LF,
    ACTIONS(15), 1,
      anon_sym_LBRACE,
    STATE(126), 1,
      sym_block,
    STATE(100), 2,
      sym__type,
      sym_type_identifier,
    ACTIONS(13), 16,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_i8,
      anon_sym_i16,
      anon_sym_int,
      anon_sym_i64,
      anon_sym_byte,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_rune,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_voidptr,
      anon_sym_size_t,
      anon_sym_any,
  [32] = 3,
    STATE(5), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(17), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
    ACTIONS(19), 16,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_i8,
      anon_sym_i16,
      anon_sym_int,
      anon_sym_i64,
      anon_sym_byte,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_rune,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_voidptr,
      anon_sym_size_t,
      anon_sym_any,
  [59] = 3,
    STATE(3), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(21), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
    ACTIONS(23), 16,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_i8,
      anon_sym_i16,
      anon_sym_int,
      anon_sym_i64,
      anon_sym_byte,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_rune,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_voidptr,
      anon_sym_size_t,
      anon_sym_any,
  [86] = 3,
    STATE(5), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(25), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
    ACTIONS(28), 16,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_i8,
      anon_sym_i16,
      anon_sym_int,
      anon_sym_i64,
      anon_sym_byte,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_rune,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_voidptr,
      anon_sym_size_t,
      anon_sym_any,
  [113] = 2,
    ACTIONS(30), 1,
      anon_sym_LF,
    ACTIONS(32), 17,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_i8,
      anon_sym_i16,
      anon_sym_int,
      anon_sym_i64,
      anon_sym_byte,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_rune,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_voidptr,
      anon_sym_size_t,
      anon_sym_any,
      anon_sym_LBRACE,
  [136] = 2,
    ACTIONS(34), 1,
      anon_sym_LF,
    ACTIONS(36), 17,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_i8,
      anon_sym_i16,
      anon_sym_int,
      anon_sym_i64,
      anon_sym_byte,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_rune,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_voidptr,
      anon_sym_size_t,
      anon_sym_any,
      anon_sym_LBRACE,
  [159] = 2,
    STATE(114), 2,
      sym__type,
      sym_type_identifier,
    ACTIONS(38), 16,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_i8,
      anon_sym_i16,
      anon_sym_int,
      anon_sym_i64,
      anon_sym_byte,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_rune,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_voidptr,
      anon_sym_size_t,
      anon_sym_any,
  [182] = 2,
    ACTIONS(40), 1,
      anon_sym_LF,
    ACTIONS(42), 17,
      anon_sym_bool,
      anon_sym_string,
      anon_sym_i8,
      anon_sym_i16,
      anon_sym_int,
      anon_sym_i64,
      anon_sym_byte,
      anon_sym_u16,
      anon_sym_u32,
      anon_sym_u64,
      anon_sym_rune,
      anon_sym_f32,
      anon_sym_f64,
      anon_sym_voidptr,
      anon_sym_size_t,
      anon_sym_any,
      anon_sym_LBRACE,
  [205] = 9,
    ACTIONS(44), 1,
      sym_int_literal,
    ACTIONS(46), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(48), 1,
      anon_sym_LBRACK,
    ACTIONS(50), 1,
      anon_sym_RBRACK,
    ACTIONS(52), 1,
      anon_sym_SQUOTE,
    ACTIONS(54), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      aux_sym_array_repeat1,
    STATE(45), 1,
      sym__expression,
    STATE(26), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [236] = 9,
    ACTIONS(56), 1,
      sym_int_literal,
    ACTIONS(59), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(62), 1,
      anon_sym_LBRACK,
    ACTIONS(65), 1,
      anon_sym_RBRACK,
    ACTIONS(67), 1,
      anon_sym_SQUOTE,
    ACTIONS(70), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      aux_sym_array_repeat1,
    STATE(45), 1,
      sym__expression,
    STATE(26), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [267] = 9,
    ACTIONS(44), 1,
      sym_int_literal,
    ACTIONS(46), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(48), 1,
      anon_sym_LBRACK,
    ACTIONS(52), 1,
      anon_sym_SQUOTE,
    ACTIONS(54), 1,
      anon_sym_DQUOTE,
    ACTIONS(73), 1,
      anon_sym_RBRACK,
    STATE(10), 1,
      aux_sym_array_repeat1,
    STATE(45), 1,
      sym__expression,
    STATE(26), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [298] = 9,
    ACTIONS(44), 1,
      sym_int_literal,
    ACTIONS(46), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(48), 1,
      anon_sym_LBRACK,
    ACTIONS(52), 1,
      anon_sym_SQUOTE,
    ACTIONS(54), 1,
      anon_sym_DQUOTE,
    ACTIONS(75), 1,
      anon_sym_RBRACK,
    STATE(11), 1,
      aux_sym_array_repeat1,
    STATE(45), 1,
      sym__expression,
    STATE(26), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [329] = 9,
    ACTIONS(44), 1,
      sym_int_literal,
    ACTIONS(46), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(48), 1,
      anon_sym_LBRACK,
    ACTIONS(52), 1,
      anon_sym_SQUOTE,
    ACTIONS(54), 1,
      anon_sym_DQUOTE,
    ACTIONS(77), 1,
      anon_sym_RBRACK,
    STATE(13), 1,
      aux_sym_array_repeat1,
    STATE(45), 1,
      sym__expression,
    STATE(26), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [360] = 7,
    ACTIONS(79), 1,
      sym_int_literal,
    ACTIONS(81), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(83), 1,
      anon_sym_LBRACK,
    ACTIONS(85), 1,
      anon_sym_SQUOTE,
    ACTIONS(87), 1,
      anon_sym_DQUOTE,
    STATE(116), 1,
      sym__expression,
    STATE(99), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [385] = 3,
    ACTIONS(91), 1,
      anon_sym_LBRACK,
    ACTIONS(93), 1,
      anon_sym_BANG,
    ACTIONS(89), 8,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [402] = 7,
    ACTIONS(79), 1,
      sym_int_literal,
    ACTIONS(81), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(83), 1,
      anon_sym_LBRACK,
    ACTIONS(85), 1,
      anon_sym_SQUOTE,
    ACTIONS(87), 1,
      anon_sym_DQUOTE,
    STATE(82), 1,
      sym__expression,
    STATE(99), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [427] = 7,
    ACTIONS(44), 1,
      sym_int_literal,
    ACTIONS(46), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(48), 1,
      anon_sym_LBRACK,
    ACTIONS(52), 1,
      anon_sym_SQUOTE,
    ACTIONS(54), 1,
      anon_sym_DQUOTE,
    STATE(104), 1,
      sym__expression,
    STATE(26), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [452] = 7,
    ACTIONS(79), 1,
      sym_int_literal,
    ACTIONS(81), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(83), 1,
      anon_sym_LBRACK,
    ACTIONS(85), 1,
      anon_sym_SQUOTE,
    ACTIONS(87), 1,
      anon_sym_DQUOTE,
    STATE(81), 1,
      sym__expression,
    STATE(99), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [477] = 7,
    ACTIONS(79), 1,
      sym_int_literal,
    ACTIONS(81), 1,
      anon_sym_LBRACK_RBRACK,
    ACTIONS(83), 1,
      anon_sym_LBRACK,
    ACTIONS(85), 1,
      anon_sym_SQUOTE,
    ACTIONS(87), 1,
      anon_sym_DQUOTE,
    STATE(98), 1,
      sym__expression,
    STATE(99), 4,
      sym__single_line_expression,
      sym_array,
      sym__string_literal,
      sym_interpreted_string_literal,
  [502] = 3,
    ACTIONS(97), 1,
      anon_sym_LBRACK,
    ACTIONS(99), 1,
      anon_sym_BANG,
    ACTIONS(95), 8,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [519] = 2,
    ACTIONS(103), 1,
      anon_sym_LBRACK,
    ACTIONS(101), 8,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [533] = 2,
    ACTIONS(107), 1,
      anon_sym_LBRACK,
    ACTIONS(105), 8,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [547] = 2,
    ACTIONS(111), 1,
      anon_sym_LBRACK,
    ACTIONS(109), 8,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [561] = 2,
    ACTIONS(115), 1,
      anon_sym_LBRACK,
    ACTIONS(113), 8,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [575] = 2,
    ACTIONS(119), 1,
      anon_sym_LBRACK,
    ACTIONS(117), 8,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [589] = 6,
    ACTIONS(121), 1,
      anon_sym_RBRACE,
    STATE(76), 1,
      sym_identifier,
    STATE(108), 1,
      sym_identifier_list,
    STATE(132), 1,
      sym__statement_list,
    ACTIONS(123), 2,
      aux_sym_identifier_token1,
      anon_sym__,
    STATE(86), 3,
      sym__statement,
      sym_short_var_declaration,
      sym_assignment_statement,
  [611] = 2,
    ACTIONS(127), 1,
      anon_sym_LBRACK,
    ACTIONS(125), 8,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [625] = 6,
    ACTIONS(5), 1,
      anon_sym_fn,
    ACTIONS(7), 1,
      anon_sym_pub,
    ACTIONS(9), 1,
      anon_sym_const,
    ACTIONS(129), 1,
      ts_builtin_sym_end,
    STATE(31), 1,
      aux_sym_source_file_repeat1,
    STATE(135), 3,
      sym__top_level_statement,
      sym_function_declaration,
      sym_const_declaration,
  [646] = 5,
    ACTIONS(131), 1,
      anon_sym_RBRACE,
    STATE(76), 1,
      sym_identifier,
    STATE(108), 1,
      sym_identifier_list,
    ACTIONS(123), 2,
      aux_sym_identifier_token1,
      anon_sym__,
    STATE(110), 3,
      sym__statement,
      sym_short_var_declaration,
      sym_assignment_statement,
  [665] = 6,
    ACTIONS(133), 1,
      ts_builtin_sym_end,
    ACTIONS(135), 1,
      anon_sym_fn,
    ACTIONS(138), 1,
      anon_sym_pub,
    ACTIONS(141), 1,
      anon_sym_const,
    STATE(31), 1,
      aux_sym_source_file_repeat1,
    STATE(135), 3,
      sym__top_level_statement,
      sym_function_declaration,
      sym_const_declaration,
  [686] = 5,
    ACTIONS(144), 1,
      anon_sym_RBRACE,
    STATE(76), 1,
      sym_identifier,
    STATE(108), 1,
      sym_identifier_list,
    ACTIONS(123), 2,
      aux_sym_identifier_token1,
      anon_sym__,
    STATE(110), 3,
      sym__statement,
      sym_short_var_declaration,
      sym_assignment_statement,
  [705] = 6,
    ACTIONS(146), 1,
      sym_escape_sequence,
    ACTIONS(151), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(154), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(157), 1,
      anon_sym_DOLLAR,
    ACTIONS(149), 2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    STATE(33), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [726] = 6,
    ACTIONS(160), 1,
      sym_escape_sequence,
    ACTIONS(162), 1,
      anon_sym_SQUOTE,
    ACTIONS(164), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    STATE(33), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [746] = 3,
    STATE(35), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(28), 3,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
      anon_sym_EQ,
    ACTIONS(170), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [760] = 6,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(173), 1,
      sym_escape_sequence,
    ACTIONS(175), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(177), 1,
      anon_sym_DQUOTE,
    STATE(41), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [780] = 6,
    ACTIONS(160), 1,
      sym_escape_sequence,
    ACTIONS(164), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(179), 1,
      anon_sym_DQUOTE,
    STATE(33), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [800] = 6,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(181), 1,
      sym_escape_sequence,
    ACTIONS(183), 1,
      anon_sym_SQUOTE,
    ACTIONS(185), 1,
      aux_sym_interpreted_string_literal_token1,
    STATE(50), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [820] = 6,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(183), 1,
      anon_sym_DQUOTE,
    ACTIONS(187), 1,
      sym_escape_sequence,
    ACTIONS(189), 1,
      aux_sym_interpreted_string_literal_token1,
    STATE(40), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [840] = 6,
    ACTIONS(160), 1,
      sym_escape_sequence,
    ACTIONS(164), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(191), 1,
      anon_sym_DQUOTE,
    STATE(33), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [860] = 6,
    ACTIONS(160), 1,
      sym_escape_sequence,
    ACTIONS(162), 1,
      anon_sym_DQUOTE,
    ACTIONS(164), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    STATE(33), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [880] = 4,
    STATE(76), 1,
      sym_identifier,
    STATE(108), 1,
      sym_identifier_list,
    ACTIONS(123), 2,
      aux_sym_identifier_token1,
      anon_sym__,
    STATE(110), 3,
      sym__statement,
      sym_short_var_declaration,
      sym_assignment_statement,
  [896] = 6,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(193), 1,
      sym_escape_sequence,
    ACTIONS(195), 1,
      anon_sym_SQUOTE,
    ACTIONS(197), 1,
      aux_sym_interpreted_string_literal_token1,
    STATE(46), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [916] = 6,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(195), 1,
      anon_sym_DQUOTE,
    ACTIONS(199), 1,
      sym_escape_sequence,
    ACTIONS(201), 1,
      aux_sym_interpreted_string_literal_token1,
    STATE(37), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [936] = 3,
    ACTIONS(205), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      anon_sym_COMMA,
    ACTIONS(203), 5,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [950] = 6,
    ACTIONS(160), 1,
      sym_escape_sequence,
    ACTIONS(164), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(179), 1,
      anon_sym_SQUOTE,
    STATE(33), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [970] = 3,
    STATE(49), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(23), 3,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
      anon_sym_EQ,
    ACTIONS(209), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [984] = 6,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(177), 1,
      anon_sym_SQUOTE,
    ACTIONS(211), 1,
      sym_escape_sequence,
    ACTIONS(213), 1,
      aux_sym_interpreted_string_literal_token1,
    STATE(34), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [1004] = 3,
    STATE(35), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(19), 3,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
      anon_sym_EQ,
    ACTIONS(215), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [1018] = 6,
    ACTIONS(160), 1,
      sym_escape_sequence,
    ACTIONS(164), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(166), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(168), 1,
      anon_sym_DOLLAR,
    ACTIONS(191), 1,
      anon_sym_SQUOTE,
    STATE(33), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [1038] = 5,
    ACTIONS(220), 1,
      anon_sym_RPAREN,
    STATE(51), 1,
      aux_sym_const_declaration_repeat1,
    STATE(121), 1,
      sym_const_spec,
    STATE(130), 1,
      sym_identifier,
    ACTIONS(217), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1055] = 2,
    ACTIONS(109), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(111), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [1066] = 2,
    ACTIONS(224), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(222), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [1077] = 2,
    ACTIONS(228), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(226), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [1088] = 2,
    ACTIONS(230), 1,
      anon_sym_LBRACK,
    ACTIONS(65), 5,
      sym_int_literal,
      anon_sym_LBRACK_RBRACK,
      anon_sym_RBRACK,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [1099] = 5,
    ACTIONS(234), 1,
      anon_sym_RPAREN,
    STATE(51), 1,
      aux_sym_const_declaration_repeat1,
    STATE(121), 1,
      sym_const_spec,
    STATE(130), 1,
      sym_identifier,
    ACTIONS(232), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1116] = 5,
    ACTIONS(236), 1,
      anon_sym_RPAREN,
    STATE(51), 1,
      aux_sym_const_declaration_repeat1,
    STATE(121), 1,
      sym_const_spec,
    STATE(130), 1,
      sym_identifier,
    ACTIONS(232), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1133] = 5,
    ACTIONS(238), 1,
      anon_sym_RPAREN,
    STATE(57), 1,
      aux_sym_const_declaration_repeat1,
    STATE(121), 1,
      sym_const_spec,
    STATE(130), 1,
      sym_identifier,
    ACTIONS(232), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1150] = 5,
    ACTIONS(236), 1,
      anon_sym_RPAREN,
    STATE(56), 1,
      aux_sym_const_declaration_repeat1,
    STATE(121), 1,
      sym_const_spec,
    STATE(130), 1,
      sym_identifier,
    ACTIONS(232), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1167] = 2,
    ACTIONS(242), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(240), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [1178] = 4,
    ACTIONS(244), 1,
      sym_int_literal,
    ACTIONS(246), 1,
      anon_sym_SQUOTE,
    ACTIONS(248), 1,
      anon_sym_DQUOTE,
    STATE(54), 3,
      sym__single_line_expression,
      sym__string_literal,
      sym_interpreted_string_literal,
  [1193] = 2,
    ACTIONS(105), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(107), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [1204] = 3,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    STATE(65), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(250), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [1216] = 4,
    ACTIONS(254), 1,
      anon_sym_RPAREN,
    STATE(8), 1,
      sym_identifier,
    STATE(96), 1,
      sym_parameter_declaration,
    ACTIONS(252), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1230] = 3,
    ACTIONS(28), 1,
      anon_sym_LPAREN,
    STATE(65), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(256), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [1242] = 4,
    ACTIONS(259), 1,
      anon_sym_LPAREN,
    STATE(115), 1,
      sym_const_spec,
    STATE(130), 1,
      sym_identifier,
    ACTIONS(232), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1256] = 3,
    ACTIONS(28), 1,
      anon_sym_EQ,
    STATE(67), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(261), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [1268] = 3,
    ACTIONS(19), 1,
      anon_sym_EQ,
    STATE(67), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(264), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [1280] = 3,
    ACTIONS(23), 1,
      anon_sym_EQ,
    STATE(68), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(266), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [1292] = 3,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    STATE(63), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(268), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [1304] = 4,
    ACTIONS(270), 1,
      anon_sym_LPAREN,
    STATE(129), 1,
      sym_const_spec,
    STATE(130), 1,
      sym_identifier,
    ACTIONS(232), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1318] = 3,
    ACTIONS(95), 1,
      anon_sym_LF,
    ACTIONS(272), 1,
      anon_sym_BANG,
    ACTIONS(97), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1329] = 3,
    STATE(8), 1,
      sym_identifier,
    STATE(113), 1,
      sym_parameter_declaration,
    ACTIONS(252), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1340] = 1,
    ACTIONS(133), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_pub,
      anon_sym_const,
  [1347] = 3,
    ACTIONS(274), 1,
      anon_sym_COMMA,
    STATE(80), 1,
      aux_sym_identifier_list_repeat1,
    ACTIONS(276), 2,
      anon_sym_COLON_EQ,
      anon_sym_EQ,
  [1358] = 3,
    ACTIONS(274), 1,
      anon_sym_COMMA,
    STATE(75), 1,
      aux_sym_identifier_list_repeat1,
    ACTIONS(278), 2,
      anon_sym_COLON_EQ,
      anon_sym_EQ,
  [1369] = 3,
    ACTIONS(89), 1,
      anon_sym_LF,
    ACTIONS(280), 1,
      anon_sym_BANG,
    ACTIONS(91), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1380] = 4,
    ACTIONS(282), 1,
      anon_sym_LF,
    ACTIONS(284), 1,
      anon_sym_COMMA,
    ACTIONS(287), 1,
      anon_sym_RBRACE,
    STATE(78), 1,
      aux_sym_short_var_declaration_repeat1,
  [1393] = 4,
    ACTIONS(289), 1,
      anon_sym_LF,
    ACTIONS(291), 1,
      anon_sym_COMMA,
    ACTIONS(293), 1,
      anon_sym_RBRACE,
    STATE(78), 1,
      aux_sym_short_var_declaration_repeat1,
  [1406] = 3,
    ACTIONS(295), 1,
      anon_sym_COMMA,
    STATE(80), 1,
      aux_sym_identifier_list_repeat1,
    ACTIONS(298), 2,
      anon_sym_COLON_EQ,
      anon_sym_EQ,
  [1417] = 4,
    ACTIONS(291), 1,
      anon_sym_COMMA,
    ACTIONS(300), 1,
      anon_sym_LF,
    ACTIONS(302), 1,
      anon_sym_RBRACE,
    STATE(83), 1,
      aux_sym_short_var_declaration_repeat1,
  [1430] = 4,
    ACTIONS(291), 1,
      anon_sym_COMMA,
    ACTIONS(304), 1,
      anon_sym_LF,
    ACTIONS(306), 1,
      anon_sym_RBRACE,
    STATE(79), 1,
      aux_sym_short_var_declaration_repeat1,
  [1443] = 4,
    ACTIONS(291), 1,
      anon_sym_COMMA,
    ACTIONS(308), 1,
      anon_sym_LF,
    ACTIONS(310), 1,
      anon_sym_RBRACE,
    STATE(78), 1,
      aux_sym_short_var_declaration_repeat1,
  [1456] = 3,
    ACTIONS(312), 1,
      anon_sym_RBRACE,
    ACTIONS(314), 1,
      sym_format_flag,
    ACTIONS(316), 1,
      anon_sym_DOT,
  [1466] = 2,
    STATE(109), 1,
      sym_identifier,
    ACTIONS(318), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1474] = 3,
    ACTIONS(320), 1,
      anon_sym_LF,
    ACTIONS(322), 1,
      anon_sym_RBRACE,
    STATE(95), 1,
      aux_sym__statement_list_repeat1,
  [1484] = 2,
    ACTIONS(105), 1,
      anon_sym_LF,
    ACTIONS(107), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1492] = 3,
    ACTIONS(324), 1,
      anon_sym_LF,
    ACTIONS(327), 1,
      anon_sym_RBRACE,
    STATE(88), 1,
      aux_sym__statement_list_repeat1,
  [1502] = 2,
    ACTIONS(113), 1,
      anon_sym_LF,
    ACTIONS(115), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1510] = 3,
    ACTIONS(329), 1,
      sym_int_literal,
    ACTIONS(331), 1,
      sym_format_flag,
    ACTIONS(333), 1,
      aux_sym_format_specifier_token1,
  [1520] = 3,
    ACTIONS(335), 1,
      anon_sym_COMMA,
    ACTIONS(338), 1,
      anon_sym_RPAREN,
    STATE(91), 1,
      aux_sym_parameter_list_repeat1,
  [1530] = 2,
    ACTIONS(101), 1,
      anon_sym_LF,
    ACTIONS(103), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1538] = 1,
    ACTIONS(220), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      anon_sym_RPAREN,
  [1544] = 2,
    STATE(103), 1,
      sym_identifier,
    ACTIONS(123), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [1552] = 3,
    ACTIONS(144), 1,
      anon_sym_RBRACE,
    ACTIONS(340), 1,
      anon_sym_LF,
    STATE(88), 1,
      aux_sym__statement_list_repeat1,
  [1562] = 3,
    ACTIONS(342), 1,
      anon_sym_COMMA,
    ACTIONS(344), 1,
      anon_sym_RPAREN,
    STATE(97), 1,
      aux_sym_parameter_list_repeat1,
  [1572] = 3,
    ACTIONS(342), 1,
      anon_sym_COMMA,
    ACTIONS(346), 1,
      anon_sym_RPAREN,
    STATE(91), 1,
      aux_sym_parameter_list_repeat1,
  [1582] = 2,
    ACTIONS(282), 1,
      anon_sym_LF,
    ACTIONS(287), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1590] = 2,
    ACTIONS(117), 1,
      anon_sym_LF,
    ACTIONS(119), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1598] = 3,
    ACTIONS(15), 1,
      anon_sym_LBRACE,
    ACTIONS(348), 1,
      anon_sym_LF,
    STATE(128), 1,
      sym_block,
  [1608] = 2,
    ACTIONS(125), 1,
      anon_sym_LF,
    ACTIONS(127), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1616] = 3,
    ACTIONS(350), 1,
      anon_sym_RBRACE,
    ACTIONS(352), 1,
      sym_format_flag,
    ACTIONS(354), 1,
      anon_sym_DOT,
  [1626] = 1,
    ACTIONS(298), 3,
      anon_sym_COMMA,
      anon_sym_COLON_EQ,
      anon_sym_EQ,
  [1632] = 3,
    ACTIONS(356), 1,
      anon_sym_RBRACE,
    ACTIONS(358), 1,
      anon_sym_COLON,
    STATE(124), 1,
      sym_format_specifier,
  [1642] = 2,
    ACTIONS(109), 1,
      anon_sym_LF,
    ACTIONS(111), 2,
      anon_sym_COMMA,
      anon_sym_RBRACE,
  [1650] = 2,
    ACTIONS(360), 1,
      anon_sym_LF,
    ACTIONS(362), 1,
      anon_sym_LBRACE,
  [1657] = 2,
    ACTIONS(364), 1,
      anon_sym_RBRACE,
    ACTIONS(366), 1,
      sym_format_flag,
  [1664] = 2,
    ACTIONS(368), 1,
      anon_sym_COLON_EQ,
    ACTIONS(370), 1,
      anon_sym_EQ,
  [1671] = 2,
    ACTIONS(372), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_parameter_list,
  [1678] = 2,
    ACTIONS(327), 1,
      anon_sym_RBRACE,
    ACTIONS(374), 1,
      anon_sym_LF,
  [1685] = 2,
    ACTIONS(376), 1,
      anon_sym_RBRACE,
    ACTIONS(378), 1,
      sym_format_flag,
  [1692] = 1,
    ACTIONS(360), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1697] = 1,
    ACTIONS(338), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1702] = 1,
    ACTIONS(380), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1707] = 1,
    ACTIONS(382), 1,
      anon_sym_LF,
  [1711] = 1,
    ACTIONS(384), 1,
      anon_sym_LF,
  [1715] = 1,
    ACTIONS(350), 1,
      anon_sym_RBRACE,
  [1719] = 1,
    ACTIONS(386), 1,
      sym_int_literal,
  [1723] = 1,
    ACTIONS(312), 1,
      anon_sym_RBRACE,
  [1727] = 1,
    ACTIONS(388), 1,
      anon_sym_LF,
  [1731] = 1,
    ACTIONS(390), 1,
      anon_sym_LF,
  [1735] = 1,
    ACTIONS(364), 1,
      anon_sym_RBRACE,
  [1739] = 1,
    ACTIONS(392), 1,
      anon_sym_RBRACE,
  [1743] = 1,
    ACTIONS(394), 1,
      anon_sym_RBRACE,
  [1747] = 1,
    ACTIONS(396), 1,
      anon_sym_LF,
  [1751] = 1,
    ACTIONS(398), 1,
      anon_sym_LF,
  [1755] = 1,
    ACTIONS(400), 1,
      anon_sym_LF,
  [1759] = 1,
    ACTIONS(402), 1,
      anon_sym_LF,
  [1763] = 1,
    ACTIONS(404), 1,
      anon_sym_LF,
  [1767] = 1,
    ACTIONS(406), 1,
      anon_sym_EQ,
  [1771] = 1,
    ACTIONS(408), 1,
      sym_int_literal,
  [1775] = 1,
    ACTIONS(410), 1,
      anon_sym_RBRACE,
  [1779] = 1,
    ACTIONS(376), 1,
      anon_sym_RBRACE,
  [1783] = 1,
    ACTIONS(412), 1,
      sym_int_literal,
  [1787] = 1,
    ACTIONS(414), 1,
      anon_sym_LF,
  [1791] = 1,
    ACTIONS(416), 1,
      ts_builtin_sym_end,
  [1795] = 1,
    ACTIONS(418), 1,
      anon_sym_LF,
  [1799] = 1,
    ACTIONS(420), 1,
      anon_sym_const,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 32,
  [SMALL_STATE(4)] = 59,
  [SMALL_STATE(5)] = 86,
  [SMALL_STATE(6)] = 113,
  [SMALL_STATE(7)] = 136,
  [SMALL_STATE(8)] = 159,
  [SMALL_STATE(9)] = 182,
  [SMALL_STATE(10)] = 205,
  [SMALL_STATE(11)] = 236,
  [SMALL_STATE(12)] = 267,
  [SMALL_STATE(13)] = 298,
  [SMALL_STATE(14)] = 329,
  [SMALL_STATE(15)] = 360,
  [SMALL_STATE(16)] = 385,
  [SMALL_STATE(17)] = 402,
  [SMALL_STATE(18)] = 427,
  [SMALL_STATE(19)] = 452,
  [SMALL_STATE(20)] = 477,
  [SMALL_STATE(21)] = 502,
  [SMALL_STATE(22)] = 519,
  [SMALL_STATE(23)] = 533,
  [SMALL_STATE(24)] = 547,
  [SMALL_STATE(25)] = 561,
  [SMALL_STATE(26)] = 575,
  [SMALL_STATE(27)] = 589,
  [SMALL_STATE(28)] = 611,
  [SMALL_STATE(29)] = 625,
  [SMALL_STATE(30)] = 646,
  [SMALL_STATE(31)] = 665,
  [SMALL_STATE(32)] = 686,
  [SMALL_STATE(33)] = 705,
  [SMALL_STATE(34)] = 726,
  [SMALL_STATE(35)] = 746,
  [SMALL_STATE(36)] = 760,
  [SMALL_STATE(37)] = 780,
  [SMALL_STATE(38)] = 800,
  [SMALL_STATE(39)] = 820,
  [SMALL_STATE(40)] = 840,
  [SMALL_STATE(41)] = 860,
  [SMALL_STATE(42)] = 880,
  [SMALL_STATE(43)] = 896,
  [SMALL_STATE(44)] = 916,
  [SMALL_STATE(45)] = 936,
  [SMALL_STATE(46)] = 950,
  [SMALL_STATE(47)] = 970,
  [SMALL_STATE(48)] = 984,
  [SMALL_STATE(49)] = 1004,
  [SMALL_STATE(50)] = 1018,
  [SMALL_STATE(51)] = 1038,
  [SMALL_STATE(52)] = 1055,
  [SMALL_STATE(53)] = 1066,
  [SMALL_STATE(54)] = 1077,
  [SMALL_STATE(55)] = 1088,
  [SMALL_STATE(56)] = 1099,
  [SMALL_STATE(57)] = 1116,
  [SMALL_STATE(58)] = 1133,
  [SMALL_STATE(59)] = 1150,
  [SMALL_STATE(60)] = 1167,
  [SMALL_STATE(61)] = 1178,
  [SMALL_STATE(62)] = 1193,
  [SMALL_STATE(63)] = 1204,
  [SMALL_STATE(64)] = 1216,
  [SMALL_STATE(65)] = 1230,
  [SMALL_STATE(66)] = 1242,
  [SMALL_STATE(67)] = 1256,
  [SMALL_STATE(68)] = 1268,
  [SMALL_STATE(69)] = 1280,
  [SMALL_STATE(70)] = 1292,
  [SMALL_STATE(71)] = 1304,
  [SMALL_STATE(72)] = 1318,
  [SMALL_STATE(73)] = 1329,
  [SMALL_STATE(74)] = 1340,
  [SMALL_STATE(75)] = 1347,
  [SMALL_STATE(76)] = 1358,
  [SMALL_STATE(77)] = 1369,
  [SMALL_STATE(78)] = 1380,
  [SMALL_STATE(79)] = 1393,
  [SMALL_STATE(80)] = 1406,
  [SMALL_STATE(81)] = 1417,
  [SMALL_STATE(82)] = 1430,
  [SMALL_STATE(83)] = 1443,
  [SMALL_STATE(84)] = 1456,
  [SMALL_STATE(85)] = 1466,
  [SMALL_STATE(86)] = 1474,
  [SMALL_STATE(87)] = 1484,
  [SMALL_STATE(88)] = 1492,
  [SMALL_STATE(89)] = 1502,
  [SMALL_STATE(90)] = 1510,
  [SMALL_STATE(91)] = 1520,
  [SMALL_STATE(92)] = 1530,
  [SMALL_STATE(93)] = 1538,
  [SMALL_STATE(94)] = 1544,
  [SMALL_STATE(95)] = 1552,
  [SMALL_STATE(96)] = 1562,
  [SMALL_STATE(97)] = 1572,
  [SMALL_STATE(98)] = 1582,
  [SMALL_STATE(99)] = 1590,
  [SMALL_STATE(100)] = 1598,
  [SMALL_STATE(101)] = 1608,
  [SMALL_STATE(102)] = 1616,
  [SMALL_STATE(103)] = 1626,
  [SMALL_STATE(104)] = 1632,
  [SMALL_STATE(105)] = 1642,
  [SMALL_STATE(106)] = 1650,
  [SMALL_STATE(107)] = 1657,
  [SMALL_STATE(108)] = 1664,
  [SMALL_STATE(109)] = 1671,
  [SMALL_STATE(110)] = 1678,
  [SMALL_STATE(111)] = 1685,
  [SMALL_STATE(112)] = 1692,
  [SMALL_STATE(113)] = 1697,
  [SMALL_STATE(114)] = 1702,
  [SMALL_STATE(115)] = 1707,
  [SMALL_STATE(116)] = 1711,
  [SMALL_STATE(117)] = 1715,
  [SMALL_STATE(118)] = 1719,
  [SMALL_STATE(119)] = 1723,
  [SMALL_STATE(120)] = 1727,
  [SMALL_STATE(121)] = 1731,
  [SMALL_STATE(122)] = 1735,
  [SMALL_STATE(123)] = 1739,
  [SMALL_STATE(124)] = 1743,
  [SMALL_STATE(125)] = 1747,
  [SMALL_STATE(126)] = 1751,
  [SMALL_STATE(127)] = 1755,
  [SMALL_STATE(128)] = 1759,
  [SMALL_STATE(129)] = 1763,
  [SMALL_STATE(130)] = 1767,
  [SMALL_STATE(131)] = 1771,
  [SMALL_STATE(132)] = 1775,
  [SMALL_STATE(133)] = 1779,
  [SMALL_STATE(134)] = 1783,
  [SMALL_STATE(135)] = 1787,
  [SMALL_STATE(136)] = 1791,
  [SMALL_STATE(137)] = 1795,
  [SMALL_STATE(138)] = 1799,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 3, .production_id = 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [19] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 2),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(5),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3),
  [32] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parameter_list, 3),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 4),
  [36] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parameter_list, 4),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 2),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parameter_list, 2),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(26),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(22),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(14),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(48),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(36),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3, .production_id = 7),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 3, .production_id = 7),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 2),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 1),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 1),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interpreted_string_literal, 2),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interpreted_string_literal, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interpreted_string_literal, 3),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interpreted_string_literal, 3),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 4, .production_id = 7),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 4, .production_id = 7),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 3),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement_list, 3),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [135] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(85),
  [138] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(138),
  [141] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(71),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement_list, 2),
  [146] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2), SHIFT_REPEAT(33),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2), SHIFT_REPEAT(33),
  [154] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2), SHIFT_REPEAT(18),
  [157] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2), SHIFT_REPEAT(61),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [168] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [170] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(35),
  [173] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [177] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [183] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [187] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [191] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [193] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 1),
  [205] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_array_repeat1, 1),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [217] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_const_declaration_repeat1, 2), SHIFT_REPEAT(69),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_const_declaration_repeat1, 2),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_interpolation, 4),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_interpolation, 4),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_interpolation, 2),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_interpolation, 2),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_array_repeat1, 2),
  [232] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [234] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [238] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_interpolation, 3),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_interpolation, 3),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [250] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [252] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [254] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [256] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(65),
  [259] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [261] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(67),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [266] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [268] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [270] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [272] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_list, 2),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_list, 1),
  [280] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_short_var_declaration_repeat1, 2),
  [284] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_short_var_declaration_repeat1, 2), SHIFT_REPEAT(20),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_short_var_declaration_repeat1, 2),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_statement, 4, .production_id = 9),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [293] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment_statement, 4, .production_id = 9),
  [295] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_identifier_list_repeat1, 2), SHIFT_REPEAT(94),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_identifier_list_repeat1, 2),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_var_declaration, 3, .production_id = 8),
  [302] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_var_declaration, 3, .production_id = 8),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_statement, 3, .production_id = 8),
  [306] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment_statement, 3, .production_id = 8),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_var_declaration, 4, .production_id = 9),
  [310] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_var_declaration, 4, .production_id = 9),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 2),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [318] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [322] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement_list, 1),
  [324] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statement_list_repeat1, 2), SHIFT_REPEAT(42),
  [327] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statement_list_repeat1, 2),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [333] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [335] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(73),
  [338] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 4, .production_id = 2),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 3),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [360] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_identifier, 1),
  [362] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_identifier, 1),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 5),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statement_list_repeat1, 2),
  [376] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 4),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [380] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_declaration, 2, .production_id = 5),
  [382] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 3),
  [384] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_spec, 3, .production_id = 4),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [388] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 6),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [396] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 4),
  [398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 4, .production_id = 3),
  [400] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 5),
  [402] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 5, .production_id = 6),
  [404] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 2),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [416] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [418] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_v(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = (const uint16_t *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
