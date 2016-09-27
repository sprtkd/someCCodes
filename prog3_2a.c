#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 50


//char stack
void push(char *stack,int *t,char var)
{

if(*t>=MAX-1)
{
printf("\nStack overflow!!");
return;
}

(*t)++;
stack[*t]=var;

}

char pop(char *stack,int *t)
{
if(*t<=-1)
{
printf("\nStack Underflow!!");
return '0';
}
return  stack[(*t)--];
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
printf("%c",stack[i]);
}

}

int precedencecheck(char c,char d)
{
int cpos,dpos;

switch(c)
{
case '^':cpos=1;
		break;	
case '/':cpos=2;
		break;
case '*':cpos=2;
		break;
case '+':cpos=3;
		break;
case '-':cpos=3;
		break;
}	

switch(d)
{
case '^':dpos=1;
		break;	
case '/':dpos=2;
		break;
case '*':dpos=2;
		break;
case '+':dpos=3;
		break;
case '-':dpos=3;
		break;
}	

if(dpos<cpos)
	return 0;
else
	return 1;
}



void intopostfix(char *infix,char *postfix,char *stack,int *t)
{
char ch,ch2;
int i,j;
i=0;
j=0;
while (1)
{
	ch=infix[i];
	
	if(ch=='\0')
	{
		postfix[j]='\0';
		break;
	}
	else if(ch=='(')
		push(stack,t,ch);
	else if(isdigit(ch))
		postfix[j++]=ch;
	else if((ch=='^')||(ch=='/')||(ch=='*')||(ch=='+')||(ch=='-'))
		{
			postfix[j++]=' ';
			while(1)
			{
				ch2=pop(stack,t);
				if((precedencecheck(ch,ch2))||(ch2=='('))
				{
					push(stack,t,ch2);
					push(stack,t,ch);
					break;
				}
				else
				{
					postfix[j++]=ch2;
					postfix[j++]=' ';
				}
			}
		}
	else if(ch==')')
	{
		postfix[j++]=' ';
		while(1)
		{
			ch2=pop(stack,t);
			if(ch2=='(')
				break;
			else
			{
				postfix[j++]=ch2;
				postfix[j++]=' ';
			}
		}
	}


i++;
}
}


void intoprefix(char *infix,char *prefixorg,char *stack,int *t)
{

char ch,ch2,prefix[MAX];
int i,j,len;
i=0;
j=0;

len=strlen(infix);
len--;

while (1)
{

	
	if((len-i+1)==0)
	{
		prefix[j]='\0';
		break;
	}
	
	ch=infix[len-i];
	
	if(ch==')')
		push(stack,t,ch);
	else if(isdigit(ch))
		prefix[j++]=ch;
	else if((ch=='^')||(ch=='/')||(ch=='*')||(ch=='+')||(ch=='-'))
		{
			prefix[j++]=' ';
			while(1)
			{
				ch2=pop(stack,t);
				if((precedencecheck(ch,ch2))||(ch2==')'))
				{
					push(stack,t,ch2);
					push(stack,t,ch);
					break;
				}
				else
				{
					prefix[j++]=ch2;
					prefix[j++]=' ';
				}
			}
		}
	else if(ch=='(')
	{
		prefix[j++]=' ';
		while(1)
		{
			ch2=pop(stack,t);
			if(ch2==')')
				break;
			else
			{
				prefix[j++]=ch2;
				prefix[j++]=' ';
			}
		}
	}


i++;
}										
len=strlen(prefix);
len--;
i=0;
while((len-i)+1) 
{
	prefixorg[i]=prefix[len-i];
	i++;
	
	
}
prefixorg[i]='\0';


}






int main()
{
char infix[MAX],prefix[MAX],postfix[MAX],stack[MAX];
int top=-1;


printf("\nEnter an infix expression(with brackets):");
scanf("%[^\n]",infix);
puts("\nYour infix expression is:");
puts(infix);

intoprefix(infix,prefix,stack,&top);
intopostfix(infix,postfix,stack,&top);

puts("\nYour prefix expression is:");
puts(prefix);
puts("\nYour postfix expression is:");
puts(postfix);
getch();
}
