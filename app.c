/*application*/
#include<stdio.h>
#define M 100

struct eli
{
       char name[M];
       int p;
       int c;
       int m;
};
int main()
{
    struct eli cand[M];
    int f=1,i;   
    printf("\nProgram to list eligible candidates:-");
    printf("\n---------------------------------------");
     for (i=0;f!=0;i++)
    {printf("\%d ",f);
        printf("\nEnter no.%d student's name:",i+1);
        gets(cand[i].name);
        printf("\nEnter no.%d student's marks in Physics,Chemistry & Maths(with\',\' seperator\n):",i+1);
        scanf("%d,%d,%d",&cand[i].p,&cand[i].c,&cand[i].m);
        printf("\nEnter any key to continue and 0 to terminate input:");
      
        
    }
    getch();
    return 0;
}

        
    
    
    
