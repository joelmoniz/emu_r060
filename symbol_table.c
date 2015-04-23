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

#ifndef QUEUES_H
#define QUEUES_H
#include "queues.h"
#endif

#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

void init_symbol_table(symbol_entry *symbol_table_hash[]) {
  int i;
  for (i = 0; i < HASH_SIZE; i++) {
    symbol_table_hash[i] = NULL;
  }
}

symbol_table_node *initialize_symbol_table_node(symbol_table_node *parent) {
  symbol_table_node *s = (symbol_table_node *) malloc(sizeof(symbol_table_node));

  if (s == NULL) {
    printf("Error!! Malloc failed in initialize_symbol_table_node()\n");
    exit(1);
  }

  s->parent = parent;

  if (parent != NULL) {
    s->level = parent->level + 1;
    s->breadth = parent->num_children;
  }
  else {
    s->level = 0;
    s->breadth = 0;
  }

  s->num_children = 0;
  init_symbol_table(s->symbol_table_hash);

  int i = 0;
  for (; i<MAX_TOKENS; i++)
    s->children[i] = NULL;
  
  return s;
}

symbol_table_node *add_new_node_to_parent(symbol_table_node *parent) {
  if (parent != NULL) {
    parent->children[parent->num_children] = initialize_symbol_table_node(parent);
    parent->num_children++;
    // printf("Added");
    return parent->children[parent->num_children-1];
  }
  else {
    symbol_table_root = initialize_symbol_table_node(NULL);
    // printf("Here1");
    return symbol_table_root;
  }
}

void print_var_type(var_type v) {
  switch(v) {
   case variable: printf("  variable");
    break;
   case parameter: printf("  parameter");
    break;
   case argument: printf("  argument");
    break;
   case return_val: printf("  return_val");
    break;
   case vt_unk: 
   default: printf("  vt_unk");
    break;
  }
}

void print_data_type(data_type d) {
  switch(d) {
   case function: printf(" function");
    break;
   case integer: printf(" integer");
    break;
   case float_point: printf(" float");
    break;
   case Point: printf(" Point");
    break;
   case Bot: printf(" Bot");
    break;
   case boolean: printf(" boolean");
    break;
   case dt_unk: 
   default: printf(" vt_unk");
    break;
  }
}

void print_symbol_table(symbol_entry *symbol_table_hash[]) {
  int i = 0;
  referred *r;
  symbol_entry *s;

  for (i = 0;i < HASH_SIZE; i++) {
    if (symbol_table_hash[i] != NULL) {
      printf("\n%d\n", i);
      printf("---\n");
      
      s = symbol_table_hash[i];
      while (s != NULL) {
        printf("name: %s\n depth: %d\n breadth: %d\n size: %d bytes\n var_type:",// %d\n refd: ", 
          s->name, s->depth, s->breadth, s->dtype);//, s->vtype);
        print_var_type(s->vtype);
        // r = s->refd;
        // while (r != NULL) {
        //   printf("<%d, %d>", r->depth, r->breadth);
        //   if (r->next != NULL)
        //     printf(", ");
        //   r = r->next;
        // }
        s = s->next;
      }
    }
    // else {
    //   printf("%d ",i);
    // }
  }
}

void print_symbol_table_tree(symbol_table_node *node) {
  if (node == NULL) {
    // printf("Ouch\n");
    return;
  }
  printf("\nLevel: %d  Breadth: %d\n", node->level, node->breadth);
  printf("====================");
  print_symbol_table(node->symbol_table_hash);

  printf("\n");
  if (node->num_children == 0) {
    return;
  }
  int i;
  for (i=0; i < node->num_children; i++) {
    print_symbol_table_tree(node->children[i]);
  }
}

