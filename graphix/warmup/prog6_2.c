#include<stdio.h>
#include "prog6head.h"
int main()
{
	int len,i,j;
	int arr[1000];
	
	
	printf("Enter the no. of ints you want to enter:");
	scanf("%d",&len);
	
	printf("\nEnter the numbers:\n");
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);

	}
	
	sortIntOrFloat(NULL, arr, len, 0);		
	return 0;
}
