#include <stdio.h>

void sortIntOrFloat(float *arr, int *arrint, int sizearr, int flag)
{

	int i,j;
	int tempint;
	float temp;

	
	if(flag)
	{
	
	for(i = 0; i < sizearr - 1; i++)
	{
		for( j = i + 1; j < sizearr; j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}

		}
	
	}
	
	printf("\n");	
	
	for( i = 0; i < sizearr; i++ )
	{
		printf("%f ",arr[i]);

	}	
	

	printf("\n");		
	return;
	}
	else
	{
		for(i = 0; i < sizearr - 1; i++)
		{
		for( j = i + 1; j < sizearr; j++)
		{
			if(arrint[i]>arrint[j])
			{
				tempint=arrint[i];
				arrint[i]=arrint[j];
				arrint[j]=tempint;
			}

		}
	
	}
	
	printf("\n");	
	
	for( i = 0; i < sizearr; i++ )
	{
		printf("%d ",arrint[i]);

	}	
	

	printf("\n");		
	return;
	}
}
