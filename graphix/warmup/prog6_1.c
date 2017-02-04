#include<stdio.h>
#include "prog6head.h"
int main()
{
	int len,i,j;
	float arr[1000];
	
	
	printf("Enter the no. of floats you want to enter:");
	scanf("%d",&len);
	
	printf("\nEnter the numbers:\n");
	for(i=0;i<len;i++)
	{
		scanf("%f",&arr[i]);

	}
	
	sortIntOrFloat(arr, NULL, len, 1);		
	return 0;
}
