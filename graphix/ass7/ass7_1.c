#include <stdio.h>
#include <math.h>
#include<time.h>
#include <GL/glut.h>
#define maxHt 640
#define maxWd 480
#define thetaSpeed 0.05

int ClickCount = 0, X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;
float theta=0.0;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,maxHt,0.0,maxWd);
glClear(GL_COLOR_BUFFER_BIT);
drawBitmapText("Click the centre",0,0,0);
glFlush();

}


void drawBitmapText(char *string,float x,float y,float z) 
{  
	char *c;
	glColor3f(1.0f,0.0f,0.0f);
	glRasterPos3f(x, y,z);

	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}

void drawPoint(int x, int y)
{
	glPointSize(7.0);
	glColor3f(0.0f,0.0f,1.0f);
	glBegin(GL_POINTS);
		glVertex2i( x,y);
	glEnd();
}


void rotateAroundPt(int px, int py, int cx, int cy)
{
	while(1)
	{
	
	glClear(GL_COLOR_BUFFER_BIT);
	int xf,yf;
	theta=theta + thetaSpeed;
	if(theta >= (2.0*3.14159))
		theta = theta - (2.0*3.14159);
	
	xf=cx + (int)((float)(px-cx)*cos(theta)) - ((float)(py-cy)*sin(theta));
	yf=cy+ (int)((float)(px-cx)*sin(theta)) + ((float)(py-cy)*cos(theta));	
	printf("\nrotate x=%d y=%d THETA =%.1f",xf,yf,theta);
	drawPoint(cx, cy);
	drawPoint(xf,yf);
	glFlush();
	delay(10);       
	}
}

void mouseClicks(int button, int state, int x, int y) 
{
 
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
 	{
	
     		ClickCount++;
     		if(ClickCount>2)
     		{
     			X1 = 0;         
			
			ClickCount = 1;Y1 = 0;
			X2 = 0;
			Y2 = 0;
     		}
			

	if(ClickCount == 1)
	{X1 = x;
	Y1 = maxWd - y;
	glClear(GL_COLOR_BUFFER_BIT);
	drawPoint(X1,Y1);
	drawBitmapText("Click the rotating point",0,0,0);
	glFlush();
	printf("\nRegistered 1st pt X = %d, Y = %d COUNT = %d",X1, Y1,ClickCount);
	}
	
	
	if(ClickCount == 2)
	{X2 = x;
	Y2 = maxWd - y;
	printf("\nRegistered 2st ptX = %d, Y = %d COUNT = %d",X2, Y2,ClickCount);
	
	rotateAroundPt(X2,Y2,X1,Y1);
	
	}
	
    }

	
}

void myDisplay(void)
{ 

}




void main(int argc, char** argv)
{
ClickCount = 0;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(100, 150);
glutCreateWindow("Draw a rotating point");
glutDisplayFunc(myDisplay);
myInit();
glutMouseFunc(mouseClicks);//register callback for mouse
glutMainLoop();
}
