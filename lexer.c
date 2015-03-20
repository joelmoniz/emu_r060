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
  fputc(token,op);
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
   case tk_bool:
   printf( "<tk_bool> " );
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
    
  } 
}

enum Token lexer(FILE * ip, FILE * op)
{
  char input,next; //our work-horse!
  input = ' ';
    int line_no, column_no;
    line_no=1;
    column_no=0;
    while(input != EOF)
    { input = fgetc(ip);
      if(input == EOF)break;
      column_no++;
      if(input == '\n')
      {
        line_no++;
        column_no = 0;
        continue;
      }

        if(input == ' ') //stripping out extra white spaces 
        { 
          do
          {
            input = fgetc(ip);
            column_no++;
          }while(input==' ');
          fseek(ip,-1,SEEK_CUR);
          continue;
        }

        if(input == '@')  //stripping out comments
        {
          if(fgetc(ip) == '~')
          {
            do
            {
              input = fgetc(ip);
            }while(input!='@' && input != EOF);
            continue;
          }
        }
        // TODO:
        // 1. Make sure comment stops at ~@, not at @
        // 2. Throw an error if file ends without a closing comment symbol

        if(isalnum(input)) //could be several things... 
        { 
          if(isalpha(input))
          {
            char inp[101]; //max size of identifier is 100
            int i = 0;
           do
            {
             
              inp[i] = input;
              if(i > 100)
              {
                printf("%d : %d identifier too big!\n",line_no,column_no);
                while(isSymbol(input)!=1)
                {
                  input = fgetc(ip);
                  column_no++;
                  if(input=='\n')
                  {
                    column_no = 0;
                    line_no++;
                    break;
                  }
                }
                continue;
              }
            
              input = fgetc(ip);
              i=i+1;
            }while(isSymbol(input)==0);
          
            inp[i] = '\0';
            fseek(ip,-1,SEEK_CUR);

            if(strcmp(inp,"main") == 0) { writeTofile(op, tk_main); continue;} 
            else if(strcmp(inp,"struct") == 0){ writeTofile(op, tk_struct); continue;}
            else if(strcmp(inp,"boolean") == 0) { writeTofile(op,tk_bool); continue;}
            else if(strcmp(inp,"Bot") == 0){ writeTofile(op,tk_bot); continue;}
            else if(strcmp(inp,"Velocity") == 0){ writeTofile(op,tk_velocity); continue;}
            else if(strcmp(inp,"int") == 0){ writeTofile(op,tk_int); continue;}
            else if(strcmp(inp,"float") == 0) {writeTofile(op,tk_float); continue;}
            else if(strcmp(inp,"function") == 0) {writeTofile(op,tk_func); continue;}
            else if(strcmp(inp,"return") == 0) {writeTofile(op,tk_return); continue;}
            else if(strcmp(inp,"rt") == 0) {writeTofile(op,tk_rt); continue;}
            else if(strcmp(inp,"addV") == 0){ writeTofile(op,tk_addv); continue;}
            else if(strcmp(inp,"true") == 0){ writeTofile(op,tk_true); continue;}
            else if(strcmp(inp,"false") == 0) {writeTofile(op,tk_false); continue;}
            else if(strcmp(inp,"fw") == 0){ writeTofile(op,tk_fw); continue;}
            else if(strcmp(inp,"Point") == 0) {writeTofile(op,tk_point); continue;}
            else if(strcmp(inp,"void") == 0) {writeTofile(op,tk_void); continue;}
            else if(strcmp(inp,"readi") == 0) {writeTofile(op,tk_readi); continue;}
            else if(strcmp(inp,"break") == 0) {writeTofile(op,tk_break); continue;}
            else if(strcmp(inp,"continue") == 0) {writeTofile(op,tk_continue); continue;}
            else if(strcmp(inp,"exit") == 0){ writeTofile(op,tk_exit); continue;}
            else if(strcmp(inp,"rt") == 0) {writeTofile(op,tk_rt); continue;}
            else if(strcmp(inp,"for") == 0){ writeTofile(op,tk_for) ; continue;}
            else if(strcmp(inp,"if") == 0) { writeTofile(op,tk_if) ; continue;}
            else if(strcmp(inp,"else") == 0){ writeTofile(op,tk_else) ; continue;}
            else { writeTofile(op,tk_id); add_ID_to_sym_table(inp, line_no, column_no); continue;}
          }


          if(isdigit(input)) 
          {
            char inp[100];
            int i = 0;
            int flag = 0;
            //check for num, rnum or illegal identifier like 12ab
            do
            {
              inp[i++]= input;
              input=fgetc(ip);
              if(isalpha(input)) //1.3e02 format not supported
              {
                flag = 1;
                printf("Error,invalid identifier at %d : %d",line_no,column_no);
                while(isSymbol(input)!=1){input=fgetc(ip);} //scan till delimiter
              }
            }while(isSymbol(input)!=1);

            if(!flag && input!='.')
            {
              fseek(ip,-1,SEEK_CUR);
              writeTofile(op,tk_num);
              continue;
            }

            else if(input == '.')
            {
              do
            {
              inp[i++]= input;
              input=fgetc(ip);
              if(isalpha(input)) //1.3e02 format not supported
              {
                flag = 1;
                printf("Error,invalid identifier at %d : %d",line_no,column_no);
                while(isSymbol(input)!=1){input=fgetc(ip);} //scan till delimiter
              }
            }while(isSymbol(input)!=1);
              writeTofile(op,tk_rnum);
              continue;
            }
            
          }
        }

        if(input == '{'){ writeTofile(op,tk_lbrace); continue;}
        if(input == '}'){ writeTofile(op,tk_rbrace); continue;}
        if(input == '('){ writeTofile(op,tk_lpara);continue;}
        if(input == ')'){ writeTofile(op,tk_rpara);continue;}
        if(input == '['){ writeTofile(op,tk_lsquare);continue;}
        if(input == ']'){ writeTofile(op,tk_rsquare);continue;}
        if(input == '['){ writeTofile(op,tk_lsquare);continue;}
        if(input == ';'){ writeTofile(op,tk_semi_cl);continue;}
        if(input == ','){ writeTofile(op,tk_comma);continue;}
        if(input == '.'){ writeTofile(op,tk_dot);continue;}

        if(input == ':')
        {
          next = fgetc(ip);
          if(next == '='){ writeTofile(op,tk_col_assign);continue;}
          else{ fseek(ip,-1, SEEK_CUR);writeTofile(op,tk_colon);continue;}
        }

        if(input == '=')
        { next = fgetc(ip);
          if( next == '='){ writeTofile(op,tk_log_eq);continue;}
          else {fseek(ip,-1, SEEK_CUR); column_no--; writeTofile(op,tk_assign_op);continue;} 
        }

        if(input == '_')
        { writeTofile(op,tk_undersc);continue;} 

        if(input == '|')
        {
          next = fgetc(ip);
          if(next == '|')
          { writeTofile(op,tk_log_or);continue;}
          else { printf("Error: unknown symbol '|' at %d : %d\n",line_no,column_no ); }
        }
        
        if(input == '&')
        {
          next = fgetc(ip);
          if(next == '&')
          { writeTofile(op,tk_log_and);continue;}
          else{ printf("Error: unknown symbol '&' at %d : %d\n",line_no,column_no );}
        }

        if(input == '+')  
        {
          next = fgetc(ip);
          if(next == '+'){ writeTofile(op,tk_unary_inc); continue;}
          else if(next == '='){ writeTofile(op,tk_pl_eq);continue;}
          else { fseek(ip,-1, SEEK_CUR);writeTofile(op,tk_plus);continue;}
        }

        if(input == '-')  
        {
          next = fgetc(ip);
          if(next == '-'){ writeTofile(op,tk_unary_dec);continue;}
          else{ fseek(ip,-1, SEEK_CUR);writeTofile(op,tk_minus);continue;}
        }

        if(input == '*'){ writeTofile(op,tk_mul);continue;}

        if(input == '/'){ writeTofile(op,tk_div);continue;}

        if(input == '<')
        { next = fgetc(ip);
          if(next == '='){writeTofile(op,tk_lte);continue;}
          else
          {fseek(ip,-1, SEEK_CUR);writeTofile(op,tk_lt);continue;}
        }

        if(input == '>')
        {
          next = fgetc(ip);

          if(next == '='){ writeTofile(op,tk_gte);continue;}
          else if(next == '>'){ writeTofile(op,tk_inpop);continue;}
          else{ fseek(ip,-1, SEEK_CUR);writeTofile(op,tk_gt);continue;}
        }
       
       else 
       {
        printf("Unknown symbol %c at %d:%d\n",input,line_no,column_no);
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

int get_hash_value(unsigned char *name) //the djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
{
  int hash = 5381;
  int c;

  while (c = *str++) hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return hash;
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


// int main(int argc, char * argv[])
// {   
//    /* if(argc!=2)
//     {
//         printf("FATAL ERROR!! : No input specified or too many parameters \n");
//         exit(1);
//     }
// */
//     init_symbol_table();
//     FILE * ip = fopen("test.txt","r");
//     FILE * op = fopen("test.lexer","w"); //WARNING: argv[1] is changed here
//     if (ip == NULL || op == NULL)
//     {
//         printf("Error opening file, check permissions! \n");
//     }
//     lexer(ip,op);
//     fclose(ip);
//     fclose(op);
// //    add_ID_to_sym_table("joel", 3, 7);
// //    add_ID_to_sym_table("gokul", 2, 2);
// //    add_ID_to_sym_table("test", 42, 42);
//     print__symbol_table();
//     return 0;
// }