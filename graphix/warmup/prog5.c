#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char str[100],*p,i;
	printf("\nEnter a string:\n");
	gets(str);
	p=(char*)malloc(strlen(str)*sizeof(str[0]));
	
	
	for(i=0;i<strlen(str);i++)
	{
		p[i] = str[i];
	}
	
	

	int *pt = (int*)(p);
	
	for(i=0;i<strlen(str);i++)
	{
		printf("%d ",pt[i]);
	}
	return 0;
}
