#include "symbol_table.h"

#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
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

void parser(FILE * ip) {
  int token;
  stack s;
  push(&s, start_state);
  int row, col;
  while(fscanf(ip,"%d",&token) != EOF) {
    ;
  }
}
/*
int main()
{
  //printf("%d",parse_table[0][0]);
  //test_stack();
  FILE * ip = fopen("_test123","r");
  parser(ip);
  return 0;
} */