/*Magic square*/
#include<stdio.h>
#define MAX 100
int main()
{
    int flag,arr[MAX][MAX]={0},n,tot,i,r,c,copyr,copyc;/*initializing whole arr as 0*/
    printf("\nProgram is intended to print magic square for nxn grid.\nMagic square is a square whose sum along row,column or diagonal are equal.\n");
    do
    {
                      flag=0;
                      printf("\nEnter odd n for nxn grid for magic square:");
                      scanf("%d",&n);
                      if(n%2==0)
                      {
                         printf("\nEnter valid parameter!!");
                         flag=1;
                      }
    }while(flag!=0);/*check for odd*/
    tot=n*n;
    for(i=1,r=0,c=n/2;i<=tot;i++,r+=2,c++)
    {
                                        copyr=r;/*initializing each row in every loop*/
                                        copyc=c;/*initializing each column in every loop*/  
                                          if(c>n-1)/*checking whether c has crossed the length of column*/
                                         { c=c-(n-1);/*checking how many columns it is greater*/
                                         c=c-1;/*decreasing it by 1 as 1 is equal to 0 in array*/
                                         }
                                          if(r>n-1)/*checking whether r has crossed the length of row*/
                                         { r=r-(n-1);/*checking how many rows it is greater*/
                                         r=r-1;/*decreasing it by 1 as 1 is equal to 0 in array*/
                                         }
                                        if(arr[r][c]!=0)/*checking whether arr r c contains any value*/
                                         {
                                                        r=copyr-1;/*subtracting 1 from preliminary r in this loop*/
                                                        c=copyc-1;/*subtracting 1 from preliminary c in this loop*/
                                         }
                                         arr[r][c]=i;
    }
    printf("\nThe magic square is:");
    for(r=0;r<n;r++)
    {
                    printf("\n\n\t");
                     for(c=0;c<n;c++)
                       printf("  %4.0d",arr[r][c]);
    }
    
    getch();
    return 0;
}

              
    
