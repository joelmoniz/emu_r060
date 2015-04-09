#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "symbol_table.h"

#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

#ifndef LEXEMES_H
#define LEXEMES_H
#include "lexemes.h"
#endif

#define BUFFER_SIZE 100

void add_ID_to_sym_table(char *name, int declared_line, int declared_position);

//Need to do only one pass!
//What was that joey blabbering about reading in blocks?
// even signs could be delimiters eg 4+3, a+b .etc - taken care of 
// what about ! and != ??
// @~ is a multi-line comment
//TODO: uncomment the code to read in a text file, right now its defaulting to test.txt
//changes made here: writing into op (.lexer output) as integer so its easier to read out 

int isSymbol(char input)
{
  if(input==' ' || input=='+' || input=='-' || input=='*' || input=='/' || input=='[' || input==']' ||
      input=='{' || input=='}' || input=='(' || input==')' || input=='@' || input==';' || input=='=' ||
      input=='.' || input=='-' || input==':' || input=='-' || input=='|' || input=='&' || input=='>' ||
      input=='<' || input=='_' || input == ',') return 1;
    else
      return 0;

}

void writeTofile(FILE* op, enum Token token)
{
  fprintf(op, "%d ", token);
  print_token(token);
}

void print_token(enum Token token) {
  switch(token)
  {
   case tk_main:
   printf( "<tk_main> " );
   break;
   
   case tk_lbrace:
   printf( "<tk_lbrace> " );
   break;
   case tk_rbrace:
   printf( "<tk_rbrace> " );
   break;
   case tk_lpara:
   printf( "<tk_lpara> " );
   break;
   case tk_rpara:
   printf( "<tk_rpara> " );
   break;
   case tk_lsquare:
   printf( "<tk_lsquare> " );
   break;
   case tk_rsquare:
   printf( "<tk_rsquare> " );
   break;
   case tk_struct:
   printf( "<tk_struct> " );
   break;
   case tk_comment:
   printf( "<tk_comment> " );
   break;
   case tk_semi_cl:
   printf( "<tk_semi_cl> " );
   break;
   case tk_assign_op:
   printf( "<tk_assign_op> " );
   break;
   case tk_id:
   printf( "<tk_id> " );
   break;
   case tk_comma:
   printf( "<tk_comma> " );
   break;
   case tk_num:
   printf( "<tk_num> " );
   break;
   case tk_rnum:
   printf( "<tk_rnum> " );
   break;
   case tk_boolean:
   printf( "<tk_boolean> " );
   break;
   case tk_bot:
   printf( "<tk_bot> " );
   break;
   case tk_velocity:
   printf( "<tk_velocity> " );
   break;
   case tk_col_assign:
   printf( "<tk_col_assign> " );
   break;
   case tk_int:
   printf( "<tk_int> " );
   break;
   case tk_float:
   printf( "<tk_float> " );
   break;
   case tk_dot:
   printf( "<tk_dot> " );
   break;
   case tk_colon:
   printf( "<tk_colon> " );
   break;
   case tk_log_or:
   printf( "<tk_log_or> " );
   break;
   case tk_log_and:
   printf( "<tk_log_and> " );
   break;
   case tk_lt:
   printf( "<tk_lt> " );
   break;
   case tk_gt:
   printf( "<tk_gt> " );
   break;
   case tk_log_eq:
   printf( "<tk_log_eq> " );
   break;
   case tk_lte:
   printf( "<tk_lte> " );
   break;
   case tk_gte:
   printf( "<tk_gte> " );
   break;
   case tk_func:
   printf( "<tk_func> " );
   break;
   case tk_return:
   printf( "<tk_return> " );
   break;
   case tk_rt:
   printf( "<tk_rt> " );
   break;
   case tk_addv:
   printf( "<tk_addv> " );
   break;
   case tk_pl_eq:
   printf( "<tk_pl_eq> " );
   break;
   case tk_true:
   printf( "<tk_true> " );
   break;
   case tk_false:
   printf( "<tk_false> " );
   break;
   case tk_inpop:
   printf( "<tk_inpop> " );
   break;
   case tk_unary_inc:
   printf( "<tk_unary_inc> " );
   break;
   case tk_unary_dec:
   printf( "<tk_unary_dec> " );
   break;
   case tk_undersc:
   printf( "<tk_ tk_undersc> " );
   break;
   case tk_fw:
   printf( "<tk_fw> " );
   break;
   case tk_point:
   printf( "<tk_point> " );
   break;
   case tk_void:
   printf( "<tk_void> " );
   break;
   case tk_readi:
   printf( "<tk_readi> " );
   break;
   case tk_break:
   printf( "<tk_break> " );
   break;
   case tk_continue:
   printf( "<tk_continue> " );
   break;
   case tk_exit:
   printf( "<tk_exit> " );
   break;
   case tk_for:
   printf( "<tk_for> " );
   break;
   case tk_if:
   printf( "<tk_if> " );
   break;
   case tk_else:
   printf( "<tk_else> " );
   break;
   case tk_plus:
   printf( "<tk_plus> " );
   break;
   case tk_minus:
   printf( "<tk_minus> " );
   break;
   case tk_mul:
   printf( "<tk_mul> " );
   break;
   case tk_div:
   printf( "<tk_div> " );
   break;
   default:
   printf("%d ", token);
   break;    
  } 
}

