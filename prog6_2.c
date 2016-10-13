//Huffman tree and huffman coding....
#include<stdio.h>
#include<stdlib.h>
#define MAX 100


typedef struct Node
{
 	char letter;
 	struct Node *next;
 	int letterfrequency;
}node;//for linked list


typedef struct Tree
{
	struct Tree *LC,*RC;
	char letter;
	int letterfrequency;
}HuffTree;//for tree

typedef struct priorityQueue
{
	HuffTree *link;
	struct priorityQueue *next;
	
}Pqueue;


void StoreCharInNode(node **S,char c)
{
	node *temp,*tmp;
	
	temp=*S;
	while(temp!=NULL)
	{
		if(temp->letter==c)
		{
			temp->letterfrequency++;
			return;
		}
		temp=temp->next;
	}
	
	
	temp=(node*)malloc(sizeof(node));
	temp->letter=c;
	temp->letterfrequency=1;
	temp->next=NULL;
	
	if(*S==NULL)
	{
		*S=temp;
	}
	else
	{
		tmp=*S;
		while(tmp->next!=NULL)
		{
			tmp=tmp->next;
		}
		tmp->next=temp;
	}
	return;
}


void dispLinkedList(node *R)
{
	node *temp;
	temp=R;
	printf("\nPrinting Linked List:\n");
	while(temp!=NULL)
	{
		printf("\n%c -> %d",temp->letter,temp->letterfrequency);
		temp=temp->next;
	}
	
}


void priorityInsert(Pqueue **H,char ch,int freq,HuffTree *LC,HuffTree *RC)
{
	Pqueue *temp;
	HuffTree *newLeaf;
	newLeaf=(HuffTree*)malloc(sizeof(HuffTree));
	newLeaf->letter=ch;
	newLeaf->letterfrequency=freq;
	newLeaf->LC=LC;
	newLeaf->RC=RC;
	
	Pqueue *newNode;
	newNode=(Pqueue*)malloc(sizeof(Pqueue));
	newNode->link=newLeaf;
	newNode->next=NULL;
	
	if(*H==NULL)
	{
		*H=newNode;
	}
	else if(freq<((*H)->link->letterfrequency))
	{
		newNode->next=*H;
		*H=newNode;
	}
	else
	{
		temp=*H;
		while(temp->next!=NULL)
		{
			if((temp->next->link->letterfrequency)>freq)
				break;
			temp=temp->next;
		}
		newNode->next=temp->next;
		temp->next=newNode;
	}
	
}



HuffTree* priorityDelete(Pqueue **H)
{
	HuffTree *retNode;
	Pqueue *temp;
	
	if(*H==NULL)
	{
		return NULL;
	}	
	
	temp=*H;
	*H=temp->next;
	retNode=temp->link;
	free(temp);
	return retNode;
	

}


void priorityDisplay(Pqueue *H)
{
	printf("\nPrinting priority queue of huffman tree:(** means parent node)\n");
	if(H==NULL)
	{
		printf("\nEmpty PriorityQueue!!");
		return;
	}
	while(H!=NULL)
	{
		if(H->link->letter==0)
			printf("\n** -> %d",H->link->letterfrequency);
		else
			printf("\n%c -> %d",H->link->letter,H->link->letterfrequency);
		H=H->next;
	}
}


void buildPriorityQueue(Pqueue **H,node *S)
{
	printf("\nBuilding priority queue for huffman tree...");
	while(S!=NULL)
	{
		priorityInsert(H,S->letter,S->letterfrequency,NULL,NULL);
		S=S->next;
	}
	
	priorityDisplay(*H);
	
}


HuffTree* buildHuffTree(Pqueue **H)
{
	HuffTree *node1,*node2,*temp;
	printf("\nBuilding huffman tree...\n-------------------------------------------\n");
	if(*H==NULL)
	{
		printf("\nCannot build huffman tree with empty priority queue...");
		return NULL;
	}
	while(1)
	{
		node1=priorityDelete(H);
		if(node1==NULL)
		{
			printf("\nError while building huffman tree..");
			return;
		}
		
	
		node2=priorityDelete(H);
		if(node2==NULL)
		{
			printf("\nTree obtained...");
			return node1;
		}//breaking the loop if only one node is available
		
		
		
		if((node1->letterfrequency)<(node2->letterfrequency))
		{
			temp=node1;
			node1=node2;
			node2=temp;
		}
			
		priorityInsert(H,0,(node1->letterfrequency)+(node2->letterfrequency),node1,node2);
		priorityDisplay(*H);		
			
	}
	
	
}



void printHuffmanCodes(HuffTree *R,int *arr, int t)
{
	int i;
	if(R->LC!=NULL)
	{
		arr[t]=0;
		printHuffmanCodes(R->LC,arr,t+1);
	}
	
	
	if(R->RC!=NULL)
	{
		arr[t]=1;
		printHuffmanCodes(R->RC,arr,t+1);
		
	}
	
	
	if((R->LC==NULL)&&(R->RC==NULL))
	{
		printf("\n%c: ", R->letter);
        for(i=0;i<t;i++)
        {
        	printf("%d",arr[i]);
		}
	}
	
	
}



int main()
{
	node *Start=NULL;
	
	Pqueue *qHead=NULL;
	HuffTree *Root;
	int arr[MAX];
 	char ch;
 	FILE *ftxt;

 	ftxt=fopen("textfile.txt","r");

 	if(ftxt==NULL)
 	{
		printf("\nFile does not exist....Exiting");	
		return 0;
 	}


 	while((ch=fgetc(ftxt))!=EOF)
 	{
		StoreCharInNode(&Start,ch);
	}
	
	fclose(ftxt);
	printf("\nFile stored...");
	dispLinkedList(Start);
	
	buildPriorityQueue(&qHead,Start);
	
 	Root=buildHuffTree(&qHead);
 	
 	printHuffmanCodes(Root,arr,0);
 	
	return 0;
}
