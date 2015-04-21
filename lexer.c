#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "symbol_table.h"

#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

#ifndef LEXEMES_H
#define LEXEMES_H
#include "lexemes.h"
#endif

#define BUFFER_SIZE 100

#define OUTPUT_LEXER 1

//Need to do only one pass!
//What was that joey blabbering about reading in blocks?
// even signs could be delimiters eg 4+3, a+b .etc - taken care of 
// what about ! and != ??
// @~ is a multi-line comment
//TODO: uncomment the code to read in a text file, right now its defaulting to test.txt
//changes made here: writing into op (.lexer output) as integer so its easier to read out 

int isSymbol(char input)
{
  if(input==' ' || input=='+' || input=='-' || input=='*' || input=='/' || input=='[' || input==']' ||
      input=='{' || input=='}' || input=='(' || input==')' || input=='@' || input==';' || input=='=' ||
      input=='.' || input=='-' || input==':' || input=='-' || input=='|' || input=='&' || input=='>' ||
      input=='<' || input=='_' || input == ',') return 1;
    else
      return 0;

}

void writeTofile(FILE* op, enum Token token)
{
  if (OUTPUT_LEXER) {
    fprintf(op, "%d ", token);
  }
  insert(&lexer_queue, token);
  print_token(token);
}

void print_token(enum Token token) {
  switch(token)
  {
   case tk_main:
   printf( "<tk_main> " );
   break;
   case tk_lbrace:
   printf( "<tk_lbrace> " );
   break;
   case tk_rbrace:
   printf( "<tk_rbrace> " );
   break;
   case tk_lpara:
   printf( "<tk_lpara> " );
   break;
   case tk_rpara:
   printf( "<tk_rpara> " );
   break;
   case tk_lsquare:
   printf( "<tk_lsquare> " );
   break;
   case tk_rsquare:
   printf( "<tk_rsquare> " );
   break;
   case tk_struct:
   printf( "<tk_struct> " );
   break;
   case tk_comment:
   printf( "<tk_comment> " );
   break;
   case tk_semi_cl:
   printf( "<tk_semi_cl> " );
   break;
   case tk_assign_op:
   printf( "<tk_assign_op> " );
   break;
   case tk_id:
   printf( "<tk_id> " );
   break;
   case tk_comma:
   printf( "<tk_comma> " );
   break;
   case tk_num:
   printf( "<tk_num> " );
   break;
   case tk_rnum:
   printf( "<tk_rnum> " );
   break;
   case tk_boolean:
   printf( "<tk_boolean> " );
   break;
   case tk_bot:
   printf( "<tk_bot> " );
   break;
   case tk_velocity:
   printf( "<tk_velocity> " );
   break;
   case tk_col_assign:
   printf( "<tk_col_assign> " );
   break;
   case tk_int:
   printf( "<tk_int> " );
   break;
   case tk_float:
   printf( "<tk_float> " );
   break;
   case tk_dot:
   printf( "<tk_dot> " );
   break;
   case tk_colon:
   printf( "<tk_colon> " );
   break;
   case tk_log_or:
   printf( "<tk_log_or> " );
   break;
   case tk_log_and:
   printf( "<tk_log_and> " );
   break;
   case tk_lt:
   printf( "<tk_lt> " );
   break;
   case tk_gt:
   printf( "<tk_gt> " );
   break;
   case tk_log_eq:
   printf( "<tk_log_eq> " );
   break;
   case tk_lte:
   printf( "<tk_lte> " );
   break;
   case tk_gte:
   printf( "<tk_gte> " );
   break;
   case tk_func:
   printf( "<tk_func> " );
   break;
   case tk_return:
   printf( "<tk_return> " );
   break;
   case tk_rt:
   printf( "<tk_rt> " );
   break;
   case tk_addv:
   printf( "<tk_addv> " );
   break;
   case tk_pl_eq:
   printf( "<tk_pl_eq> " );
   break;
   case tk_true:
   printf( "<tk_true> " );
   break;
   case tk_false:
   printf( "<tk_false> " );
   break;
   case tk_inpop:
   printf( "<tk_inpop> " );
   break;
   case tk_unary_inc:
   printf( "<tk_unary_inc> " );
   break;
   case tk_unary_dec:
   printf( "<tk_unary_dec> " );
   break;
   case tk_undersc:
   printf( "<tk_ tk_undersc> " );
   break;
   case tk_fw:
   printf( "<tk_fw> " );
   break;
   case tk_point:
   printf( "<tk_point> " );
   break;
   case tk_void:
   printf( "<tk_void> " );
   break;
   case tk_readi:
   printf( "<tk_readi> " );
   break;
   case tk_break:
   printf( "<tk_break> " );
   break;
   case tk_continue:
   printf( "<tk_continue> " );
   break;
   case tk_exit:
   printf( "<tk_exit> " );
   break;
   case tk_for:
   printf( "<tk_for> " );
   break;
   case tk_if:
   printf( "<tk_if> " );
   break;
   case tk_else:
   printf( "<tk_else> " );
   break;
   case tk_plus:
   printf( "<tk_plus> " );
   break;
   case tk_minus:
   printf( "<tk_minus> " );
   break;
   case tk_mul:
   printf( "<tk_mul> " );
   break;
   case tk_div:
   printf( "<tk_div> " );
   break;
   default:
   printf("%d ", token);
   break;    
  } 
}

