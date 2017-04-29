#include <stdio.h>
#include <GL/glut.h>
#include<math.h>
#define maxHt 640
#define maxWd 480

int ClickCount = 0, X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;






void myInit(void)
{

glClearColor(1.0,1.0,1.0,0.0);
glColor3f(1.0f,0.0f,0.0f);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0);
glClear(GL_COLOR_BUFFER_BIT);
drawBitmapText("Click first point of the line",0,0,0);
glutSwapBuffers();
}


void drawBitmapText(char *string,float x,float y,float z) 
{  
	char *c;
	glRasterPos3f(x, y,z);

	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}



void drawLineDDA(int x1,int y1,int x2,int y2)
{
	//finding slope
	float lineSlope,ytemp,xtemp;
	int xtempi, ytempi;
	
	
	ytemp=(float) (y2-y1);
	xtemp = (float) (x2-x1);
	lineSlope = ytemp/xtemp;
	printf("\nSlope=%f.",lineSlope);
	
	glColor3f(0.0f,0.0f,0.0f);
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
              glVertex2i(xtempi, round(ytemp));   
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
              glVertex2i(round(xtemp), ytempi);   
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
	glutSwapBuffers();
	printf("\nRegistered 1st pt X = %d, Y = %d COUNT = %d",X1, Y1,ClickCount);
	
	}
	
	
	if(ClickCount == 2)
	{X2 = x;
	Y2 = maxWd - y;
	glClear(GL_COLOR_BUFFER_BIT);
	//glutSwapBuffers();
	drawLineDDA(X1,Y1,X2,Y2);
	glColor3f(1.0f,0.0f,0.0f);
	drawBitmapText("Click first point of the line",0,0,0);
	glutSwapBuffers();
	printf("\nRegistered 2st ptX = %d, Y = %d COUNT = %d",X2, Y2,ClickCount);
	}
	
    }

	
}

void myDisplay(void)
{ 
glClear(GL_COLOR_BUFFER_BIT);
drawBitmapText("Click first point of the line",0,0,0);
//glutSwapBuffers();

}




void main(int argc, char** argv)
{
ClickCount = 0;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(100, 150);
glutCreateWindow("Draw a Line using DDA");
glutDisplayFunc(myDisplay);
myInit();
glutMouseFunc(mouseClicks);//register callback for mouse
glutMainLoop();
}
