#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define SIZE 100

void push(int *stack,int *tp,int var)
{
	if(*tp>=SIZE-1)
	{
		puts("Stack overflow!!");
		return;
	}
	
	stack[++(*tp)]=var;
	
	
	
}

int pop(int *stack,int *tp)
{
	if(*tp<=-1)
	{
		puts("Stack underflow!!");
		return 0;
	}
	
	return stack[(*tp)--];

}


int main()
{
	int stack[SIZE],num,top=-1,i,j,v1,v2,res;
	char str[SIZE],numstr[30];		
	printf("\nEnter a postfix expression (all with spaces):");
	scanf("%[^\n]",str);
	puts("The entered string is:");
	j=0;
	printf("\n");
	for(i=0;str[i]!='\0';i++)
	{
		if(isdigit(str[i]))
			{
				numstr[j]=str[i];
				j++;
				
			}
		else if(str[i]==' ')
			{
				if(j!=0)
				{
					numstr[j]='\0';
					num=atoi(numstr);
					printf("%d ",num);
					push(stack,&top,num);
					
				}
			j=0;
				
			}
		else
			{
				v1=pop(stack,&top);
				v2=pop(stack,&top);
				
				switch(str[i])
				{
					case '+':printf("+ ");
						res=v2+v1;
						break;
				    case '-':printf("- ");
						res=v2-v1;
						break;
					case '*':printf("* ");
						res=v2*v1;
						break;
					case '/':printf("/ ");
						res=v2/v1;
						break;
					case '^':printf("^ ");
						res=pow(v2,v1);
						break;
				
				}
				push(stack,&top,res);
			
			}
	}
	printf("\nThe final result:%d",pop(stack,&top));
	return 0;
}
