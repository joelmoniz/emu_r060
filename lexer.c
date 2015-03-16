#include <stdio.h>
#include <string.h>

//TODO: hash table of keywords
enum Token {
  
  tk_eof ,
  tk_ main, //main
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
  tk_rt, //rt
  tk_for, //for
  tk_if, //if
  tk_else, //else
  
};

int main(int argc, char * argv[])
{   
    if(argc!=2)
    {
        printf("FATAL ERROR!! : No input specified or too many parameters \n");
        exit(1);
    }

    FILE * ip = fopen(argv[1],"r");
    FILE * op = fopen(strcat(argv[1],".lexer"),"w"); //WARNING: argv[1] is changed here
    if (ip == NULL || op == NULL)
    {
        printf("Error opening file, check permissions!");
    }

    char input,next; //our work-horse!

    //Need to do only one pass!
    //DFAs? get from Joey or discuss -> DFAs requiring a check of id, constants or keywords
    //What was that joey blabbering about reading in blocks?
    
    while(input = fgetc(ip))
    {   
        if(input == ' ') //stripping out extra white spaces 
        {
          do
          {
            input = fgetc(ip);

          }while(input==' ');
        }

        if(input == '@')  //stripping out comments
        {
          if(fgetc(ip) == '~')
          {
            do
            {
              input = fgetc(ip);
            }while(input!='@');
            
            continue;
          }
          else
          {
            //error handling routine TODO
          }
        }

        if(input == '{')
        {
          return tk_lbrace;
        }

        if(input == '}')
        {
          return tk_rbrace;
        }


        if(input == '(')
        {
          return tk_lpara;
        }

        if(input == ')')
        {
          return tk_rpara;
        }

        if(input == '[')
        {
          return tk_lsquare;
        }

        if(input == ']')
        {
          return tk_rsquare;
        }

        if(input == '[')
        {
          return tk_lsquare;
        }

        if(input == ';')
        {
          return tk_semi_cl;
        }

        if(input == ',')
        {
          return tk_comma;
        }

        if(input == '.')
        {
          return tk_dot;
        }

        if(input == ':')
        {
          next = fgetc(ip);
          if(next == '=')
          {
            return tk_col_assign;
          }
          else if (next == ' ')
          {
            return tk_colon;
          }
          else
          {
            //error handling 
          }
        }

        if(input == '=')
        { next = fgetc(ip);
          if( next == '=')
          {
            return tk_log_eq;
          }

          else if (next == ' ')
          {
            return tk_assign_op;
          }

          else
          {
            //error handling 
          } 
        }

        if(input == '_')
        {
          return tk_undersc;
        } 

        if(input == '|')
        {
          next = fgetc(ip);
          if(next == '|')
          {
            return tk_log_or;
          }
          else
          {
            //error handling
          }
        }
        
        if(input == '&')
        {
          next = fgetc(ip);
          if(next == '&')
          {
            return tk_log_and;
          }
          else
          {
            //error handling
          }
        }

        if(input == '+')  //TODO: just + ??
        {
          next = fgetc(ip);
          if(next == '+')
          {
            return tk_unary_inc;
          }
          else if(next == ' ')
          {
            //its a + sign fags, TODO
          }
          else if(next == '=')
          {
            return tk_pl_eq;
          }
          else
          {
            //error handling
          }
        }

        if(input == '-')  //TODO: just + ??
        {
          next = fgetc(ip);
          if(next == '-')
          {
            return tk_unary_dec;
          }
          else if(next == ' ')
          {
            //its a - sign fags, TODO
          }
          else
          {
            //error handling
          }
        }

        if(input == '<')
        {
          next = fgetc(ip);
          if(next == ' ')
          {
            return tk_lt;
          }
          else if(next == '=')
          {
            return tk_lte;
          }
          else
          {
            //error handle
          }
        }

        if(input == '>')
        {
          next = fgetc(ip);
          if(next == ' ')
          {
            return tk_gt;
          }
          else if(next == '=')
          {
            return tk_gte;
          }
          else if(next == '>')
          {
            return tk_inpop;
          }
          else
          {
            //error handle
          }
        }

    }

    return 0;
}
