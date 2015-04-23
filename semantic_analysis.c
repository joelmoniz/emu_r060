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