void print_rule(enum Token rule) {
  switch (rule) {
    case tk_program:
      printf("<tk_program> ");
      break;
    case tk_mainFunction:
      printf("<tk_mainFunction> ");
      break;
    case tk_stmts:
      printf("<tk_stmts> ");
      break;
    case tk_stmt:
      printf("<tk_stmt> ");
      break;
    case tk_loop_stmts:
      printf("<tk_loop_stmts> ");
      break;
    case tk_loop_stmt:
      printf("<tk_loop_stmt> ");
      break;
    case tk_lp_stmt:
      printf("<tk_lp_stmt> ");
      break;
    case tk_global_vars:
      printf("<tk_global_vars> ");
      break;
    case tk_global_assignment:
      printf("<tk_global_assignment> ");
      break;
    case tk_gen_stmt:
      printf("<tk_gen_stmt> ");
      break;
    case tk_other_stmt:
      printf("<tk_other_stmt> ");
      break;
    case tk_func_ass:
      printf("<tk_func_ass> ");
      break;
    case tk_unary_stmts:
      printf("<tk_unary_stmts> ");
      break;
    case tk_unary_stmt_more:
      printf("<tk_unary_stmt_more> ");
      break;
    case tk_primitive_declaration_stmt:
      printf("<tk_primitive_declaration_stmt> ");
      break;
    case tk_assign_more:
      printf("<tk_assign_more> ");
      break;
    case tk_assign_comma:
      printf("<tk_assign_comma> ");
      break;
    case tk_array2:
      printf("<tk_array2> ");
      break;
    case tk_assign_2d:
      printf("<tk_assign_2d> ");
      break;
    case tk_curly_values:
      printf("<tk_curly_values> ");
      break;
    case tk_meta_curly:
      printf("<tk_meta_curly> ");
      break;
    case tk_more_curliness:
      printf("<tk_more_curliness> ");
      break;
    case tk_point_decl_stmt:
      printf("<tk_point_decl_stmt> ");
      break;
    case tk_pv_rest:
      printf("<tk_pv_rest> ");
      break;
    case tk_bot_decl_stmt:
      printf("<tk_bot_decl_stmt> ");
      break;
    case tk_bot_rest:
      printf("<tk_bot_rest> ");
      break;
    case tk_assign_operators:
      printf("<tk_assign_operators> ");
      break;
    case tk_type:
      printf("<tk_type> ");
      break;
    case tk_type_list:
      printf("<tk_type_list> ");
      break;
    case tk_type_more:
      printf("<tk_type_more> ");
      break;
    case tk_primitive_type:
      printf("<tk_primitive_type> ");
      break;
    case tk_bot_type:
      printf("<tk_bot_type> ");
      break;
    case tk_assignment_stmt:
      printf("<tk_assignment_stmt> ");
      break;
    case tk_leftHandSide1:
      printf("<tk_leftHandSide1> ");
      break;
    case tk_bot_point1:
      printf("<tk_bot_point1> ");
      break;
    case tk_bot_or_point:
      printf("<tk_bot_or_point> ");
      break;
    case tk_idNum:
      printf("<tk_idNum> ");
      break;
    case tk_leftHandSideMultiple:
      printf("<tk_leftHandSideMultiple> ");
      break;
    case tk_righHandSide:
      printf("<tk_righHandSide> ");
      break;
    case tk_righHandSideMultiple:
      printf("<tk_righHandSideMultiple> ");
      break;
    case tk_var:
      printf("<tk_var> ");
      break;
    case tk_array:
      printf("<tk_array> ");
      break;
    case tk_brack_pair1:
      printf("<tk_brack_pair1> ");
      break;
    case tk_array2d:
      printf("<tk_array2d> ");
      break;
    case tk_values:
      printf("<tk_values> ");
      break;
    case tk_values_more:
      printf("<tk_values_more> ");
      break;
    case tk_value:
      printf("<tk_value> ");
      break;
    case tk_value_rest:
      printf("<tk_value_rest> ");
      break;
    case tk_funcCall_inside_Value:
      printf("<tk_funcCall_inside_Value> ");
      break;
    case tk_funcCall_inside_Value_rest:
      printf("<tk_funcCall_inside_Value_rest> ");
      break;
    case tk_idBool:
      printf("<tk_idBool> ");
      break;
    case tk_bool:
      printf("<tk_bool> ");
      break;
    case tk_const_value:
      printf("<tk_const_value> ");
      break;
    case tk_loop_condnal_stmt:
      printf("<tk_loop_condnal_stmt> ");
      break;
    case tk_loop_condnal_stmt_more:
      printf("<tk_loop_condnal_stmt_more> ");
      break;
    case tk_loop_condnal_stmt_even_more:
      printf("<tk_loop_condnal_stmt_even_more> ");
      break;
    case tk_condnal_stmt:
      printf("<tk_condnal_stmt> ");
      break;
    case tk_condnal_stmt_suffix:
      printf("<tk_condnal_stmt_suffix> ");
      break;
    case tk_condnal_stmt_more:
      printf("<tk_condnal_stmt_more> ");
      break;
    case tk_condnal_stmt_even_more:
      printf("<tk_condnal_stmt_even_more> ");
      break;
    case tk_expressions:
      printf("<tk_expressions> ");
      break;
    case tk_more_expression:
      printf("<tk_more_expression> ");
      break;
    case tk_array_arithm_expr:
      printf("<tk_array_arithm_expr> ");
      break;
    case tk_array_arithm_expr1:
      printf("<tk_array_arithm_expr1> ");
      break;
    case tk_arr_mul_div_expr:
      printf("<tk_arr_mul_div_expr> ");
      break;
    case tk_arr_mul_div_expr1:
      printf("<tk_arr_mul_div_expr1> ");
      break;
    case tk_arr_un_expr:
      printf("<tk_arr_un_expr> ");
      break;
    case tk_arr_end:
      printf("<tk_arr_end> ");
      break;
    case tk_expression:
      printf("<tk_expression> ");
      break;
    case tk_expression1:
      printf("<tk_expression1> ");
      break;
    case tk_and_expr:
      printf("<tk_and_expr> ");
      break;
    case tk_and_expr1:
      printf("<tk_and_expr1> ");
      break;
    case tk_reln_expr:
      printf("<tk_reln_expr> ");
      break;
    case tk_reln_expr1:
      printf("<tk_reln_expr1> ");
      break;
    case tk_rel_op:
      printf("<tk_rel_op> ");
      break;
    case tk_add_sub_expr:
      printf("<tk_add_sub_expr> ");
      break;
    case tk_add_sub_expr1:
      printf("<tk_add_sub_expr1> ");
      break;
    case tk_sum_ops:
      printf("<tk_sum_ops> ");
      break;
    case tk_mul_div_expr:
      printf("<tk_mul_div_expr> ");
      break;
    case tk_mul_div_expr1:
      printf("<tk_mul_div_expr1> ");
      break;
    case tk_mul_ops:
      printf("<tk_mul_ops> ");
      break;
    case tk_un_expr:
      printf("<tk_un_expr> ");
      break;
    case tk_prefix_op:
      printf("<tk_prefix_op> ");
      break;
    case tk_typcast:
      printf("<tk_typcast> ");
      break;
    case tk_expression_more:
      printf("<tk_expression_more> ");
      break;
    case tk_arg_list:
      printf("<tk_arg_list> ");
      break;
    case tk_arg_list_more2:
      printf("<tk_arg_list_more2> ");
      break;
    case tk_funcCall_stmt:
      printf("<tk_funcCall_stmt> ");
      break;
    case tk_funcCall_stmt_rest:
      printf("<tk_funcCall_stmt_rest> ");
      break;
    case tk_otherFunctions:
      printf("<tk_otherFunctions> ");
      break;
    case tk_function:
      printf("<tk_function> ");
      break;
    case tk_fn_stmts:
      printf("<tk_fn_stmts> ");
      break;
    case tk_parameter_list:
      printf("<tk_parameter_list> ");
      break;
    case tk_parameter_list_more:
      printf("<tk_parameter_list_more> ");
      break;
    case tk_io_stmt:
      printf("<tk_io_stmt> ");
      break;
    case tk_bot_stmt:
      printf("<tk_bot_stmt> ");
      break;
    case tk_for_stmt:
      printf("<tk_for_stmt> ");
      break;
    case tk_update_stmt:
      printf("<tk_update_stmt> ");
      break;
    default:
      print_token(rule);
      break;
  }
}

