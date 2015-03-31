#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char*argv[])
{
	if(argc!=2)
    {
         printf("FATAL ERROR!! : No input specified or too many parameters \n");
         exit(1);
     }
 char opf[100];
 
 strcpy(opf,argv[1]);
 strcat (opf,".lexer");

 FILE * ip = fopen(argv[1],"r");
 FILE * op = fopen(opf,"w"); 
     if (ip == NULL || op == NULL)
     {
         printf("Error opening file, check permissions! \n");
     }
     lexer(ip,op);
	 
     fclose(ip);
     fclose(op);

     FILE * ip1 = fopen(opf,"r");
     if (ip1 == NULL)
     {
         printf("Error opening file %s, check permissions! \n",opf);
     }
     
     parser(ip1);
     fclose(ip1);
     return 0;
 
}
