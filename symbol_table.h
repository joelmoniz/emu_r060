#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

#ifndef LEXEMES_H
#define LEXEMES_H
#include "lexemes.h"
#endif

#define HASH_SIZE 50
#define MAX_BRANCHING 15

typedef union _data_val {
  int i;
  int bln;
  float f;
} data_val;

typedef struct _referred {
  int depth;
  int breadth;
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
  int depth, breadth; // line 27, character 5
  referred *refd; // linked list indicating lines and locations where my_int has been used
  var_type misc; // variable
  struct _symbol_entry *next;
} symbol_entry;

typedef struct _symbol_table_node {
  struct _symbol_table_node *parent;
  struct _symbol_table_node *children[MAX_BRANCHING];
  int num_children; // how many children it has
  int level;
  int breadth; // how many "elder siblings" it has
  symbol_entry *symbol_table_hash[HASH_SIZE];
} symbol_table_node;

symbol_table_node *symbol_table_root;

symbol_table_node *initialize_symbol_table_root();
symbol_table_node *initialize_symbol_table_node(symbol_table_node *parent);
symbol_table_node *add_new_node_to_parent(symbol_table_node *parent);
void add_ID_to_sym_table_node(symbol_table_node *node, char *name);
void init_symbol_table(symbol_entry *symbol_table_hash[]);
void free_symbol_table(symbol_entry *symbol_table_hash[]);
void print_symbol_table_tree(symbol_table_node *node);
void print_symbol_table(symbol_entry *symbol_table_hash[]);

int get_hash_value(unsigned char *name);
