#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "symbol_table.h"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        printf("name: %s\n token: %d\n type: %d\n has_val: %d\n scope: %d\n depth: %d\n breadth: %d\n refd: ", 
          s->name, s->token_type, s->dtype, s->has_value, 
          s->scope, s->depth, s->breadth);
        r = s->refd;
        while (r != NULL) {
          printf("<%d, %d>", r->depth, r->breadth);
          if (r->next != NULL)
            printf(", ");
          r = r->next;
        }
        printf("\n misc: %d\n", s->misc);
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

void add_ID_to_sym_table_node(symbol_table_node *node, char *name) {
  int index = get_hash_value(name);
  symbol_entry *s = node->symbol_table_hash[index];
  symbol_entry *prev = NULL;

  referred *r = (referred *) malloc(sizeof(referred));
  r->depth = node->level;
  r->breadth = node->breadth;
  r->next = NULL;

  while ( s != NULL) {
    if (strcmp(name, s->name) != 0) {
      prev = s;
      s = s->next;
    }
    else {// entry found => add occurance to symbol table
      r->next = s->refd;
      s->refd = r;
      return;
    }
  }

  s = (symbol_entry *) malloc(sizeof(symbol_entry));
  s->name = (char *) malloc(sizeof(name));
  strcpy(s->name, name);
  s->token_type = tk_id;
  s->dtype = dt_unk;
  s->has_value = 0;
  s->scope = -1;
  s->depth = node->level;
  s->breadth = node->breadth;
  s->refd = r;
  s->misc = vt_unk;
  s->next = node->symbol_table_hash[index];

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