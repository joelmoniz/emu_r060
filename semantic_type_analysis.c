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
    case tk_log_or:
    case tk_log_and: return bool_op;
    case tk_lt:
    case tk_gt:
    case tk_log_eq:
    case tk_lte:
    case tk_gte: return reln_op;
    case tk_unary_inc:
    case tk_unary_dec: return unary_op;
    case tk_expression_more: return typecast_op;

    // the following wont come in the picture
    case tk_pl_eq: return assign_op;
    case tk_addv: return point_op;
    case tk_readi: return read_op;
    case tk_rt:
    case tk_fw: return bot_op;
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
        if (node->value.id->dtype != function) {
          print_data_type(node->value.id->dtype);
          return node->value.id->dtype;
        }
        else {
          if (node->value.id->dval->fn->num_ret_vals == 1)
            return node->value.id->dval->fn->ret_vals[0];
          else if (is_an_expression) {
            printf("Error: Function %s may not be used in an expression, since it returns multiple values.\n", node->value.id->name);
          }
        }
        break;
      default:
        if (!is_datatype(node->token_id)) {
          printf("Unrecognized token in expression: ");
          print_rule(node->token_id);
          printf("\n");
        }
        else {
          switch (node->token_id) {
            case tk_int: return integer;
            case tk_float: return float_point;
            case tk_bot: return Bot;
            case tk_point: return Point;
            case tk_boolean: return boolean;
          }
        }
        break;
    }
  }
  else if (node->num_child == 1) {
    data_type child = get_and_check_type(node->children[0], 1);
    switch(get_op_type(node->token_id)) {
      case unary_op: 
        if (child != integer) {
          if (child != dt_unk) {
            printf("Type Error: Cannot use ");
            print_rule(node->children[0]->token_id);
            printf("of type");
            print_data_type(child);
            printf(" with the unary operator ");
            print_rule(node->token_id);
            printf("\n");
          }
          return dt_unk;
        }
        else
          return integer;
    }
  }
  else if (node->num_child == 2) {
    data_type left_child = get_and_check_type(node->children[0], 1);
    data_type right_child = get_and_check_type(node->children[1], 1);
    switch(get_op_type(node->token_id)) {
      case reln_op:
      case arithm_op:
        if (left_child == integer) {
          if (right_child == integer)
            return integer;
          else if (right_child == float_point) {
            printf("Type Warning: Implicit conversion of ");
            print_rule(node->children[0]->token_id);
            printf("of type");
            print_data_type(left_child);
            printf(" into type");
            print_data_type(right_child);
            printf(" for the binary operator ");
            print_rule(node->token_id);
            printf("\n");
            return float_point;
          }
          else if (right_child != dt_unk){
            printf("Type Error: Cannot use ");
            print_rule(node->children[1]->token_id);
            printf("of type");
            print_data_type(right_child);
            printf(" with the binary operator ");
            print_rule(node->token_id);
            printf("\n");
            return dt_unk;
          }
        }
        else if (left_child == float_point) {
          if (right_child == float_point)
            return float_point;
          else if (right_child == integer) {
            printf("Type Warning: Implicit conversion of ");
            print_rule(node->children[1]->token_id);
            printf("of type");
            print_data_type(right_child);
            printf(" into type");
            print_data_type(left_child);
            printf(" for the arithmetic operator ");
            print_rule(node->token_id);
            printf("\n");
            return float_point;
          }
          else if (right_child != dt_unk){
            printf("Type Error: Cannot use ");
            print_rule(node->children[1]->token_id);
            printf("of type");
            print_data_type(right_child);
            printf(" with the binary operator ");
            print_rule(node->token_id);
            printf("\n");
            return dt_unk;
          }
        }
        else if (left_child != dt_unk) {
          printf("Type Error: Cannot use ");
          print_rule(node->children[0]->token_id);
          printf("of type");
          print_data_type(left_child);
          printf(" with the binary operator ");
          print_rule(node->token_id);
          printf("\n");
          return dt_unk;
        }
        break;
      case bool_op:
        if (left_child != boolean && left_child != dt_unk) {
          printf("Type Error: Cannot use ");
          print_rule(node->children[0]->token_id);
          printf("of type");
          print_data_type(left_child);
          printf(" with the binary operator ");
          print_rule(node->token_id);
          printf("\n");
          return dt_unk;
        }
        else if (right_child != boolean && right_child != dt_unk) {
          printf("Type Error: Cannot use ");
          print_rule(node->children[1]->token_id);
          printf("of type");
          print_data_type(right_child);
          printf(" with the binary operator ");
          print_rule(node->token_id);
          printf("\n");
          return dt_unk;
        }
        else if (left_child == boolean && right_child == boolean) {
          return boolean;
        }
        break;
      case typecast_op: 
        if (left_child == float_point) {
          if (right_child == integer || right_child == float_point)
            return float_point;
          else if (right_child != dt_unk) {
            printf("Type Error: Cannot typecast ");
            print_rule(node->children[1]->token_id);
            printf("of type");
            print_data_type(right_child);
            printf(" into the type float");
            printf("\n");
            return dt_unk;
          }
        }
        else if (left_child == integer) {
          if (right_child == integer || right_child == float_point)
            return integer;
          else if (right_child != dt_unk) {
            printf("Type Error: Cannot typecast ");
            print_rule(node->children[1]->token_id);
            printf("of type");
            print_data_type(right_child);
            printf(" into the type int");
            printf("\n");
            return dt_unk;
          }
        }
        else {
          printf("Type Error: Cannot have a typecast of the type");
          print_data_type(left_child);
          printf("\n");  
          return dt_unk;        
        }
    }
  }

  return dt_unk;
  // data_type left = get_and_check_type()
}

void check_expression_types(parse_tree_node *node) {
  // printf("\n\n");
  // print_rule(node->token_id);
  int i;
  for (i=0;i<node->num_child;i++) {
    if (get_op_type(node->children[i]->token_id) != unk) {
      data_type d = get_and_check_type(node->children[i],1);
      printf("\nDatatype for ");
      print_rule(node->token_id);
      printf("is");
      print_data_type(d);
      printf("\n");
    }
    else
      check_expression_types(node->children[i]);
  }
}

void prevent_func_call_and_recursion(parse_tree_node *node) {
  ;
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