char buf[2][BUFFER_SIZE];
int buf_in_use;
int at_eof;
int read_size[2];
int curr_locn;

inline char read_next_char(FILE * ip) {
  curr_locn++;
  if (curr_locn == read_size[buf_in_use] - 1 && read_size[buf_in_use]  < BUFFER_SIZE) 
    at_eof = 1;
  else if (curr_locn >= 100) {
    buf_in_use = !buf_in_use;
    read_size[buf_in_use] = fread(buf[buf_in_use], sizeof(char), BUFFER_SIZE, ip);
    if (read_size[buf_in_use] == 0) {
      at_eof = 1;
      memset(&buf[buf_in_use], ' ', sizeof(buf[buf_in_use]));
    }
    curr_locn = 0;
  }
  // printf("at_eof: %d curr_locn: %d buf_in_use: %d read_size:%d\n", at_eof, curr_locn, buf_in_use, read_size[buf_in_use]);
  // if (at_eof)
  //   return EOF;
  // else
    return buf[buf_in_use][curr_locn];
}

queue initialize_queue(int size) {
  queue q;
  q.que = (int *) malloc(size*sizeof(int));
  if (q.que == NULL) {
    printf("Error!! Malloc failed in initialize_stack()\n");
    exit(1);
  }
  q.front = q.back = -1;
  q.size = size;
  return q;
}

