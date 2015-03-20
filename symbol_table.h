#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

#ifndef LEXEMES_H
#define LEXEMES_H
#include "lexemes.h"
#endif

#define hash_size  1000

typedef union _data_val {
  int i;
  int bln;
  float f;
} data_val;

typedef struct _referred {
  int line;
  int loc;
  struct _referred *next;
} referred;

typedef enum _data_type {
  dt_unk,
  integer,
  float_point,
  boolean
} data_type;

typedef enum _var_type {
  vt_unk,
  variable,
  parameter,
  argument,
  return_val
} var_type;

// Eg: int my_int = 42;
typedef struct _symbol_entry {
  char *name; // my_int
  TOK token_type; // TK_ID
  data_type dtype; // integer
  data_val value; // 42
  int has_value; // 1 (represents if valid value is held)
  int size; // 2 (bytes)
  int scope; // number represting scope
  int declared_line, declared_position; // line 27, character 5
  referred *refd; // linked list indicating lines and locations where my_int has been used
  var_type misc; // variable
  struct _symbol_entry *next;
} symbol_entry;

symbol_entry *symbol_table_hash[hash_size];

int get_hash_value(unsigned char *name);
