#include <stdio.h>
#include <stdlib.h>

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "symbol_table.h"
#endif

#define N 3

struct _id_type a[3] = {{integer,"a",{0,0}},{float_point,"b",{2,3}},{boolean,"c",{4,4}}};
int main()
{
	int i;
	FILE * f = fopen("test","r");
	if (f==NULL)
	{
		printf("Error opening test");
		exit(1);
	}
	FILE* f1 = fopen("codegen_output","w");
	if (f1==NULL)
	{
		printf("error opening output");
		exit(2);
	}
	
	fprintf(f1,"\n%s\n","section .data\n"); //for storing constants that don't change (do we have these?


	fprintf(f1,"\n%s","section .bss\n");
	//iterate through a list of _id_type and put stuff here!
	// Row major alignment!!
	for(i=0;i<N;i++)
	{
		fprintf(f1,"\t%s",a[i].name);
		if(a[i].dtype == integer) //1 word long
		{
			fprintf(f1,"\t%s\t","resw");
		}
		else if(a[i].dtype == float_point)//2 word, double long
		{
			fprintf(f1,"\t%s\t","resd");
		}
		else if(a[i].dtype == boolean) //1 byte long
		{
			fprintf(f1,"\t%s\t","resb");
		}
		if(a[i].array_dim1[0] == 0 && a[i].array_dim1[1] == 0)
		{
			fprintf(f1,"%s","1");
		}
		else
		{
			fprintf(f1,"%d",a[i].array_dim1[0]*a[i].array_dim1[1]);
		}

		fprintf(f1,"%s\n","");
	}
	
	fprintf(f1,"\n%s\n","section .text");
	fprintf(f1,"%s\n","\tglobal main");
	fprintf(f1,"%s\n","main:");
	//DO I need to write the EOF character at the end of file?
	
	
	//the exit sys call to prevent segfaults
	fprintf(f1,"\n\t%s\n","mov\teax,1");
	fprintf(f1, "\t%s\n","mov\tebx,0");
	fprintf(f1, "\t%s\n","int\t80h");
	
	close(f);
	close(f1);
	return 0;
}
