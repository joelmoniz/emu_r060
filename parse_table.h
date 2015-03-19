#define stack_size 500
#include "lexemes.h"
#define start_state 0
#define end_marker 200
#define error 184
#define FIRST_TOKEN 2
#define POP_error 183
#define SCAN_error 184

// "RBRACE",
// "BREAK",
// "SEMI_CL",
// "CONTINUE","ID","ASSIGN_OP","<other_stm","<comment>","COMMA","LSQUARE","<NUM>","RSQUARE","LBRACE","POINT","COL_ASSIGN","BOT","PL_EQ","VOID","INT","FLOAT","BOOLEAN","NUM","COLON","LPARA","RPARA","TRUE","FALSE","RNUM","IF","ELSE","LOG_OR","LOG_AND","LT","GT","LOG_EQ","LTE","RTE","PLUS","MINUS","MULTIPLY","DIVIDE","UNARY_INCR","UNARY_DECR","MAIN","FUNCTION","RETURN","READI","INPOP","ADDV","FW","RT","FOR","$"],
/*
NOTE:
If a terminal is absent from a non-terminal's predict set, 
an error code is placed in the table. 
If that terminal is in follow(that non-terminal), the error is a POP error. Else, it's a SCAN error.

    POP error code = # of predict table productions + 1
    SCAN error code = # of predict table productions + 2
*/

