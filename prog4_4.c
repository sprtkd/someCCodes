//Stack permutation...
#include<stdio.h>

#define MAX 100

//Functions for queue-------
void insertq(int *q,int *f,int *r,int val)
{
	if(*r==MAX-1)
	{
		printf("\nQueue overflow!!");
		return;
	}
	if(*r==-1)
		*f=(*f)+1;
		
	(*r)=(*r)+1;
	q[*r]=val;
	
	return;
	
}

int deleteq(int *q,int *f,int *r,int *val)
{
		
	
	if((*f)==-1)
	{
		return 0;
	}
	(*val)=q[*f];
	if((*f)==(*r))
	{
		*f=-1;
		*r=-1;
	}
	else
		*f=(*f)+1;
	
	return 1;	
}

void printq(int *q,int f,int r)
{
	int i;
	
	if(f==-1)
	{
		printf("\nQueue empty..");
		return;
	}
	printf("\n");
	for(i=f;i<=r;i++)
	{
		printf("%d ",q[i]);
	}
	
}

//Functions for queue-------



//Functions for stack-------
void push(int *stack,int *t,int val)
{

	if(*t>=MAX-1)
	{
		printf("\nStack overflow!!");
		return;
	}

	(*t)++;
	stack[*t]=val;

}

int pop(int *stack,int *t,int *val)
{
	int retval;
	if(*t<=-1)
	{
		return 0;
	}
	*val=stack[*t];
	(*t)--;
	return 1;

}

void displayStack(int *stack,int t)
{
	int i;
	if(t<=-1)
	{
		printf("\nStack Empty!!");
		return;
	}
	for(i=t;i>=0;i--)
	{
		printf("\n%d",stack[i]);
	}

}
//Functions for stack-------

int main()
{
	int S[MAX],topS=-1,P[MAX],frontP=-1,rearP=-1,Q[MAX],frontQ=-1,rearQ=-1;
	int n,i,input[MAX],val,flag;
	
	// We are only allowed to dequeue from P and allowed to 
	//enqueue into the Q. We can do push and pop from the stack S
	
	
	
	printf("\nEnter the no. of numbers you want to enter\nto enter permutations(<100):");
	scanf("%d",&n);
	printf("\nEnter the permutated sequence:\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter no. %d:",i+1);
		scanf("%d",&input[i]);
		val=i+1;
		insertq(P,&frontP,&rearP,val);
	}
	
	printf("\nYour permutated sequence is:\n");
	for(i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }
        
    printf("\nYour original input sequence is:\n");
    printq(P,frontP,rearP);
	
	
	flag=1;//is indicating whether st permute or not
	
	for(i=0;i<n;i++)
	{
		if(flag==0)
			break;
		
		//input[i] is the i_th value of the permutation to be checked..
		
		if(pop(S,&topS,&val))
		{
			if(val==input[i])
			{
				insertq(Q,&frontQ,&rearQ,val);
			}
			else
			{
				push(S,&topS,val);
				
				do
				{
					if(deleteq(P,&frontP,&rearP,&val))
					{
						if(val!=input[i])
						{
							push(S,&topS,val);
						}
					
					}
					else//then it means that popped value did not match as well as not found in queue..
					{
						flag=0;
						break;
					}
				}while(val!=input[i]);
				
				if(flag)
					insertq(Q,&frontQ,&rearQ,val);
			}
			
		}
		else//if stack empty
		{
			do
			{
				if(deleteq(P,&frontP,&rearP,&val))
				{
					if(val!=input[i])
					{
						push(S,&topS,val);
					}
					
				}
				else//then it means that stack is empty as well as not found in queue..
				{   //which is not possible
					printf("\nLoop error!!");
					break;
					flag=0;
				}
				
			}while(val!=input[i]);
				
			if(flag)
				insertq(Q,&frontQ,&rearQ,val);
		}
	}	
	
	//we are not printing the queue Q as only whether stack permutation or not is reqd..
	
	if(flag)
		printf("\n\nIt is a stack permutation..");
	else
		printf("\n\nIt is not a stack permutation..");
		
		
}

