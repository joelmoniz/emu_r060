#include <stdio.h>
#include <stdlib.h>
#include "parse_table.h"


//SHALL BE The parser later on...
//read in lexeme stream - done
//include the parse_table - done
//include the enum file - done
//order the enum file - TODO
// integrate this with lexer!	

int main()
{	char input;
	enum Token lexeme, curr_lexeme;
	int curr_state = 0; //though we have the array as 2D array of enum ,fine

	FILE * f = fopen("lexeme","r");
	if(f == NULL)
	{
		printf("error opening stream, killing process\n");
		exit(1);
	}
	while(input = fgetc(f) != EOF )
	{
		lexeme = input;
		//TODO: so now we have read in token, now what?
	}


	return 0;
}