typedef enum Token {  
  tk_null = -1,
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

enum Token states [][11] = 
{
{tk_global_vars,tk_otherFunctions,tk_mainFunction,tk_null}
{tk_stmts, tk_null},  
{tk_stmt,tk_stmts,tk_null},
{tk_rbrace,tk_null},
{tk_gen_stmt,tk_null},
{tk_condnal_stmt,tk_null},
{tk_loop_stmt,tk_loop_stmts,tk_null},
{tk_rbrace,tk_null},
{tk_lp_stmt,tk_null},
{tk_break, tk_semi_cl, tk_null},
{tk_continue,tk_semi_cl,tk_null},
{tk_gen_stmt,tk_null},
{tk_loop_condnal_stmt,tk_null},
{tk_global_assignment,tk_null},
{tk_eps,tk_null},
{tk_primitive_type,tk_id,tk_assign_op,tk_const_value,tk_semi_cl,tk_null},
{tk_id,tk_func_ass,tk_null},
{tk_other_stmt,tk_null},
{tk_io_stmt,tk_null},
{tk_for_stmt,tk_null},
{tk_bot_stmt,tk_null},
{tk_comment,tk_null},
{tk_unary_stmts,tk_null},
{tk_primitive_declaration_stmt,tk_null},
{tk_array,tk_leftHandSide1,tk_null},
{tk_funcCall_stmt,tk_null},
{tk_prefix_op,tk_id,tk_unary_stmt_more,tk_null},
{tk_comma,tk_prefix_op,tk_id,tk_unary_stmt_more,tk_null},
{tk_semi_cl,tk_null},
{tk_primitive_type,tk_id,tk_assign_more,tk_null},
{tk_assign_op,tk_expression,tk_assign_comma,tk_null},
{tk_lsquare,tk_num,tk_rsquare,tk_array2,tk_null},
{tk_assign_comma,tk_null},
{tk_comma,tk_id,tk_assign_more,tk_null},
{tk_semi_cl,tk_null},
{tk_assign_op,tk_curly_values,tk_assign_comma,tk_null},
{tk_lsquare,tk_num,tk_rsquare,tk_assign_2d,tk_null},
{tk_assign_comma,tk_null},
{tk_assign_op,tk_meta_curly,tk_assign_comma,tk_null},
{tk_assign_comma,tk_null},
{tk_lbrace,tk_values,tk_rbrace,tk_null},
{tk_lbrace,tk_curly_values,tk_more_curliness,tk_null},
{tk_comma,tk_curly_values,tk_more_curliness,tk_null},
{tk_rbrace,tk_null},
{tk_point,tk_id,tk_pv_rest,tk_null},
{tk_semi_cl,tk_null},
{tk_col_assign,tk_lbrace,tk_idNum,tk_comma,tk_idNum,tk_rbrace,tk_semi_cl,tk_null}, //7 symbols!
{tk_bot,tk_id,tk_bot_rest,tk_null},
{tk_semi_cl,tk_null},
{tk_col_assign,tk_lbrace,tk_id,tk_comma,tk_idNum,tk_comma,tk_idNum,tk_comma,tk_idNum,tk_comma,tk_idBool,tk_rbrace,tk_semi_cl,tk_null},//11 rules
{tk_assign_op,tk_null},
{tk_pl_eq,tk_null},
{tk_primitive_type,tk_null},
{tk_bot_type,tk_null},
{tk_id,tk_null},
{tk_type,tk_type_more,tk_null},
{tk_void,tk_id,tk_null},
{tk_comma,tk_type,tk_type_more,tk_null},
{tk_id,tk_null},
{tk_int,tk_null},
{tk_float,tk_null},
{tk_bool,tk_null}, //check!!
{tk_point,tk_null},
{tk_bot,tk_null},
{tk_var,tk_leftHandSide1,tk_null},
{tk_assign_operators,tk_righHandSide,tk_null},
{tk_comma,tk_var,tk_leftHandSideMultiple,tk_null},
{tk_col_assign,tk_lbrace,tk_bot_point1,tk_null},
{tk_id,tk_comma,tk_idNum,tk_bot_point1,tk_null},
{tk_num, tk_comma,tk_idNum,tk_rbrace,tk_semi_cl,tk_null },//<num> and num ??
{tk_rbrace,tk_semi_cl,tk_null},
{tk_comma,tk_idNum,tk_comma,tk_idBool,tk_rbrace,tk_semi_cl,tk_null},//6 symbols
{tk_id,tk_null},
{tk_num,tk_null},
{tk_comma,tk_var,tk_leftHandSideMultiple,tk_null},
{tk_assign_op,tk_righHandSide,tk_null},
{tk_expression,tk_righHandSideMultiple,tk_null},
{tk_comma,tk_expression,tk_righHandSideMultiple,tk_null},
{tk_semi_cl,tk_null},
{tk_id,tk_array,tk_null},
{tk_lsquare,tk_array_arithm_expr,tk_brack_pair1,tk_null},
{tk_eps,tk_null},
{tk_rsquare,tk_array2d}, //83
{tk_colon,tk_array_arithm_expr,tk_rsquare,tk_null},
{tk_eps,tk_null},
{tk_lsquare,tk_array_arithm_expr,tk_rsquare,tk_null},
{tk_value,tk_values_more,tk_null},
{tk_comma,tk_values,tk_null},
{tk_eps,tk_null},
{tk_const_value,tk_null},
{tk_id,tk_value_rest,tk_null},
{tk_funcCall_inside_Value,tk_null},
{tk_array,tk_null},
{tk_lpara,tk_funcCall_inside_Value_rest,tk_null},
{tk_arg_list,tk_null},
{tk_rpara,tk_null},
{tk_id,tk_null},
{tk_bool,tk_null},
{tk_true,tk_null},
{tk_false,tk_null},
{tk_num,tk_null},
{tk_rnum,tk_null},
{tk_bool,tk_null},
{tk_if,tk_lpara,tk_expression,tk_rpara,tk_lbrace,tk_loop_stmts,tk_loop_condnal_stmt_more,tk_null},
{tk_else,tk_loop_condnal_stmt_even_more,tk_null},
{tk_eps,tk_null},
{tk_loop_condnal_stmt,tk_null},
{tk_lbrace,tk_loop_stmts,tk_null},
{tk_if,tk_lpara,tk_expression,tk_rpara,tk_lbrace,tk_condnal_stmt_suffix,tk_null},
{tk_stmts,tk_loop_condnal_stmt_more,tk_null},
{tk_else,tk_loop_condnal_stmt_even_more,tk_null},
{tk_eps,tk_null},
{tk_condnal_stmt,tk_null},
{tk_lbrace,tk_stmts,tk_null},
{tk_expression,tk_more_expression,tk_null},
{tk_comma,tk_expression,tk_more_expression,tk_null},
{tk_eps,tk_null},
{tk_arr_mul_div_expr,tk_array_arithm_expr1,tk_null},//<array_arithm_expr'> is  tk_array_arithm_expr1
{tk_sum_ops,tk_arr_mul_div_expr,tk_array_arithm_expr1,tk_null},
{tk_eps,tk_null}, //rule 120
{tk_arr_un_expr,tk_arr_mul_div_expr1,tk_null},
{tk_mul_ops,tk_arr_un_expr,tk_arr_mul_div_expr1,tk_null},
{tk_eps,tk_null},
{tk_prefix_op,tk_arr_end,tk_null},
{tk_idNum,tk_null},
{tk_lpara,tk_array_arithm_expr,tk_rpara,tk_null}, //rule 126
{tk_and_expr,tk_expression1,tk_null},
{tk_log_or,tk_and_expr,tk_expression1,tk_null},
{tk_eps,tk_null},
{tk_reln_expr,tk_and_expr1,tk_null},
{tk_log_and,tk_reln_expr,tk_and_expr1,tk_null},
{tk_eps,tk_null},
{tk_add_sub_expr,tk_reln_expr1,tk_null},
{tk_rel_op,tk_add_sub_expr,tk_reln_expr1,tk_null},
{tk_eps,tk_null},
{tk_lt,tk_null},
{tk_gt,tk_null},
{tk_log_eq,tk_null},
{tk_lte,tk_null},
{tk_rte,tk_null},
{tk_mul_div_expr,tk_add_sub_expr1,tk_null},
{tk_sum_ops,tk_mul_div_expr,tk_add_sub_expr1,tk_null},
{tk_eps,tk_null},
{tk_plus,tk_null},
{tk_minus,tk_null},
{tk_un_expr,tk_arr_mul_div_expr1,tk_null},
{tk_mul_ops,tk_un_expr,tk_arr_mul_div_expr1,tk_null},
{tk_eps,tk_null},
{tk_mul,tk_null},
{tk_div,tk_null},
{tk_prefix_op,tk_typcast},
{tk_typcast,tk_null},
{tk_unary_inc,tk_null},
{tk_unary_dec,tk_null},
{tk_value,tk_null},
{tk_lpara,tk_expression_more,tk_null},
{tk_expression,tk_rpara,tk_null},// this is rule 157
{tk_primitive_type,tk_rpara,tk_lpara,tk_expression,tk_rpara,tk_null},
{tk_id,tk_assign_op,tk_value,tk_arg_list_more2,tk_null},
{tk_comma,tk_arg_list,tk_null},
{tk_rpara,tk_null},
{tk_lpara,tk_funcCall_stmt_rest,tk_null},
{tk_arg_list,tk_semi_cl,tk_null},
{tk_rpara,tk_semi_cl,tk_null},
{tk_function,tk_otherFunctions,tk_null},
{tk_main,tk_lpara,tk_rpara,tk_lbrace,tk_null},
{tk_function,tk_type_list,tk_lpara,tk_parameter_list,tk_lbrace,tk_fn_stmts,tk_null},
{tk_stmt,tk_fn_stmts},
{tk_return,tk_expressions,tk_semi_cl,tk_rbrace,tk_null},
{tk_type,tk_id,tk_parameter_list_more,tk_null},
{tk_rpara,tk_null},
{tk_comma,tk_type,tk_id,tk_parameter_list_more},
{tk_rpara,tk_null},
{tk_readi,tk_inpop,tk_id,tk_semi_cl,tk_null},
{tk_addv,tk_id,tk_comma,tk_id,tk_comma,tk_semi_cl,tk_null},
{tk_fw,tk_id,tk_comma,tk_expression,tk_semi_cl,tk_null},
{tk_rt,tk_id,tk_semi_cl,tk_null},
{tk_point_decl_stmt,tk_null},
{tk_bot_decl_stmt,tk_null},
{tk_for,tk_lpara,tk_assignment_stmt,tk_expression,tk_semi_cl,tk_update_stmt,tk_rpara,tk_lbrace,tk_loop_stmts,tk_null},
{tk_assignment_stmt},
{tk_unary_stmts}
};

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
