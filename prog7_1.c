#include<stdio.h>
#define MAX 100

void quickSort(int *arr,int l,int h)
{
	/*first set the last one as pivot..
	then swap last or first one on condition..
	increment first or last pointer as reqd..
	if first and last match with pivot then return..
	*/	
	
	
	
	int a,b,pivot,temp;
	pivot = h;
	a=l;
	b=h;
	if(a>=b)
	{
		return;
	}
		
	
		
	while(a<b)
	{
	
		if(arr[a]==arr[pivot])
		{
			if(arr[b]<arr[pivot])
			{
				//swap
				temp=arr[pivot];
				arr[pivot]=arr[b];
				arr[b]=temp;
				pivot=b;
				a++;
			}
			else
				b--;		
		}
		else if(arr[b]==arr[pivot])
		{
			if(arr[a]>arr[pivot])
			{
				//swap
				temp=arr[pivot];
				arr[pivot]=arr[a];
				arr[a]=temp;
				pivot=a;
				b--;
			}
			else
				a++;
		}
		else
			printf("\nError!");
	}
	
	quickSort(arr,l,pivot-1);
	quickSort(arr,pivot+1,h);
	
}

void binsearch(int *arr,int s,int v)
{
	int mid, l, r;
	l = 0;
	r = s - 1;
	
	while(l<=r)
	{
		mid = l + ((r - l) / 2);

		if(v == arr[mid])
		{
			printf("\nValue found at index %d",mid + 1);
			return;
		}
		else if(v < arr[mid])
		{
			r = mid - 1;
		}
		else if(v > arr[mid])
		{
			l = mid + 1;
		}
		else
			printf("\nError");
	}
	printf("\nValue not found!");
}


int main()
{
	int input[MAX],size,i,val;
	
	printf("\nEnter size of array:");
	scanf("%d",&size);
	
	printf("\nEnter an array:\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&input[i]);
	}
	
	printf("\nYour entered array:\n");
	for(i=0;i<size;i++)
        {
                printf("%d ",input[i]);
        }

	printf("\nQuicksorting....");
	quickSort(input,0,size-1);	
	
	printf("\nThe quicksorted array:\n");
	for(i=0;i<size;i++)
        {
                printf("%d ",input[i]);
        }
	
	while(1)
	{
	printf("\nEnter a number to search:");
	scanf("%d",&val);
	binsearch(input,size,val);
	printf("\ndo you want to search again(1/0):");
	scanf("%d",&val);
	if(val==0)
		break;
	}


	return 0;
}
