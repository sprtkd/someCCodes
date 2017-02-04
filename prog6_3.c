//Max heap..

#include<stdio.h>
#include<stdlib.h>
#define MAX 100000



void insertMaxHeap(int *H,int *n,int v)
{
	int currentNode;
		
	(*n)++;
    H[*n] = v;
    currentNode = (*n);
    
    while(H[currentNode/2]<v) 
    {
    	if((currentNode/2)==0)
    		break;	//H[0] will remain empty
        H[currentNode] = H[currentNode/2];
        currentNode=currentNode/2;
    }
        
	H[currentNode] = v;
}

void printMaxHeap(int *H,int n)
{
	int i;
	printf("\nPrinting array for max heap:\n");
	for(i=1;i<=n;i++)
	{
		printf("\n%d",H[i]);		
	}
	
}

void deleteAllAndPrint(int *H,int *n)
{
	printf("\nPrinting elements after deletion....\n");
	while((*n)>=1)
	{
	
	
        int maxElement,lastElement,child,now;
        maxElement = H[1];

        lastElement = H[(*n)--];
        /* now refers to the index at which we are now */
        for(now = 1; now*2 <= *n ;now = child)
        {
                /* child is the index of the element which is maximum among both the children */ 
                /* Indexes of children are i*2 and i*2 + 1*/
                child = now*2;
                /*child!=*n because H[*n+1] does not exist, which means it has only one 
                  child */
                if(child != (*n) && H[child+1] > H[child] ) 
                {
                        child++;
                }

                /* To check if the last element fits ot not it suffices to check if the last element
                   is less than the minimum element among both the children*/
                if(lastElement < H[child])
                {
                        H[now] = H[child];
                }
                else /* It fits there */
                {
                        break;
                }
        }
        H[now] = lastElement;
        printf("\n%d",maxElement);
	}
}
int main()
{
	int val,opt,heapCount;
	int maxHeap[MAX];
	
	heapCount=0;
	opt=1;
	while(opt==1)
	{
		printf("\nDo you want to enter a new heap node?(1/0): ");
		scanf("%d",&opt);
		if(opt==1)
		{
			printf("\nEnter an integer: ");
			scanf("%d",&val);
			insertMaxHeap(maxHeap,&heapCount,val);
		}
		
	}
	
	printMaxHeap(maxHeap,heapCount);
	
	deleteAllAndPrint(maxHeap,&heapCount);
	printf("\n");
	return 0;
}
