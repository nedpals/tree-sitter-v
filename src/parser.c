#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 93
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 63
#define ALIAS_COUNT 0
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 7

enum {
  anon_sym_LF = 1,
  sym_escape_sequence = 2,
  sym_int_literal = 3,
  anon_sym_SQUOTE = 4,
  aux_sym_interpreted_string_literal_token1 = 5,
  anon_sym_DQUOTE = 6,
  anon_sym_DOLLAR_LBRACE = 7,
  anon_sym_RBRACE = 8,
  anon_sym_DOLLAR = 9,
  sym_format_flag = 10,
  anon_sym_COLON = 11,
  aux_sym_format_specifier_token1 = 12,
  anon_sym_DOT = 13,
  aux_sym_identifier_token1 = 14,
  anon_sym__ = 15,
  aux_sym_identifier_token2 = 16,
  anon_sym_LPAREN = 17,
  anon_sym_COMMA = 18,
  anon_sym_RPAREN = 19,
  anon_sym_bool = 20,
  anon_sym_string = 21,
  anon_sym_i8 = 22,
  anon_sym_i16 = 23,
  anon_sym_int = 24,
  anon_sym_i64 = 25,
  anon_sym_byte = 26,
  anon_sym_u16 = 27,
  anon_sym_u32 = 28,
  anon_sym_u64 = 29,
  anon_sym_rune = 30,
  anon_sym_f32 = 31,
  anon_sym_f64 = 32,
  anon_sym_voidptr = 33,
  anon_sym_size_t = 34,
  anon_sym_any = 35,
  anon_sym_LBRACE = 36,
  anon_sym_fn = 37,
  anon_sym_pub = 38,
  anon_sym_const = 39,
  anon_sym_EQ = 40,
  sym_source_file = 41,
  sym__top_level_statement = 42,
  sym__expression = 43,
  sym__single_line_expression = 44,
  sym__string_literal = 45,
  sym_interpreted_string_literal = 46,
  sym_string_interpolation = 47,
  sym_format_specifier = 48,
  sym_identifier = 49,
  sym_parameter_declaration = 50,
  sym_parameter_list = 51,
  sym__type = 52,
  sym_type_identifier = 53,
  sym_block = 54,
  sym_function_declaration = 55,
  sym_const_declaration = 56,
  sym_const_spec = 57,
  aux_sym_source_file_repeat1 = 58,
  aux_sym_interpreted_string_literal_repeat1 = 59,
  aux_sym_identifier_repeat1 = 60,
  aux_sym_parameter_list_repeat1 = 61,
  aux_sym_const_declaration_repeat1 = 62,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [sym_escape_sequence] = "escape_sequence",
  [sym_int_literal] = "int_literal",
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
  [anon_sym_COMMA] = ",",
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
  [anon_sym_fn] = "fn",
  [anon_sym_pub] = "pub",
  [anon_sym_const] = "const",
  [anon_sym_EQ] = "=",
  [sym_source_file] = "source_file",
  [sym__top_level_statement] = "_top_level_statement",
  [sym__expression] = "_expression",
  [sym__single_line_expression] = "_single_line_expression",
  [sym__string_literal] = "_string_literal",
  [sym_interpreted_string_literal] = "interpreted_string_literal",
  [sym_string_interpolation] = "string_interpolation",
  [sym_format_specifier] = "format_specifier",
  [sym_identifier] = "identifier",
  [sym_parameter_declaration] = "parameter_declaration",
  [sym_parameter_list] = "parameter_list",
  [sym__type] = "_type",
  [sym_type_identifier] = "type_identifier",
  [sym_block] = "block",
  [sym_function_declaration] = "function_declaration",
  [sym_const_declaration] = "const_declaration",
  [sym_const_spec] = "const_spec",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_interpreted_string_literal_repeat1] = "interpreted_string_literal_repeat1",
  [aux_sym_identifier_repeat1] = "identifier_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
  [aux_sym_const_declaration_repeat1] = "const_declaration_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_int_literal] = sym_int_literal,
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
  [anon_sym_COMMA] = anon_sym_COMMA,
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
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_pub] = anon_sym_pub,
  [anon_sym_const] = anon_sym_const,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_source_file] = sym_source_file,
  [sym__top_level_statement] = sym__top_level_statement,
  [sym__expression] = sym__expression,
  [sym__single_line_expression] = sym__single_line_expression,
  [sym__string_literal] = sym__string_literal,
  [sym_interpreted_string_literal] = sym_interpreted_string_literal,
  [sym_string_interpolation] = sym_string_interpolation,
  [sym_format_specifier] = sym_format_specifier,
  [sym_identifier] = sym_identifier,
  [sym_parameter_declaration] = sym_parameter_declaration,
  [sym_parameter_list] = sym_parameter_list,
  [sym__type] = sym__type,
  [sym_type_identifier] = sym_type_identifier,
  [sym_block] = sym_block,
  [sym_function_declaration] = sym_function_declaration,
  [sym_const_declaration] = sym_const_declaration,
  [sym_const_spec] = sym_const_spec,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_interpreted_string_literal_repeat1] = aux_sym_interpreted_string_literal_repeat1,
  [aux_sym_identifier_repeat1] = aux_sym_identifier_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
  [aux_sym_const_declaration_repeat1] = aux_sym_const_declaration_repeat1,
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
  [anon_sym_COMMA] = {
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
  [anon_sym_EQ] = {
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
  [aux_sym_interpreted_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_identifier_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameter_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_const_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_body = 1,
  field_name = 2,
  field_result = 3,
  field_type = 4,
  field_value = 5,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_name] = "name",
  [field_result] = "result",
  [field_type] = "type",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 2},
  [5] = {.index = 7, .length = 2},
  [6] = {.index = 9, .length = 3},
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
};

static TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
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
      if (eof) ADVANCE(73);
      if (lookahead == '"') ADVANCE(84);
      if (lookahead == '$') ADVANCE(87);
      if (lookahead == '\'') ADVANCE(81);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == ')') ADVANCE(113);
      if (lookahead == ',') ADVANCE(112);
      if (lookahead == '.') ADVANCE(95);
      if (lookahead == '0') ADVANCE(80);
      if (lookahead == ':') ADVANCE(93);
      if (lookahead == '=') ADVANCE(134);
      if (lookahead == '\\') ADVANCE(62);
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'b') ADVANCE(43);
      if (lookahead == 'c') ADVANCE(91);
      if (lookahead == 'f') ADVANCE(89);
      if (lookahead == 'i') ADVANCE(11);
      if (lookahead == 'p') ADVANCE(92);
      if (lookahead == 'r') ADVANCE(54);
      if (lookahead == 's') ADVANCE(90);
      if (lookahead == 'u') ADVANCE(12);
      if (lookahead == 'v') ADVANCE(40);
      if (lookahead == '{') ADVANCE(130);
      if (lookahead == '}') ADVANCE(86);
      if (('+' <= lookahead && lookahead <= '/')) ADVANCE(94);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(79);
      if (('E' <= lookahead && lookahead <= 'G') ||
          lookahead == 'S' ||
          lookahead == 'X' ||
          ('d' <= lookahead && lookahead <= 'g') ||
          lookahead == 'o' ||
          lookahead == 'x') ADVANCE(88);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(75);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(74);
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'b') ADVANCE(43);
      if (lookahead == 'f') ADVANCE(15);
      if (lookahead == 'i') ADVANCE(11);
      if (lookahead == 'r') ADVANCE(54);
      if (lookahead == 's') ADVANCE(32);
      if (lookahead == 'u') ADVANCE(12);
      if (lookahead == 'v') ADVANCE(40);
      if (lookahead == '{') ADVANCE(130);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3)
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == 'a') ADVANCE(106);
      if (lookahead == 'b') ADVANCE(108);
      if (lookahead == 'f') ADVANCE(101);
      if (lookahead == 'i') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(109);
      if (lookahead == 's') ADVANCE(105);
      if (lookahead == 'u') ADVANCE(100);
      if (lookahead == 'v') ADVANCE(107);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(103);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (lookahead != 0) ADVANCE(96);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(4)
      if (lookahead == ')') ADVANCE(113);
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(98);
      if (lookahead != 0) ADVANCE(96);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(5)
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (lookahead != 0) ADVANCE(96);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(6)
      if (lookahead == '=') ADVANCE(134);
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (lookahead != 0) ADVANCE(96);
      END_STATE();
    case 7:
      if (lookahead == '\n') SKIP(7)
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(104);
      if (lookahead != 0) ADVANCE(96);
      END_STATE();
    case 8:
      if (lookahead == '"') ADVANCE(83);
      if (lookahead == '$') ADVANCE(87);
      if (lookahead == '\'') ADVANCE(81);
      if (lookahead == '\\') ADVANCE(62);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(82);
      if (lookahead != 0) ADVANCE(83);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(95);
      if (lookahead == '}') ADVANCE(86);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      if (('E' <= lookahead && lookahead <= 'G') ||
          lookahead == 'S' ||
          lookahead == 'X' ||
          ('c' <= lookahead && lookahead <= 'g') ||
          lookahead == 'o' ||
          lookahead == 'p' ||
          lookahead == 's' ||
          lookahead == 'x') ADVANCE(88);
      END_STATE();
    case 10:
      if (lookahead == '0') ADVANCE(80);
      if (lookahead == '}') ADVANCE(86);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (('+' <= lookahead && lookahead <= '/')) ADVANCE(94);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(79);
      if (('E' <= lookahead && lookahead <= 'G') ||
          lookahead == 'S' ||
          lookahead == 'X' ||
          ('c' <= lookahead && lookahead <= 'g') ||
          lookahead == 'o' ||
          lookahead == 'p' ||
          lookahead == 's' ||
          lookahead == 'x') ADVANCE(88);
      END_STATE();
    case 11:
      if (lookahead == '1') ADVANCE(20);
      if (lookahead == '6') ADVANCE(18);
      if (lookahead == '8') ADVANCE(116);
      if (lookahead == 'n') ADVANCE(49);
      END_STATE();
    case 12:
      if (lookahead == '1') ADVANCE(21);
      if (lookahead == '3') ADVANCE(14);
      if (lookahead == '6') ADVANCE(19);
      END_STATE();
    case 13:
      if (lookahead == '2') ADVANCE(125);
      END_STATE();
    case 14:
      if (lookahead == '2') ADVANCE(122);
      END_STATE();
    case 15:
      if (lookahead == '3') ADVANCE(13);
      if (lookahead == '6') ADVANCE(17);
      END_STATE();
    case 16:
      if (lookahead == '3') ADVANCE(13);
      if (lookahead == '6') ADVANCE(17);
      if (lookahead == 'n') ADVANCE(131);
      END_STATE();
    case 17:
      if (lookahead == '4') ADVANCE(126);
      END_STATE();
    case 18:
      if (lookahead == '4') ADVANCE(119);
      END_STATE();
    case 19:
      if (lookahead == '4') ADVANCE(123);
      END_STATE();
    case 20:
      if (lookahead == '6') ADVANCE(117);
      END_STATE();
    case 21:
      if (lookahead == '6') ADVANCE(121);
      END_STATE();
    case 22:
      if (lookahead == '_') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(76);
      END_STATE();
    case 23:
      if (lookahead == '_') ADVANCE(57);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(77);
      END_STATE();
    case 24:
      if (lookahead == '_') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 25:
      if (lookahead == '_') ADVANCE(51);
      END_STATE();
    case 26:
      if (lookahead == 'b') ADVANCE(132);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(44);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(120);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(124);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 31:
      if (lookahead == 'g') ADVANCE(115);
      END_STATE();
    case 32:
      if (lookahead == 'i') ADVANCE(56);
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 33:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 34:
      if (lookahead == 'i') ADVANCE(38);
      END_STATE();
    case 35:
      if (lookahead == 'l') ADVANCE(114);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(47);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 40:
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 42:
      if (lookahead == 'o') ADVANCE(37);
      END_STATE();
    case 43:
      if (lookahead == 'o') ADVANCE(41);
      if (lookahead == 'y') ADVANCE(48);
      END_STATE();
    case 44:
      if (lookahead == 'p') ADVANCE(52);
      END_STATE();
    case 45:
      if (lookahead == 'r') ADVANCE(127);
      END_STATE();
    case 46:
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 47:
      if (lookahead == 's') ADVANCE(50);
      END_STATE();
    case 48:
      if (lookahead == 't') ADVANCE(28);
      END_STATE();
    case 49:
      if (lookahead == 't') ADVANCE(118);
      END_STATE();
    case 50:
      if (lookahead == 't') ADVANCE(133);
      END_STATE();
    case 51:
      if (lookahead == 't') ADVANCE(128);
      END_STATE();
    case 52:
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 53:
      if (lookahead == 'u') ADVANCE(26);
      END_STATE();
    case 54:
      if (lookahead == 'u') ADVANCE(39);
      END_STATE();
    case 55:
      if (lookahead == 'y') ADVANCE(129);
      END_STATE();
    case 56:
      if (lookahead == 'z') ADVANCE(30);
      END_STATE();
    case 57:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(77);
      END_STATE();
    case 58:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(76);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(79);
      END_STATE();
    case 60:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 61:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(60);
      END_STATE();
    case 62:
      if (sym_escape_sequence_character_set_1(lookahead)) ADVANCE(75);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == 'U') ADVANCE(71);
      if (lookahead == 'u') ADVANCE(67);
      if (lookahead == 'x') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(61);
      END_STATE();
    case 63:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(75);
      END_STATE();
    case 64:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 65:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(63);
      END_STATE();
    case 66:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(65);
      END_STATE();
    case 67:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 68:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(67);
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
      if (eof) ADVANCE(73);
      if (lookahead == '"') ADVANCE(84);
      if (lookahead == '\'') ADVANCE(81);
      if (lookahead == ')') ADVANCE(113);
      if (lookahead == ',') ADVANCE(112);
      if (lookahead == '0') ADVANCE(80);
      if (lookahead == 'a') ADVANCE(36);
      if (lookahead == 'b') ADVANCE(43);
      if (lookahead == 'c') ADVANCE(42);
      if (lookahead == 'f') ADVANCE(16);
      if (lookahead == 'i') ADVANCE(11);
      if (lookahead == 'p') ADVANCE(53);
      if (lookahead == 'r') ADVANCE(54);
      if (lookahead == 's') ADVANCE(32);
      if (lookahead == 'u') ADVANCE(12);
      if (lookahead == 'v') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(72)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(79);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(74);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == '_') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == '_') ADVANCE(57);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == '_') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == '_') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_int_literal);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(23);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(22);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(24);
      if (lookahead == '_') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(76);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_interpreted_string_literal_token1);
      if (lookahead == '"') ADVANCE(83);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '$' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(83);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_interpreted_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '$' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_DOLLAR_LBRACE);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '{') ADVANCE(85);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_format_flag);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_format_flag);
      if (lookahead == '3') ADVANCE(13);
      if (lookahead == '6') ADVANCE(17);
      if (lookahead == 'n') ADVANCE(131);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_format_flag);
      if (lookahead == 'i') ADVANCE(56);
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_format_flag);
      if (lookahead == 'o') ADVANCE(37);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_format_flag);
      if (lookahead == 'u') ADVANCE(26);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym_format_specifier_token1);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '(') ADVANCE(111);
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(96);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == ')') ADVANCE(113);
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(98);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(96);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '1') ADVANCE(20);
      if (lookahead == '6') ADVANCE(18);
      if (lookahead == '8') ADVANCE(116);
      if (lookahead == 'n') ADVANCE(49);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '1') ADVANCE(21);
      if (lookahead == '3') ADVANCE(14);
      if (lookahead == '6') ADVANCE(19);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '3') ADVANCE(13);
      if (lookahead == '6') ADVANCE(17);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '=') ADVANCE(134);
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(96);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == 'a') ADVANCE(106);
      if (lookahead == 'b') ADVANCE(108);
      if (lookahead == 'f') ADVANCE(101);
      if (lookahead == 'i') ADVANCE(99);
      if (lookahead == 'r') ADVANCE(109);
      if (lookahead == 's') ADVANCE(105);
      if (lookahead == 'u') ADVANCE(100);
      if (lookahead == 'v') ADVANCE(107);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(103);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(96);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '_') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(96);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'i') ADVANCE(56);
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'o') ADVANCE(41);
      if (lookahead == 'y') ADVANCE(48);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'u') ADVANCE(39);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_i8);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_i16);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_i64);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_byte);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_u16);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_u32);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_u64);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_rune);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_f32);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_f64);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_voidptr);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_size_t);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_any);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_pub);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_const);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 72},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 3},
  [5] = {.lex_state = 3},
  [6] = {.lex_state = 72},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 8},
  [11] = {.lex_state = 72},
  [12] = {.lex_state = 72},
  [13] = {.lex_state = 8},
  [14] = {.lex_state = 8},
  [15] = {.lex_state = 8},
  [16] = {.lex_state = 8},
  [17] = {.lex_state = 72},
  [18] = {.lex_state = 8},
  [19] = {.lex_state = 8},
  [20] = {.lex_state = 8},
  [21] = {.lex_state = 8},
  [22] = {.lex_state = 8},
  [23] = {.lex_state = 72},
  [24] = {.lex_state = 8},
  [25] = {.lex_state = 8},
  [26] = {.lex_state = 8},
  [27] = {.lex_state = 4},
  [28] = {.lex_state = 72},
  [29] = {.lex_state = 8},
  [30] = {.lex_state = 8},
  [31] = {.lex_state = 8},
  [32] = {.lex_state = 8},
  [33] = {.lex_state = 4},
  [34] = {.lex_state = 8},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 5},
  [39] = {.lex_state = 6},
  [40] = {.lex_state = 6},
  [41] = {.lex_state = 6},
  [42] = {.lex_state = 5},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 5},
  [45] = {.lex_state = 5},
  [46] = {.lex_state = 5},
  [47] = {.lex_state = 72},
  [48] = {.lex_state = 7},
  [49] = {.lex_state = 72},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 10},
  [54] = {.lex_state = 9},
  [55] = {.lex_state = 7},
  [56] = {.lex_state = 9},
  [57] = {.lex_state = 72},
  [58] = {.lex_state = 72},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 2},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 72},
  [64] = {.lex_state = 72},
  [65] = {.lex_state = 10},
  [66] = {.lex_state = 10},
  [67] = {.lex_state = 72},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 72},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 72},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 72},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 72},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 2},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym_int_literal] = ACTIONS(1),
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
    [anon_sym_COMMA] = ACTIONS(1),
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
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_pub] = ACTIONS(1),
    [anon_sym_const] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(92),
    [sym__top_level_statement] = STATE(91),
    [sym_function_declaration] = STATE(91),
    [sym_const_declaration] = STATE(91),
    [aux_sym_source_file_repeat1] = STATE(11),
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
    STATE(85), 1,
      sym_block,
    STATE(52), 2,
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
    STATE(4), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(21), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
    ACTIONS(24), 16,
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
    STATE(4), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(26), 3,
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
    STATE(64), 2,
      sym__type,
      sym_type_identifier,
    ACTIONS(30), 16,
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
  [136] = 2,
    ACTIONS(32), 1,
      anon_sym_LF,
    ACTIONS(34), 17,
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
    ACTIONS(36), 1,
      anon_sym_LF,
    ACTIONS(38), 17,
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
  [205] = 6,
    ACTIONS(44), 1,
      sym_escape_sequence,
    ACTIONS(49), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(52), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(55), 1,
      anon_sym_DOLLAR,
    ACTIONS(47), 2,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
    STATE(10), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [226] = 6,
    ACTIONS(5), 1,
      anon_sym_fn,
    ACTIONS(7), 1,
      anon_sym_pub,
    ACTIONS(9), 1,
      anon_sym_const,
    ACTIONS(58), 1,
      ts_builtin_sym_end,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(91), 3,
      sym__top_level_statement,
      sym_function_declaration,
      sym_const_declaration,
  [247] = 6,
    ACTIONS(60), 1,
      ts_builtin_sym_end,
    ACTIONS(62), 1,
      anon_sym_fn,
    ACTIONS(65), 1,
      anon_sym_pub,
    ACTIONS(68), 1,
      anon_sym_const,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(91), 3,
      sym__top_level_statement,
      sym_function_declaration,
      sym_const_declaration,
  [268] = 6,
    ACTIONS(71), 1,
      sym_escape_sequence,
    ACTIONS(73), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(75), 1,
      anon_sym_DQUOTE,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    STATE(15), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [288] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(81), 1,
      sym_escape_sequence,
    ACTIONS(83), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(85), 1,
      anon_sym_DQUOTE,
    STATE(10), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [308] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(81), 1,
      sym_escape_sequence,
    ACTIONS(83), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(87), 1,
      anon_sym_DQUOTE,
    STATE(10), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [328] = 6,
    ACTIONS(75), 1,
      anon_sym_SQUOTE,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(89), 1,
      sym_escape_sequence,
    ACTIONS(91), 1,
      aux_sym_interpreted_string_literal_token1,
    STATE(26), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [348] = 4,
    ACTIONS(93), 1,
      sym_int_literal,
    ACTIONS(95), 1,
      anon_sym_SQUOTE,
    ACTIONS(97), 1,
      anon_sym_DQUOTE,
    STATE(50), 4,
      sym__expression,
      sym__single_line_expression,
      sym__string_literal,
      sym_interpreted_string_literal,
  [364] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(81), 1,
      sym_escape_sequence,
    ACTIONS(83), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(99), 1,
      anon_sym_SQUOTE,
    STATE(10), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [384] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(81), 1,
      sym_escape_sequence,
    ACTIONS(83), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(99), 1,
      anon_sym_DQUOTE,
    STATE(10), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [404] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(81), 1,
      sym_escape_sequence,
    ACTIONS(83), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(85), 1,
      anon_sym_SQUOTE,
    STATE(10), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [424] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(101), 1,
      sym_escape_sequence,
    ACTIONS(103), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(105), 1,
      anon_sym_DQUOTE,
    STATE(14), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [444] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(107), 1,
      sym_escape_sequence,
    ACTIONS(109), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    STATE(19), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [464] = 4,
    ACTIONS(113), 1,
      sym_int_literal,
    ACTIONS(115), 1,
      anon_sym_SQUOTE,
    ACTIONS(117), 1,
      anon_sym_DQUOTE,
    STATE(83), 4,
      sym__expression,
      sym__single_line_expression,
      sym__string_literal,
      sym_interpreted_string_literal,
  [480] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(111), 1,
      anon_sym_SQUOTE,
    ACTIONS(119), 1,
      sym_escape_sequence,
    ACTIONS(121), 1,
      aux_sym_interpreted_string_literal_token1,
    STATE(18), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [500] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(105), 1,
      anon_sym_SQUOTE,
    ACTIONS(123), 1,
      sym_escape_sequence,
    ACTIONS(125), 1,
      aux_sym_interpreted_string_literal_token1,
    STATE(20), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [520] = 6,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LBRACE,
    ACTIONS(79), 1,
      anon_sym_DOLLAR,
    ACTIONS(81), 1,
      sym_escape_sequence,
    ACTIONS(83), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(87), 1,
      anon_sym_SQUOTE,
    STATE(10), 2,
      sym_string_interpolation,
      aux_sym_interpreted_string_literal_repeat1,
  [540] = 5,
    ACTIONS(130), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym_const_declaration_repeat1,
    STATE(87), 1,
      sym_const_spec,
    STATE(90), 1,
      sym_identifier,
    ACTIONS(127), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [557] = 4,
    ACTIONS(132), 1,
      sym_int_literal,
    ACTIONS(134), 1,
      anon_sym_SQUOTE,
    ACTIONS(136), 1,
      anon_sym_DQUOTE,
    STATE(34), 3,
      sym__single_line_expression,
      sym__string_literal,
      sym_interpreted_string_literal,
  [572] = 2,
    ACTIONS(140), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(138), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [583] = 2,
    ACTIONS(144), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(142), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [594] = 2,
    ACTIONS(148), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(146), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [605] = 2,
    ACTIONS(152), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(150), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [616] = 5,
    ACTIONS(156), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym_const_declaration_repeat1,
    STATE(87), 1,
      sym_const_spec,
    STATE(90), 1,
      sym_identifier,
    ACTIONS(154), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [633] = 2,
    ACTIONS(160), 1,
      aux_sym_interpreted_string_literal_token1,
    ACTIONS(158), 5,
      sym_escape_sequence,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_DOLLAR_LBRACE,
      anon_sym_DOLLAR,
  [644] = 5,
    ACTIONS(162), 1,
      anon_sym_RPAREN,
    STATE(37), 1,
      aux_sym_const_declaration_repeat1,
    STATE(87), 1,
      sym_const_spec,
    STATE(90), 1,
      sym_identifier,
    ACTIONS(154), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [661] = 5,
    ACTIONS(164), 1,
      anon_sym_RPAREN,
    STATE(33), 1,
      aux_sym_const_declaration_repeat1,
    STATE(87), 1,
      sym_const_spec,
    STATE(90), 1,
      sym_identifier,
    ACTIONS(154), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [678] = 5,
    ACTIONS(164), 1,
      anon_sym_RPAREN,
    STATE(27), 1,
      aux_sym_const_declaration_repeat1,
    STATE(87), 1,
      sym_const_spec,
    STATE(90), 1,
      sym_identifier,
    ACTIONS(154), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [695] = 4,
    ACTIONS(166), 1,
      anon_sym_LPAREN,
    STATE(88), 1,
      sym_const_spec,
    STATE(90), 1,
      sym_identifier,
    ACTIONS(154), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [709] = 3,
    ACTIONS(24), 1,
      anon_sym_EQ,
    STATE(39), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(168), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [721] = 3,
    ACTIONS(28), 1,
      anon_sym_EQ,
    STATE(39), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(171), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [733] = 3,
    ACTIONS(19), 1,
      anon_sym_EQ,
    STATE(40), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(173), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [745] = 4,
    ACTIONS(175), 1,
      anon_sym_LPAREN,
    STATE(89), 1,
      sym_const_spec,
    STATE(90), 1,
      sym_identifier,
    ACTIONS(154), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [759] = 4,
    ACTIONS(179), 1,
      anon_sym_RPAREN,
    STATE(6), 1,
      sym_identifier,
    STATE(58), 1,
      sym_parameter_declaration,
    ACTIONS(177), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [773] = 3,
    ACTIONS(28), 1,
      anon_sym_LPAREN,
    STATE(45), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(181), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [785] = 3,
    ACTIONS(24), 1,
      anon_sym_LPAREN,
    STATE(45), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(183), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [797] = 3,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    STATE(44), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(186), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [809] = 1,
    ACTIONS(60), 4,
      ts_builtin_sym_end,
      anon_sym_fn,
      anon_sym_pub,
      anon_sym_const,
  [816] = 3,
    STATE(6), 1,
      sym_identifier,
    STATE(63), 1,
      sym_parameter_declaration,
    ACTIONS(177), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [827] = 3,
    ACTIONS(188), 1,
      anon_sym_COMMA,
    ACTIONS(191), 1,
      anon_sym_RPAREN,
    STATE(49), 1,
      aux_sym_parameter_list_repeat1,
  [837] = 3,
    ACTIONS(193), 1,
      anon_sym_RBRACE,
    ACTIONS(195), 1,
      anon_sym_COLON,
    STATE(74), 1,
      sym_format_specifier,
  [847] = 1,
    ACTIONS(130), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      anon_sym_RPAREN,
  [853] = 3,
    ACTIONS(15), 1,
      anon_sym_LBRACE,
    ACTIONS(197), 1,
      anon_sym_LF,
    STATE(81), 1,
      sym_block,
  [863] = 3,
    ACTIONS(199), 1,
      sym_int_literal,
    ACTIONS(201), 1,
      sym_format_flag,
    ACTIONS(203), 1,
      aux_sym_format_specifier_token1,
  [873] = 3,
    ACTIONS(205), 1,
      anon_sym_RBRACE,
    ACTIONS(207), 1,
      sym_format_flag,
    ACTIONS(209), 1,
      anon_sym_DOT,
  [883] = 2,
    STATE(62), 1,
      sym_identifier,
    ACTIONS(211), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [891] = 3,
    ACTIONS(213), 1,
      anon_sym_RBRACE,
    ACTIONS(215), 1,
      sym_format_flag,
    ACTIONS(217), 1,
      anon_sym_DOT,
  [901] = 3,
    ACTIONS(219), 1,
      anon_sym_COMMA,
    ACTIONS(221), 1,
      anon_sym_RPAREN,
    STATE(49), 1,
      aux_sym_parameter_list_repeat1,
  [911] = 3,
    ACTIONS(219), 1,
      anon_sym_COMMA,
    ACTIONS(223), 1,
      anon_sym_RPAREN,
    STATE(57), 1,
      aux_sym_parameter_list_repeat1,
  [921] = 1,
    ACTIONS(148), 2,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [926] = 1,
    ACTIONS(152), 2,
      anon_sym_RBRACE,
      anon_sym_COLON,
  [931] = 2,
    ACTIONS(225), 1,
      anon_sym_LF,
    ACTIONS(227), 1,
      anon_sym_LBRACE,
  [938] = 2,
    ACTIONS(229), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_parameter_list,
  [945] = 1,
    ACTIONS(191), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [950] = 1,
    ACTIONS(231), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [955] = 2,
    ACTIONS(233), 1,
      anon_sym_RBRACE,
    ACTIONS(235), 1,
      sym_format_flag,
  [962] = 2,
    ACTIONS(237), 1,
      anon_sym_RBRACE,
    ACTIONS(239), 1,
      sym_format_flag,
  [969] = 1,
    ACTIONS(225), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [974] = 1,
    ACTIONS(241), 1,
      anon_sym_LF,
  [978] = 1,
    ACTIONS(233), 1,
      anon_sym_RBRACE,
  [982] = 1,
    ACTIONS(243), 1,
      sym_int_literal,
  [986] = 1,
    ACTIONS(237), 1,
      anon_sym_RBRACE,
  [990] = 1,
    ACTIONS(245), 1,
      sym_int_literal,
  [994] = 1,
    ACTIONS(247), 1,
      anon_sym_RBRACE,
  [998] = 1,
    ACTIONS(249), 1,
      anon_sym_RBRACE,
  [1002] = 1,
    ACTIONS(213), 1,
      anon_sym_RBRACE,
  [1006] = 1,
    ACTIONS(251), 1,
      sym_int_literal,
  [1010] = 1,
    ACTIONS(148), 1,
      anon_sym_LF,
  [1014] = 1,
    ACTIONS(205), 1,
      anon_sym_RBRACE,
  [1018] = 1,
    ACTIONS(253), 1,
      anon_sym_const,
  [1022] = 1,
    ACTIONS(152), 1,
      anon_sym_LF,
  [1026] = 1,
    ACTIONS(255), 1,
      anon_sym_LF,
  [1030] = 1,
    ACTIONS(257), 1,
      anon_sym_LF,
  [1034] = 1,
    ACTIONS(259), 1,
      anon_sym_LF,
  [1038] = 1,
    ACTIONS(261), 1,
      anon_sym_LF,
  [1042] = 1,
    ACTIONS(263), 1,
      anon_sym_LF,
  [1046] = 1,
    ACTIONS(265), 1,
      anon_sym_RBRACE,
  [1050] = 1,
    ACTIONS(267), 1,
      anon_sym_LF,
  [1054] = 1,
    ACTIONS(269), 1,
      anon_sym_LF,
  [1058] = 1,
    ACTIONS(271), 1,
      anon_sym_LF,
  [1062] = 1,
    ACTIONS(273), 1,
      anon_sym_EQ,
  [1066] = 1,
    ACTIONS(275), 1,
      anon_sym_LF,
  [1070] = 1,
    ACTIONS(277), 1,
      ts_builtin_sym_end,
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
  [SMALL_STATE(11)] = 226,
  [SMALL_STATE(12)] = 247,
  [SMALL_STATE(13)] = 268,
  [SMALL_STATE(14)] = 288,
  [SMALL_STATE(15)] = 308,
  [SMALL_STATE(16)] = 328,
  [SMALL_STATE(17)] = 348,
  [SMALL_STATE(18)] = 364,
  [SMALL_STATE(19)] = 384,
  [SMALL_STATE(20)] = 404,
  [SMALL_STATE(21)] = 424,
  [SMALL_STATE(22)] = 444,
  [SMALL_STATE(23)] = 464,
  [SMALL_STATE(24)] = 480,
  [SMALL_STATE(25)] = 500,
  [SMALL_STATE(26)] = 520,
  [SMALL_STATE(27)] = 540,
  [SMALL_STATE(28)] = 557,
  [SMALL_STATE(29)] = 572,
  [SMALL_STATE(30)] = 583,
  [SMALL_STATE(31)] = 594,
  [SMALL_STATE(32)] = 605,
  [SMALL_STATE(33)] = 616,
  [SMALL_STATE(34)] = 633,
  [SMALL_STATE(35)] = 644,
  [SMALL_STATE(36)] = 661,
  [SMALL_STATE(37)] = 678,
  [SMALL_STATE(38)] = 695,
  [SMALL_STATE(39)] = 709,
  [SMALL_STATE(40)] = 721,
  [SMALL_STATE(41)] = 733,
  [SMALL_STATE(42)] = 745,
  [SMALL_STATE(43)] = 759,
  [SMALL_STATE(44)] = 773,
  [SMALL_STATE(45)] = 785,
  [SMALL_STATE(46)] = 797,
  [SMALL_STATE(47)] = 809,
  [SMALL_STATE(48)] = 816,
  [SMALL_STATE(49)] = 827,
  [SMALL_STATE(50)] = 837,
  [SMALL_STATE(51)] = 847,
  [SMALL_STATE(52)] = 853,
  [SMALL_STATE(53)] = 863,
  [SMALL_STATE(54)] = 873,
  [SMALL_STATE(55)] = 883,
  [SMALL_STATE(56)] = 891,
  [SMALL_STATE(57)] = 901,
  [SMALL_STATE(58)] = 911,
  [SMALL_STATE(59)] = 921,
  [SMALL_STATE(60)] = 926,
  [SMALL_STATE(61)] = 931,
  [SMALL_STATE(62)] = 938,
  [SMALL_STATE(63)] = 945,
  [SMALL_STATE(64)] = 950,
  [SMALL_STATE(65)] = 955,
  [SMALL_STATE(66)] = 962,
  [SMALL_STATE(67)] = 969,
  [SMALL_STATE(68)] = 974,
  [SMALL_STATE(69)] = 978,
  [SMALL_STATE(70)] = 982,
  [SMALL_STATE(71)] = 986,
  [SMALL_STATE(72)] = 990,
  [SMALL_STATE(73)] = 994,
  [SMALL_STATE(74)] = 998,
  [SMALL_STATE(75)] = 1002,
  [SMALL_STATE(76)] = 1006,
  [SMALL_STATE(77)] = 1010,
  [SMALL_STATE(78)] = 1014,
  [SMALL_STATE(79)] = 1018,
  [SMALL_STATE(80)] = 1022,
  [SMALL_STATE(81)] = 1026,
  [SMALL_STATE(82)] = 1030,
  [SMALL_STATE(83)] = 1034,
  [SMALL_STATE(84)] = 1038,
  [SMALL_STATE(85)] = 1042,
  [SMALL_STATE(86)] = 1046,
  [SMALL_STATE(87)] = 1050,
  [SMALL_STATE(88)] = 1054,
  [SMALL_STATE(89)] = 1058,
  [SMALL_STATE(90)] = 1062,
  [SMALL_STATE(91)] = 1066,
  [SMALL_STATE(92)] = 1070,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 3, .production_id = 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [19] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(4),
  [24] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2),
  [26] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 2),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 4),
  [34] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parameter_list, 4),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 2),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parameter_list, 2),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parameter_list, 3),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2), SHIFT_REPEAT(10),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2), SHIFT_REPEAT(10),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2), SHIFT_REPEAT(17),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_interpreted_string_literal_repeat1, 2), SHIFT_REPEAT(28),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(55),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(79),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(42),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [127] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_const_declaration_repeat1, 2), SHIFT_REPEAT(41),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_const_declaration_repeat1, 2),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_interpolation, 4),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_interpolation, 4),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_interpolation, 3),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_interpolation, 3),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interpreted_string_literal, 3),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interpreted_string_literal, 3),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_interpreted_string_literal, 2),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_interpreted_string_literal, 2),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [156] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_interpolation, 2),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_interpolation, 2),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [168] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(39),
  [171] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [173] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [175] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [177] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [183] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(45),
  [186] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [188] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(48),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 4, .production_id = 2),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 2),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 3),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_identifier, 1),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_identifier, 1),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_declaration, 2, .production_id = 5),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 4),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 5),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 5),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_format_specifier, 6),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 5, .production_id = 6),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_spec, 3, .production_id = 4),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 4),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 4, .production_id = 3),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 3),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 2),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [277] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
