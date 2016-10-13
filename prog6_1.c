//binary search tree
#include<stdio.h>
#include<stdlib.h>


//globals
int valueFoundFlag;
int NodeCount;
int leafCount;
int fullNodeCount;
int ancestorCount;
int descendantCount;
int isFoundForDescendants;
typedef struct Tree
{
	struct Tree *LC,*RC;
	int data;
}BST;

void insertTree(BST **R,int v)
{
     
	if((*R)==NULL)
	{
		*R=(BST*)malloc(sizeof(BST));
		(*R)->data = v;
		(*R)->LC = NULL;
		(*R)->RC = NULL;
	}
	else if((*R)->data > v)
		insertTree(&((*R)->LC ),v);
	else if((*R)->data < v)
		insertTree(&((*R)->RC ),v);
	else
		printf("\nDuplicate Data!!");
}


void findElement(BST **R,int val)
{
    
     if((*R)==NULL)
		return;
	else if((*R)->data==val)
	{
		valueFoundFlag=1;
	}
	else if(((*R)->LC==NULL)&&((*R)->RC==NULL))
	{
		valueFoundFlag=0;
	}
	else if((*R)->data>val)
	{
		findElement(&((*R)->LC),val);
	}
	else if((*R)->data<val)
	{
		findElement(&((*R)->RC),val);
	}
}

void inOrder(BST *R)
{
	if((R)==NULL)
		printf("\nEmpty tree!!");
		
	else
	{
		if(R->LC!=NULL)
			inOrder(R->LC);
		printf("\n%d",R->data);
		 if(R->RC!=NULL)
                        inOrder(R->RC);
	}


}

BST* deleteChild(BST *R,int v)//Not workin!!!!!!
{
    if(R==NULL)
    {
    	printf("\nEmpty tree!!Cannot delete..");
		return R;	
	}
	else if(v<R->data)
	{
		R->LC=deleteChild(R->LC,v);
	}	
	else if(v>R->data)
	{
		R->RC=deleteChild(R->RC,v);
	}
    else if(v==R->data)
    {
    	//found...
    	printf("\nData to delete found...");
    	//for no child
		if((R->LC==NULL)&&(R->RC==NULL))
		{
			printf("\nDeleting node with no child");
			free(R);
			R=NULL;
			return R;
		}
		//for single child on left
		else if(R->RC==NULL)
		{
			printf("\nDeleting node with left child");
			BST *temp;
			temp=R;
			R=R->LC;
			free(temp);
			return R;
		}
		//for single child on right
		else if(R->LC==NULL)
		{
			printf("\nDeleting node with right child");
			BST *temp;
			temp=R;
			R=R->RC;
			free(temp);
			return R;
		}
		//for two children
		else
		{
			//we have to replace the value with the minimum value in the right subtree and then delete it..
			printf("\nDeleting node with two children");
			BST *temp,*prev;
			temp=R->RC;
			prev=R;
			while(temp->LC!=NULL)
			{
				prev=temp;
				temp=temp->LC;
			}
			
			if(prev!=NULL)
				prev->LC=NULL;
				
			R->data=temp->data;//replacing value..
			
			free(temp);//deleting smallest node in right subtree..
			
			return R;
			
			
		}
    	
	}
	else
	{
		printf("\nError while deleting;");
		return R;
	}
	 
}


void findMin(BST **R)
{
	if((*R)==NULL)
		printf("\nEmpty tree!!");	
	if((*R)->LC==NULL)
	{
		printf("\nMinimum: %d",(*R)->data);

	}
	else
	{
		findMin(&((*R)->LC));	
	}

}

void findMax(BST **R)
{
	if((*R)==NULL)
		printf("\nEmpty tree!!");	

	if((*R)->RC==NULL)
	{
		printf("\nMaximum: %d",(*R)->data);

	}
	else
	{
		findMax(&((*R)->RC));	
	}

}

void printLeftChild(BST *R,int val)
{
	if((R)==NULL)
		printf("\nError");
		
	else
	{
		if(R->LC!=NULL)
			printLeftChild(R->LC,val);
		if(R->data==val)
		{
			if(R->LC!=NULL)
			{
				printf("\nThe left child is:%d",R->LC->data); 
			}
			else
				printf("\nNo left child!!");
			return;	
		}
		 if(R->RC!=NULL)
                        printLeftChild(R->RC,val);
	}


}

void printRightChild(BST *R,int val)
{
	if((R)==NULL)
		printf("\nError");
		
	else
	{
		if(R->RC!=NULL)
			printRightChild(R->RC,val);
		if(R->data==val)
		{
			if(R->RC!=NULL)
			{
				printf("\nThe right child is:%d",R->RC->data); 
			}
			else
				printf("\nNo right child!!");
			return;	
		}
		 if(R->RC!=NULL)
                        printRightChild(R->RC,val);
	}


}


void CountNodes(BST *R)
{
     if((R)==NULL)
		printf("\nEmpty tree!!");
		
	else
	{
		if(R->LC!=NULL)
			CountNodes(R->LC);
	  	NodeCount++;
		 if(R->RC!=NULL)
            CountNodes(R->RC);
	}
     
     
     
     
}


