#include<stdio.h>
#include<string.h>
/*
tokens taken lite/ignored - to be done later
struct
ascii_char
id
num
boolean
point
bot
velocity
int 
float
*/

//TODO: hash table of keywords
enum Token {
  tk_eof = -1,
  tk_ main= -2, //main
  tk_lbrace = -3, //{
  tk_rbrace = -4, //}
  tk_lpara = -5, //(
  tk_rpara = -6, //}
  tk_lsquare = -7, //[
  tk_rsquare = -8,//]
  tk_cmnt_begin = -9, // @~
  tk_semi_cl = -10, // ;
  tk_assign_op = -11, // =
  tk_comma = -12, // , 
  tk_col_assign = -13, // :=
  tk_dot = -14, // .
  tk_colon = -15, // :

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

    char input; //our work-horse!

    //Need to do only one pass!
    // Need to strip white spaces, how to?
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
          do
          {
            input = fgetc(ip);
          }while(input!='@');
          continue;
        }



    }

    return 0;
}