#define stack_size 500
#define start_state 0
#define end_marker 200
#define error 184
#define FIRST_TOKEN 2

"RBRACE",
"BREAK",
"SEMI_CL",
"CONTINUE","ID","ASSIGN_OP","<other_stm","<comment>","COMMA","LSQUARE","<NUM>","RSQUARE","LBRACE","POINT","COL_ASSIGN","BOT","PL_EQ","VOID","INT","FLOAT","BOOLEAN","NUM","COLON","LPARA","RPARA","TRUE","FALSE","RNUM","IF","ELSE","LOG_OR","LOG_AND","LT","GT","LOG_EQ","LTE","RTE","PLUS","MINUS","MULTIPLY","DIVIDE","UNARY_INCR","UNARY_DECR","MAIN","FUNCTION","RETURN","READI","INPOP","ADDV","FW","RT","FOR","$"],


typedef enum Token {  
  tk_rbrace, //}
  tk_break, //break
  tk_semi_cl,// ;
  tk_continue,  //continue
  
  tk_main, //main
  tk_lbrace, //{
  tk_lpara, //(
  tk_rpara, //)
  tk_lsquare, //[
  tk_rsquare,//]
  tk_struct, // struct
  tk_cmnt_begin, // @~
  tk_cmnt_end, // ~@
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
  tk_exit, //exit
  tk_for, //for
  tk_if, //if
  tk_else, //else
  tk_plus, //+
  tk_minus, //-
  tk_mul, //*
  tk_div // /
} TOK;

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
