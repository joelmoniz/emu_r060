#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum Token {
  
  tk_eof ,
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
  tk_rt, //rt
  tk_for, //for
  tk_if, //if
  tk_else, //else
  tk_plus, //+
  tk_minus, //-
  tk_mul, //*
  tk_div // /
  
};

int isSymbol(char input)
{
  if(input!=' ' || input!='+' || input!='-' || input!='*' || input!='/' || input!='[' || input!=']' ||
      input!='{' || input!='}' || input!='(' || input!=')' || input!='@' || input!=';' || input!='=' ||
      input!='.' || input!='-' || input!=':' || input!='-' || input!='|' || input!='&' || input!='>' ||
      input!='<' || input!='_') return 1;
    else
      return 0;

}
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
    // even signs could be delimiters eg 4+3, a+b .etc
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
        if(isalnum(input)) //could be several things... //TODO possible different delimiters
        { 
          if(isalpha(input))
          {
            char inp[101]; //max size of identifier is 100
            int i = 0;
            do
            {
              inp[i++] = input;
              if(i > 100)
              {
                printf("identifier too big!\n");
                exit(1);
              }
              input = fgetc(ip);
            }while(isSymbol(input)!=1);
            inp[i] = '/0';
            fseek(ip,-1,SEEK_CUR);

            if(strcmp(inp,"main") == 0) return tk_main;
            else if(strcmp(inp,"struct") == 0) return tk_struct;
            else if(strcmp(inp,"boolean") == 0) return tk_bool;
            else if(strcmp(inp,"Bot") == 0) return tk_bot ;
            else if(strcmp(inp,"Velocity") == 0) return tk_velocity;
            else if(strcmp(inp,"int") == 0) return tk_int;
            else if(strcmp(inp,"float") == 0) return tk_float;
            else if(strcmp(inp,"function") == 0) return tk_func;
            else if(strcmp(inp,"return") == 0) return tk_return;
            else if(strcmp(inp,"rt") == 0) return tk_rt;
            else if(strcmp(inp,"addV") == 0) return tk_addv ;
            else if(strcmp(inp,"true") == 0) return tk_true ;
            else if(strcmp(inp,"false") == 0) return tk_false ;
            else if(strcmp(inp,"fw") == 0) return tk_fw ;
            else if(strcmp(inp,"Point") == 0) return tk_point ;
            else if(strcmp(inp,"void") == 0) return tk_void ;
            else if(strcmp(inp,"readi") == 0) return tk_readi ;
            else if(strcmp(inp,"break") == 0) return tk_break ;
            else if(strcmp(inp,"continue") == 0) return tk_continue ;
            else if(strcmp(inp,"exit") == 0) return tk_exit ;
            else if(strcmp(inp,"rt") == 0) return tk_rt ;
            else if(strcmp(inp,"for") == 0) return tk_for ;
            else if(strcmp(inp,"if") == 0) return tk_if ;
            else if(strcmp(inp,"else") == 0) return tk_else ;
            else return tk_id;
          }


          if(isnum(input)) //TODO
          {
            char inp[100];
            //check for num, rnum or illegal identifier like 12ab
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
          else 
          {
            fseek(ip,-1, SEEK_CUR);
            return tk_colon;
          }
        }

        if(input == '=')
        { next = fgetc(ip);
          if( next == '=')
          {
            return tk_log_eq;
          }
          else 
          {
            return tk_assign_op;
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

        if(input == '+')  
        {
          next = fgetc(ip);
          if(next == '+')
          {
            return tk_unary_inc;
          }
          else if(next == '=')
          {
            return tk_pl_eq;
          }
          else
          {
            fseek(ip,-1, SEEK_CUR);
            return tk_plus;
          }
        }

        if(input == '-')  
        {
          next = fgetc(ip);
          if(next == '-')
          {
            return tk_unary_dec;
          }
          else
          {
            fseek(ip,-1, SEEK_CUR);
            return tk_minus;
          }
        }

        if(input == '*')
        {
          return tk_mul;
        }

        if(input == '/')
        {
          return tk_mul;
        }

        if(input == '<')
        {
          if(next == '=')
          {
            return tk_lte;
          }
          else
          {
            fseek(ip,-1, SEEK_CUR);
            return tk_lt;
          }
        }

        if(input == '>')
        {
          next = fgetc(ip);

          if(next == '=')
          {
            return tk_gte;
          }
          else if(next == '>')
          {
            return tk_inpop;
          }
          else
          {
            fseek(ip,-1, SEEK_CUR);
            return tk_gt;
          }
        }
    }
    return 0;
}
