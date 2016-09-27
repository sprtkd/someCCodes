#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>

#define MAX 10


typedef struct TIme
{
	int h;
	int m;
	int s;
	
}Time;


typedef struct Employee
{
	char name[MAX];
	int taskno;
	int timeleft;//considering it in minutes
	struct Employee *nextemployee;
	
}employee;




void employeeinit(employee **header,char *name,int tnum,int tottime)
{
	employee *temp,*next;
	
	if (tnum==0)
		return;
		
	temp=(employee*)malloc(sizeof(employee));	
	strcpy(temp->name,name);
	temp->taskno=tnum;
	temp->timeleft=tottime;
	temp->nextemployee=NULL;
	
	
	if(*header==NULL)
	{
		*header=temp;
		
	}
	else
	{
		next=*header;
		
		while(next!=NULL)
		{
			if(next->taskno==tnum)
			{
				printf("\nTask number already alloted..\nPlease use valid task number!!");
				free(temp);
				return;
			}
			next=next->nextemployee;
		}
		
		next=*header;	
		
		while (next->nextemployee!=NULL)
		{
			next=next->nextemployee;
		}
		
		next->nextemployee=temp;
	}
	
}


void addmintotime(Time *tim,int minutes)
{
	tim->m=tim->m+minutes;
	tim->h=tim->h+(tim->m/60);
	tim->m=tim->m%60;
	tim->h=tim->h%24;
	return;
	
}



void employeesworking(employee **header,int rinterval)
{
	time_t epoch_time;//for time
    struct tm *starttime;//for time
    Time currenttime;
    int flag,reqdtime;
    employee *next;
    
    if(*header==NULL)
    {
    	printf("\nTask list empty..No one is working!!");
    	return;
	}
    
	epoch_time = time( NULL );
    starttime = localtime( &epoch_time );
    
	currenttime.h=starttime->tm_hour;
	currenttime.m=starttime->tm_min;
	currenttime.s=starttime->tm_sec;
	   
    printf("\nStarting time :%2d:%2d:%2d",currenttime.h,currenttime.m,currenttime.s);
	printf("\n------------------------------------------------------------------------------------------------------\n");
	
	
	next=*header;
	flag=0;
	
	printf("\nName\tTask no.\tStart time\tEnd time\tTime consumed");
	printf("\n------------------------------------------------------------------------------------------------------\n");
	while(1)
	{
		if(next->timeleft!=0)
		{
		printf("\n%s\t  %d\t\t%2d:%2d:%2d\t",next->name,next->taskno,currenttime.h,currenttime.m,currenttime.s);
		if(next->timeleft<rinterval)
			reqdtime=next->timeleft;
		else
			reqdtime=rinterval;
		
		next->timeleft=next->timeleft-reqdtime;
		addmintotime(&currenttime,reqdtime);
		printf("%2d:%2d:%2d\t%d",currenttime.h,currenttime.m,currenttime.s,reqdtime);
		
		}
		flag=flag+(next->timeleft);
		
		//moving to next node..
		next=next->nextemployee;
		
			
		if(next==NULL)
			{
				next=*header;
				if(flag==0)
					break;
				flag=0;
			}
		
	}
	
	
	printf("\n------------------------------------------------------------------------------------------------------\n");
	printf("\nEnding time :%d:%d:%d",currenttime.h,currenttime.m,currenttime.s);
	printf("\n------------------------------------------------------------------------------------------------------\n");
	
	
	
}

void displayemplist(employee *head)
{
	employee *next;
	
	if(head==NULL)
	{
		printf("\nTask list is empty!!");
		return;
	}
	
	next=head;
	
	printf("\nName  |Task no.\t|Time to complete\n",next->name,next->taskno,next->timeleft);
	printf("\n------------------------------------------------------------------------------------------------------\n");
	while(next!=NULL)
	{
		printf("\n%s\t%d\t%d",next->name,next->taskno,next->timeleft);
		next=next->nextemployee;
	}
	printf("\n------------------------------------------------------------------------------------------------------\n");
		
		
	
	
}


int main()
{
	
    employee *start=NULL;
    int tasknum,totaltime,reportinterval;
    char nameemp[MAX];
    
    do
    {
    	printf("\nEnter task number to add employee \nor <0> to end:");
    	scanf("%d",&tasknum);
    	if (tasknum!=0)
    	{
    		printf("\nEnter name of employee:");
    		fflush(stdin);
    		scanf("%[^\n]",nameemp);
    		printf("\nEnter time to be allotted:");
    		scanf("%d",&totaltime);
    		
    		employeeinit(&start,nameemp,tasknum,totaltime);
		}
	}while(tasknum!=0);
    
    
    printf("\nList of employees:\n");
    
    displayemplist(start);
    
    printf("\nEnter the time interval of reporting(in mins):");
    scanf("%d",&reportinterval);
    printf("\nPress enter to instruct employees \nto start the work..\n\n");
    fflush(stdin);
    getchar();
    
    employeesworking(&start,reportinterval);	
	
	return 0;
}
