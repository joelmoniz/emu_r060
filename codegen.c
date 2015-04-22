#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * f = fopen("test","r");
	if (f==NULL)
	{
		printf("Error opening test");
		exit(1);
	}
	FILE* f1 = fopen("output","w");
	if (f1==NULL)
	{
		printf("error opening output");
		exit(2);
	}
	return 0;
}
