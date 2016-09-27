#include<stdio.h>
#define MAX 50


//char stack
int push(char *stack,int *t)
{
char ch;
if(*t>=MAX-1)
{
printf("\nStack overflow!!");
return 0;
}
(*t)++;
ch=getchar();
if(ch=='\n')
{
stack[*t]='\0';
return 0;
}
stack[*t]=ch;
return 1;
}

char pop(char *stack,int *t)
{
if(*t<=-1)
{
return '\n';
}

return (stack[(*t)--]);


}


int main()
{
char stack[MAX],ch;

int top=-1;
int flag,i;
printf("\nEnter a string:");

while (push(stack,&top));

printf("\nEntered string is:");

puts(stack);

top--;
i=0;
flag=1;
while(1)
{
ch=pop(stack,&top);
if(ch=='\n')
break;

if(ch!=stack[i])
{
flag=0;
break;
}
i++;
}
if(flag)
puts("\nPalindrome.");
else
puts("\nNot palindrome..");



}
