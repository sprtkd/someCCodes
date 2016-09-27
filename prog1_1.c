#include <stdio.h>

int main()
{
int arr[100],i,n,larnum,smallnum;

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

/*To find largest and smallest no.*/
larnum=arr[0];
smallnum=arr[0];


for(i=0;i<n;i++)
{
if(larnum<arr[i])
larnum=arr[i];

if(smallnum>arr[i])
smallnum=arr[i];
}


printf("\nThe largest no. is = %d",larnum);

printf("\nThe smallest no. is = %d",smallnum);

getch();
return 0;
}
