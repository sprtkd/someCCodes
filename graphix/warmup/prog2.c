#include<stdio.h>

void printPrimeFactors(int n)
{
	if(n==0||n==1)
	{
		return;
	}
	
	int i;
	
	for(i=2;i<n/2;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
				n=n/i;

			printPrimeFactors(n);
			printPrimeFactors(i);
			return;
		}
	
	}
	
	printf("%d\n",n);
	return;

}


int main()
{
	int num;
	printf("\nEnter a number:");
	scanf("%d",&num);
	
	printPrimeFactors(num);	
	return 0;
}
