#define NO_OF_TERMINALS 50 //TODO: not fixed yet

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
  tk_comment, // @~
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

tk_leftHandSide1
tk_unary_stmts
tk_funcCall_stmt_rest
tk_array2
tk_mul_ops
tk_assign_2d
tk_righHandSide
tk_global_vars
tk_arg_list_more2
tk_brack_pair1
tk_funcCall_stmt
tk_typcast
tk_value
tk_rte
tk_loop_stmt
tk_other_stmt
tk_un_expr
tk_prefix_op
tk_add_sub_expr
tk_funcCall_inside_Value
tk_rel_op
tk_more_curliness
tk_loop_stmts
tk_gen_stmt
tk_primitive_declaration_stmt
tk_idNum
tk_value_rest
tk_assignment_stmt
tk_primitive_type
tk_arr_un_expr
tk_add_sub_expr1
tk_arr_end
tk_assign_comma
tk_pv_rest
tk_expression_more
tk_eps
tk_bot_rest
tk_array_arithm_expr1
tk_curly_values
tk_loop_condnal_stmt
tk_leftHandSideMultiple
tk_lp_stmt
tk_array
tk_meta_curly
tk_and_expr1
tk_mul_div_expr
tk_reln_expr1
tk_function
tk_var
tk_array2d
tk_mainFunction
tk_arr_mul_div_expr1
tk_parameter_list_more
tk_unary_stmt_more
tk_reln_expr
tk_global_assignment
tk_null
tk_fn_stmts
tk_righHandSideMultiple
tk_bot_type
tk_more_expression
tk_bot_point1
tk_and_expr
tk_bot_stmt
tk_func_ass
tk_arr_mul_div_expr
tk_assign_operators
tk_const_value
tk_update_stmt
tk_funcCall_inside_Value_rest
tk_type_list
tk_array_arithm_expr
tk_point_decl_stmt
tk_bot_decl_stmt
tk_assign_more
tk_expressions
tk_arg_list
tk_parameter_list
tk_condnal_stmt
tk_values
tk_expression
tk_loop_condnal_stmt_even_more
tk_otherFunctions
tk_loop_condnal_stmt_more
tk_stmt
tk_values_more
tk_stmts
tk_io_stmt
tk_expression1
tk_sum_ops
tk_type
tk_condnal_stmt_suffix
tk_type_more
tk_for_stmt
tk_idBool

} TOK;

void print_token(enum Token token);
