#include <stdio.h>

typedef enum Token {  
  tk_main, //main
  tk_lbrace, //{
  tk_rbrace, //}
  tk_lpara, //(
  tk_rpara, //)
  tk_lsquare, //[
  tk_rsquare,//]
  tk_struct, // struct
  tk_cmnt_begin, // @~
  tk_cmnt_end, // ~@
  tk_semi_cl,// ;
  tk_assign_op, // =
  tk_id, // [A­Z a­z] [A­Z a­z _ 0­9]* identifier
  tk_comma, // , 
  tk_num, //integer [1­9][0­9]* | [0] 
  tk_rnum, // [0­9]+”.”[0­9]+ 
  tk_bool, // boolean
  tk_bot, //Bot
  tk_velocity, //Velocity
  tk_col_assign, // :=
  tk_int, // int
  tk_float, // float
  tk_dot, // .
  tk_colon, // :
  tk_log_or, // ||
  tk_log_and, // &&
  tk_lt, // <
  tk_gt, // > 
  tk_log_eq, // ==
  tk_lte, // <=
  tk_gte, // >=
  tk_func, // function
  tk_return, // return
  tk_rt, // rt
  tk_addv, // addV
  tk_pl_eq, // +=
  tk_true, // true
  tk_false, // false
  tk_inpop, // >>
  tk_unary_inc, // ++
  tk_unary_dec, // --
  tk_undersc, // _
  tk_fw, // fw
  tk_point, // Point
  tk_void, //void
  tk_readi, //readi
  tk_break, //break
  tk_continue,  //continue
  tk_exit, //exit
  tk_for, //for
  tk_if, //if
  tk_else, //else
  tk_plus, //+
  tk_minus, //-
  tk_mul, //*
  tk_div // /
} TOK;

typedef union _data_val {
  int i;
  int bln;
  float f;
} data_val;

typedef struct _referred {
  int loc;
  struct _referred *next;
} referred;

typedef struct _symbol_entry {
  char *name;
  int token_type;
  int dtype;
  data_val value;
  int size;
  int scope;
  int declared_line, declared_position;
  referred refd;
  int misc;
  struct _symbol_entry *next;
} parse_entry;

