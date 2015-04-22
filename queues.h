#ifndef LEXEMES_H
#define LEXEMES_H
#include "lexemes.h"
#endif

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "symbol_table.h"
#endif

#define LEXER_QUEUE_SIZE 500
#define SYM_TBL_QUEUE_SIZE 100
#define NUM_TBL_QUEUE_SIZE 100

typedef struct _queue {
  int *que;
  int front;
  int back;
  int size;
} queue;

queue initialize_queue(int size);
void insert(queue *q, int num);
int get_first(queue *q);
void print_queue(queue q);

typedef struct _num_queue {
  float *que;
  int front;
  int back;
  int size;
} num_queue;

num_queue initialize_num_queue(int size);
void insert_num(num_queue *q, float num);
float get_first_num(num_queue *q);
void print_num_queue(num_queue q);

// Not required any more. Keeping just in case
typedef struct _id_queue {
  char **que;
  int front;
  int back;
  int size;
} id_queue;

id_queue initialize_id_queue(int size);
void insert_id(id_queue *q, char id[]);
char* get_first_id(id_queue *q);
void print_id_queue(id_queue q);

typedef struct _st_queue {
  symbol_entry **que;
  int front;
  int back;
  int size;
} st_queue;

st_queue initialize_st_queue(int size);
void insert_st(st_queue *q, symbol_entry *id);
symbol_entry* get_first_st(st_queue *q);
void print_st_queue(st_queue q);

queue lexer_queue;
num_queue num_lexemes_queue;
// id_queue id_lexemes_queue;
st_queue st_lex_queue;

