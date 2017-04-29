#include <stdio.h>
#include <GL/glut.h>
#define maxHt 800
#define maxWd 600

#define transSpeed 1
#define rotSpeed 1

/*
program to make a dinosaur walk

parts
----------------
head+neck
upper body boundary(only translation)
tail
back leg front
back leg rear
lower body boundary(only translation)
front leg rear
front leg front
------------------------

all should be joined
*/



FILE *fp;


void myInit(void)
{

glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);

glLoadIdentity();
gluOrtho2D(0,maxHt,0,maxWd);
glClear(GL_COLOR_BUFFER_BIT);
}

void drawPolyDino()
{

	glColor3f(1.0f,0.0f,0.0f);
	int count=0,x1,y1,x2,y2;
	rewind(fp);
	while(!feof(fp) )
	{
		count++;
		if(count>2)
		{
			x1=x2;
			y1=y2;
			count=2;
		}
		if(count==1)
		{
			fscanf(fp, "%d,%d",&x1,&y1);
		}
		else
		{
			fscanf(fp, "%d,%d",&x2,&y2);
			printf("\n%d,%d",x2,y2);
			glBegin(GL_LINES);
				glVertex2i( x1,y1);
				glVertex2i( x2,y2);
			glEnd();
			glFlush();
		}
	}
		
		
}

void drawDino(void)
{

	drawPolyDino();
    
    
}

void main(int argc, char** argv)
{
	fp=fopen ("PolyDino.txt","r");
if ( fp == NULL )
    {
        printf( "Could not open file" ) ;
        return;
    }
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(0,0);
glutCreateWindow("Walking dinosaur");
myInit();
glutDisplayFunc(drawDino);

glutMainLoop();
fclose(fp);
}
