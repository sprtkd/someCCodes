#include <stdio.h>
#include <string.h>

int main()
{
	long int num;
	char *str[100];
	int strcount =-1;
	char *numbers[10] = {""," one"," two"," three"," four"," five"," six"," seven"," eight"," nine"};
	char *tenplus[10] = {" ten"," eleven"," twelve"," thirteen"," fourteen"," fifteen"," sixteen"," seventeen"," eighteen"," nineteen"};
	char *tens[10] = {"",""," twenty"," thirty"," forty"," fifty"," sixty"," seventy"," eighty"," ninety"};
	char *blank = "";
	char *hundred = " hundred ";
	char *thousand = " thousand ";
	char *million = " million ";
	int pos=0,dig,prevdig;
	printf("Enter a number (<9999999): ");
	scanf("%ld",&num);
	if(num==0)
		printf("Zero.\n");
	else
	{
		while(num)
		{
			pos++;
			dig = num%10;
			switch(pos)
			{
				case 1: str[0] = numbers[dig];
						strcount++;
						break;
				case 2: if(dig==1)
						{
							str[0] = blank;
							str[1] = tenplus[prevdig];
						}
						else
						{
							str[1] = tens[dig];
						}
						strcount++;
						break;
				case 3: str[3] = numbers[dig];
						if(dig!=0)
							str[2] = hundred;
						else
							str[2] = blank;
						strcount+=2;
						break;
				case 4:	str[5] = numbers[dig];
						if(dig!=0)
							str[4] = thousand;
						else
							str[4] = blank;
							
						strcount+=2;
						break;
				case 5: if(dig==1)
						{
							str[5] = blank;
							str[6] = tenplus[prevdig];
						}
						else
						{
							str[6] = tens[dig];
						}
						strcount++;
						if(dig!=0)
							str[4] = thousand;
						break;
				case 6: str[8] = numbers[dig];
						if(dig!=0)
							str[7] = hundred;
						else
							str[7] = blank;
						if(dig!=0)
							str[4] = thousand;
						strcount+=2;
						break;
				case 7: str[10] = numbers[dig];
						if(dig!=0)
							str[9] = million;
						else
							str[9] = blank;
						strcount+=2;
						break;				
				
			}
			num = num/10;
			prevdig=dig;
			
			
		}
		for(dig=strcount; dig>=0;dig--)
			{
				printf("%s",str[dig]);
			}
			printf(".\n");
	}
	return 0;	
}
