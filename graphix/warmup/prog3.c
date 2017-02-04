#include<stdio.h>

int gcdfind(int n1,int n2)
{
	int temp;

	if(n1<0)
		n1 = n1*-1;
	if(n2<0)
		n2 = n2*-1;

	if(n1<n2)
	{
		temp=n1;
		n1=n2;
		n2=temp;
	}
	
	if(n2==0)
		return 1;

	if(n1%n2!=0)
	{
		return gcdfind(n2,n1%n2);
	}
	else
		return n2;
}





int main()
{
	int n1,n2;
	printf("\nEnter two numbers(separated by comma): ");
	scanf("%d,%d",&n1,&n2);
	
	printf("\nGCD is: %d\n",gcdfind(n1,n2));
	return 0;
}
