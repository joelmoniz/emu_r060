#ifndef STANDARD_H
#define STANDARD_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#endif

#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

#ifndef QUEUES_H
#define QUEUES_H
#include "queues.h"
#endif

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "symbol_table.h"
#endif

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
  if (q->back == q->size - 1) {
    q->size = (int)(2*q->size + 1);
    q->que = (int *) realloc(q->que, q->size*sizeof(int));
    if (q->que == NULL) {
      printf("Error!! Realloc failed in initialize_stack()\n");
      exit(1);
    }
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

num_queue initialize_num_queue(int size) {
  num_queue q;
  q.que = (float *) malloc(size*sizeof(float));
  if (q.que == NULL) {
    printf("Error!! Malloc failed in initialize_stack()\n");
    exit(1);
  }
  q.front = q.back = -1;
  q.size = size;
  return q;
}

void insert_num(num_queue *q, float num) {
  if (q->back == q->size - 1) {
    q->size = (int)(2*q->size + 1);
    q->que = (float *) realloc(q->que, q->size*sizeof(float));
    if (q->que == NULL) {
      printf("Error!! Realloc failed in initialize_stack()\n");
      exit(1);
    }
  }
  q->back++;
  if (q->front == -1) {
    q->front = 0;
  }
  q->que[q->back] = num;
}

float get_first_num(num_queue *q) {
  if (q->front == q->back + 1) {
    return -1.0;
  }
  // q->front++;
  return q->que[q->front++];
}

void print_num_queue(num_queue q) {
  printf("->");
  int i = q.front;
  while(i <= q.back) {
    printf("%f    ", q.que[i]);
    i++;
  }
  printf("\n");
}

void test_num_queue() {
  num_queue q;
  q = initialize_num_queue(3);
  insert_num(&q, 1.31);
  insert_num(&q, 5.27);
  insert_num(&q, 2.141);
  insert_num(&q, 7.893);
  insert_num(&q, 10.567);
  print_num_queue(q);
  float x = get_first_num(&q);
  while (x != -1.0) {
    printf("Remove: %f\n", x);
    print_num_queue(q);
    x = get_first_num(&q);
  }
}

id_queue initialize_id_queue(int size)  {
  id_queue q;
  q.que = (char **) malloc(size*sizeof(char *));
  if (q.que == NULL) {
    printf("Error!! Malloc failed in initialize_stack()\n");
    exit(1);
  }
  q.front = q.back = -1;
  q.size = size;
  return q;
}

void insert_id(id_queue *q, char id[]) 
 {
  if (q->back == q->size - 1) {
    q->size = (int)(2*q->size + 1);
    q->que = (char **) realloc(q->que, q->size*sizeof(char *));
    if (q->que == NULL) {
      printf("Error!! Realloc failed in initialize_stack()\n");
      exit(1);
    }
  }
  q->back++;
  if (q->front == -1) {
    q->front = 0;
  }
  q->que[q->back] = (char *) malloc(strlen(id)*sizeof(char));
  strcpy(q->que[q->back], id);
}

char* get_first_id(id_queue *q) 
 {
  if (q->front == q->back + 1) {
    return "NULL";
  }
  // q->front++;
  return q->que[q->front++];
}

void print_id_queue(id_queue q) 
 {
  printf("->");
  int i = q.front;
  while(i <= q.back) {
    printf("%s    ", q.que[i]);
    i++;
  }
  printf("\n");
}

void test_id_queue() {
  id_queue q;
  q = initialize_id_queue(3);
  insert_id(&q, "abcdefs");
  insert_id(&q, "joelmoniz");
  insert_id(&q, "gokuluf");
  insert_id(&q, "sleepy");
  insert_id(&q, "iendorseyou");
  print_id_queue(q);
  char* x = get_first_id(&q);
  while (strcmp(x,"NULL")) {
    printf("Remove: %s\n", x);
    print_id_queue(q);
    x = get_first_id(&q);
  }
}

st_queue initialize_st_queue(int size)  {
  st_queue q;
  q.que = (symbol_entry **) malloc(size*sizeof(symbol_entry *));
  if (q.que == NULL) {
    printf("Error!! Malloc failed in initialize_stack()\n");
    exit(1);
  }
  q.front = q.back = -1;
  q.size = size;
  return q;
}

void insert_st(st_queue *q, symbol_entry *st) 
 {
  if (q->back == q->size - 1) {
    q->size = (int)(2*q->size + 1);
    q->que = (symbol_entry **) realloc(q->que, q->size*sizeof(symbol_entry *));
    if (q->que == NULL) {
      printf("Error!! Realloc failed in initialize_stack()\n");
      exit(1);
    }
  }
  q->back++;
  if (q->front == -1) {
    q->front = 0;
  }
  q->que[q->back] = st;
}

symbol_entry* get_first_st(st_queue *q) 
 {
  if (q->front == q->back + 1) {
    return NULL;
  }
  // q->front++;
  return q->que[q->front++];
}

void print_st_queue(st_queue q) 
 {
  printf("->");
  int i = q.front;
  while(i <= q.back) {
    printf("%s    ", q.que[i]->name);
    i++;
  }
  printf("\n");
}

// void main() {
//   test_queue();
//   printf("\n");
//   test_num_queue();
// }