char buf[2][BUFFER_SIZE];
int buf_in_use;
int at_eof;
int read_size[2];
int curr_locn;

char read_next_char(FILE * ip) {
  curr_locn++;
  if (curr_locn == read_size[buf_in_use] - 1 && read_size[buf_in_use]  < BUFFER_SIZE) 
    at_eof = 1;
  else if (curr_locn >= 100) {
    buf_in_use = !buf_in_use;
    read_size[buf_in_use] = fread(buf[buf_in_use], BUFFER_SIZE, 1, ip);
    curr_locn = 0;
  }
  return buf[buf_in_use][curr_locn];
}

enum Token lexer(FILE * ip, FILE * op)
{

  buf_in_use = 1;
  at_eof = 0;
  read_size[0] = read_size[1] = 0;
  curr_locn = 100;

  char input,next,prev; //our work-horse!
  input = ' ';
  int line_no, column_no;
  line_no=1;
  column_no=0;
  prev = '\0';

    while(!at_eof)
    { 
      if (prev != '\0')
        input = prev;
      else
        input = read_next_char(ip);
      
      if(input == EOF || input == 0)
        break;
           
      if(input == '\n')
      {
        line_no++;
        column_no = 0;
        prev = '\0';
        continue;
      }

      if(input == ' ') //stripping out extra white spaces 
      { 
        column_no++;
        prev = '\0';
        continue;
      }

      if(input == '@')  //stripping out comments
      {
        column_no++;
        
        if(read_next_char(ip) == '~')
        {
          input = '~';
          column_no++;
          while(input != EOF)
          {
            input = read_next_char(ip);
            column_no++;
            if (input == '\n') {
              column_no = 0;
              line_no++;
            }
            else if (input == '~') {
              input = read_next_char(ip);
              column_no++;
              if (input == '@') {
                break;
              }
            }
          }
          if (input == EOF) {
            printf("\nError: EOF without terminating comment\n");
            return tk_null;
          }
          prev = '\0';
          continue;
        }
        else {
          printf("\n%d : %d Unrecognized symbol @\n",line_no,column_no);
          return tk_null;
        }
      }

      if(isalnum(input)) //could be several things... 
      { 
        column_no++;
        if(isalpha(input))
        {
          char inp[101]; //max size of identifier is 100
          int i = 0;
         do
          {
            inp[i] = input;
            if(i > 100)
            {
              printf("\n%d : %d identifier too big!\n",line_no,column_no);
              while(isSymbol(input)!=1)
              {
                input = read_next_char(ip);
                column_no++;
                if(input=='\n')
                {
                  column_no = 0;
                  line_no++;
                  break;
                }
              }
              prev = input;
              continue;
            }
          
            input = read_next_char(ip);
            column_no++;
            i=i+1;
          }while(isSymbol(input)==0);
        
          inp[i] = '\0';
          prev = input;

          if(inp[0] == 'a' && inp[1] == 'd' && inp[2] == 'd' 
            && inp[3] == 'V' && inp[4] == '\0'){ // addV
            writeTofile(op,tk_addv); 
            prev = '\0'; 
            continue;
          }
          else if (inp[0] == 'b') { // boolean OR break
            if (inp[1] == 'o' && inp[2] == 'o' && inp[3] == 'l' 
              && inp[4] == 'e' && inp[5] == 'a' && inp[6] == 'n' && inp[7] == '\0') {
              writeTofile(op,tk_boolean); 
              prev = '\0'; 
              continue;
            }
            else if (inp[1] == 'r' && inp[2] == 'e' && inp[3] == 'a' 
              && inp[4] == 'k' && inp[5] == '\0') {
              writeTofile(op,tk_break); 
              prev = '\0'; 
              continue;
            }
            else {
              writeTofile(op,tk_id); 
              add_ID_to_sym_table(inp, line_no, column_no); 
              prev = '\0'; 
              continue;
            }
          }
          else if(inp[0] == 'B' && inp[1] == 'o' && inp[2] == 't' && inp[3] == '\0') { 
            writeTofile(op,tk_bot); 
            prev = '\0'; 
            continue;
          }
          else if(inp[0] == 'c' && inp[1] == 'o' && inp[2] == 'n' 
            && inp[3] == 't' && inp[4] == 'i' && inp[5] == 'n' 
            && inp[6] == 'u' && inp[7] == 'e' && inp[8] == '\0') {
            writeTofile(op,tk_continue); 
            prev = '\0'; 
            continue;
          }
          else if(inp[0] == 'e' && inp[1] == 'l' && inp[2] == 's' && inp[3] == 'e'
             && inp[4] == '\0'){ 
            writeTofile(op,tk_else) ; 
            prev = '\0'; 
            continue;
          }
          else if (inp[0] == 'f') {
            if(inp[1] == 'l' && inp[2] == 'o' && inp[3] == 'a' 
                && inp[4] == 't' && inp[5] == '\0') {
              writeTofile(op,tk_float); 
              prev = '\0'; 
              continue;
            }
            else if (inp[1] == 'u' && inp[2] == 'n' && inp[3] == 'c' 
                && inp[4] == 't' && inp[5] == 'i' && inp[6] == 'o' && inp[7] == 'n'
                && inp[8] == '\0') {
              writeTofile(op,tk_func); 
              prev = '\0'; 
              continue;
            }
            else if(inp[1] == 'a' && inp[2] == 'l' && inp[3] == 's' 
                && inp[4] == 'e' && inp[5] == '\0') {
              writeTofile(op,tk_float); 
              prev = '\0'; 
              continue;
            }
            else if (inp[1] == 'w' && inp[2] == '\0') {
              writeTofile(op,tk_fw); 
              prev = '\0'; 
              continue;
            }
            else if (inp[1] == 'o' && inp[2] == 'r' && inp[3] == '\0') {
              writeTofile(op,tk_for); 
              prev = '\0'; 
              continue;
            }
            else {
              writeTofile(op,tk_id); 
              add_ID_to_sym_table(inp, line_no, column_no); 
              prev = '\0'; 
              continue;
            }
          }
          else if (inp[0] == 'i') {
            if (inp[1] == 'n' && inp[2] == 't' && inp[3] == '\0') {
              writeTofile(op,tk_int); 
              prev = '\0'; 
              continue;
            }
            else if (inp[1] == 'f' && inp[2] == '\0') {
              writeTofile(op,tk_if); 
              prev = '\0'; 
              continue;
            }
            else {
              writeTofile(op,tk_id); 
              add_ID_to_sym_table(inp, line_no, column_no); 
              prev = '\0'; 
              continue;
            }
          }
          else if(inp[0] == 'm' && inp[1] == 'a' && inp[2] == 'i' && inp[3] == 'n'
             && inp[4] == '\0') { 
            writeTofile(op, tk_main); 
            prev = '\0'; 
            continue;
          } 
          else if(inp[0] == 'P' && inp[1] == 'o' && inp[2] == 'i' && inp[3] == 'n'
             && inp[4] == 't' && inp[5] == '\0') {
            writeTofile(op,tk_point); 
            prev = '\0'; 
            continue;
          }
          else if(inp[0] == 'r' && inp[1] == 'e' && inp[2] == 't' 
            && inp[3] == 'u' && inp[4] == 'r' && inp[5] == 'n' 
            && inp[6] == '\0') {
            writeTofile(op,tk_return); 
            prev = '\0'; 
            continue;
          }
          else if(inp[0] == 'r') {
            if (inp[1] == 't' && inp[2] == '\0') {
              writeTofile(op,tk_rt); 
              prev = '\0'; 
              continue;
            }
            else if(inp[1] == 'e' && inp[2] == 'a' && inp[3] == 'd' 
                && inp[4] == 'i' && inp[5] == '\0') {
              writeTofile(op,tk_readi); 
              prev = '\0'; 
              continue;
            }
            else {
              writeTofile(op,tk_id); 
              add_ID_to_sym_table(inp, line_no, column_no); 
              prev = '\0'; 
              continue;
            }
          }
          else if(inp[0] == 's' && inp[1] == 't' && inp[2] == 'r' 
            && inp[3] == 'u' && inp[4] == 'c' && inp[5] == 't' 
            && inp[6] == '\0'){ 
            writeTofile(op, tk_struct); 
            prev = '\0'; 
            continue;
          }
          else if(inp[0] == 't' && inp[1] == 'r' && inp[2] == 'u' && inp[3] == 'e'
             && inp[4] == '\0') { 
            writeTofile(op,tk_true); 
            prev = '\0'; 
            continue;
          }
          else if(inp[0] == 'v' && inp[1] == 'o' && inp[2] == 'i' && inp[3] == 'd'
             && inp[4] == '\0') {
            writeTofile(op,tk_void); 
            prev = '\0'; 
            continue;
          }
          else { 
            writeTofile(op,tk_id); 
            add_ID_to_sym_table(inp, line_no, column_no); 
            prev = '\0'; 
            continue;
          }
        }

        if(isdigit(input)) 
        {
          column_no++;
          char inp[100];
          int i = 0;
          int flag = 0;
          //check for num, rnum or illegal identifier like 12ab
          do
          {
            inp[i++]= input;
            input=read_next_char(ip);
            column_no++;
            if(isalpha(input)) //1.3e02 format not supported
            {
              flag = 1;
              printf("\nError,invalid identifier at %d : %d",line_no,column_no);
              while(isSymbol(input)!=1){input=read_next_char(ip);column_no++;} //scan till delimiter
            }
          } while(isSymbol(input)!=1);

          if(!flag && input!='.')
          {
            prev = input;
            writeTofile(op,tk_num);
            continue;
          }
          else if(input == '.')
          {
            do
            {
              inp[i++]= input;
              input=read_next_char(ip);
              column_no++;
              if(isalpha(input)) //1.3e02 format not supported
              {
                flag = 1;
                printf("\nError,invalid identifier at %d : %d",line_no,column_no);
                while(isSymbol(input)!=1){input=read_next_char(ip);column_no++;} //scan till delimiter
              }
            }while(isSymbol(input)!=1);
            prev = input;
            writeTofile(op,tk_rnum);
            continue;
          }
        }
      }

      if(input == '{'){ writeTofile(op,tk_lbrace); prev = '\0'; continue;}
      if(input == '}'){ writeTofile(op,tk_rbrace); prev = '\0'; continue;}
      if(input == '('){ writeTofile(op,tk_lpara);prev = '\0'; continue;}
      if(input == ')'){ writeTofile(op,tk_rpara);prev = '\0'; continue;}
      if(input == '['){ writeTofile(op,tk_lsquare);prev = '\0'; continue;}
      if(input == ']'){ writeTofile(op,tk_rsquare);prev = '\0'; continue;}
      if(input == '['){ writeTofile(op,tk_lsquare);prev = '\0'; continue;}
      if(input == ';'){ writeTofile(op,tk_semi_cl);prev = '\0'; continue;}
      if(input == ','){ writeTofile(op,tk_comma);prev = '\0'; continue;}
      if(input == '.'){ writeTofile(op,tk_dot);prev = '\0'; continue;}

      if(input == ':')
      {
        next = read_next_char(ip);
        column_no++;
        if(next == '='){ writeTofile(op,tk_col_assign);prev = '\0'; continue;}
        else{ prev = input;writeTofile(op,tk_colon);continue;}
      }

      if(input == '=')
      { next = read_next_char(ip);
        column_no++;
        if( next == '='){ writeTofile(op,tk_log_eq);prev = '\0'; continue;}
        else {prev = input; writeTofile(op,tk_assign_op);continue;} 
      }

      if(input == '_')
      { writeTofile(op,tk_undersc);prev = '\0'; continue;} 

      if(input == '|')
      {
        next = read_next_char(ip);
        column_no++;
        if(next == '|')
        { writeTofile(op,tk_log_or);prev = '\0'; continue;}
        else { printf("\nError: unknown symbol '|' at %d : %d\n",line_no,column_no ); }
      }
      
      if(input == '&')
      {
        next = read_next_char(ip);
        column_no++;
        if(next == '&')
        { writeTofile(op,tk_log_and);prev = '\0'; continue;}
        else{ printf("\nError: unknown symbol '&' at %d : %d\n",line_no,column_no );}
      }

      if(input == '+')  
      {
        next = read_next_char(ip);
        column_no++;
        if(next == '+'){ writeTofile(op,tk_unary_inc); prev = '\0'; continue;}
        else if(next == '='){ writeTofile(op,tk_pl_eq);prev = '\0'; continue;}
        else { prev = input; writeTofile(op,tk_plus);continue;}
      }

      if(input == '-')  
      {
        next = read_next_char(ip);
        column_no++;
        if(next == '-'){ writeTofile(op,tk_unary_dec);prev = '\0'; continue;}
        else{ prev = input; writeTofile(op,tk_minus);continue;}
      }

      if(input == '*'){ writeTofile(op,tk_mul);prev = '\0'; continue;}

      if(input == '/'){ writeTofile(op,tk_div);prev = '\0'; continue;}

      if(input == '<')
      { next = read_next_char(ip);
        column_no++;
        if(next == '='){writeTofile(op,tk_lte);prev = '\0'; continue;}
        else
        {prev = input; writeTofile(op,tk_lt);continue;}
      }

      if(input == '>')
      {
        next = read_next_char(ip);
        column_no++;

        if(next == '='){ writeTofile(op,tk_gte);prev = '\0'; continue;}
        else if(next == '>'){ writeTofile(op,tk_inpop);prev = '\0'; continue;}
        else{ prev = input; writeTofile(op,tk_gt);continue;}
      }
     
      else 
      {
        if (input != ' ')
          printf("\nUnknown symbol %c (=%d) at %d:%d\n",input,(int)input,line_no,column_no);
      } 
    }
  }