void insert(queue *q, int num) {
  int a;
  if (q->back == q->size - 1) {
    q->size = (int)(2*q->size + 1);
    q->que = (int *) realloc(q->que, q->size*sizeof(int));
    if (q->que == NULL) {
      printf("Error!! Realloc failed in initialize_stack()\n");
      exit(1);
    }
    a = 0; //dummy to debug
  }
  q->back++;
  if (q->front == -1) {
    q->front = 0;
  }
  q->que[q->back] = num;
}

int get_first(queue *q) {
  if (q->front == q->back + 1) {
    return -1;
  }
  // q->front++;
  return q->que[q->front++];
}

void print_queue(queue q) {
  printf("->");
  int i = q.front;
  while(i <= q.back) {
    printf("%d    ", q.que[i]);
    i++;
  }
  printf("\n");
}

void test_queue() {
  queue q;
  q = initialize_queue(3);
  insert(&q, 1);
  insert(&q, 5);
  insert(&q, 2);
  insert(&q, 7);
  insert(&q, 10);
  print_queue(q);
  int x = get_first(&q);
  while (x != -1) {
    printf("Remove: %d\n", x);
    print_queue(q);
    x = get_first(&q);
  }
}

enum Token lexer(FILE * ip, FILE * op)
{

  symbol_table_node *node = add_new_node_to_parent(NULL);

