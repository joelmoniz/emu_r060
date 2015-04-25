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
          // print_data_type(node->value.id->dtype);
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
        if (left_child == integer) {
          if (right_child == integer)
            return boolean;
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
            return boolean;
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
            return boolean;
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
            return boolean;
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

void check_function_call_and_assignment(parse_tree_node *node) {
  int ret_n = 0;
  int arg_n = 0;
  int rhs_n = 0;
  int is_assignment = 0;
  // int return_early = 0;
  data_type ret_vals[MAX_RETURN_VALUES];
  data_type arg_vals[MAX_ARGS];
  data_type rhs_vals[MAX_LHS_ASSIGNMENTS];
  parse_tree_node *arglist_node;
  parse_tree_node *temp = node;
  if (node->children[1]->token_id == tk_arg_list && node->children[0]->value.id->dtype == function) {
    if (node->children[0]->value.id->dval->fn->num_ret_vals != 0) {
      printf("Error: The function %s returns %d values, but none of these values are assigned\n",
        temp->children[0]->value.id->name, temp->children[0]->value.id->dval->fn->num_ret_vals);
    }
    arglist_node = node->children[1];
  }
  else {
    if (temp->token_id == tk_col_assign)
      return;

    while (temp->children[0]->token_id == tk_id) {
      if (temp->children[0]->token_id == tk_col_assign || temp->children[1]->token_id == tk_col_assign)
        return;
      ret_vals[ret_n] = get_and_check_type(temp->children[0],1);
      ret_n++;
      temp = temp->children[1];
    }

    if (temp->children[1]->token_id != tk_value) {
      // if (temp->children[1]->token_id == tk_id && temp->children[1]->value.id != NULL 
      //   && temp->children[1]->value.id->dtype == function) {
      //   temp = temp->children[1];
      //   return_early = 1;
      // }
      // else {
        is_assignment = 1;
        temp = temp->children[1];//->children[1];
      // }
    }
    else
      temp = temp->children[1]->children[0];

    if (!is_assignment) {
      if (ret_n != temp->value.id->dval->fn->num_ret_vals) {
        printf("Error in function call %s: Returns %d value(s), but assigned to %d instead\n", 
          temp->value.id->name, temp->value.id->dval->fn->num_ret_vals, ret_n);
      }
      else {
        int i;
        // temp = temp->children[0];
        for (i=0; i<ret_n; i++) {
          if (temp->value.id->dval->fn->ret_vals[i] != ret_vals[i]) {
            printf("Error in function call %s: Return values are of type", 
              temp->value.id->name);
            int j;
            for (j=0; j<ret_n-1; j++) {
              print_data_type(temp->value.id->dval->fn->ret_vals[j]);
              printf(",");
            }
            print_data_type(temp->value.id->dval->fn->ret_vals[j]);
            printf(" but the variables they are assigned to are of the type\n");
            for (j=0; j<ret_n-1; j++) {
              print_data_type(ret_vals[j]);
              printf(",");
            }
            print_data_type(ret_vals[j]);
            printf("\n");
            break;
          }
        }
      }

      // if (return_early)
      //   return;

      // parse_tree_node *temp2 = temp;
      // temp2 = temp2->parent;
      // if (temp2->num_child <= 1 && temp2->children[0]->value.id->dval->fn->num_args != 0) {
      //   printf("Error: The function %s expects %d arguments, but no arguments were passed\n",
      //     temp2->children[0]->value.id->name, temp2->children[0]->value.id->dval->fn->num_args);
      // }
      // else if (temp2->num_child >= 1) {
      //   temp2 = temp2->children[1];//->children[1];
      //   while (temp2->num_child > 3) {
      //     arg_vals[arg_n] = get_and_check_type(temp2->children[2],1);
      //     arg_n++;
      //     temp2 = temp2->children[3];
      //   }
      //   arg_vals[arg_n] = get_and_check_type(temp2->children[2],1);
      //   arg_n++;

      //   if (arg_n != temp->value.id->dval->fn->num_args) {
      //     printf("Error in function call %s: Expects %d argument(s), but provided %d arguments instead\n", 
      //       temp->value.id->name, temp->value.id->dval->fn->num_args, arg_n);
      //   }
      //   else {
      //     int i;
      //     // temp = temp->children[0];
      //     for (i=0; i<arg_n; i++) {
      //       if (temp->value.id->dval->fn->args[i] != arg_vals[i]) {
      //         printf("Error in function call %s: Arguments expected are of type", 
      //           temp->value.id->name);
      //         int j;
      //         for (j=0; j<arg_n-1; j++) {
      //           print_data_type(temp->value.id->dval->fn->args[j]);
      //           printf(",");
      //         }
      //         print_data_type(temp->value.id->dval->fn->args[j]);
      //         printf(" but the arguments provided are of the type\n");
      //         for (j=0; j<arg_n-1; j++) {
      //           print_data_type(arg_vals[j]);
      //           printf(",");
      //         }
      //         print_data_type(arg_vals[j]);
      //         printf("\n");
      //         break;
      //       }
      //     }
      //   }
      // }

    }
    else {
      // if (temp->parent->token_id != tk_assign_op) 
      //   return;
      if (ret_n > MAX_LHS_ASSIGNMENTS) {
        printf("Error: Too many variables (%d) on LHS: Maximum permissible number is %d\n", ret_n, MAX_LHS_ASSIGNMENTS);
      }
      else if (temp->token_id != tk_righHandSide) {
        rhs_n = 1;
        rhs_vals[0] = get_and_check_type(temp,1);
      }
      else {
        // temp = temp->children[1];
        printf("%d variable assignment\n",ret_n);
        while (temp->children[1]->token_id == tk_righHandSide || temp->children[1]->token_id == tk_righHandSideMultiple) {
          rhs_vals[rhs_n] = get_and_check_type(temp->children[0],1);
          rhs_n++;
          temp = temp->children[1];
        }
        rhs_vals[rhs_n] = get_and_check_type(temp->children[0],1);
        rhs_n++;
        rhs_vals[rhs_n] = get_and_check_type(temp->children[1],1);
        rhs_n++;
      }

      if (ret_n != rhs_n) {
        printf("Error in multiple assignment statement: %d value(s) found in LHS, but %d found on RHS\n", 
          ret_n, rhs_n);
      }
      else {
        int i;
        // temp = temp->children[0];
        for (i=0; i<ret_n; i++) {
          if (rhs_vals[i] != ret_vals[i]) {
            printf("Error in multiple assignment statement: Values are of type");
            int j;
            for (j=0; j<ret_n-1; j++) {
              print_data_type(rhs_vals[j]);
              printf(",");
            }
            print_data_type(rhs_vals[j]);
            printf(" on the RHS, but they have been assigned to variables of the type");
            for (j=0; j<ret_n-1; j++) {
              print_data_type(ret_vals[j]);
              printf(",");
            }
            print_data_type(ret_vals[j]);
            printf(" on the LHS\n");
            break;
          }
        }
      }
    }

  }
}

void check_expression_types(parse_tree_node *node) {
  // printf("\n\n");
  // print_rule(node->token_id);
  int i;
  for (i=0;i<node->num_child;i++) {
    if (get_op_type(node->children[i]->token_id) != unk && node->token_id != tk_return) {
      data_type d = get_and_check_type(node->children[i],1);
      printf("Datatype for ");
      print_rule(node->token_id);
      printf("is");
      print_data_type(d);
      printf("\n");
    }
    else if (node->children[i]->token_id == tk_gen_stmt) {
      check_function_call_and_assignment(node->children[i]);
    }
    else if (node->children[i]->token_id == tk_for) {
      data_type d = get_and_check_type(node->children[i]->children[1], 1);
      if (d != boolean) {
        printf("Error: Expected conditional part of for loop to be a boolean expression, instead found a(n)");
        print_data_type(d);
        printf("\n");
      }
      check_expression_types(node->children[i]);
    }
    else if (node->children[i]->token_id == tk_if) {
      data_type d = get_and_check_type(node->children[i]->children[0], 1);
      if (d != boolean) {
        printf("Error: Expected conditional expression in if statement to be a boolean expression, instead found a(n)");
        print_data_type(d);
        printf("\n");
      }
      check_expression_types(node->children[i]);
    }
    else if (node->token_id == tk_stmts && node->children[i]->token_id == tk_id) {
      if (node->children[i]->value.id != NULL && node->children[i]->value.id->dtype == function 
        && node->children[i]->value.id->dval->fn->num_ret_vals != 0) {
        printf("Error: The function %s returns %d values, but none of these values are assigned\n",
        node->children[i]->value.id->name, node->children[i]->value.id->dval->fn->num_ret_vals);
      }
      check_expression_types(node->children[i]);
    }
    else
      check_expression_types(node->children[i]);
  }
}

void check_individ_function_return(parse_tree_node *node) {
  parse_tree_node *ret_node = node->children[node->num_child-1];
  while (ret_node->token_id != tk_return)
    ret_node = ret_node->children[1];
  if (node->children[1]->value.id->dval->fn->num_ret_vals > MAX_RETURN_VALUES)
    return;
  int n = 0;
  data_type ret_vals[MAX_RETURN_VALUES];
  if (ret_node->num_child == 1) {
    n = 1;
    ret_vals[n-1] = get_and_check_type(ret_node->children[0], 1);
  }
  else {
    while (ret_node->children[1]->token_id == tk_more_expression) {
      n++;
      ret_vals[n-1] = get_and_check_type(ret_node->children[0], 1);
      ret_node = ret_node->children[1];
    }
    n++;
    ret_vals[n-1] = get_and_check_type(ret_node->children[0], 1);
    n++;
    ret_vals[n-1] = get_and_check_type(ret_node->children[1], 1);
  }

  if (n != node->children[1]->value.id->dval->fn->num_ret_vals) {
    printf("Error in function %s: Expecting %d return value(s), but found %d instead\n", 
      node->children[1]->value.id->name, node->children[1]->value.id->dval->fn->num_ret_vals, n);
  }
  else {
    int i;
    for (i=0; i<n; i++) {
      if (node->children[1]->value.id->dval->fn->ret_vals[i] != ret_vals[i]) {
        printf("Error in function %s: Expecting return values of type", 
          node->children[1]->value.id->name);
        int j;
        for (j=0; j<n-1; j++) {
          print_data_type(node->children[1]->value.id->dval->fn->ret_vals[j]);
          printf(",");
        }
        print_data_type(node->children[1]->value.id->dval->fn->ret_vals[j]);
        printf(" but the values actually returned are of the type");
        for (j=0; j<n-1; j++) {
          print_data_type(ret_vals[j]);
          printf(",");
        }
        print_data_type(ret_vals[j]);
        printf("\n");
        break;
      }
    }
  }
}

void check_function_returns() {
  int i;
  parse_tree_node *node = parse_root;
  for (i=0; i<node->num_child; i++) {
    if (parse_root->children[i]->token_id == tk_otherFunctions) {
      node = parse_root->children[i];
      while (node->children[1]->token_id != tk_func) {
        if (node->children[0]->token_id == tk_func) {
          check_individ_function_return(node->children[0]);
          node = node->children[1];
        }
        else {
          // printf("\n\nOUCH: ");print_rule(node->token_id);
          // printf("   ");print_rule(node->children[0]->token_id);
          break;
        }
      }
      check_individ_function_return(node->children[0]);
      check_individ_function_return(node->children[1]);
      break;
    }
    else if (parse_root->children[i]->token_id == tk_func) {
      check_individ_function_return(parse_root->children[i]);
      break;
    }
  }
}