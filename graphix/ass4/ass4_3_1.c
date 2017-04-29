#include <stdio.h>
#include <GL/glut.h>
#include<math.h>
#define maxHt 640
#define maxWd 480
#define gap 8
#define sizept 1

int ClickCount = 0, X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;


void drawBitmapText(char *string,float x,float y,float z) 
{  
	char *c;
	glRasterPos3f(x, y,z);

	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}






void DisplayGraph(void)
{ 
    int i,j;
     
     
     glColor3f(0.0f,0.0f,1.0f);
     glPointSize(sizept);
     glBegin(GL_POINTS); 
     
     //vertical lines
     for( i = 0; i <= maxHt; i=i+(gap))
     {
          for( j=0; j <= maxWd; j++)
               glVertex2i(i,j);
     }
     
     //horizontal lines
     for( j = 0; j <= maxWd; j=j+(gap))
     {
          for( i=0; i <= maxHt; i++)
               glVertex2i(i,j);
     }
      
      //middle line reinforcement horizontal
       for( j = (maxWd/2) - (gap/8); j <= (maxWd/2) + (gap/8); j++)
     {
          for( i=0; i <= maxHt; i++)
               glVertex2i(i,j);
     } 
     
     //middle line reinforcement vertical
       for( i = (maxHt/2) - (gap/8); i <= (maxHt/2) + (gap/8); i++)
     {
          for( j=0; j <= maxHt; j++)
               glVertex2i(i,j);
     }    

     glEnd();
    
     
}

void blankDisplay()
{
glClear(GL_COLOR_BUFFER_BIT);
DisplayGraph();
glColor3f(1.0f,0.0f,0.0f);
drawBitmapText("Click first point of the line",0,0,0);
glutSwapBuffers();
}

void normalisePoint(int *x, int *y)
{
int j,k;
j=*x;
k=*y;
     
*x=((j/gap)*gap) +(gap/2);
*y=((k/gap)*gap) +(gap/2);
//printf(" -> %d, %d",*x,*y);     
}

void myInit(void)
{

glClearColor(1.0,1.0,1.0,0.0);
glColor3f(1.0f,0.0f,0.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0);
}



void drawLineDDA(int x1,int y1,int x2,int y2)
{
	//finding slope
	float lineSlope,ytemp,xtemp;
	int xtempi, ytempi, xMap, yMap;
	
	
	ytemp=(float) (y2-y1);
	xtemp = (float) (x2-x1);
	lineSlope = ytemp/xtemp;
	printf("\nSlope=%f.",lineSlope);
	
	glColor3f(1.0f,0.0f,0.0f);
		glPointSize(gap);
	glBegin(GL_POINTS);
	
	if((abs(lineSlope) < 1.000000)&&(abs(x2-x1)))
	{
           //proceed with x     
          
          //first find out smaller x
          if(x1>x2)
          {
                   xtempi = x2;
                   x2=x1;
                   x1 = xtempi;
                   ytempi = y2;
                   y2 = y1;
                   y1 = ytempi;
          }
          xtempi = x1;//init
          ytemp = (float)y1;
          while( xtempi <= x2)
          {
                //printf("\t%d , %d",xtempi,ytempi);
                xMap = xtempi;
                yMap = round(ytemp);
                normalisePoint(&xMap,&yMap);
              glVertex2i(xMap, yMap);   
               xtempi++;//increment x by 1 
              
               ytemp = ytemp+ lineSlope;
                
          }
                        
    }
    else
    {
         //proceed with y
         //first find out smaller y
          if(y1>y2)
          {
                   xtempi = x2;
                   x2=x1;
                   x1 = xtempi;
                   ytempi = y2;
                   y2 = y1;
                   y1 = ytempi;
          }
          xtemp = (float)x1;//init
          ytempi = y1;
          while( ytempi <= y2)
          {
                 //printf("\t%d , %d",xtempi,ytempi);
                 xMap = round(xtemp);
                yMap = ytempi;
                normalisePoint(&xMap,&yMap);
              glVertex2i(xMap, yMap); 
              
               ytempi++;//increment x by 1 
              
               xtemp = xtemp+ (1.0/lineSlope);
                
          }
    }
	glEnd();

}



void mouseClicks(int button, int state, int x, int y) 
{
 
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
 {
	
     ClickCount++;
    	if(ClickCount > 2)
	{ClickCount = 1;
	X1 = 0;
	Y1 = 0;
	X2 = 0;
	Y2 = 0;
	
	}

	if(ClickCount == 1)
	{X1 = x;
	Y1 = maxWd - y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.0f);
	drawBitmapText("Click second point of the line",0,0,0);
	DisplayGraph();
	glutSwapBuffers();
	printf("\nRegistered 1st pt X = %d, Y = %d COUNT = %d",X1, Y1,ClickCount);
	
	}
	
	
	if(ClickCount == 2)
	{X2 = x;
	Y2 = maxWd - y;
	glClear(GL_COLOR_BUFFER_BIT);
	drawLineDDA(X1,Y1,X2,Y2);
	glColor3f(1.0f,0.0f,0.0f);
	drawBitmapText("Click first point of the line",0,0,0);
	DisplayGraph();
	glutSwapBuffers();
	printf("\nRegistered 2st ptX = %d, Y = %d COUNT = %d",X2, Y2,ClickCount);
	}
	
    }

	
}




void main(int argc, char** argv)
{
ClickCount = 0;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(100, 150);
glutCreateWindow("Draw a Line using DDA in graph");
myInit();
glutDisplayFunc(blankDisplay);
glutMouseFunc(mouseClicks);//register callback for mouse
glutMainLoop();
}
