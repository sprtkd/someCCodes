#include<stdio.h>
#include<math.h>
long int DecToBin(int dec)
{
int i;
long int bin;
int ultobin[200]={0};

bin=0;
i=0;
while(dec)
{
ultobin[i]=(dec%2);
dec=dec/2;
i++;
}
//if(dec)
//i=0;

while(i)
{
i--;
bin=(bin*10)+ultobin[i];
}
return bin;
}

int BinToDec(long int bin)
{
int dec,i;
dec=0;
i=0;
while(bin)
{
dec=dec+(pow(2,i)*(bin%10));
bin=bin/10;
i++;
}

return dec;
}

int main()
{
int o,dec;
long int bin;

printf("\nEnter 0 to enter decimal or any number for binary:");
scanf("%d",&o);

if(o)
{
printf("\nEnter a binary number:");
scanf("%ld",&bin);
printf("Decimal=%d.",BinToDec(bin));

}
else
{
printf("\nEnter a decimal number:");
scanf("%d",&dec);
printf("Binary=%ld.",DecToBin(dec));
}

getch();
}
