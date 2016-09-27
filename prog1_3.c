#include<stdio.h>

int chklenstr(char *stringptr)
{
int i=0;

while(stringptr[i]!='\0')
i++;

return i;

}


int chkpalindrome(char *stringptr)
{
int len=chklenstr(stringptr);
int flag,i;
flag=0;
for(i=0;i<len/2;i++)
{
	if(stringptr[i]!=stringptr[len-i-1])
	{flag=1;
	break;
	}
}
return flag;


}



int main()
{
char str[100];

printf("\nEnter a string:");
scanf("%[^\n]",str);

printf("\nEntered string is:");
puts(str);

//checking whether palindrome
if(chkpalindrome(str))
printf("\nThe string is not palindrome.");
else
printf("\nThe string is palindrome.");

}
