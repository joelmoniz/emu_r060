#ifndef STANDARD_H
#define STANDARD_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#endif

int main(int argc, char*argv[])
{
    FILE * ip;
    char opf[100];

    if(argc!=2)
    {
         // printf("FATAL ERROR!! : No input specified or too many parameters \n");
         // exit(1);

        ip = fopen("./test_cases/submitted_test1.txt","r");
        strcpy(opf,"./test_cases/submitted_test1.txt");
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
      function_call_semanticize();
    }
    return 0;
}
