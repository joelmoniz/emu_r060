#include<stdio.h>
#include<string.h>
//TODO: hash table of keywords

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
	//DFAs? get from Joey or discuss
	//What was that joey blabbering about reading in blocks?
	
	while(input = fgetc(ip))
	{


	}

	return 0;
}