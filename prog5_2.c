#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 25

typedef struct Node
{
char string[MAX];
int strlength;
struct Node *next;
int strfrequency;
}node;




int strcomp(char *a,char *b)
{
	int c = 0;
 
   	while (a[c] == b[c]) 
	{
      		if (a[c] == '\0' || b[c] == '\0')
         		break;
      		c++;
   	}
 
   	if (a[c] == '\0' && b[c] == '\0')
      		return 1;
   	else
      		return 0;



}





//loes is the pointer to the length of existing string....
void StoreCharInNode(node **st,int *loes,char *str,char ch)
{
	
	node *nextnode,*temp;
	int flag;
	

	if((ch==' ')||(ch=='.')||(ch==',')||(ch=='\n'))
	{
		if((*loes)==-1)
			return;
		else
		{
			(*loes)++;
			str[*loes]='\0';
			/*Now we have to search for the same word..If matched we have to increment the freq val
			else we will create a new node to store it */			
			
			nextnode=*st;
			flag=1;		
			while(nextnode!=NULL)
			{
				if(strcomp(nextnode->string,str))
				{
					flag=0;
					(nextnode->strfrequency)++;
					break;
					
				}
				nextnode=nextnode->next;		

			}	
			
	
			if(flag)
			{
				temp=(node*)malloc(sizeof(node));
				strcpy(temp->string,str);
				temp->strlength=strlen(str);
				(temp->strfrequency)=1;
				temp->next=NULL;
				if(*st==NULL)
				{
					*st=temp;
				}
				else
				{
					nextnode=*st;
					while(nextnode->next!=NULL)
					{
						nextnode=nextnode->next;
					
					}
					nextnode->next=temp;

				}
			
			
				printf("\n%s is stored",str);


			}
			

		}
		(*loes)=-1;

	}
	else
	{
		
		(*loes)++;
		str[*loes]=ch;
		
		return;
		
	
	}


}

void ScanLengthOfWord(node *st,int len)
{
	node *nextnode;	
	nextnode=st;
	while(nextnode!=NULL)
	{	
		
		if(nextnode->strlength==len)
		{
			printf("\n%s- %d time(s).",nextnode->string,nextnode->strfrequency);
			

		}
			nextnode=nextnode->next;
					
	}

	return;
}





int main()
{
node *Start=NULL,*inNode;
char ch,string[MAX];
int len,loestring;
FILE *ftxt;

ftxt=fopen("textfile.txt","r");

if(ftxt==NULL)
{
	printf("\nFile does not exist....Exiting");	
	return 0;
}

loestring=-1;

while((ch=fgetc(ftxt))!=EOF)
{
	StoreCharInNode(&Start,&loestring,string,ch);
}

ch='.';
StoreCharInNode(&Start,&loestring,string,ch);



fclose(ftxt);

len=1;

while(len)
{
printf("\nEnter the length of string to search \nor <0> to end:");
scanf("%d",&len);
if(len)
{
	printf("\nYour words with %d no. of letters is:\n",len);
	ScanLengthOfWord(Start,len);
}

}


return 0;
}
