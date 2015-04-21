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

#define DEBUG 0
#define PRINT_AST_DETAILS 1

enum Token states [][MAX_TOKENS + 1] =
{
{tk_null},
{tk_global_vars,tk_otherFunctions,tk_mainFunction,tk_null},
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
{tk_global_assignment,tk_global_vars,tk_null},
{/*tk_eps*/tk_null},
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
{tk_col_assign,tk_lbrace,tk_id,tk_comma,tk_idNum,tk_comma,tk_idNum,tk_comma,tk_idBool,tk_rbrace,tk_semi_cl,tk_null},//12 rules
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
{tk_boolean,tk_null}, //check!!
{tk_point,tk_null},
{tk_bot,tk_null},
{tk_var,tk_leftHandSide1,tk_null},
{tk_assign_operators,tk_righHandSide,tk_null},
{tk_comma,tk_var,tk_leftHandSideMultiple,tk_null},
{tk_col_assign,tk_lbrace,tk_bot_point1,tk_null},
{tk_id,tk_comma,tk_idNum,tk_bot_or_point,tk_null},
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
{/*tk_eps*/tk_null},
{tk_rsquare,tk_array2d,tk_null}, //83
{tk_colon,tk_array_arithm_expr,tk_rsquare,tk_null},
{/*tk_eps*/tk_null},
{tk_lsquare,tk_array_arithm_expr,tk_rsquare,tk_null},
{tk_value,tk_values_more,tk_null},
{tk_comma,tk_values,tk_null},
{/*tk_eps*/tk_null},
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
{/*tk_eps*/tk_null},
{tk_loop_condnal_stmt,tk_null},
{tk_lbrace,tk_loop_stmts,tk_null},
{tk_if,tk_lpara,tk_expression,tk_rpara,tk_lbrace,tk_condnal_stmt_suffix,tk_null},
{tk_stmts,tk_condnal_stmt_more,tk_null},
{tk_else,tk_condnal_stmt_even_more,tk_null},
{/*tk_eps*/tk_null},
{tk_condnal_stmt,tk_null},
{tk_lbrace,tk_stmts,tk_null},
{tk_expression,tk_more_expression,tk_null},
{tk_comma,tk_expression,tk_more_expression,tk_null},
{/*tk_eps*/tk_null},
{tk_arr_mul_div_expr,tk_array_arithm_expr1,tk_null},//<array_arithm_expr'> is  tk_array_arithm_expr1
{tk_sum_ops,tk_arr_mul_div_expr,tk_array_arithm_expr1,tk_null},
{/*tk_eps*/tk_null}, //rule 120
{tk_arr_un_expr,tk_arr_mul_div_expr1,tk_null},
{tk_mul_ops,tk_arr_un_expr,tk_arr_mul_div_expr1,tk_null},
{/*tk_eps*/tk_null},
{tk_prefix_op,tk_arr_end,tk_null},
{tk_idNum,tk_null},
{tk_lpara,tk_array_arithm_expr,tk_rpara,tk_null}, //rule 126
{tk_and_expr,tk_expression1,tk_null},
{tk_log_or,tk_and_expr,tk_expression1,tk_null},
{/*tk_eps*/tk_null},
{tk_reln_expr,tk_and_expr1,tk_null},
{tk_log_and,tk_reln_expr,tk_and_expr1,tk_null},
{/*tk_eps*/tk_null},
{tk_add_sub_expr,tk_reln_expr1,tk_null},
{tk_rel_op,tk_add_sub_expr,tk_reln_expr1,tk_null},
{/*tk_eps*/tk_null},
{tk_lt,tk_null},
{tk_gt,tk_null},
{tk_log_eq,tk_null},
{tk_lte,tk_null},
{tk_gte,tk_null},
{tk_mul_div_expr,tk_add_sub_expr1,tk_null},
{tk_sum_ops,tk_mul_div_expr,tk_add_sub_expr1,tk_null},
{/*tk_eps*/tk_null},
{tk_plus,tk_null},
{tk_minus,tk_null},
{tk_un_expr,tk_mul_div_expr1,tk_null},
{tk_mul_ops,tk_un_expr,tk_mul_div_expr1,tk_null},
{/*tk_eps*/tk_null},
{tk_mul,tk_null},
{tk_div,tk_null},
{tk_prefix_op,tk_typcast,tk_null},
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
{tk_func,tk_type_list,tk_lpara,tk_parameter_list,tk_lbrace,tk_fn_stmts,tk_null},
{tk_stmt,tk_fn_stmts,tk_null},
{tk_return,tk_expressions,tk_semi_cl,tk_rbrace,tk_null},
{tk_type,tk_id,tk_parameter_list_more,tk_null},
{tk_rpara,tk_null},
{tk_comma,tk_type,tk_id,tk_parameter_list_more,tk_null},
{tk_rpara,tk_null},
{tk_readi,tk_inpop,tk_id,tk_semi_cl,tk_null},
{tk_addv,tk_id,tk_comma,tk_id,tk_semi_cl,tk_null},
{tk_fw,tk_id,tk_comma,tk_expression,tk_semi_cl,tk_null},
{tk_rt,tk_id,tk_semi_cl,tk_null},
{tk_point_decl_stmt,tk_null},
{tk_bot_decl_stmt,tk_null},
{tk_for,tk_lpara,tk_assignment_stmt,tk_expression,tk_semi_cl,tk_update_stmt,tk_rpara,tk_lbrace,tk_loop_stmts,tk_null},
{tk_assignment_stmt,tk_null},
{tk_unary_stmts,tk_null}
};

