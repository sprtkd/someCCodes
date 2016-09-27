#include<stdio.h>
#define MAX 50
void push(int *stack,int *t,int var)
{

if(*t>=MAX-1)
{
printf("\nStack overflow!!");
return;
}

(*t)++;

stack[*t]=var;

}
int pop(int *stack,int *t)
{
if(*t<=-1)
{
printf("\nStack Underflow!!");
return 0;
}

return stack[(*t)--];
}

void display(int *stack,int t)
{
int i;
if(t<=-1)
{
printf("\nStack Empty!!");
return;
}
for(i=0;i<=t;i++)
{
printf("\n%d",stack[i]);
}

}

void duplicateStack(int *stack,int *t)
{

int array[MAX],stacknew[MAX],tnew=-1;
int toplocal=-1,i,j,flag;

while((*t)>-1)
	array[++toplocal]=pop(stack,t);

i=toplocal;

while(i>-1)
{
	push(stack,t,array[i]);
	i--;
}

i=toplocal;

while(i>-1)
{
	j=toplocal;
	flag=1;
	while(j>i)
	{
		if(array[i]==array[j])
		{
			flag=0;
			break;
		}
	j--;
	}

if(flag)
push(stacknew,&tnew,array[i]);
i--;
}



puts("\nYour copied stack is:");
display(stacknew,tnew);
}




int main()
{
int stack[MAX],x,i,n;
int top=-1;
printf("\nEnter how many elements you want to enter:");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("\nEnter element %d:",i+1);
scanf("%d",&x);
push(stack,&top,x);
}
puts("\nYour stack is:");
display(stack,top);

duplicateStack(stack,&top);


puts("\nYour initial stack:");
display(stack,top);
puts("\n");

}
