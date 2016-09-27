#include<stdio.h>
#define MAX 100

typedef struct pNode
{
	int priority;
	int number;

}priorityNode;



void PRIORITYINSERT(priorityNode *q,int *f,int *r,int val,int pr)
{
	int i,flag,pos;
	
	if(*r==MAX-1)
	{
		printf("\nQueue overflow!!");
		return;
	}
	
	if(*r==-1)//1st value entered without checking 
	{
		*f=(*f)+1;
		(*r)=(*r)+1;
		q[*r].priority=pr;
		q[*r].number=val;
	}
	else
	{
		flag=1;//if it is to be entered at last..
		
		for(i=(*f);i<=(*r);i++)
		{
			if(q[i].priority<pr)
			{
				pos=i;
				flag=0;//val not to be entered at last..
				break;
				
			}
		}
		
		if(flag)//val to be entered at last..
		{
			(*r)=(*r)+1;
			q[*r].priority=pr;
			q[*r].number=val;
		}
		else
		{
			//rest of the values are to be shifted by 1 place & copied to gain the position..
			for(i=(*r);i>=(pos);i--)
			{
				q[i+1].priority=q[i].priority;
				q[i+1].number=q[i].number;
			
			}
			
			//new one is put into its position..
			q[pos].priority=pr;
			q[pos].number=val;
			
			//rear is increased..
			(*r)=(*r)+1;
		}
		
	}
	
	
	return;	

}



int PRIORITYDELETE(priorityNode *q,int *f,int *r)
{
	int retval;	
	
	if((*f)==-1)
	{
		printf("\nQueue underflow!!");
		return 0;
	}
	
	retval=q[*f].number;
	if((*f)==(*r))
	{
		*f=-1;
		*r=-1;
	}
	else
		*f=(*f)+1;
	
	return retval;	
	

}

void displayQ(priorityNode *q,int f,int r)
{
	int i;
	
	if(f==-1)
	{
		printf("\nQueue empty..");
		return;
	}
	for(i=f;i<=r;i++)
	{
		printf("\n%d->%d",q[i].priority,q[i].number);
	}


}



int main()
{
	priorityNode prQueue[MAX];
	int front=-1,rear=-1,flag,value,prio;
	flag=1;
	puts("\nEnter:\n\t<1> to insert\n\t<2> to delete\n\t<3> to display:\n\t<0> to exit\n");
	while(flag)
	{
  		printf("\nEnter option: ");
  		scanf("%d",&flag);
  
  		switch(flag)
 		{

 			case 1: printf("\nEnter Priority: ");
                    scanf("%d",&prio);
					printf("\nEnter number: ");
         			scanf("%d",&value);
         			PRIORITYINSERT(prQueue,&front,&rear,value,prio);
 	 				break;
 	 			
 			case 2: printf("\nYour deleted value:%d",PRIORITYDELETE(prQueue,&front,&rear));
	 				break;
	 			
 			case 3: puts("\nYour queue:");
	 				displayQ(prQueue,front,rear);
	 				break;
   	 
 
 		}
	}

	return 0;
}
