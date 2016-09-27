#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int rstored;
	int cstored;
	int data;
	struct Node *nextnode;
	
	
}matnode;

typedef struct Infomat
{
	int rows;
	int cols;
	matnode *firstnode;
	
}infomat;

void matinit(infomat *M,int r,int c)
{
	M->rows=r;
	M->cols=c;
	M->firstnode=NULL;
	
}

void matstore(infomat *M,int r,int c,int val)
{
	if(val==0)
		return;
		
	matnode *temp,*next;
	
	temp=(matnode*)malloc(sizeof(matnode));
	temp->cstored=c;
	temp->rstored=r;
	temp->data=val;
	temp->nextnode=NULL;
	
	if(M->firstnode==NULL)
	{
		M->firstnode=temp;
		
	}
	else
	{
		next=M->firstnode;
		while(next->nextnode!=NULL)
		{
			next=next->nextnode;
		}
		next->nextnode=temp;
	
	}

}




void sparsedisplay(infomat *M)
{
	int i,j,val,flag;
	matnode *next;
	
	
	for(i=1;i<=M->rows;i++)
	{
		printf("\n");
		
		for(j=1;j<=M->cols;j++)
		{
			next=M->firstnode;
			flag=0;
			
			while(next!=NULL)
			{
				if((next->rstored==i)&&(next->cstored==j))
				{
					flag=1;
					break;
				}
				next=next->nextnode;
				
			}
			
			if(flag)
				val=next->data;
			else
				val=0;
			
			printf("%d  ",val);
			
		}
		
	}
	
}


void addtwomat(infomat *M1,infomat *M2,infomat *Madd)
{
	if((M1->rows!=M2->rows)||(M1->cols!=M2->cols))
	{
		printf("\nMatrices are not of same dimension..Could not add..");
		return;	
	}	
	
	
	int i,j,val1,val2,flag1,flag2;
	matnode *next1,*next2;
	
	matinit(Madd,M1->rows,M1->cols);
	
	
	
	
	for(i=1;i<=M1->rows;i++)
	{
		
		for(j=1;j<=M1->cols;j++)
		{
			next1=M1->firstnode;
			next2=M2->firstnode;
			
			flag1=0;
			flag2=0;
			
			while(next1!=NULL)
			{
				if((next1->rstored==i)&&(next1->cstored==j))
				{
					flag1=1;
					break;
				}
				next1=next1->nextnode;
				
			}
			
			if(flag1)
				val1=next1->data;
			else
				val1=0;
			
			
			
			while(next2!=NULL)
			{
				if((next2->rstored==i)&&(next2->cstored==j))
				{
					flag2=1;
					break;
				}
				next2=next2->nextnode;
				
			}
			
			if(flag2)
				val2=next2->data;
			else
				val2=0;
			
			
			matstore(Madd,i,j,val1+val2);
			
			
			
		}
		
	}
	
	
	
	
}

int main()
{
	infomat Mat1,Mat2,Matsum;
	int i,j,r,c,val;
	
	
	printf("\nEnter dimension of matrix 1(format r,c):");
	scanf("%d,%d",&r,&c);
	
	matinit(&Mat1,r,c);
	
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			printf("\nEnter element[%d][%d]: ",i,j);
			scanf("%d",&val);
			matstore(&Mat1,i,j,val);
			
		}
		
	}
	
	puts("\nYour matrix 1:\n");
	sparsedisplay(&Mat1);
	
	printf("\nEnter dimension of matrix 2(format r,c):");
	scanf("%d,%d",&r,&c);
	
	matinit(&Mat2,r,c);
	
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			printf("\nEnter element[%d][%d]: ",i,j);
			scanf("%d",&val);
			matstore(&Mat2,i,j,val);
			
		}
		
	}
	
	puts("\nYour matrix 2:\n");
	sparsedisplay(&Mat2);
	
	addtwomat(&Mat1,&Mat2,&Matsum);
	
	puts("\nYour added matrix:\n");
	sparsedisplay(&Matsum);
	
	return 0;
}
