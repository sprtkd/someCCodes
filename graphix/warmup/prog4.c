#include<stdio.h>

int main()
{
	void *pvoid;
	int *pint;
	float *pfloat;
	char *pchar;

	printf("\nThe size of void pointer:%lu bytes.\n",sizeof(pvoid));
	printf("\nThe size of int pointer:%lu bytes.\n",sizeof(pint));
	printf("\nThe size of float pointer:%lu bytes.\n",sizeof(pfloat));
	printf("\nThe size of char pointer:%lu bytes.\n",sizeof(pchar));
	

	return 0;
}
