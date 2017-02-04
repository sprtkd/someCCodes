#include <stdio.h>

int strLength(char *str)
{
	int count=0;
	while(str[count]!='\0')
		count++;

	return count;
}

int substrreverse(char *str,int a,int b,char *revstr)
{
	if((a<1)||(b<1)||(a>strLength(str))||(b>strLength(str)))
	{
		printf("\nString out of bounds!!\nPlease enter valid positions!\n");
		return 0;
	}
	
	int i,j;
	j=0;
	for(i=b-1;i>=a-1;i--)
	{
		revstr[j]=str[i];
		j++;
	}
	
	revstr[j]='\0';
	
	return 1;
	
}


int main()
{
	char str[500],revsubstr[500];
	int a,b;
	printf("\nEnter a string:");
	gets(str);
	printf("\nEnter the 1st pos of substring:");
	scanf("%d",&a);
	printf("\nEnter the last pos of substring:");
	scanf("%d",&b);
	
	if(substrreverse(str,a,b,revsubstr))
	{
		printf("\n%s",revsubstr);
	}
	
	
	
	return 0;
}
