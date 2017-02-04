#include<stdio.h>

int strLength(char *str)
{
	int count=0;
	while(str[count]!='\0')
		count++;

	return count;
}

int strComp(char *firststr,char *secondstr)
{
	int len1,len2;
	len1=strLength(firststr);
	len2=strLength(secondstr);
		
	if(len1!=len2)
		return 1;
	for(len2=0;len2<len1;len2++)
	{
		if(firststr[len2]!=secondstr[len2])
			return 1;
	}
	
	
	return 0;
}


int main()
{
	char str1[100],str2[100];
	printf("\nEnter a string:\n");
	gets(str1);
	printf("\nEnter second string:\n");
	gets(str2);
	
	printf("\n%d",strComp(str1,str2));

	return 0;
}
