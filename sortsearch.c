/*To sort and search*/
#include<stdio.h>
#define MAX 100
void SSort(int arr[],int n);
void BSearch(int arr[],int n,int val);
int main()
{
    int n,val,arr[MAX],i;
    printf("\nEnter the number of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
                    printf("\nEnter element of array:");
                    scanf("%d",&arr[i]);
    }
    SSort(arr,n);
    printf("\nThe sorted array is:");
    for(i=0;i<n;i++)
                    printf("\n%d",arr[i]);
    printf("\nEnter the value of element to be searched:");
    scanf("%d",&val);
    BSearch(arr,n,val);
    getch();
    return 0;
}

void SSort(int arr[],int n)
{
     
     int i,j,swap;
     for(i=0;i<n;i++)
             for(j=i+1;j<n;j++)
             if(arr[i]>arr[j])
             {
                              swap=arr[i];
                              arr[i]=arr[j];
                              arr[j]=swap;
             }
}

void BSearch(int arr[],int n,int val)
{
      int i,j,m,flag=0;
      for(i=0,j=n-1;i<=j;i++)
      {
                          m=(i+j)/2;
                          if(val<arr[i])
                            j=m-1;
                          if(val>arr[i])
                            j=m+1;
                          if(val==arr[i])
                           {
                                         flag=1;
                                         break;
                           }
      }
      if(flag==0)
                 printf("\nValue not found.");
      else
                 printf("\nValue found at position %d.",i);
      
}
     
     
     
     
     
     
     
     
