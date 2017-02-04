#include<stdio.h>

int main()
{
	int len,i,j;
	float arr[1000],temp;
	
	scanf("%d",&len);

	for(i=0;i<len;i++)
	{
		scanf("%f",&arr[i]);

	}
	
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}

		}
	
	}
	
	for(i=0;i<len;i++)
	{
		printf("%g ",arr[i]);

	}	
		
	return 0;
}
