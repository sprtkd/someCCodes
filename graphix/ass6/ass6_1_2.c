#include <stdio.h>
#include <GL/glut.h>
#define maxHt 800
#define maxWd 600

#define minPixThresh 6

int ClickCount = 0, X1 = 0, Y1 = 0, X2 = 0, Y2 = 0,xBegin = 0,yBegin = 0,statusComplete = 0;
FILE *fp,*fp2;

void myInit(void)
{

glClearColor(1.0,1.0,1.0,0.0);
glColor3f(1.0f,0.0f,0.0f);
glPointSize(3.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,maxHt,0.0,maxWd);

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

void mouseClicks(int button, int state, int x, int y) 
{
 
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && statusComplete!=2)
 	{
	
     ClickCount++;
    	if(ClickCount > 2)
	{ClickCount = 2;
	X1 = X2;
	Y1 = Y2;
	X2 = 0;
	Y2 = 0;
	}

	if(ClickCount == 1)
	{X1 = x;
	Y1 = maxWd - y;
	xBegin = X1;
	yBegin = Y1;
	printf("\nRegistered 1st pt X = %d, Y = %d",X1, Y1);
	if(statusComplete==0)
	fprintf (fp, "%d,%d\n",X1,Y1);
    else
     fprintf (fp2, "%d,%d\n",X1,Y1); 
	}
	
	
	if(ClickCount == 2)
	{X2 = x;
	Y2 = maxWd - y;
	glBegin(GL_LINES);
		glVertex2i( X1,Y1);
		glVertex2i( X2,Y2);
	glEnd();
		glFlush();
	printf("\nRegistered pt X = %d, Y = %d",X2, Y2);
	if(statusComplete==0)
	fprintf (fp, "%d,%d\n",X2,Y2);
    else
     fprintf (fp2, "%d,%d\n",X2,Y2); 
	
	if( ((X2-xBegin)*(X2-xBegin)) + ((Y2-yBegin)*(Y2-yBegin)) <= (minPixThresh*minPixThresh))
	{
		X1 = X2;
		Y1 = Y2;
		X2 = xBegin;
		Y2 = yBegin;
		glBegin(GL_LINES);
			glVertex2i( X1,Y1);
			glVertex2i( X2,Y2);
		glEnd();
		printf("\nPolygon complete....");
		if(statusComplete==0)
	    drawBitmapText("Draw 2nd polygon....",0,3,0);
    else
     drawBitmapText("Polygon complete....",0,30,0);
		
		if(statusComplete==0)
	    fprintf (fp, "%d,%d\n",X2,Y2);
        else
        fprintf (fp2, "%d,%d\n",X2,Y2); 
		glFlush();
		if(statusComplete==0)
	    fclose(fp);
    else
     fclose(fp2);
		
		statusComplete++;
		ClickCount = 0;
	}
	}
	

	
	
    }

	
}

void myDisplay(void)
{ 
glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}




void main(int argc, char** argv)
{

fp=fopen ("Poly1Ka.txt","w");
fp2=fopen ("Poly2Ka.txt","w");
if ( fp == NULL|| fp2 == NULL)
    {
        printf( "Could not open file" ) ;
        return;
    }
ClickCount = 0;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(150, 150);
glutCreateWindow("Draw Ka using a polygon");
glutDisplayFunc(myDisplay);
myInit();
glutMouseFunc(mouseClicks);//register callback for mouse
glutMainLoop();
}