void init_symbol_table() {
  int i;
  for (i = 0; i < hash_size; i++) {
    symbol_table_hash[i] = NULL;
  }
}

void add_ID_to_sym_table(char *name, int declared_line, int declared_position) {
  int index = get_hash_value(name);
  symbol_entry *s = symbol_table_hash[index];
  symbol_entry *prev = NULL;

  referred *r = (referred *) malloc(sizeof(referred));
  r->line = declared_line;
  r->loc = declared_position;
  r->next = NULL;

  while ( s != NULL) {
    if (strcmp(name, s->name) != 0) {
      prev = s;
      s = s->next;
    }
    else {// entry found => add occurance to symbol table
      r->next = s->refd;
      s->refd = r;
      return;
    }
  }

  s = (symbol_entry *) malloc(sizeof(symbol_entry));
  s->name = (char *) malloc(sizeof(name));
  strcpy(s->name, name);
  s->token_type = tk_id;
  s->dtype = dt_unk;
  s->has_value = 0;
  s->scope = -1;
  s->declared_line = declared_line;
  s->declared_position = declared_position;
  s->refd = NULL;
  s->misc = vt_unk;
  s->next = symbol_table_hash[index];

  symbol_table_hash[index] = s;
}

void free_symbol_table() {
  int i;
  for (i = 0; i < hash_size; i++) {
    while (symbol_table_hash[i] != NULL) {
      symbol_entry *s = symbol_table_hash[i];
      symbol_table_hash[i] = s->next;
      free(s->name);

      while (s->refd != NULL) {
        referred *r = s->refd;
        s->refd = r->next;
        free(r);
      }

      free(s);
    }
  }
}

