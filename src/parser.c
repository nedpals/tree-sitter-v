#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 34
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 39
#define ALIAS_COUNT 0
#define TOKEN_COUNT 27
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 6

enum {
  anon_sym_LF = 1,
  aux_sym_identifier_token1 = 2,
  anon_sym__ = 3,
  aux_sym_identifier_token2 = 4,
  anon_sym_LPAREN = 5,
  anon_sym_COMMA = 6,
  anon_sym_RPAREN = 7,
  anon_sym_bool = 8,
  anon_sym_string = 9,
  anon_sym_i8 = 10,
  anon_sym_i16 = 11,
  anon_sym_int = 12,
  anon_sym_i64 = 13,
  anon_sym_byte = 14,
  anon_sym_u16 = 15,
  anon_sym_u32 = 16,
  anon_sym_u64 = 17,
  anon_sym_rune = 18,
  anon_sym_f32 = 19,
  anon_sym_f64 = 20,
  anon_sym_voidptr = 21,
  anon_sym_size_t = 22,
  anon_sym_any = 23,
  anon_sym_LBRACE = 24,
  anon_sym_RBRACE = 25,
  anon_sym_fn = 26,
  sym_source_file = 27,
  sym__top_level_statement = 28,
  sym_identifier = 29,
  sym_parameter_declaration = 30,
  sym_parameter_list = 31,
  sym__type = 32,
  sym_type_identifier = 33,
  sym_block = 34,
  sym_function_declaration = 35,
  aux_sym_source_file_repeat1 = 36,
  aux_sym_identifier_repeat1 = 37,
  aux_sym_parameter_list_repeat1 = 38,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
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
  [anon_sym_RBRACE] = "}",
  [anon_sym_fn] = "fn",
  [sym_source_file] = "source_file",
  [sym__top_level_statement] = "_top_level_statement",
  [sym_identifier] = "identifier",
  [sym_parameter_declaration] = "parameter_declaration",
  [sym_parameter_list] = "parameter_list",
  [sym__type] = "_type",
  [sym_type_identifier] = "type_identifier",
  [sym_block] = "block",
  [sym_function_declaration] = "function_declaration",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_identifier_repeat1] = "identifier_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
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
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_fn] = anon_sym_fn,
  [sym_source_file] = sym_source_file,
  [sym__top_level_statement] = sym__top_level_statement,
  [sym_identifier] = sym_identifier,
  [sym_parameter_declaration] = sym_parameter_declaration,
  [sym_parameter_list] = sym_parameter_list,
  [sym__type] = sym__type,
  [sym_type_identifier] = sym_type_identifier,
  [sym_block] = sym_block,
  [sym_function_declaration] = sym_function_declaration,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_identifier_repeat1] = aux_sym_identifier_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
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
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
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
  [aux_sym_source_file_repeat1] = {
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
};

