a = ["RBRACE","BREAK","SEMI_CL","CONTINUE","ID","ASSIGN_OP","<comment>","COMMA","LSQUARE","<NUM>","RSQUARE","LBRACE","POINT","COL_ASSIGN","BOT","PL_EQ","VOID","INT","FLOAT","BOOLEAN","NUM","COLON","LPARA","RPARA","TRUE","FALSE","RNUM","IF","ELSE","LOG_OR","LOG_AND","LT","GT","LOG_EQ","LTE","RTE","PLUS","MINUS","MULTIPLY","DIVIDE","UNARY_INCR","UNARY_DECR","MAIN","FUNCTION","RETURN","READI","INPOP","ADDV","FW","RT","FOR","$"]
print len(a)
a = [ "tk_"+i.lower() for i in a]
for i in a:
	pass
b = set(a)
c = ''' tk_rbrace, tk_break, 
  tk_semi_cl,
  tk_continue, 
  tk_main, 
  tk_lbrace,
  tk_lpara,  
  tk_rpara,  
  tk_lsquare,  
  tk_rsquare,  
  tk_comment,
  tk_assign_op,  
  tk_id,  
  tk_comma,  
  tk_num,  
  tk_rnum,  
  tk_boolean,  
  tk_bot,  
  tk_col_assign,  
  tk_int,  
  tk_float,  
  tk_dot,  
  tk_colon,  
  tk_log_or,  
  tk_log_and,  
  tk_lt,  
  tk_gt,  
  tk_log_eq,  
  tk_lte,  
  tk_rte,  
  tk_function,  
  tk_return,  
  tk_rt,  
  tk_addv,  
  tk_pl_eq,  
  tk_true,  
  tk_false,  
  tk_inpop,  
  tk_unary_incr,  
  tk_unary_decr,  
  tk_undersc,  
  tk_fw,  
  tk_point,  
  tk_void,  
  tk_readi,  
  tk_exit,  
  tk_for,  
  tk_if,  
  tk_else,  
  tk_plus,  
  tk_minus,  
  tk_multiply,  
  tk_divide  '''
c = c.split(',')
c = set([i.strip() for i in c])
d = b.difference(c)
e = c.difference(b)
print "in hacking, not in enum"
print d 
print "in enum not in hacking"
print e