int get_hash_value(unsigned char *name) //the djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
{
  int hash = 5381;
  int c;

  while ((c = *name++) != '\0')
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return (hash%hash_size);
}

void print__symbol_table() {
  int i = 0;
  referred *r;
  symbol_entry *s;

  for (i = 0;i < hash_size; i++) {
    if (symbol_table_hash[i] != NULL) {
      printf("\n\n%d\n", i);
      printf("===\n\n");
      
      s = symbol_table_hash[i];
      while (s != NULL) {
        printf("name: %s\n token: %d\n type: %d\n has_val: %d\n scope: %d\n line: %d\n posn: %d\n refd: ", 
          s->name, s->token_type, s->dtype, s->has_value, 
          s->scope, s->declared_line, s->declared_position);
        r = s->refd;
        while (r != NULL) {
          printf("<%d, %d>", r->line, r->loc);
          if (r->next != NULL)
            printf(", ");
          r = r->next;
        }
        printf("\n misc: %d\n\n", s->misc);
        s = s->next;
      }
    }
  }
}


int main(int argc, char * argv[])
{   
   /* if(argc!=2)
    {
        printf("FATAL ERROR!! : No input specified or too many parameters \n");
        exit(1);
    }
*/
    init_symbol_table();
    FILE * ip = fopen("test.txt","r");
    FILE * op = fopen("test.lexer","w"); //WARNING: argv[1] is changed here
    if (ip == NULL || op == NULL)
    {
        printf("Error opening file, check permissions! \n");
    }
    lexer(ip,op);
    fclose(ip);
    fclose(op);
//    add_ID_to_sym_table("joel", 3, 7);
//    add_ID_to_sym_table("gokul", 2, 2);
//    add_ID_to_sym_table("test", 42, 42);
    print__symbol_table();
    free_symbol_table();
    return 0;
}