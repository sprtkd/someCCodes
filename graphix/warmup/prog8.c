#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;

void append(Node **start,int val)
{
	Node *p,*temp;
    p=(Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    
    
    if(*start==NULL)
        *start=p;
    else
    {
       temp=*start;
	   while(temp->next!=NULL)
	   	temp=temp->next;
		   
	   temp->next=p; 
    }
}


void display(Node *start)
{
     Node *ptr;
     ptr=start;
      
     while(ptr!=NULL)
     {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
     }
    
     
     
}

void breakupList(Node **start,Node **startodd,Node **starteven)
{
	int count=0;
	Node *temp1,*temp2;
	temp1=*startodd;
	temp2=*starteven;
	
	while((*start)!=NULL)
	{
		count++;
		if(count%2==0)
		{
			if(*starteven==NULL)
			{
				*starteven=*start;
				temp2=*starteven;
			}
			else
			{
				temp2->next=*start;
				temp2=temp2->next;
			}
		}
		else
		{
			if(*startodd==NULL)
			{
				*startodd=*start;
				temp1=*startodd;
			}
			else
			{
				temp1->next=*start;
				temp1=temp1->next;
			}
		}
		
		*start=(*start)->next;
	
	}
	if(temp1!=NULL)
		temp1->next=NULL;
	if(temp2!=NULL)
		temp2->next=NULL;
	
}



int main()
{
	int v;
	Node *Start = NULL,*StartOdd = NULL,*StartEven = NULL;
	
	do
	{
		printf("\nEnter a value:");
		scanf("%d",&v);
		append(&Start,v);
		printf("\nEnter 1 to continue or 0 to end:");
		scanf("%d",&v);
	}while(v);
	
	printf("\nThe Actual list:");
	display(Start);
	
	breakupList(&Start,&StartOdd,&StartEven);
	printf("\nOdd List:");
	display(StartOdd);
	printf("\nEven List:");
	display(StartEven);
	return 0;
}