//},break,;,continue,id,=,@~,, ,[,num,],{,Point,:=,Bot,+=,void,int,float,boolean,:,(,),true,false,rnum,if,else,||,&&,<,> ,==,<=,>=,+,-,*,/,++,--,main,function,return,readi,>>,addV,fw,rt,for
enum Token parse_table[][53] = //1 indexed both row and column
{
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,1,1,1,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,1,1,184,184,184,184,184,184,184,183},
{0,2,184,184,184,2,184,2,184,184,184,184,184,2,184,2,184,184,2,2,2,184,184,184,184,184,184,2,184,184,184,184,184,184,184,184,184,184,184,184,2,2,184,184,184,2,184,2,2,2,2,183},
{0,4,184,184,184,3,184,3,184,184,184,184,184,3,184,3,184,184,3,3,3,184,184,184,184,184,184,3,183,184,184,184,184,184,184,184,184,184,184,184,3,3,184,184,183,3,184,3,3,3,3,183},
{0,183,184,184,184,5,184,5,184,184,184,184,184,5,184,5,184,184,5,5,5,184,184,184,184,184,184,6,184,184,184,184,184,184,184,184,184,184,184,184,5,5,184,184,183,5,184,5,5,5,5,184},
{0,8,7,184,7,7,184,7,184,184,184,184,184,7,184,7,184,184,7,7,7,184,184,184,184,184,184,7,183,184,184,184,184,184,184,184,184,184,184,184,7,7,184,184,183,7,184,7,7,7,7,184},
{0,183,10,184,11,9,184,9,184,184,184,184,184,9,184,9,184,184,9,9,9,184,184,184,184,184,184,9,184,184,184,184,184,184,184,184,184,184,184,184,9,9,184,184,184,9,184,9,9,9,9,184},
{0,183,183,184,183,12,184,12,184,184,184,184,184,12,184,12,184,184,12,12,12,184,184,184,184,184,184,13,184,184,184,184,184,184,184,184,184,184,184,184,12,12,184,184,184,12,184,12,12,12,12,184},
{0,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,14,14,14,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,15,15,184,184,184,184,184,184,184,184},
{0,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,16,16,16,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,184,184,184,184,184,184},
{0,183,183,184,183,17,184,18,184,184,184,184,184,18,184,18,184,184,18,18,18,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,18,18,184,184,183,18,184,18,18,18,18,184},
{0,183,183,184,183,183,184,22,184,184,184,184,184,21,184,21,184,184,24,24,24,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,23,23,184,184,183,19,184,21,21,21,20,184},
{0,183,183,184,183,183,25,183,25,25,184,184,184,183,25,183,25,184,183,183,183,184,26,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,184,183,183,184,183,184,184,184,184,184,183,184,183,184,184,183,183,183,184,184,183,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,27,27,184,184,183,183,184,183,183,183,183,184},
{0,183,183,29,183,183,184,183,28,184,184,184,184,183,184,183,184,184,183,183,183,184,184,183,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,184,183,183,184,183,184,184,184,184,184,183,184,183,184,184,30,30,30,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,33,183,183,31,183,33,32,184,184,184,183,184,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,35,183,183,184,183,34,184,184,184,184,183,184,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,38,183,183,36,183,38,37,184,184,184,183,184,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,40,183,183,39,183,40,184,184,184,184,183,184,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,184,183,184,184,184,184,183,184,184,184,41,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,183,184,184,184,184,183,184,184,184,42,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,44,184,183,184,184,184,184,43,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,183,184,183,183,184,183,184,184,184,184,184,45,184,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,46,183,183,184,183,184,184,184,184,184,183,47,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,184,183,183,184,183,184,184,184,184,184,183,184,48,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,49,183,183,184,183,184,184,184,184,184,183,50,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,184,184,184,184,183,51,184,184,184,183,184,184,184,184,184,52,184,184,184,184,184,183,184,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,55,184,184,183,184,184,184,184,54,184,54,184,184,53,53,53,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,56,184,184,184,184,184,184,184,56,184,56,184,57,56,56,56,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,59,184,184,58,184,184,184,184,184,184,184,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,183,184,184,183,184,184,184,184,184,184,184,184,184,60,61,62,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,183,184,184,183,184,184,184,184,63,184,64,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,65,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,184,184,184,184,184,184,184,184},
{0,183,183,184,183,183,66,183,67,184,183,184,184,183,68,183,66,184,183,183,183,184,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,184,183,69,184,183,184,184,70,184,184,183,184,183,184,184,183,183,183,184,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,71,183,184,183,183,184,183,72,184,183,184,184,183,184,183,184,184,183,183,183,184,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,184,184,184,73,184,184,183,184,74,183,184,184,184,184,184,184,184,184,184,183,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,183,184,183,183,76,183,75,184,183,184,184,183,184,183,184,184,183,183,183,184,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,184,183,77,184,183,184,184,77,184,184,183,184,183,184,184,183,183,183,184,77,183,77,77,77,183,184,184,184,184,184,184,184,184,184,184,184,184,77,77,184,184,183,183,184,183,183,183,183,184},
{0,183,183,79,183,183,184,183,78,184,183,184,184,183,184,183,184,184,183,183,183,184,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,184,184,184,184,80,183,184,183,184,184,184,184,184,183,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,82,184,82,184,184,82,184,82,81,184,184,184,184,82,184,82,184,184,184,184,184,184,82,184,184,184,184,184,82,82,82,82,82,82,82,82,82,82,82,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,184,183,184,184,183,184,183,184,184,83,184,184,183,184,183,184,184,184,184,84,184,183,184,184,184,184,184,183,183,183,183,183,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,85,184,85,184,184,85,184,85,86,184,184,184,184,85,184,85,184,184,184,184,184,184,85,184,184,184,184,184,85,85,85,85,85,85,85,85,85,85,85,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,184,184,184,87,184,184,184,184,87,184,184,184,184,184,184,184,184,184,184,184,184,184,87,87,87,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,89,184,184,184,184,184,184,88,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,184,183,184,91,184,184,183,184,90,184,184,184,184,184,184,184,184,184,184,184,184,183,90,90,90,184,184,183,183,183,183,183,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,93,184,93,184,184  ,93,184,93,93,184,184,184,184,93,184,93,184,184,184,184,184,92, 93,184,184,184,184,184,93,93,93,93,93,93,93,93,93,93,93,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,184,183,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,94,183,184,184,184,184,184,183,183,183,183,183,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,184,183,184,95,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,184,96,184,184,184,184,184,183,183,183,183,183,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,184,184,184,97,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,98,98,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,184,183,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,184,183,99,100,184,184,184,183,183,183,183,183,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,184,183,184,184,184,184,183,184,101,184,184,184,184,184,184,184,184,184,184,184,184,183,103,103,102,184,184,183,183,183,183,183,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,183,184,183,183,184,183,184,184,184,184,184,183,184,183,184,184,183,183,183,184,184,184,184,184,184,104,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,184,183,184,183,183,183,183,184},
{0,106,106,184,106,106,184,106,184,184,184,184,184,106,184,106,184,184,106,106,106,184,184,184,184,184,184,106,105,184,184,184,184,184,184,184,184,184,184,184,106,106,184,184,184,106,184,106,106,106,106,184},
{0,183,183,184,183,183,184,183,184,184,184,184,108,183,184,183,184,184,183,183,183,184,184,184,184,184,184,107,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,184,183,184,183,183,183,183,184},
{0,183,184,184,184,183,184,183,184,184,184,184,184,183,184,183,184,184,183,183,183,184,184,184,184,184,184,109,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,110,184,184,184,110,184,110,184,184,184,184,184,110,184,110,184,184,110,110,110,184,184,184,184,184,184,110,184,184,184,184,184,184,184,184,184,184,184,184,110,110,184,184,183,110,184,110,110,110,110,184},
{0,112,184,184,184,112,184,112,184,184,184,184,184,112,184,112,184,184,112,112,112,184,184,184,184,184,184,112,111,184,184,184,184,184,184,184,184,184,184,184,112,112,184,184,112,112,184,112,112,112,112,184},
{0,183,184,184,184,183,184,183,184,184,184,184,114,183,184,183,184,184,183,183,183,184,184,184,184,184,184,113,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,184,184,183,184,115,184,184,184,184,115,184,184,184,184,184,184,184,184,184,184,184,115,184,115,115,115,184,184,184,184,184,184,184,184,184,184,184,184,184,115,115,184,184,184,184,184,184,184,184,184,184},
{0,184,184,117,184,184,184,184,116,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,183,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,118,118,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,184,184,184,184,184,184,120,184,184,184,184,184,184,184,184,184,120,184,120,184,184,184,184,184,184,184,184,184,184,184,184,119,119,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,183,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,121,121,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,184,184,184,184,184,184,123,184,184,184,184,184,184,184,184,184,123,184,123,184,184,184,184,184,184,184,184,184,184,184,184,123,123,122,122,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,183,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,183,183,124,124,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,125,184,184,184,184,125,183,184,184,184,184,184,184,184,184,184,183,126,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,183,184,127,184,184,183,184,127,184,184,184,184,184,184,184,184,184,184,184,127,183,127,127,127,184,184,184,184,184,184,184,184,184,184,184,184,184,127,127,184,184,184,184,184,184,184,184,184,184},
{0,184,184,129,184,184,184,184,129,184,184,184,184,184,184,184,184,184,184,184,184,184,184,129,184,184,184,184,184,128,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,183,184,130,184,184,183,184,130,184,184,184,184,184,184,184,184,184,184,184,130,183,130,130,130,184,184,183,184,184,184,184,184,184,184,184,184,184,130,130,184,184,184,184,184,184,184,184,184,184},
{0,184,184,132,184,184,184,184,132,184,184,184,184,184,184,184,184,184,184,184,184,184,184,132,184,184,184,184,184,132,131,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,183,184,133,184,184,183,184,133,184,184,184,184,184,184,184,184,184,184,184,133,183,133,133,133,184,184,183,183,184,184,184,184,184,184,184,184,184,133,133,184,184,184,184,184,184,184,184,184,184},
{0,184,184,135,184,184,184,184,135,184,184,184,184,184,184,184,184,184,184,184,184,184,184,135,184,184,184,184,184,135,135,134,134,134,134,134,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,183,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,183,184,183,183,183,184,184,184,184,136,137,138,139,140,184,184,184,184,183,183,184,184,184,184,184,184,184,184,184,184},
{0,184,184,183,184,141,184,184,183,184,141,184,184,184,184,184,184,184,184,184,184,184,141,183,141,141,141,184,184,183,183,183,183,183,183,183,184,184,184,184,141,141,184,184,184,184,184,184,184,184,184,184},
{0,184,184,143,184,184,184,184,143,184,184,184,184,184,184,184,184,184,184,184,184,184,184,143,184,184,184,184,184,143,143,143,143,143,143,143,142,142,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,183,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,183,184,183,183,183,184,184,184,184,184,184,184,184,184,144,145,184,184,183,183,184,184,184,184,184,184,184,184,184,184},
{0,184,184,183,184,146,184,184,183,184,146,184,184,184,184,184,184,184,184,184,184,184,146,183,146,146,146,184,184,183,183,183,183,183,183,183,183,183,184,184,146,146,184,184,184,184,184,184,184,184,184,184},
{0,184,184,148,184,184,184,184,148,184,184,184,184,184,184,184,184,184,184,184,184,184,184,148,184,184,184,184,184,148,148,148,148,148,148,148,148,148,147,147,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,183,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,183,184,183,183,183,184,184,184,184,184,184,184,184,184,184,184,149,150,183,183,184,184,184,184,184,184,184,184,184,184},
{0,184,184,183,184,152,184,184,183,184,152,184,184,184,184,184,184,184,184,184,184,184,152,183,152,152,152,184,184,183,183,183,183,183,183,183,183,183,183,183,151,151,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,183,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,183,184,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184,184,153,154,184,184,184,184,184,184,184,184,184,184},
{0,184,184,183,184,155,184,184,183,184,155,184,184,184,184,184,184,184,184,184,184,184,156,183,155,155,155,184,184,183,183,183,183,183,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,183,184,157,184,184,183,184,157,184,184,184,184,184,184,184,158,158,158,184,157,183,157,157,157,184,184,183,183,183,183,183,183,183,183,183,183,183,157,157,184,184,184,184,184,184,184,184,184,184},
{0,183,184,183,184,159,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,184,183,184,184,184,184,184,183,183,183,183,183,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,184,183,184,184,184,184,160,184,184,184,184,184,184,184,184,184,184,184,184,184,184,161,184,184,184,184,184,183,183,183,183,183,183,183,183,183,183,183,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,183,184,183,183,184,183,184,184,184,184,184,183,184,183,184,184,183,183,183,184,162,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,183,184,183,163,184,183,184,184,184,184,184,183,184,183,184,184,183,183,183,184,184,164,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,183,184},
{0,183,184,184,184,183,184,183,184,184,184,184,184,183,184,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,166,165,184,183,184,183,183,183,183,184},
{0,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,183,167,184,184,184,184,184,184,184,184},
{0,184,184,184,184,168,184,168,184,184,184,184,184,168,184,168,184,184,168,168,168,184,184,184,184,184,184,168,184,184,184,184,184,184,184,184,184,184,184,184,168,168,183,183,169,168,184,168,168,168,168,184},
{0,184,184,184,184,170,184,184,184,184,184,184,183,170,184,170,184,184,170,170,170,184,184,171,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,184,184,184,184,184,184,184,172,184,184,184,183,184,184,184,184,184,184,184,184,184,184,173,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184},
{0,183,183,184,183,183,184,183,184,184,184,184,184,183,184,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,174,184,183,183,183,183,184},
{0,183,183,184,183,183,184,183,184,184,184,184,184,178,184,179,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,175,176,177,183,184},
{0,183,183,184,183,183,184,183,184,184,184,184,184,183,184,183,184,184,183,183,183,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,183,183,184,184,183,183,184,183,183,183,180,184},
{0,184,184,184,184,181,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,183,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,184,182,182,184,184,184,184,184,184,184,184,184,184}
};

