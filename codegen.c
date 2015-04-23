#include <stdio.h>
#include <stdlib.h>

#ifndef PARSE_TABLE_H
#define PARSE_TABLE_H
#include "parse_table.h"
#endif

#define N 3 //change later as per requirement
FILE* f1;

typedef enum registers
{
	EAX,
	EBX,
	ECX,
	EDX,
	UNK
}

char * print_register(registers r)
{
 if(r == EAX)
 {
 	return "EAX";
 }
 if(r == EBX)
 {
 	return "EBX";
 }
 if(r == ECX)
 {
 	return "ECX";
 }
 if(r == EDX)
 {
 	return "EDX";
 }
 if(r == UNK)
 	printf("Error!! in register");
 	exit(5);

}
  
int isArithOper(int token)
{
	if(token==tk_plus || token ==tk_minus || token == tk_mul || 
	   token == tk_div || token == tk_unary_inc || token == tk_unary_dec)
		return 1;
	else return 0;
}


void codegen_from_ast(parse_tree_node root, registers dest)
{
	int i;
	registers r,source_reg;
	r = EAX;
	if(root->num_child == 0) //leaf node 
	{
		if(root->token_id == tk_id)
		{
			fprintf("MOV %s, %s\n",print_register(dest), root->(id->); //Todo
		}
		else if(root->token_id == tk_num)//num
		{
			fprintf("MOV %s, %d\n",print_register(dest),root->(value.num));
		}
		else if(root->token_id == tk_rnum)//rnum
		{	
			fprintf("MOV %s, %f\n",print_register(dest),root->(value.rnum));
		}
	}

	if (isArithOper(root->token_id))
	{
		for(i=0; i < num_child;i++)
		{
			codegen_from_ast(root->children[i],r++);
			if (r > EDX)
			{
				printf("registers overloaded\n");
			} 
		}
		source_reg = EAX;
		if(root->token_id == tk_plus)
		{
			if((root->children[0])->value.num == 1)
			{
				fprintf("INC EBX\n");
				source_reg = EBX;
			}
			else if((root->children[1])->value.num == 1)
			{
				fprintf("INC EAX\n");
				source_reg = EAX;
			}
			else
			{
				fprintf("ADD EAX, EBX\n");		
			}
		}
		if(root->token_id == tk_minus)
		{
			fprintf("SUB EAX, EBX\n");
		}
		if(root->token_id == tk_mul)
		{
			fprintf("MUL EAX, EBX\n");
		}
		if(root->token_id == tk_div)
		{
			fprintf("DIV EAX, EBX\n");
		}
	}

	fprintf(f1,"\tMOV %s, %s \n",print_register(dest),print_register(source_reg));
}

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
	f1 = fopen("codegen_output","w");
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
