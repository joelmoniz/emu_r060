#ifndef STANDARD_H
#define STANDARD_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#endif

#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

#ifndef CODEGEN_H
#define CODEGEN_H
#include "codegen.h"
#endif

int main(int argc, char*argv[])
{
    FILE * ip;
    char opf[100];

    if(argc!=2)
    {
         // printf("FATAL ERROR!! : No input specified or too many parameters \n");
         // exit(1);

        ip = fopen("./test_cases/misc_test5.txt","r");
        strcpy(opf,"./test_cases/misc_test5.txt");
    }
    else {
        ip = fopen(argv[1],"r");
        strcpy(opf,argv[1]);
    }

    strcat (opf,".lexer");

    FILE * op = fopen(opf,"w"); 
    if (ip == NULL || op == NULL)
    {
     printf("Error opening file, check permissions! \n");
    }
    lexer(ip,op);

    fclose(ip);
    fclose(op);

    printf("\n");

    FILE * ip1 = fopen(opf,"r");
    if (ip1 == NULL)
    {
     printf("Error opening file %s, check permissions! \n",opf);
    }

    int parser_error_detected = parser(ip1); // input file passed due to legacy reasons
    fclose(ip1);

    if (!parser_error_detected) {
      // function_call_semanticize();
      check_expression_types(parse_root);
      check_function_returns();
    }

    if (parse_root->children[0]->token_id == tk_otherFunctions || parse_root->children[1]->token_id == tk_otherFunctions
        || parse_root->children[0]->token_id == tk_func || parse_root->children[1]->token_id == tk_func) {
      printf("\nFunctions detected in the program. emu_r060 does not support functions at present. Exiting...\n\n");
      return;
    }

    //codegen code
    int i;
    char codegen [100];
    strcpy(codegen,argv[1]);
    strcat(codegen,".codegen_output");
    FILE* f1 = fopen(codegen,"w");
    struct _id_type a[3] = {{integer,"a",{0,0}},{float_point,"b",{2,3}},{boolean,"c",{4,4}}}; //dummy test
    if (f1==NULL)
    {
        printf("error opening output");
        exit(2);
    }
    
    fprintf(f1,"\n%s\n","section .data\n"); //for storing constants that don't change (do we have these?


    fprintf(f1,"\n%s","section .bss\n");
    //iterate through a list of _id_type and put stuff here!
    // Row major alignment!!
    create_bss_section_from_tree(f1,symbol_table_root);
    fprintf(f1,"\n%s\n","section .text");
    fprintf(f1,"%s\n","\tglobal main");
    fprintf(f1,"%s\n","main:");
    //DO I need to write the EOF character at the end of file?
    //parse_tree_node * arith_base = parse_root;
    registers r1 = EAX;
    //printf("here1");

    codegen_from_ast(parse_root, r1, f1);
    //printf("here");
    //the exit sys call to prevent segfaults
    fprintf(f1,"\n\t%s\n","mov\teax,1");
    fprintf(f1, "\t%s\n","mov\tebx,0");
    fprintf(f1, "\t%s\n","int\t80h");
    
    close(f1);
    return 0;
}
