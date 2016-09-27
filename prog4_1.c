#include<stdio.h>
#define MAX 100

void INSERT(int *q,int *r,int *c,int val)
{
 if((*c)==MAX)
 {
	printf("\nQueue is full!!");
	return;
 }

(*r)=((*r)+1)%MAX;
q[*r]=val;
(*c)++;

}



int DELETE(int *q,int *f,int *c)
{
int val;
if(*c==0)
{
 printf("\nQueue is empty!!");
 return 0;

}
val=q[*f];
*f=(*f+1)%MAX;
(*c)--;
return val;

}

void displayQ(int *q,int f,int r,int c)
{
int i,j;

for(i=f,j=0;j<c;j++)
{
printf("\n%d",q[i]);
i++;
(i)=(i%MAX);
}


}

int main()
{
int circQueue[MAX],front=0,rear=-1,count=0,flag,value;
flag=1;
puts("\nEnter:\n\t<1> to insert\n\t<2> to delete\n\t<3> to display:\n\t<0> to exit\n");
while(flag)
{
  printf("\nEnter option: ");
  scanf("%d",&flag);
  
  switch(flag)
 {

 case 1: printf("\nEnter number: ");
         scanf("%d",&value);
         INSERT(circQueue,&rear,&count,value);
 	 break;
 case 2: printf("\nYour deleted value:%d",DELETE(circQueue,&front,&count));
	 break;
 case 3: puts("\nYour queue:");
	 displayQ(circQueue,front,rear,count);
	 break;
   	 
 
 }
}

return 0;
}
