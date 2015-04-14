#define NO_OF_TERMINALS 50 //TODO: not fixed yet

typedef enum Token {  
  tk_null = -1,
  tk_temp,
  tk_program,
  tk_mainFunction,
  tk_stmts,
  tk_stmt,
  tk_loop_stmts,  
  tk_loop_stmt,
  tk_lp_stmt,
  tk_global_vars,
  tk_global_assignment,
  tk_gen_stmt,
  tk_other_stmt,
  tk_func_ass,
  tk_unary_stmts,
  tk_unary_stmt_more,
  tk_primitive_declaration_stmt,
  tk_assign_more,
  tk_assign_comma,
  tk_array2,
  tk_assign_2d,
  tk_curly_values,
  tk_meta_curly,
  tk_more_curliness,
  tk_point_decl_stmt,
  tk_pv_rest,
  tk_bot_decl_stmt,
  tk_bot_rest,
  tk_assign_operators,
  tk_type,
  tk_type_list,
  tk_type_more,
  tk_primitive_type,
  tk_bot_type,
  tk_assignment_stmt,
  tk_leftHandSide1,
  tk_bot_point1,
  tk_bot_or_point,
  tk_idNum,
  tk_leftHandSideMultiple,
  tk_righHandSide,
  tk_righHandSideMultiple,
  tk_var,
  tk_array,
  tk_brack_pair1,
  tk_array2d,
  tk_values,
  tk_values_more,
  tk_value,
  tk_value_rest,
  tk_funcCall_inside_Value,
  tk_funcCall_inside_Value_rest,
  tk_idBool,
  tk_bool,
  tk_const_value,
  tk_loop_condnal_stmt,
  tk_loop_condnal_stmt_more,
  tk_loop_condnal_stmt_even_more,
  tk_condnal_stmt,
  tk_condnal_stmt_suffix,
  tk_condnal_stmt_more,
  tk_condnal_stmt_even_more,
  tk_expressions,
  tk_more_expression,
  tk_array_arithm_expr,
  tk_array_arithm_expr1,
  tk_arr_mul_div_expr,
  tk_arr_mul_div_expr1,
  tk_arr_un_expr,
  tk_arr_end,
  tk_expression,
  tk_expression1,
  tk_and_expr,
  tk_and_expr1,
  tk_reln_expr,
  tk_reln_expr1,
  tk_rel_op,
  tk_add_sub_expr,
  tk_add_sub_expr1,
  tk_sum_ops,
  tk_mul_div_expr,
  tk_mul_div_expr1,
  tk_mul_ops,
  tk_un_expr,
  tk_prefix_op,
  tk_typcast,
  tk_expression_more,
  tk_arg_list,
  tk_arg_list_more2,
  tk_funcCall_stmt,
  tk_funcCall_stmt_rest,
  tk_otherFunctions,
  tk_function,
  tk_fn_stmts,
  tk_parameter_list,
  tk_parameter_list_more,
  tk_io_stmt,
  tk_bot_stmt,
  tk_for_stmt,
  tk_update_stmt,

  tk_rbrace, //}
  tk_break, //break
  tk_semi_cl,// ;
  tk_continue,  //continue
  tk_id, // [A­Z a­z] [A­Z a­z _ 0­9]* identifier
  tk_assign_op, // =
  tk_comment, // @~
  tk_comma, // , 
  tk_lsquare, //[
  tk_num, //integer [1­9][0­9]* | [0] 
  tk_rsquare,//]
  tk_lbrace, //{
  tk_point, // Point
  tk_col_assign, // :=
  tk_bot, //Bot
  tk_pl_eq, // +=
  tk_void, //void
  tk_int, // int
  tk_float, // float
  tk_boolean, // boolean
  tk_colon, // :
  tk_lpara, //(
  tk_rpara, //)
  tk_true, // true
  tk_false, // false
  tk_rnum, // [0­9]+”.”[0­9]+ 
  tk_if, //if
  tk_else, //else
  tk_log_or, // ||
  tk_log_and, // &&
  tk_lt, // <
  tk_gt, // > 
  tk_log_eq, // ==
  tk_lte, // <=
  tk_gte, // >=
  tk_plus, //+
  tk_minus, //-
  tk_mul, //*
  tk_div, // /
  tk_unary_inc, // ++
  tk_unary_dec, // --
  tk_main, //main
  tk_func, // function
  tk_return, // return
  tk_readi, //readi
  tk_inpop, // >>
  tk_addv, // addV
  tk_fw, // fw
  tk_rt, // rt
  tk_for, //for

  tk_struct, // struct
  tk_velocity, //Velocity
  tk_dot, // .
  tk_undersc, // _
  tk_exit //exit
} TOK;

void print_token(enum Token token);
void print_rule(enum Token token);
