/*To chck whether inputted string is palindrome or not*/
#include<stdio.h>
#include<string.h>
#define M 100

int main()
{
    char x[M],y[M];
    int i,n,flag=1;
    printf("\nEnter string to check for palindrome:");
    gets(x);
    n=strlen(x);
    for(i=0;x[i]!='\0';i++)
    {
                           if(x[i]!=x[n-i-1])
                           {
                                           flag=0;
                                           break;
                           }
    }
    if(flag==1)
    printf("\nThe string is palindrome.");
    else
    printf("\nThe string is not palindrome.");
    getch();
    return 0;
}

    