enum {
  field_body = 1,
  field_name = 2,
  field_result = 3,
  field_type = 4,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_body] = "body",
  [field_name] = "name",
  [field_result] = "result",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 2},
  [5] = {.index = 7, .length = 3},
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
    {field_type, 1},
  [7] =
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

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(43);
      if (lookahead == '(') ADVANCE(60);
      if (lookahead == ')') ADVANCE(62);
      if (lookahead == ',') ADVANCE(61);
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == 'a') ADVANCE(27);
      if (lookahead == 'b') ADVANCE(32);
      if (lookahead == 'f') ADVANCE(11);
      if (lookahead == 'i') ADVANCE(6);
      if (lookahead == 'r') ADVANCE(40);
      if (lookahead == 's') ADVANCE(23);
      if (lookahead == 'u') ADVANCE(7);
      if (lookahead == 'v') ADVANCE(30);
      if (lookahead == '{') ADVANCE(79);
      if (lookahead == '}') ADVANCE(80);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(44);
      if (lookahead == 'a') ADVANCE(27);
      if (lookahead == 'b') ADVANCE(32);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'i') ADVANCE(6);
      if (lookahead == 'r') ADVANCE(40);
      if (lookahead == 's') ADVANCE(23);
      if (lookahead == 'u') ADVANCE(7);
      if (lookahead == 'v') ADVANCE(30);
      if (lookahead == '{') ADVANCE(79);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == 'a') ADVANCE(54);
      if (lookahead == 'b') ADVANCE(56);
      if (lookahead == 'f') ADVANCE(50);
      if (lookahead == 'i') ADVANCE(48);
      if (lookahead == 'r') ADVANCE(57);
      if (lookahead == 's') ADVANCE(53);
      if (lookahead == 'u') ADVANCE(49);
      if (lookahead == 'v') ADVANCE(55);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      if (lookahead != 0) ADVANCE(45);
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(3)
      if (lookahead == '(') ADVANCE(60);
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      if (lookahead != 0) ADVANCE(45);
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(4)
      if (lookahead == ')') ADVANCE(62);
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(47);
      if (lookahead != 0) ADVANCE(45);
      END_STATE();
    case 5:
      if (lookahead == '\n') SKIP(5)
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0) ADVANCE(45);
      END_STATE();
    case 6:
      if (lookahead == '1') ADVANCE(15);
      if (lookahead == '6') ADVANCE(13);
      if (lookahead == '8') ADVANCE(65);
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 7:
      if (lookahead == '1') ADVANCE(16);
      if (lookahead == '3') ADVANCE(9);
      if (lookahead == '6') ADVANCE(14);
      END_STATE();
    case 8:
      if (lookahead == '2') ADVANCE(74);
      END_STATE();
    case 9:
      if (lookahead == '2') ADVANCE(71);
      END_STATE();
    case 10:
      if (lookahead == '3') ADVANCE(8);
      if (lookahead == '6') ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == '3') ADVANCE(8);
      if (lookahead == '6') ADVANCE(12);
      if (lookahead == 'n') ADVANCE(81);
      END_STATE();
    case 12:
      if (lookahead == '4') ADVANCE(75);
      END_STATE();
    case 13:
      if (lookahead == '4') ADVANCE(68);
      END_STATE();
    case 14:
      if (lookahead == '4') ADVANCE(72);
      END_STATE();
    case 15:
      if (lookahead == '6') ADVANCE(66);
      END_STATE();
    case 16:
      if (lookahead == '6') ADVANCE(70);
      END_STATE();
    case 17:
      if (lookahead == '_') ADVANCE(38);
      END_STATE();
    case 18:
      if (lookahead == 'd') ADVANCE(33);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(73);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 22:
      if (lookahead == 'g') ADVANCE(64);
      END_STATE();
    case 23:
      if (lookahead == 'i') ADVANCE(42);
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 24:
      if (lookahead == 'i') ADVANCE(18);
      END_STATE();
    case 25:
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(63);
      END_STATE();
    case 27:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 28:
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 29:
      if (lookahead == 'n') ADVANCE(20);
      END_STATE();
    case 30:
      if (lookahead == 'o') ADVANCE(24);
      END_STATE();
    case 31:
      if (lookahead == 'o') ADVANCE(26);
      END_STATE();
    case 32:
      if (lookahead == 'o') ADVANCE(31);
      if (lookahead == 'y') ADVANCE(36);
      END_STATE();
    case 33:
      if (lookahead == 'p') ADVANCE(39);
      END_STATE();
    case 34:
      if (lookahead == 'r') ADVANCE(76);
      END_STATE();
    case 35:
      if (lookahead == 'r') ADVANCE(25);
      END_STATE();
    case 36:
      if (lookahead == 't') ADVANCE(19);
      END_STATE();
    case 37:
      if (lookahead == 't') ADVANCE(67);
      END_STATE();
    case 38:
      if (lookahead == 't') ADVANCE(77);
      END_STATE();
    case 39:
      if (lookahead == 't') ADVANCE(34);
      END_STATE();
    case 40:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 41:
      if (lookahead == 'y') ADVANCE(78);
      END_STATE();
    case 42:
      if (lookahead == 'z') ADVANCE(21);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '(') ADVANCE(60);
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(45);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == ')') ADVANCE(62);
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(45);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '1') ADVANCE(15);
      if (lookahead == '6') ADVANCE(13);
      if (lookahead == '8') ADVANCE(65);
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '1') ADVANCE(16);
      if (lookahead == '3') ADVANCE(9);
      if (lookahead == '6') ADVANCE(14);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '3') ADVANCE(8);
      if (lookahead == '6') ADVANCE(12);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == 'a') ADVANCE(54);
      if (lookahead == 'b') ADVANCE(56);
      if (lookahead == 'f') ADVANCE(50);
      if (lookahead == 'i') ADVANCE(48);
      if (lookahead == 'r') ADVANCE(57);
      if (lookahead == 's') ADVANCE(53);
      if (lookahead == 'u') ADVANCE(49);
      if (lookahead == 'v') ADVANCE(55);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(45);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == '_') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(45);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'i') ADVANCE(42);
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'o') ADVANCE(24);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'o') ADVANCE(31);
      if (lookahead == 'y') ADVANCE(36);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_identifier_token1);
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_identifier_token2);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_i8);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_i16);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_i64);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_byte);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_u16);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_u32);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_u64);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_rune);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_f32);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_f64);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_voidptr);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_size_t);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_any);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 3},
  [16] = {.lex_state = 5},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 5},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
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
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(33),
    [sym__top_level_statement] = STATE(32),
    [sym_function_declaration] = STATE(32),
    [aux_sym_source_file_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_fn] = ACTIONS(5),
  },
  [2] = {
    [sym__type] = STATE(18),
    [sym_type_identifier] = STATE(18),
    [sym_block] = STATE(29),
    [anon_sym_LF] = ACTIONS(7),
    [anon_sym_bool] = ACTIONS(9),
    [anon_sym_string] = ACTIONS(9),
    [anon_sym_i8] = ACTIONS(9),
    [anon_sym_i16] = ACTIONS(9),
    [anon_sym_int] = ACTIONS(9),
    [anon_sym_i64] = ACTIONS(9),
    [anon_sym_byte] = ACTIONS(9),
    [anon_sym_u16] = ACTIONS(9),
    [anon_sym_u32] = ACTIONS(9),
    [anon_sym_u64] = ACTIONS(9),
    [anon_sym_rune] = ACTIONS(9),
    [anon_sym_f32] = ACTIONS(9),
    [anon_sym_f64] = ACTIONS(9),
    [anon_sym_voidptr] = ACTIONS(9),
    [anon_sym_size_t] = ACTIONS(9),
    [anon_sym_any] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
  },
  [3] = {
    [aux_sym_identifier_repeat1] = STATE(3),
    [aux_sym_identifier_token1] = ACTIONS(13),
    [anon_sym__] = ACTIONS(13),
    [aux_sym_identifier_token2] = ACTIONS(13),
    [anon_sym_bool] = ACTIONS(16),
    [anon_sym_string] = ACTIONS(16),
    [anon_sym_i8] = ACTIONS(16),
    [anon_sym_i16] = ACTIONS(16),
    [anon_sym_int] = ACTIONS(16),
    [anon_sym_i64] = ACTIONS(16),
    [anon_sym_byte] = ACTIONS(16),
    [anon_sym_u16] = ACTIONS(16),
    [anon_sym_u32] = ACTIONS(16),
    [anon_sym_u64] = ACTIONS(16),
    [anon_sym_rune] = ACTIONS(16),
    [anon_sym_f32] = ACTIONS(16),
    [anon_sym_f64] = ACTIONS(16),
    [anon_sym_voidptr] = ACTIONS(16),
    [anon_sym_size_t] = ACTIONS(16),
    [anon_sym_any] = ACTIONS(16),
  },
  [4] = {
    [aux_sym_identifier_repeat1] = STATE(3),
    [aux_sym_identifier_token1] = ACTIONS(18),
    [anon_sym__] = ACTIONS(18),
    [aux_sym_identifier_token2] = ACTIONS(18),
    [anon_sym_bool] = ACTIONS(20),
    [anon_sym_string] = ACTIONS(20),
    [anon_sym_i8] = ACTIONS(20),
    [anon_sym_i16] = ACTIONS(20),
    [anon_sym_int] = ACTIONS(20),
    [anon_sym_i64] = ACTIONS(20),
    [anon_sym_byte] = ACTIONS(20),
    [anon_sym_u16] = ACTIONS(20),
    [anon_sym_u32] = ACTIONS(20),
    [anon_sym_u64] = ACTIONS(20),
    [anon_sym_rune] = ACTIONS(20),
    [anon_sym_f32] = ACTIONS(20),
    [anon_sym_f64] = ACTIONS(20),
    [anon_sym_voidptr] = ACTIONS(20),
    [anon_sym_size_t] = ACTIONS(20),
    [anon_sym_any] = ACTIONS(20),
  },
  [5] = {
    [aux_sym_identifier_repeat1] = STATE(4),
    [aux_sym_identifier_token1] = ACTIONS(22),
    [anon_sym__] = ACTIONS(22),
    [aux_sym_identifier_token2] = ACTIONS(22),
    [anon_sym_bool] = ACTIONS(24),
    [anon_sym_string] = ACTIONS(24),
    [anon_sym_i8] = ACTIONS(24),
    [anon_sym_i16] = ACTIONS(24),
    [anon_sym_int] = ACTIONS(24),
    [anon_sym_i64] = ACTIONS(24),
    [anon_sym_byte] = ACTIONS(24),
    [anon_sym_u16] = ACTIONS(24),
    [anon_sym_u32] = ACTIONS(24),
    [anon_sym_u64] = ACTIONS(24),
    [anon_sym_rune] = ACTIONS(24),
    [anon_sym_f32] = ACTIONS(24),
    [anon_sym_f64] = ACTIONS(24),
    [anon_sym_voidptr] = ACTIONS(24),
    [anon_sym_size_t] = ACTIONS(24),
    [anon_sym_any] = ACTIONS(24),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(26), 1,
      anon_sym_LF,
    ACTIONS(28), 17,
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
  [23] = 2,
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
  [46] = 2,
    STATE(22), 2,
      sym__type,
      sym_type_identifier,
    ACTIONS(34), 16,
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
  [69] = 2,
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
  [92] = 4,
    ACTIONS(5), 1,
      anon_sym_fn,
    ACTIONS(40), 1,
      ts_builtin_sym_end,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(32), 2,
      sym__top_level_statement,
      sym_function_declaration,
  [106] = 3,
    ACTIONS(24), 1,
      anon_sym_LPAREN,
    STATE(13), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(42), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [118] = 4,
    ACTIONS(44), 1,
      ts_builtin_sym_end,
    ACTIONS(46), 1,
      anon_sym_fn,
    STATE(12), 1,
      aux_sym_source_file_repeat1,
    STATE(32), 2,
      sym__top_level_statement,
      sym_function_declaration,
  [132] = 3,
    ACTIONS(20), 1,
      anon_sym_LPAREN,
    STATE(15), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(49), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [144] = 4,
    ACTIONS(53), 1,
      anon_sym_RPAREN,
    STATE(8), 1,
      sym_identifier,
    STATE(20), 1,
      sym_parameter_declaration,
    ACTIONS(51), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [158] = 3,
    ACTIONS(16), 1,
      anon_sym_LPAREN,
    STATE(15), 1,
      aux_sym_identifier_repeat1,
    ACTIONS(55), 3,
      aux_sym_identifier_token1,
      anon_sym__,
      aux_sym_identifier_token2,
  [170] = 3,
    STATE(8), 1,
      sym_identifier,
    STATE(24), 1,
      sym_parameter_declaration,
    ACTIONS(51), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [181] = 3,
    ACTIONS(58), 1,
      anon_sym_COMMA,
    ACTIONS(60), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      aux_sym_parameter_list_repeat1,
  [191] = 3,
    ACTIONS(11), 1,
      anon_sym_LBRACE,
    ACTIONS(62), 1,
      anon_sym_LF,
    STATE(31), 1,
      sym_block,
  [201] = 2,
    STATE(26), 1,
      sym_identifier,
    ACTIONS(64), 2,
      aux_sym_identifier_token1,
      anon_sym__,
  [209] = 3,
    ACTIONS(58), 1,
      anon_sym_COMMA,
    ACTIONS(66), 1,
      anon_sym_RPAREN,
    STATE(17), 1,
      aux_sym_parameter_list_repeat1,
  [219] = 3,
    ACTIONS(68), 1,
      anon_sym_COMMA,
    ACTIONS(71), 1,
      anon_sym_RPAREN,
    STATE(21), 1,
      aux_sym_parameter_list_repeat1,
  [229] = 1,
    ACTIONS(73), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [234] = 2,
    ACTIONS(75), 1,
      anon_sym_LF,
    ACTIONS(77), 1,
      anon_sym_LBRACE,
  [241] = 1,
    ACTIONS(71), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [246] = 1,
    ACTIONS(44), 2,
      ts_builtin_sym_end,
      anon_sym_fn,
  [251] = 2,
    ACTIONS(79), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_parameter_list,
  [258] = 1,
    ACTIONS(75), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [263] = 1,
    ACTIONS(81), 1,
      anon_sym_RBRACE,
  [267] = 1,
    ACTIONS(83), 1,
      anon_sym_LF,
  [271] = 1,
    ACTIONS(85), 1,
      anon_sym_LF,
  [275] = 1,
    ACTIONS(87), 1,
      anon_sym_LF,
  [279] = 1,
    ACTIONS(89), 1,
      anon_sym_LF,
  [283] = 1,
    ACTIONS(91), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 23,
  [SMALL_STATE(8)] = 46,
  [SMALL_STATE(9)] = 69,
  [SMALL_STATE(10)] = 92,
  [SMALL_STATE(11)] = 106,
  [SMALL_STATE(12)] = 118,
  [SMALL_STATE(13)] = 132,
  [SMALL_STATE(14)] = 144,
  [SMALL_STATE(15)] = 158,
  [SMALL_STATE(16)] = 170,
  [SMALL_STATE(17)] = 181,
  [SMALL_STATE(18)] = 191,
  [SMALL_STATE(19)] = 201,
  [SMALL_STATE(20)] = 209,
  [SMALL_STATE(21)] = 219,
  [SMALL_STATE(22)] = 229,
  [SMALL_STATE(23)] = 234,
  [SMALL_STATE(24)] = 241,
  [SMALL_STATE(25)] = 246,
  [SMALL_STATE(26)] = 251,
  [SMALL_STATE(27)] = 258,
  [SMALL_STATE(28)] = 263,
  [SMALL_STATE(29)] = 267,
  [SMALL_STATE(30)] = 271,
  [SMALL_STATE(31)] = 275,
  [SMALL_STATE(32)] = 279,
  [SMALL_STATE(33)] = 283,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 3, .production_id = 1),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [13] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(3),
  [16] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2),
  [18] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [20] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 2),
  [22] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [24] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_identifier, 1),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 4),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parameter_list, 4),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 2),
  [32] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parameter_list, 2),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parameter_list, 3),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(19),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_identifier_repeat1, 2), SHIFT_REPEAT(15),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 4, .production_id = 2),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(16),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_declaration, 2, .production_id = 4),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_identifier, 1),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_identifier, 1),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 4, .production_id = 3),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declaration, 5, .production_id = 5),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [91] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
