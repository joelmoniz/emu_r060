#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "symbol_table.h"
#endif

#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

#ifndef LEXEMES_H
#define LEXEMES_H
#include "lexemes.h"
#endif

#ifndef QUEUES_H
#define QUEUES_H
#include "queues.h"
#endif

typedef enum _op_type {
  arithm_op,
  bool_op,
  reln_op,
  bot_op,
  point_op,
  assign_op,
  unary_op,
  unk // error
} op_type;

op_type get_op_type(int op);
data_type get_and_check_type(parse_tree_node *node, int is_an_expression);
