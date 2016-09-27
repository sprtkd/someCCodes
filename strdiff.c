/*string diff*/
#include<stdio.h>
#include<string.h>
#define M 100

int main()
{
         char c[M],d[M];
         int x,y,i,count=0;
         do
         {
                    puts("Program to find out how 2 strings of equal length differ:\n");
                     puts("\nEnter 1st string:\n");
                     gets(c);
                     puts("\nEnter 2nd string:\n");
                     gets(d);
                     x=strlen(c);
                     y=strlen(d);
                     if(x!=y)
                     puts("\nPlease enter strings of EQUAL LENGTH(Blanks are considered):\n");
                     
         }while(x!=y);
         for(i=0;i<x;i++)
         {
            if((c[i]>='a')&&(c[i]<='z'))
            c[i]=c[i]-32;
            
         }
         for(i=0;i<x;i++)
         {
            if((d[i]>='a')&&(d[i]<='z'))
            d[i]=d[i]-32;
            
         }
        
         for(i=0;i<x;i++)
         {
            if(c[i]==d[i])
            count++;
         }
         printf("The strings have %d similar positions and %d dissimilar positions",count,(x-count));              
         getch();
         return 0;
}
         
         
