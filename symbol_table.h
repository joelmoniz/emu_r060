#ifndef LEXEMES_H
#define LEXEMES_H
#include "lexemes.h"
#endif

#define HASH_SIZE 50
#define MAX_BRANCHING 15

#define MAX_RETURN_VALUES 5
#define MAX_ARGS 5
#define MAX_LHS_ASSIGNMENTS 3

typedef struct _function_details function_details;

typedef union _data_val {
  int i;
  int bln;
  float f;
  function_details *fn;
} data_val;

typedef struct _referred {
  int depth;
  int breadth;
  struct _referred *next;
} referred;

typedef enum _var_type {
  vt_unk,
  variable,
  parameter,
  argument,
  return_val
} var_type;

typedef enum _data_type { // the value of the enum represents the size of the data type
  dt_unk = -1,
  function = 0,
  integer = 2,
  float_point = 4,
  Point = 8,
  Bot = 16,
  boolean = 1
} data_type;

struct _function_details {
  data_type args[MAX_ARGS];
  data_type ret_vals[MAX_RETURN_VALUES];
  char *arg_names[MAX_ARGS];
  int num_args;
  int num_ret_vals;
};

typedef struct _id_type {
  data_type dtype;
  char *name;
  int array_dim1[2]; // {0,0} => not an array
} id_type;

void print_var_type(var_type v);
void print_data_type(data_type d);

typedef struct _symbol_entry symbol_entry;
typedef struct _symbol_table_node symbol_table_node;

// Eg: int my_int = 42;
struct _symbol_entry {
  char *name; // my_int
  data_type dtype; // integer
  int depth, breadth; // line 27, character 5
  referred *refd; // linked list indicating lines and locations where my_int has been used
  var_type vtype; // variable
  symbol_table_node *container;
  data_val *dval;
  symbol_entry *next;
};

struct _symbol_table_node {
  symbol_table_node *parent;
  symbol_table_node *children[MAX_BRANCHING];
  int num_children; // how many children it has
  int level;
  int breadth; // how many "elder siblings" it has => not really valid; keeping for 
               // easy visualization
  symbol_entry *symbol_table_hash[HASH_SIZE];
};

symbol_table_node *symbol_table_root;

symbol_table_node *initialize_symbol_table_root();
symbol_table_node *initialize_symbol_table_node(symbol_table_node *parent);
symbol_table_node *add_new_node_to_parent(symbol_table_node *parent);
void add_ID_to_sym_table_node(symbol_table_node *node, char *name, data_type dt);
void update_st_function(char fn_name[], symbol_table_node *node, function_details *func_info);
function_details *get_function_details(symbol_table_node *node, char *func_name);
void init_symbol_table(symbol_entry *symbol_table_hash[]);
void free_symbol_table(symbol_entry *symbol_table_hash[]);
void print_symbol_table_tree(symbol_table_node *node);
void print_symbol_table(symbol_entry *symbol_table_hash[]);

int get_hash_value(unsigned char *name);