void add_ID_to_sym_table_node(symbol_table_node *node, char *name, data_type dt) {
  int index = get_hash_value(name);
  symbol_entry *s = node->symbol_table_hash[index];
  symbol_entry *prev = NULL;

  // printf("\nHere:  %s, ", name);print_data_type(dt);printf("\n");

  int dp, bdt;

  int is_dt_orig_unk = (dt == dt_unk);

  referred *r = (referred *) malloc(sizeof(referred));
  r->next = NULL;  

  symbol_table_node *node_temp = node->parent;
  while (node_temp != NULL) {
    symbol_entry *s_temp = node_temp->symbol_table_hash[get_hash_value(name)];

    while (s_temp != NULL) {
      if (strcmp(name, s_temp->name) != 0) {
        s_temp = s_temp->next;
      }
      else {// entry found
        if (is_dt_orig_unk)
          dt = s_temp->dtype;
        else if (s_temp->dtype == function)
          printf("\nError: Cannot have a variable with the same name as a function (%s)\n", name);
        break;
      }
    }

    if (s_temp != NULL)
      break;
    node_temp = node_temp->parent;
  }

  if (node_temp != NULL) {
    dp = node_temp->level;
    bdt = node_temp->breadth;
  }
  else {
    dp = node->level;
    bdt = node->breadth;
    node_temp = node;
  }

  while ( s != NULL) {
    if (strcmp(name, s->name) != 0) {
      prev = s;
      s = s->next;
    }
    else {// entry found => add occurance to symbol table
      r->next = s->refd;
      s->refd = r;
      insert_st(&st_lex_queue, s);
      if (is_dt_orig_unk)
        return;
      // printf("\nPrinting: %s  ",name);print_data_type(s->dtype);printf("\n");
      if (dt == function) {
        if (s->dtype != function)
          printf("\nError: Cannot have a function with the same name as a variable (%s)\n", name);
        else
          printf("\nError: Overloading of function %s not permitted\n", name);
      }
      else if (dt != function) {
        if (s->dtype == function)
          printf("\nError: Cannot define a variable with the same name as a function (%s)\n", name);
        else if (dt != s->dtype) {
          printf("\nError: Trying to declare %s as", name);
          print_data_type(dt);
          printf(" when it has already been declared as");
          print_data_type(s->dtype);
          printf("\n");
        }
        else {
          printf("\nError: Redeclaration of variable %s\n", name);
        }
      }
      return;
    }
  }

  s = (symbol_entry *) malloc(sizeof(symbol_entry));
  s->name = (char *) malloc(sizeof(name));
  strcpy(s->name, name);

  if (dt == dt_unk) {
    printf("\nError: Undeclared identifier %s\n", name);
  }

  s->depth = dp;
  s->breadth = bdt;
  s->refd = r;
  s->dtype = dt;
  s->vtype = vt_unk;

  if (is_dt_orig_unk)
    s->container = node_temp;
  else
    s->container = node;

  s->next = node->symbol_table_hash[index];
  insert_st(&st_lex_queue, s);

  node->symbol_table_hash[index] = s;
}

void free_symbol_table(symbol_entry *symbol_table_hash[]) {
  int i;
  for (i = 0; i < HASH_SIZE; i++) {
    while (symbol_table_hash[i] != NULL) {
      symbol_entry *s = symbol_table_hash[i];
      symbol_table_hash[i] = s->next;
      free(s->name);

      while (s->refd != NULL) {
        referred *r = s->refd;
        s->refd = r->next;
        free(r);
      }

      free(s);
    }
  }
}

int get_hash_value(unsigned char *name) //the djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
{
  int hash = 5381;
  int c;

  while ((c = *name++) != '\0')
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return (hash>0)?(hash%HASH_SIZE):(-hash%HASH_SIZE);
}

// void main() {
//   symbol_table_node *node = add_new_node_to_parent(NULL);
//   // print_symbol_table_tree(symbol_table_root);
//   node = add_new_node_to_parent(node);
//   add_ID_to_sym_table_node(node,"a");
//   node = add_new_node_to_parent(node);
//   add_ID_to_sym_table_node(node,"a");
//   add_ID_to_sym_table_node(node,"b");
//   print_symbol_table_tree(symbol_table_root);
// }