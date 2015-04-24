#ifndef STANDARD_H
#define STANDARD_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#endif

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

#ifndef SEMANTIC_TYPE_H
#define SEMANTIC_TYPE_H
#include "semantic_type_analysis.h"
#endif

op_type get_op_type(int op) {
  switch(op) {
    case tk_plus:
    case tk_minus:
    case tk_mul:
    case tk_div: return arithm_op;
    case tk_rt:
    case tk_fw: return bot_op;
    case tk_log_or:
    case tk_log_and: return bool_op;
    case tk_lt:
    case tk_gt:
    case tk_log_eq:
    case tk_lte:
    case tk_gte: return reln_op;
    case tk_addv: return point_op;
    case tk_pl_eq: return assign_op;
    case tk_unary_inc:
    case tk_unary_dec:
    case tk_readi: return unary_op;
    default: return unk;
  }
}

data_type get_and_check_type(parse_tree_node *node, int is_an_expression) {
  if (node->num_child == 0) {
    switch(node->token_id) {
      case tk_num: return integer;
      case tk_rnum: return float_point;
      case tk_true:
      case tk_false: return boolean;
      case tk_id:
        if (node->value.id->dtype != function)
          return node->value.id->dtype;
        else {
          if (node->value.id->dval->fn->num_ret_vals == 1)
            return node->value.id->dval->fn->ret_vals[0];
          else if (is_an_expression) {
            printf("\nError: Function %s may not be used in an expression, since it returns multiple values.\n", node->value.id->name);
          }
        }
    }
  }

  return dt_unk;
  // data_type left = get_and_check_type()
}

void prevent_func_call_and_recursion(parse_tree_node *node) {
  printf("\n\n");
  print_rule(node->token_id);
}

void function_call_semanticize() {
  int i;
  for (i=0; i<parse_root->num_child; i++) {
    if (parse_root->children[i]->token_id == tk_otherFunctions) {
      parse_tree_node *node = parse_root->children[i];
      while (node->children[1]->token_id != tk_func) {
        if (node->children[0]->token_id == tk_func) {
          prevent_func_call_and_recursion(node->children[0]);
          node = node->children[1];
        }
        else {
          // printf("\n\nOUCH: ");print_rule(node->token_id);
          // printf("   ");print_rule(node->children[0]->token_id);
          break;
        }
      }
      prevent_func_call_and_recursion(node->children[0]);
      prevent_func_call_and_recursion(node->children[1]);
      break;
    }
    else if (parse_root->children[i]->token_id == tk_func) {
      prevent_func_call_and_recursion(parse_root->children[i]);
      break;
    }
  }
}