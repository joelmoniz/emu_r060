#include "symbol_table.h"

#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

#ifndef LEXEMES_H
#define LEXEMES_H
#include "lexemes.h"
#endif

#include <stdio.h>
#include <stdlib.h>


stack initialize_stack(int size) {
  stack s;
  s.stk = (int *) malloc(size*sizeof(int));
  s.top = -1;
  s.size = size;
  return s;
}

void push(stack *s, int num) {
  if (s->top == s->size - 1) {
  	s->size = (int)(1.5*s->size + 1);
  	s->stk = (int *) realloc(s->stk, s->size*sizeof(int));
  }
  s->top++;
  s->stk[s->top] = num;
}

int pop(stack *s) {
  if (s->top == -1) {
    return -1;
  }
  s->top--;
  return s->stk[s->top + 1];
}

void print_stack(stack s) {
  printf("->");
  int i = s.top;
  while(i >= 0) {
    printf("%d    ", s.stk[i]);
    i--;
  }
  printf("\n");
}

void test_stack() {
  stack s;
  s = initialize_stack(2);
  push(&s, 1);
  push(&s, 5);
  push(&s, 2);
  push(&s, 7);
  push(&s, 10);
  print_stack(s);
  printf("Pop: %d\n", pop(&s));
  print_stack(s);
}

/*
typedef struct _parse_tree_node {
  struct _parse_tree_node *parent;
  struct _parse_tree_node *children[MAX_TOKENS];
  int num_child;
  int visited_child;
  int token_id;
} parse_tree_node;
*/

parse_tree_node *initialize_parse_tree_node(parse_tree_node *parent, int token) {
  parse_tree_node *p = (parse_tree_node *) malloc(sizeof(parse_tree_node));
  p->token_id = token;
  p->parent = parent;
  p->num_child = 0;
  p->visited_child = 0;
  int i = 0;
  for (; i<MAX_TOKENS; i++)
    p->children[i] = NULL;
  return p;
}

void print_parse_tree(parse_tree_node *node, int lv) {
  if (node == NULL)
    return;
  printf("%d -> ", lv);
  print_token(node->token_id);
  //printf("%d", node->token_id);
  printf("\n");
  if (node->num_child == 0) {
    return;
  }
  int i;
  for (i=0; i < node->num_child; i++) {
    print_parse_tree(node->children[i], lv+1);
  }
}

int is_unecessary_node(int i) {
  return (enum Token)i == tk_lbrace || (enum Token)i == tk_rbrace || 
    (enum Token)i == tk_lpara || (enum Token)i == tk_rpara || 
    (enum Token)i == tk_lsquare || (enum Token)i == tk_rsquare || 
    (enum Token)i == tk_semi_cl;
}

void remove_unecessary_nodes(parse_tree_node *node) {
  int i, j;
  for (i=0; i < node->num_child; i++) {
    remove_unecessary_nodes(node->children[i]);

    if (node->children[i]->num_child == 0 
      && is_unecessary_node(node->children[i]->token_id)) {

      free(node->children[i]);
      
      for (j=i; j < node->num_child - 1; j++)
        node->children[j] = node->children[j+1];

      node->num_child--;
    }
  }
}

parse_tree_node *fold_and_assign(parse_tree_node *node) {
  int i;
  for (i=0; i < node->num_child; i++) {
    node->children[i] = fold_and_assign(node->children[i]);
  }
  if (node->num_child == 1) {// fold // && node->children[0]->num_child == 0)
    parse_tree_node *temp = node->children[0];
    node->children[0]->parent = node->parent;
    free(node);
    return temp;
  }
  else
    return node;
}

void fold_tree() {
  int i;
  for (i=0; i < parse_root->num_child; i++) {
    parse_root->children[i] = fold_and_assign(parse_root->children[i]);
  }
}

void parse_tree_to_AST() {
  remove_unecessary_nodes(parse_root);
  printf("\n\nUnecessary Removed:\n");
  print_parse_tree(parse_root, 0);
  fold_tree(parse_root);
  printf("\n\nFolded:\n");
  print_parse_tree(parse_root, 0);
}

/*
E = 0, X = 1, int = 2, + = 3, float = 4, * = 5, bool = 6
Test
E -> int + E | X
X -> float * X | bool
*/
int parse_table_test[][5] = {{0, -1, 1, -1, 1}, {-1, -1, 2, -1, 3}};
int rule_test[][4] = {{2, 3, 0, -1}, {1,-1}, {4,5,1,-1}, {6,-1}};
// TODO: Make error checking proper
void parser(FILE * ip) {
  int token;
  stack s = initialize_stack(2);
  push(&s, end_marker);
  push(&s, start_state);
  parse_root = initialize_parse_tree_node(NULL, start_state);
  parse_tree_node *current = parse_root;
  int row, col;
  int top;
  int rule_no;
  int rule_token_no;
  print_stack(s);
  while(fscanf(ip,"%d",&token) != EOF) {
    top = pop(&s);

    while (!is_token(top) && !is_error(top)) {
      rule_no = parse_table_test[top][token - FIRST_TOKEN];
      printf("Rule: %d\n", rule_no);
      rule_token_no = 0;

      if (rule_no != -1) { // TODO: Change this to scan vs pop errors
        while (rule_test[rule_no][rule_token_no] != -1) { // TODO: change this to tk_null
          current->children[rule_token_no] = initialize_parse_tree_node(current, rule_test[rule_no][rule_token_no]);
          current->num_child++;
          rule_token_no++;
        }

        current = current->children[0];
        rule_token_no--;

        while (rule_token_no >= 0) {
          push(&s, rule_test[rule_no][rule_token_no]);
          rule_token_no--;
        }
      }
      else // TODO: Handle pop vs scan errors separately
        printf("Error\n");

      print_stack(s);
      //print_parse_tree(parse_root, 0);

      top = pop(&s);
    }

    if (top != token) {
      printf("Expecting ");
      print_token(token);
      printf("but found ");
      print_token(top);
      printf("\n");
    }

    while (1) {
      if (current == NULL)
        break;

      if (current->num_child == 0) {
        current = current->parent;
        continue;
      }

      current->visited_child++;

      if (current->visited_child >= current->num_child) {
        current = current->parent;
        continue;
      }

      current = current->children[current->visited_child];
      break;
    }
    print_stack(s);
  }
  int x = pop(&s);
  if (x != end_marker)
    printf("Error\n");
  printf("Parsing successful\n");
  printf("\n\nParse tree:\n");
  current = parse_root;
  printf("\n/\\\n");
  print_parse_tree(current, 0);

  parse_tree_to_AST();
  printf("\n\nAbstract Syntax tree:\n");
  print_parse_tree(current, 0);
}

int is_token(int t) {
  return (t>=2);
}

int is_error(int t) {
  return 0;
}

int main()
{
  //printf("%d",parse_table[0][0]);
  //test_stack();
  FILE * ip = fopen("_test123","r");
  parser(ip);
  return 0;
} 