/*matrix multiplication*/
#include<stdio.h>
#define MAX 100

int main()
{
    int arr1[MAX][MAX],arr2[MAX][MAX],arr3[MAX][MAX]={0},i,j,k,n;
    printf("\nEnter n for nxn grid for matrices A and B:");
    scanf("%d",&n);
    printf("\nEnter values for matices :");
     for (i=0;i<n;i++)
          for (j=0;j<n;j++)
          {
               printf("Array[%d][%d] of matrix A:",i,j);
               scanf("%d",&arr1[i][j]);
               printf("Array[%d][%d] of matrix B:",i,j);
               scanf("%d",&arr2[i][j]);
          }
          printf("Matrix A:");
     for (i=0;i<n;i++)
          {
                      for (j=0;j<n;j++)
                         { printf("%d",arr1[i][j]);
                         }
                      printf("\n");
          }
     printf("Matrix B:");
     for (i=0;i<n;i++)
          {
                      for (j=0;j<n;j++)
                         { printf("%d",arr2[i][j]);
                         }
                      printf("\n");
          }
     for(i=0;i<n;i++)
       for(j=0;j<n;j++)
         for(k=0;k<n;k++)
                         arr3[i][j]=arr3[i][j]+arr1[i][k]*arr2[k][j];
                          printf("The multiplied matrix:");
     for (i=0;i<n;i++)
          {
                      for (j=0;j<n;j++)
                         { printf("%d",arr3[i][j]);
                         }
                      printf("\n");
          }
     getch();
     return 0;
}
     
     