  buf_in_use = 1;
  at_eof = 0;
  read_size[0] = read_size[1] = 0;
  curr_locn = 100;
  
  lexer_queue = initialize_queue(500);

  char input,next,prev; //our work-horse!
  input = ' ';
  int line_no, column_no;
  line_no=1;
  column_no=0;
  prev = '\0';

  printf("LEXER Output\n");
  printf("============\n\n");

  while(!at_eof)
  { 
    if (prev != '\0')
      input = prev;
    else
      input = read_next_char(ip);
    
    if(input == EOF || input == 0)
      break;
         
    if(input == '\n')
    {
      line_no++;
      column_no = 0;
      prev = '\0';
      continue;
    }

    if(input == ' ' || input == '\t') //stripping out extra white spaces 
    { 
      column_no++;
      prev = '\0';
      continue;
    }

    if(input == '@')  //stripping out comments
    {
      column_no++;
      
      if(read_next_char(ip) == '~')
      {
        input = '~';
        column_no++;
        while(input != EOF)
        {
          input = read_next_char(ip);
          column_no++;
          if (input == '\n') {
            column_no = 0;
            line_no++;
          }
          else if (input == '~') {
            input = read_next_char(ip);
            column_no++;
            if (input == '@') {
              break;
            }
          }
        }
        if (input == EOF) {
          printf("\nError: EOF without terminating comment\n");
          return tk_null;
        }
        prev = '\0';
        continue;
      }
      else {
        printf("\n%d : %d Unrecognized symbol @\n",line_no,column_no);
        return tk_null;
      }
    }

    if(isalnum(input)) //could be several things... 
    { 
      column_no++;
      if(isalpha(input))
      {
        char inp[101]; //max size of identifier is 100
        int i = 0;
       do
        {
          inp[i] = input;
          if(i > 100)
          {
            printf("\n%d : %d identifier too big!\n",line_no,column_no);
            while(isSymbol(input)!=1)
            {
              input = read_next_char(ip);
              column_no++;
              if(input=='\n')
              {
                column_no = 0;
                line_no++;
                break;
              }
            }
            prev = input;
            continue;
          }
        
          input = read_next_char(ip);
          column_no++;
          i=i+1;
        }while(isSymbol(input)==0);
      
        inp[i] = '\0';
        prev = input;

        if(inp[0] == 'a' && inp[1] == 'd' && inp[2] == 'd' 
          && inp[3] == 'V' && inp[4] == '\0'){ // addV
          writeTofile(op,tk_addv); 
          // prev = '\0'; 
          continue;
        }
        else if (inp[0] == 'b') { // boolean OR break
          if (inp[1] == 'o' && inp[2] == 'o' && inp[3] == 'l' 
            && inp[4] == 'e' && inp[5] == 'a' && inp[6] == 'n' && inp[7] == '\0') {
            writeTofile(op,tk_boolean); 
            // prev = '\0'; 
            continue;
          }
          else if (inp[1] == 'r' && inp[2] == 'e' && inp[3] == 'a' 
            && inp[4] == 'k' && inp[5] == '\0') {
            writeTofile(op,tk_break); 
            // prev = '\0'; 
            continue;
          }
          else {
            writeTofile(op,tk_id); 
            add_ID_to_sym_table_node(node,inp);
            // prev = '\0'; 
            continue;
          }
        }
        else if(inp[0] == 'B' && inp[1] == 'o' && inp[2] == 't' && inp[3] == '\0') { 
          writeTofile(op,tk_bot); 
          // prev = '\0'; 
          continue;
        }
        else if(inp[0] == 'c' && inp[1] == 'o' && inp[2] == 'n' 
          && inp[3] == 't' && inp[4] == 'i' && inp[5] == 'n' 
          && inp[6] == 'u' && inp[7] == 'e' && inp[8] == '\0') {
          writeTofile(op,tk_continue); 
          // prev = '\0'; 
          continue;
        }
        else if(inp[0] == 'e' && inp[1] == 'l' && inp[2] == 's' && inp[3] == 'e'
           && inp[4] == '\0'){ 
          writeTofile(op,tk_else) ; 
          // prev = '\0'; 
          continue;
        }
        else if (inp[0] == 'f') {
          if(inp[1] == 'l' && inp[2] == 'o' && inp[3] == 'a' 
              && inp[4] == 't' && inp[5] == '\0') {
            writeTofile(op,tk_float); 
            // prev = '\0'; 
            continue;
          }
          else if (inp[1] == 'u' && inp[2] == 'n' && inp[3] == 'c' 
              && inp[4] == 't' && inp[5] == 'i' && inp[6] == 'o' && inp[7] == 'n'
              && inp[8] == '\0') {
            writeTofile(op,tk_func); 
            // prev = '\0'; 
            continue;
          }
          else if(inp[1] == 'a' && inp[2] == 'l' && inp[3] == 's' 
              && inp[4] == 'e' && inp[5] == '\0') {
            writeTofile(op,tk_float); 
            // prev = '\0'; 
            continue;
          }
          else if (inp[1] == 'w' && inp[2] == '\0') {
            writeTofile(op,tk_fw); 
            // prev = '\0'; 
            continue;
          }
          else if (inp[1] == 'o' && inp[2] == 'r' && inp[3] == '\0') {
            writeTofile(op,tk_for); 
            // prev = '\0'; 
            continue;
          }
          else {
            writeTofile(op,tk_id); 
            add_ID_to_sym_table_node(node,inp);
            // prev = '\0'; 
            continue;
          }
        }
        else if (inp[0] == 'i') {
          if (inp[1] == 'n' && inp[2] == 't' && inp[3] == '\0') {
            writeTofile(op,tk_int); 
            // prev = '\0'; 
            continue;
          }
          else if (inp[1] == 'f' && inp[2] == '\0') {
            writeTofile(op,tk_if); 
            // prev = '\0'; 
            continue;
          }
          else {
            writeTofile(op,tk_id); 
            add_ID_to_sym_table_node(node,inp);
            // prev = '\0'; 
            continue;
          }
        }
        else if(inp[0] == 'm' && inp[1] == 'a' && inp[2] == 'i' && inp[3] == 'n'
           && inp[4] == '\0') { 
          writeTofile(op, tk_main); 
          // prev = '\0'; 
          continue;
        } 
        else if(inp[0] == 'P' && inp[1] == 'o' && inp[2] == 'i' && inp[3] == 'n'
           && inp[4] == 't' && inp[5] == '\0') {
          writeTofile(op,tk_point); 
          // prev = '\0'; 
          continue;
        }
        else if(inp[0] == 'r' && inp[1] == 'e' && inp[2] == 't' 
          && inp[3] == 'u' && inp[4] == 'r' && inp[5] == 'n' 
          && inp[6] == '\0') {
          writeTofile(op,tk_return); 
          // prev = '\0'; 
          continue;
        }
        else if(inp[0] == 'r') {
          if (inp[1] == 't' && inp[2] == '\0') {
            writeTofile(op,tk_rt); 
            // prev = '\0'; 
            continue;
          }
          else if(inp[1] == 'e' && inp[2] == 'a' && inp[3] == 'd' 
              && inp[4] == 'i' && inp[5] == '\0') {
            writeTofile(op,tk_readi); 
            // prev = '\0'; 
            continue;
          }
          else {
            writeTofile(op,tk_id); 
            add_ID_to_sym_table_node(node,inp);
            // prev = '\0'; 
            continue;
          }
        }
        else if(inp[0] == 's' && inp[1] == 't' && inp[2] == 'r' 
          && inp[3] == 'u' && inp[4] == 'c' && inp[5] == 't' 
          && inp[6] == '\0'){ 
          writeTofile(op, tk_struct); 
          // prev = '\0'; 
          continue;
        }
        else if(inp[0] == 't' && inp[1] == 'r' && inp[2] == 'u' && inp[3] == 'e'
           && inp[4] == '\0') { 
          writeTofile(op,tk_true); 
          // prev = '\0'; 
          continue;
        }
        else if(inp[0] == 'v' && inp[1] == 'o' && inp[2] == 'i' && inp[3] == 'd'
           && inp[4] == '\0') {
          writeTofile(op,tk_void); 
          // prev = '\0'; 
          continue;
        }
        else { 
          writeTofile(op,tk_id); 
          add_ID_to_sym_table_node(node,inp);
          // prev = '\0'; 
          continue;
        }
      }

      if(isdigit(input)) 
      {
        column_no++;
        char inp[100];
        int i = 0;
        int flag = 0;
        //check for num, rnum or illegal identifier like 12ab
        do
        {
          inp[i++]= input;
          input=read_next_char(ip);
          column_no++;
          if(isalpha(input)) //1.3e02 format not supported
          {
            flag = 1;
            printf("\nError,invalid identifier at %d : %d",line_no,column_no);
            while(isSymbol(input)!=1){input=read_next_char(ip);column_no++;} //scan till delimiter
          }
        } while(isSymbol(input)!=1);

        if(!flag && input!='.')
        {
          prev = input;
          writeTofile(op,tk_num);
          continue;
        }
        else if(input == '.')
        {
          do
          {
            inp[i++]= input;
            input=read_next_char(ip);
            column_no++;
            if(isalpha(input)) //1.3e02 format not supported
            {
              flag = 1;
              printf("\nError,invalid identifier at %d : %d",line_no,column_no);
              while(isSymbol(input)!=1){input=read_next_char(ip);column_no++;} //scan till delimiter
            }
          }while(isSymbol(input)!=1);
          prev = input;
          writeTofile(op,tk_rnum);
          continue;
        }
      }
    }

    if(input == '{') { 
      writeTofile(op,tk_lbrace); 
      prev = '\0'; 
      node = add_new_node_to_parent(node); 
      continue;
    }
    if(input == '}'){ writeTofile(op,tk_rbrace); prev = '\0'; node = node->parent; continue;}
    if(input == '('){ writeTofile(op,tk_lpara);prev = '\0'; continue;}
    if(input == ')'){ writeTofile(op,tk_rpara);prev = '\0'; continue;}
    if(input == '['){ writeTofile(op,tk_lsquare);prev = '\0'; continue;}
    if(input == ']'){ writeTofile(op,tk_rsquare);prev = '\0'; continue;}
    if(input == ';'){ writeTofile(op,tk_semi_cl);prev = '\0'; continue;}
    if(input == ','){ writeTofile(op,tk_comma);prev = '\0'; continue;}
    if(input == '.'){ writeTofile(op,tk_dot);prev = '\0'; continue;}

    if(input == ':')
    {
      next = read_next_char(ip);
      column_no++;
      if(next == '='){ writeTofile(op,tk_col_assign);prev = '\0'; continue;}
      else{ prev = next;writeTofile(op,tk_colon);continue;}
    }

    if(input == '=')
    { next = read_next_char(ip);
      column_no++;
      if( next == '='){ writeTofile(op,tk_log_eq);prev = '\0'; continue;}
      else {prev = next; writeTofile(op,tk_assign_op);continue;} 
    }

    if(input == '_')
    { writeTofile(op,tk_undersc);prev = '\0'; continue;} 

    if(input == '|')
    {
      next = read_next_char(ip);
      column_no++;
      if(next == '|')
      { writeTofile(op,tk_log_or);prev = '\0'; continue;}
      else { printf("\nError: unknown symbol '|' at %d : %d\n",line_no,column_no ); }
    }
    
    if(input == '&')
    {
      next = read_next_char(ip);
      column_no++;
      if(next == '&')
      { writeTofile(op,tk_log_and);prev = '\0'; continue;}
      else{ printf("\nError: unknown symbol '&' at %d : %d\n",line_no,column_no );}
    }

    if(input == '+')  
    {
      next = read_next_char(ip);
      column_no++;
      if(next == '+'){ writeTofile(op,tk_unary_inc); prev = '\0'; continue;}
      else if(next == '='){ writeTofile(op,tk_pl_eq);prev = '\0'; continue;}
      else { prev = next; writeTofile(op,tk_plus);continue;}
    }

    if(input == '-')  
    {
      next = read_next_char(ip);
      column_no++;
      if(next == '-'){ writeTofile(op,tk_unary_dec);prev = '\0'; continue;}
      else{ prev = next; writeTofile(op,tk_minus);continue;}
    }

    if(input == '*'){ writeTofile(op,tk_mul);prev = '\0'; continue;}

    if(input == '/'){ writeTofile(op,tk_div);prev = '\0'; continue;}

    if(input == '<')
    { next = read_next_char(ip);
      column_no++;
      if(next == '='){writeTofile(op,tk_lte);prev = '\0'; continue;}
      else
      {prev = next; writeTofile(op,tk_lt);continue;}
    }

    if(input == '>')
    {
      next = read_next_char(ip);
      column_no++;

      if(next == '='){ writeTofile(op,tk_gte);prev = '\0'; continue;}
      else if(next == '>'){ writeTofile(op,tk_inpop);prev = '\0'; continue;}
      else{ prev = next; writeTofile(op,tk_gt);continue;}
    }
   
    else 
    {
      if (input != ' ' && input != '\t') {
        printf("\nUnknown symbol %c (=%d) at %d:%d\n",input,(int)input,line_no,column_no);
      }
      prev = '\0';
    } 
  }
  printf("\n\nSYMBOL TABLE\n");
  printf("============\n\n");
  print_symbol_table_tree(symbol_table_root);
}

// int main(int argc, char * argv[])
// {   
//    /* if(argc!=2)
//     {
//         printf("FATAL ERROR!! : No input specified or too many parameters \n");
//         exit(1);
//     }
// */
//     init_symbol_table();
//     FILE * ip = fopen("test.txt","r");
//     FILE * op = fopen("test.lexer","w"); //WARNING: argv[1] is changed here
//     if (ip == NULL || op == NULL)
//     {
//         printf("Error opening file, check permissions! \n");
//     }
//     lexer(ip,op);
//     fclose(ip);
//     fclose(op);
// //    add_ID_to_sym_table("joel", 3, 7);
// //    add_ID_to_sym_table("gokul", 2, 2);
// //    add_ID_to_sym_table("test", 42, 42);
//     print_symbol_table();
//     free_symbol_table();
//     return 0;
// }