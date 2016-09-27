#include<stdio.h>
#define MAX 100

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

int pop(int *stack,int *t,int *returnval)
{
	if(*t<=-1)
	{
		return 0;
	}
	else
	{
		*returnval=stack[(*t)--];
		return 1;
	}
}

void display(int *stack,int t)
{
	int i;
	if(t<=-1)
	{
		printf("\nStack used is Empty!!");
		return;
	}
	for(i=0;i<=t;i++)
	{
		printf("\n%d",stack[i]);
	}

}

void insQfromStack(int *st1,int *t1,int val)
{
	push(st1,t1,val);
}

int delQfromStack(int *st1,int *st2,int *t1,int *t2)
{
	int valrecd,delval;
	if((*t1)==-1)
		printf("\nQueue underflow!!");

	while(pop(st1,t1,&valrecd))
	{
		push(st2,t2,valrecd);
		
	}

	pop(st2,t2,&delval);

	while(pop(st2,t2,&valrecd))
        {
                push(st1,t1,valrecd);

        }
	
	return delval;


}



int main(void)
{
	int stack1[MAX],stack2[MAX],top1=-1,top2=-1,flag,value;
	//Queue using two stacks
	flag=1;
	puts("\nEnter:\n\t<1> to insert\n\t<2> to delete\n\t<3> to display:\n\t<0> to exit\n");
	while(flag)
	{
		printf("\nEnter option: ");
  		scanf("%d",&flag);
  
  		switch(flag)
 		{

 			case 1: printf("\nEnter number: ");
         			scanf("%d",&value);
         			insQfromStack(stack1,&top1,value);
 	 			break;
 			case 2: printf("\nYour deleted value:%d",delQfromStack(stack1,stack2,&top1,&top2));
	 			break;
		 	case 3: puts("\nYour queue:");
	 			display(stack1,top1);
	 			break;
   	 
 
 		}
	}

	return 0;


}