void CountLeafs(BST *R)
{
     if((R)==NULL)
		return;
		
	else
	{
		if(R->LC!=NULL)
			CountLeafs(R->LC);
	  	if((R->LC == NULL)&&(R->RC == NULL))
	  	          leafCount++;
		 if(R->RC!=NULL)
            CountLeafs(R->RC);
	}
     
     
}

void CountFullNodes(BST *R)
{
      if((R)==NULL)
		return;
		
	else
	{
		if(R->LC!=NULL)
			CountFullNodes(R->LC);
	  	if((R->LC != NULL)&&(R->RC != NULL))
	  	          fullNodeCount++;
		 if(R->RC!=NULL)
            CountFullNodes(R->RC);
	}
     
     
}


int CountAncestors(BST *R,int v)
{
     
    
  if (R == NULL)
     return 0;
 
  if (R->data == v)
     return 1;

  if ( (CountAncestors(R->LC,v)==1) || (CountAncestors(R->RC,v)==1) )
  {
    ancestorCount++;
    return 1;
  }

  return 0;
     

}

int CountDescendants(BST *R,int v)
{
     if((R)==NULL)
		return;
		
	else
	{
        if(R->data==v)
	  	     isFoundForDescendants=1; 
          
		if(R->LC!=NULL)
			CountDescendants(R->LC,v);
			
		if((isFoundForDescendants==1)&&(R->data!=v))
           descendantCount++; 
           
	  	          
	  	          
		 if(R->RC!=NULL)
            CountDescendants(R->RC,v);
            
         if(R->data==v)
            isFoundForDescendants=0;                
	}
     
}



int main()
{
	BST *Root=NULL;
	int opt,val;
	
	opt=1;
	printf("\nEnter \n\t1 to insert\n\t2 to delete node"
	"\n\t3 to display in in_order"
	"\n\t4 to find an element\n\t5 to find min\n\t6 to find max"
	"\n\t7 to print left child of given node\n\t8 to print right child of a given node"
	"\n\t9 to print number of ancestors of a given node\n\t10 to print number of descendants of a given node"
    "\n\t11 to print info about tree\n\t0 to exit...");

	while (opt)
	{
		printf("\nEnter option:");
		scanf("%d",&opt);
		//resetting globals..
		valueFoundFlag=0;
        NodeCount=0;
        leafCount=0;
        fullNodeCount=0;
        ancestorCount=0;
        descendantCount=0;
        isFoundForDescendants=0;



		switch(opt)
		{
			case 1:printf("\nEnter value to store:");
				scanf("%d",&val);
				insertTree(&Root,val);
				break;
					
			case 2:printf("\nEnter the number you want to delete:");
				   scanf("%d",&val);
				   findElement(&Root,val);
				   if(valueFoundFlag)
					   Root=deleteChild(Root,val);
				   else
					    printf("\nValue not found..");
				break;
				
			case 3:printf("\nPrinting in in_order:\n");
				inOrder(Root);
				break;
			case 4:printf("\nEnter the number you want to search:");
				scanf("%d",&val);
				findElement(&Root,val);
				if(valueFoundFlag)
					printf("\nValue found..");
				else
					printf("\nValue not found..");			
				break;
			case 5:findMin(&Root);
				break;
			case 6:findMax(&Root);
				break;
			case 7:printf("\nEnter a value to print its left child:");
				  scanf("%d",&val);
				   findElement(&Root,val);
				   if(valueFoundFlag)
				   {
					    printLeftChild(Root,val);
				   }
				   else
					    printf("\nValue not found..");	
			    	break;
			case 8:printf("\nEnter a value to print its right child:");
			    	scanf("%d",&val);
			    	findElement(&Root,val);
			     	if(valueFoundFlag)
			    	{
				    	printRightChild(Root,val);
			    	}
			    	else
				    	printf("\nValue not found..");
			    	break;
			case 9:printf("\nEnter a value to print its ancestors:");
                    scanf("%d",&val);
				    findElement(&Root,val);
				    if(valueFoundFlag)
				    {
				    	CountAncestors(Root,val);
                        printf("\nNo. of ancestors of %d in tree=%d.",val,ancestorCount);
				    }
			    	else
				    	printf("\nValue not found..");	
                    break;
            case 10:printf("\nEnter a value to print its descendants:");
                    scanf("%d",&val);
				    findElement(&Root,val);
				    if(valueFoundFlag)
				    {
                          CountDescendants(Root,val);
                          printf("\nNo. of descendants of %d in tree=%d.",val,descendantCount);
				    }
			    	else
				    	printf("\nValue not found..");	
                    break;    	
			    	
			case 11:printf("\nTree info:\n");
                    CountNodes(Root);
                    printf("\nNo. of nodes in tree=%d.",NodeCount);
                    CountLeafs(Root);
                    printf("\nNo. of leaves in tree=%d.",leafCount);
                    CountFullNodes(Root);
                    printf("\nNo. of full nodes in tree=%d.",fullNodeCount);
                    
                    
			    	break;
			case 0:printf("\nExiting...");
			    	break;
			default:printf("\nInvalid option!!!");
			    	break;
		}

	}	

	return 0;

	

}
