/*string search*/
#include<stdio.h>
#define M 100

int main()
{
         char x[M],s[M],sc[M],ss[M],cas;        /*ini*/
         int i,j,c,c1,len,flag;
         
         
         
         
         printf("\nEnter a sentence:");                     /*input*/
         scanf("%[^\n]",x);
         printf("\nEnter the word to be searched:");
         gets(s);
         
         len=strlen(s);
         
         
    
         
         /*checking for case sensivity*/
         
          do
         {
                    puts("\nIs your search case sensitive:(y/n):");
                    cas=getche();
                    if((cas=='y')||(cas=='Y')||(cas=='n')||(cas=='N'))
                    flag=0;
                    else
                    {
                        puts("\nPlease enter a valid option!!");
                        flag=1;
                    }
                          
                     
         }while(flag);
      /*Actual checking*/
         
        if(cas=='y'||cas=='Y')
        {
                               j=0;c=0;c1=0;
         
         for(i=0;x[i]!='\0';i++)
         {
                       
              if(x[i]==s[j])
              j++;
              else
              j=0;
              if(s[j]=='\0')
              {c++;
              j=0;
              if(((x[i+1]=='\0')||(x[i+1]=='.')||(x[i+1]==' '))&&((x[i-len]==' ')||(i-len+1==0)))
              c1++;
              }        
         }             
                                                                              
                      printf("\nThe string entered has \'%s\'  %d  time(s) & that as word(s) %d time(s).",s,c,c1); 
              
         }
        else
        { 
            
                 /*conver to small & cap*/
         
         for(i=0;i<=len;i++)
         {
            if((s[i]>='a')&&(s[i]<='z'))
            sc[i]=s[i]-32;
            else 
            sc[i]=s[i];
            
         }
       for(i=0;i<=len;i++)
         {
            if((s[i]>='A')&&(s[i]<='Z'))
            ss[i]=s[i]+32;
            else 
            ss[i]=s[i];
            
         }
         
         
         
         
        j=0;c=0;c1=0;
         
         for(i=0;x[i]!='\0';i++)
         {
                       
              if((x[i]==ss[j])||(x[i]==sc[j]))
              j++;
              else
              j=0;
              if(ss[j]=='\0')
              {c++;
              j=0;
              if(((x[i+1]=='\0')||(x[i+1]=='.')||(x[i+1]==' '))&&((x[i-len]==' ')||(i-len+1==0)))
              c1++;
              }        
         }             
                  /*print*/                                                           
                      printf("\nThe string entered has \'%s\' or \'%s\' %d  time(s) & that as word(s) %d time(s).",ss,sc,c,c1); 
              
         
                               
        }
        
         getch();
         return 0;
}
         
         
