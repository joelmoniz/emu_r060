#define stack_size 500

#ifndef LEXEMES_H
#define LEXEMES_H
#include "lexemes.h"
#endif

#define START_STATE 0
#define end_marker 200
#define error 184
#define FIRST_TOKEN 0
#define POP_ERROR 183
#define SCAN_ERROR 184
#define MAX_TOKENS 14

// "RBRACE",
// "BREAK",
// "SEMI_CL",
// "CONTINUE","ID","ASSIGN_OP","<other_stm","<comment>","COMMA","LSQUARE","<NUM>","RSQUARE","LBRACE","POINT","COL_ASSIGN","BOT","PL_EQ","VOID","INT","FLOAT","BOOLEAN","NUM","COLON","LPARA","RPARA","TRUE","FALSE","RNUM","IF","ELSE","LOG_OR","LOG_AND","LT","GT","LOG_EQ","LTE","GTE","PLUS","MINUS","MULTIPLY","DIVIDE","UNARY_INCR","UNARY_DECR","MAIN","FUNCTION","RETURN","READI","INPOP","ADDV","FW","RT","FOR","$"],
/*
NOTE:
If a terminal is absent from a non-terminal's predict set, 
an error code is placed in the table. 
If that terminal is in follow(that non-terminal), the error is a POP error. Else, it's a SCAN error.

    POP error code = # of predict table productions + 1
    SCAN error code = # of predict table productions + 2
*/


extern enum Token states[][MAX_TOKENS + 1];
extern int parse_table[][53];

int is_token(int);
int is_error(int);

typedef struct _stack {
	int *stk;
	int top;
	int size;
} stack;

stack initialize_stack(int size);
void push(stack *s, int num);
int pop(stack *s);
void print_stack(stack s);

typedef struct _parse_tree_node {
  struct _parse_tree_node *parent;
  struct _parse_tree_node *children[MAX_TOKENS];
  int num_child;
  int visited_child;
  int token_id;
} parse_tree_node;

parse_tree_node *parse_root;
parse_tree_node *initialize_parse_tree_node(parse_tree_node *parent, int token);
void print_parse_tree(parse_tree_node *node, int lv);
void parse_tree_to_AST();

int is_unecessary_node(int i);
int is_bool_operator(int i);
int is_singleton_operator(int i);
int is_datatype(int i);
int is_all_alone(int i);