stack initialize_stack(int size) {
  stack s;
  s.stk = (int *) malloc(size*sizeof(int));
  if (s.stk == NULL) {
    printf("Error!! Malloc failed in initialize_stack()\n");
    exit(1);
  }
  s.top = -1;
  s.size = size;
  return s;
}

void push(stack *s, int num) {
  int a;
  if (s->top == s->size - 1) {
    // print_stack(*s);
  	s->size = (int)(1.5*s->size + 1);
  	s->stk = (int *) realloc(s->stk, s->size*sizeof(int));
    if (s->stk == NULL) {
      printf("Error!! Realloc failed in initialize_stack()\n");
      exit(1);
    }
    a = 0; //dummy to debug
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

void print_stack_as_rules(stack s) {
  printf("->  ");
  int i = s.top;
  while(i >= 0) {
    print_rule(s.stk[i]);
    printf("  ");
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

parse_tree_node *initialize_parse_tree_node(parse_tree_node *parent, int token) {
  parse_tree_node *p = (parse_tree_node *) malloc(sizeof(parse_tree_node));

  if (p == NULL) {
    printf("Error!! Malloc failed in initialize_parse_tree_node()\n");
    exit(1);
  }

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
  if (DEBUG) {
    print_token(node->token_id);
  }
  else {
    print_rule(node->token_id);
  }
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
    (enum Token)i == tk_semi_cl || (enum Token)i == tk_inpop
    || (enum Token)i == tk_comma;
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
      i--;
    }
    else if (node->children[i]->num_child == 0 
      && !is_token(node->children[i]->token_id)) {

      free(node->children[i]);
      
      for (j=i; j < node->num_child - 1; j++)
        node->children[j] = node->children[j+1];

      node->num_child--;
      i--;
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

  if (parse_root->num_child == 1) {// fold the root if needed
      // && node->children[0]->num_child == 0)
    parse_tree_node *temp = parse_root->children[0];
    parse_root->children[0]->parent = temp;
    free(parse_root);
    parse_root = temp;
  }
}

int is_bool_operator(int i) {
  return (i == tk_log_or || i ==  tk_log_and || 
    i == tk_lt || i == tk_gt || i == tk_log_eq ||
    i == tk_lte || i ==  tk_gte || i == tk_pl_eq ||
    i ==  tk_plus || i ==  tk_minus || i == tk_addv || 
    i ==  tk_mul || i ==  tk_div || i == tk_fw ||
    i == tk_col_assign || //i == tk_assign_op ||
    i == tk_colon || i == tk_dot || i == tk_comma);
}

int is_singleton_operator(int i) {
  return (i == tk_rt || i ==  tk_unary_inc  || 
    i ==  tk_unary_dec  || i == tk_readi);
}

int is_datatype(int i) {
  return (i == tk_int || i == tk_float ||
    i == tk_boolean || i == tk_bot || 
    i == tk_point || i == tk_void);
}

int is_all_alone(int i) {
  return (i == tk_id || i == tk_num || 
    i == tk_rnum || i == tk_true);
}

int is_flow_construct(int i) { // for, if, func
  return (i == tk_for || i == tk_if || 
    i == tk_else || i == tk_func || 
    i == tk_return);
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
void elevate_symbols(parse_tree_node *node) {
  int i, j;
  // tk_break, tk_continue dont need to 
  // be handled explicitly- done by fold_tree()

  if (node == NULL || node->num_child == 0)
    return;

  int type = -1;
  
  typedef enum _node_type {
    null,
    flow_construct,
    datatype,
    singleton_operator,
    bool_operator,
    dont_touch
  } node_type;

  node_type n = null;
  int position = -1;

  for (i=0; i < node->num_child; i++) {
    elevate_symbols(node->children[i]);
  }

  for (i=0; i < node->num_child; i++) {
    if (is_flow_construct(node->children[i]->token_id)) {
      if (!node->children[i]->num_child) {
        position = i;
        n = flow_construct;
        break;
      }
    }
    else if (is_datatype(node->children[i]->token_id)) {
      if (n == null) {
        n = datatype;
        position = i;
      }
      else if (n != flow_construct) {
        n = dont_touch;
        break;
      }
    }
    else if(is_singleton_operator(node->children[i]->token_id)) {
      if (n == null && !node->children[i]->num_child) {
        n = singleton_operator;
        position = i;
      }
    }
    else if (is_bool_operator(node->children[i]->token_id)) {
      if ((n == null || n == bool_operator || n== singleton_operator) && node->children[i]->num_child <= 1) {
        n = bool_operator;
        position = i;
      }
      else if (n != flow_construct) {
        n = dont_touch;
        break;
      }
    }
  }

  if (n == flow_construct && node->children[position]->num_child == 0) {
    node->token_id = node->children[position]->token_id;
    node->num_child--;
    free(node->children[position]);

    for (j=position; j < node->num_child; j++)
      node->children[j] = node->children[j+1];

    if (node->token_id == tk_return) {
      parse_tree_node *expressions = node->children[0];
      node->num_child = expressions->num_child;

      for (j=0; j < node->num_child; j++)
        node->children[j] = expressions->children[j];

      free(expressions);
    }
    else if (node->token_id == tk_func) {
      parse_tree_node *get_id = node->children[0];
      while (get_id->children[1]->token_id != tk_id) 
        get_id = get_id->children[1];
      if (get_id->token_id != tk_type_list) {
        get_id->token_id = get_id->children[0]->token_id;
        free(get_id->children[0]);
        get_id->num_child = 0;
      }
      else {
        get_id->num_child--;
      }
      node->num_child++;
      for(j=node->num_child-1; j>1; j--) {
        node->children[j] = node->children[j-1];
      }
      node->children[j] = get_id->children[1]; // j = 1 here after loop
    }
  }
  // else if (n == datatype) {
  //   node->token_id = node->children[position]->token_id;
  //   node->num_child--;
  //   free(node->children[position]);

  //   for (j=position; j < node->num_child; j++)
  //     node->children[j] = node->children[j+1];
  // }
  else if(n == singleton_operator) {
    node->token_id = node->children[position]->token_id;
    node->num_child--;
    free(node->children[position]);

    for (j=position; j < node->num_child; j++)
      node->children[j] = node->children[j+1];
  }
  else if (n == bool_operator) {
    if (!(node->children[position]->token_id == tk_col_assign && node->token_id == tk_gen_stmt)) {
      node->token_id = node->children[position]->token_id;
  
      for (j=0; j < node->children[position]->num_child; j++) {
        node->children[node->num_child] = node->children[position]->children[j];
        node->num_child++;
      }
      
      free(node->children[position]);
      node->num_child--;
  
      for (j=position; j < node->num_child; j++)
        node->children[j] = node->children[j+1];
      }
    else {
      parse_tree_node *get_col_eq1 = node->children[position]->children[0];
      int nc = 2;
      if (get_col_eq1->num_child > 2) {
        node->children[position]->children[2] = get_col_eq1->children[2]->children[0];
        node->children[position]->children[3] = get_col_eq1->children[2]->children[1];
        nc = 4;
        free(get_col_eq1->children[2]);
      }
      node->children[position]->children[0] = get_col_eq1->children[0];
      node->children[position]->children[1] = get_col_eq1->children[1];
      node->children[position]->num_child = nc;
    }
  }

  if (node->token_id == tk_program) {
    for (i=0; i < node->num_child; i++) {
      if (node->children[i]->token_id == tk_main && !node->children[i]->num_child) {
        free(node->children[i]);

        for (j=i; j < node->num_child - 1; j++) {
          // if (node->children[j+1]->token_id == tk_stmts)

          node->children[j] = node->children[j+1];
        }
        node->children[i+1]->token_id = tk_main;
        node->num_child--;
      }
    }
  }
  else if (node->token_id == tk_otherFunctions) {
    for (i=node->num_child-1; i >= 0; i--) {
      if (node->children[i]->token_id == tk_main) {
        free(node->children[i]);
        node->num_child--;
        node->parent->children[node->parent->num_child-1]->token_id = tk_main;
        break;
      }
    }
  }
  else if (node->token_id == tk_condnal_stmt_suffix) {
    // stetemts if condition is true
    node->parent->children[node->parent->num_child - 1] = node->children[0];
    node->parent->num_child++;

    // else part
    node->parent->children[node->parent->num_child - 1] = node->children[1]->children[0];

    // free else node
    free(node->children[1]);

    free(node);
  }
}

void get_final_AST() {
  int i,j;

  for (i=0; i < parse_root->num_child; i++) {
    if (parse_root->children[i]->token_id == tk_main) {
      parse_root->token_id = parse_root->children[i]->token_id;
      parse_root->num_child--;
      free(parse_root->children[i]);

      for (j=i; j < parse_root->num_child; j++)
        parse_root->children[j] = parse_root->children[j+1];

      break;
    }
  }
  get_final_AST(parse_root);
}

void parse_tree_to_AST() {
  remove_unecessary_nodes(parse_root);
  
  if (PRINT_AST_DETAILS) {
    printf("\n\n");
    printf("Unecessary Removed:\n");
    printf("-------------------\n");
    print_parse_tree(parse_root, 0);
  }
  
  fold_tree();

  if (PRINT_AST_DETAILS) {
    printf("\n\n");
    printf("Folded:\n");
    printf("-------\n");
    print_parse_tree(parse_root, 0);
  }

  elevate_symbols(parse_root);
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

  printf("\n\n");
  printf("PARSER Output\n");
  printf("=============\n\n");

  int token;
  int error_detected = 0;
  stack s = initialize_stack(500);
  push(&s, end_marker);
  push(&s, START_STATE);
  parse_root = initialize_parse_tree_node(NULL, START_STATE);
  parse_tree_node *current = parse_root;
  int row, col;
  int top;
  int rule_no;
  int rule_token_no;

  printf("LL1 Derivation\n");
  printf("--------------\n\n");
  
  // while(fscanf(ip,"%d",&token) != EOF) {
  while((token = get_first(&lexer_queue)) != -1) {
    if (DEBUG) {
      printf("Token: %d  ", token);
      print_token(token);
      printf("\n");
    }

    if (DEBUG)
      print_stack(s);
    else
      print_stack_as_rules(s);

    top = pop(&s);

    if (top == end_marker) {
      printf("Error: Extra tokens found: \n");
      error_detected = 1;
      print_token(token);
      // while(fscanf(ip,"%d",&token) != EOF) {
      while((token = get_first(&lexer_queue)) != -1) {
        print_token(token);
      }
      printf("\n");
      break;
    }

    while (!is_token(top) && !is_error(top)) {
      
      rule_no = parse_table[top][token - tk_rbrace + 1 ];
      	
      if (DEBUG) {
        printf("Rule: %d Top no.: %d Top: ", rule_no, top);
        print_rule(top);
        printf("Token no.:%d Token: ", token - FIRST_TOKEN + 1);
        print_token(token);
        printf("\n");
      }

      rule_token_no = 0;

      if (rule_no != POP_ERROR && rule_no != SCAN_ERROR) { // TODO: Change this to scan vs pop errors
        while (states[rule_no][rule_token_no] != tk_null) {
          current->children[rule_token_no] = initialize_parse_tree_node(current, states[rule_no][rule_token_no]);
          current->num_child++;
          rule_token_no++;
        }

        if (current->num_child) {
          current = current->children[0];
        }
        else {
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
        }

        rule_token_no--;

        while (rule_token_no >= 0) {
          push(&s, states[rule_no][rule_token_no]);
          rule_token_no--;
        }

        if (DEBUG) {
          printf("\n");
          print_stack(s);
        }
        else {
          print_stack_as_rules(s);
        }
      }
      else {// TODO: Handle pop vs scan errors separately}
        if (rule_no == POP_ERROR) {
          printf("Error for token ");
          print_rule(token);
          printf("  ==> Popping ");
          print_rule(top);
          printf(" from the stack...\n");
          // top = pop(&s);
          if (top == end_marker) {
            push(&s, top);
          }
          lexer_queue.que[--lexer_queue.front] = token;
        }
        else if (rule_no == SCAN_ERROR) {
          printf("Error for token ");
          print_rule(token);
          printf("  ==> Continuing scan...\n");
          // token = get_first(&lexer_queue);
          push(&s, top);
        }
        break;
      }

      top = pop(&s);
    }

    if (DEBUG) {
      printf("\n");
      print_token(top);
    }

    if (top != token) {
      printf("Error: Expecting ");
      print_rule(top);
      printf("but found ");
      print_token(token);
      printf("\n");
      error_detected = 1;
    }

    while (!error_detected) {
      // printf("\nValue:");
      // print_rule(token);
      // printf("Top:%d  Tree:%d Tree value:", top, current->token_id);
      // print_rule(token);
      // printf("\n\n");

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
    //print_stack_as_rules(s);
  }
  int x = pop(&s);

  if (x != end_marker && top != end_marker) {
    printf("Error: non empty stack\n");
    error_detected = 1;
  }

  if (!error_detected) {
    printf("\nParsing completed successfully.\n\n\n");
    printf("Parse tree:\n");
    printf("-----------\n");
    current = parse_root;
    //printf("\n/\\\n");
    print_parse_tree(current, 0);

    parse_tree_to_AST();
    printf("\n\n");
    printf("Abstract Syntax tree:\n");
    printf("---------------------\n\n");
    print_parse_tree(current, 0);
  }
  else {
    printf("\nParsing completed. Errors detected.\n\n");
  }
}

int is_token(int t) {
  return (t >= FIRST_TOKEN && t <= 199);
}

int is_error(int t) {
  return (t == end_marker || t == tk_null || t < 0);
}


// int main()
// {
//   //printf("%d",parse_table[0][0]);
//   //test_stack();
//   FILE * ip = fopen("test.txt.lexer","r");
//   parser(ip);
//   return 0;
// } 
