#include<stdio.h>
#define MAX 50
void push(int *stack,int *t)
{

if(*t>=MAX-1)
{
printf("\nStack overflow!!");
return;
}

(*t)++;
printf("\nEnter an integer:");
scanf("%d",&stack[*t]);

}

void pop(int *stack,int *t)
{
if(*t<=-1)
{
printf("\nStack Underflow!!");
return;
}
(*t)--;

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

int main()
{
int stack[MAX],opt;
int top=-1;

opt=1;
printf("\nEnter 1 to push,2 to pop,\n3 to display and 0 to exit...");
while (opt)
{
printf("\nEnter option:");
scanf("%d",&opt);

switch(opt)
{
case 1:push(stack,&top);
	break;
case 2:printf("\nPopping...");
	pop(stack,&top);
	break;
case 3:display(stack,top);
	break;
case 0:printf("\nExiting...");
	break;
default:printf("\nInvalid option!!!");
	break;

}

}
}
