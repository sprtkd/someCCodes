#include<stdio.h>

int main()
{

int arr[100],i,temp,n;

printf("\nEnter the no. of elements to enter:");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("\nEnter element %d:",i+1);
scanf("%d",&arr[i]);
}

for(i=0;i<n;i++)
{
printf("\nElement %d=%d",i+1,arr[i]);
}

//to reverse the array


for(i=0;i<n/2;i++)
{
temp=arr[i];
arr[i]=arr[n-i-1];
arr[n-i-1]=temp;

}

printf("\nThe reversed array:\n\n");

for(i=0;i<n;i++)
{
printf("\nElement %d=%d",i+1,arr[i]);
}



}
