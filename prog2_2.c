#include<stdio.h>
#define MAX 50


//char stack
void push(char *stack,int *t)
{

if(*t>=MAX-1)
{
printf("\nStack overflow!!");
return;
}

(*t)++;
printf("\nEnter a character:");
getchar();
stack[*t]=getchar();

}

void pop(char *stack,int *t)
{
if(*t<=-1)
{
printf("\nStack Underflow!!");
return;
}
(*t)--;

}

void display(char *stack,int t)
{
int i;
if(t<=-1)
{
printf("\nStack Empty!!");
return;
}
for(i=0;i<=t;i++)
{
printf("\n%c",stack[i]);
}

}

int main()
{
char stack[MAX];
int opt;
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
