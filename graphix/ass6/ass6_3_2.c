#include <stdio.h>
#include <GL/glut.h>
#define maxHt 800
#define maxWd 600

FILE *fp,*fp2;
float fillCol[3] = {0.0,0.6,0.0};  
float borderCol[3] = {1.0,0.0,0.0};  
void myInit(void)
{

glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,maxHt,0,maxWd);
glClear(GL_COLOR_BUFFER_BIT);
}

void drawPoly(FILE *fl)
{
	int count=0,x1,y1,x2,y2;
	while(!feof(fl) )
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
			fscanf(fl, "%d,%d",&x1,&y1);
		}
		else
		{
			fscanf(fl, "%d,%d",&x2,&y2);
			glBegin(GL_LINES);
				glVertex2i( x1,y1);
				glVertex2i( x2,y2);
			glEnd();
			glFlush();
		}
	}
		
		
}
boundaryFillfour(x,y)
{
	if(x>maxHt||x<0||y<0||y>maxWd)
		return;
	
	float ptdata[3];
	 glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,ptdata);
	 printf("\n%f %f %f",ptdata[0],ptdata[1],ptdata[2]);  
	if(((ptdata[0]!=fillCol[0])||(ptdata[1]!=fillCol[1])||(ptdata[2]!=fillCol[2]))&&((ptdata[0]!=borderCol[0])
	||(ptdata[1]!=borderCol[1])||(ptdata[2]!=borderCol[2])))
	{
		glColor3f(fillCol[0],fillCol[1],fillCol[2]);
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		glEnd();
		glFlush();
		boundaryFillfour(x+1,y);
		boundaryFillfour(x-1,y);
		boundaryFillfour(x,y+1);
		boundaryFillfour(x,y-1);
		
	}
}
void mouseClicks(int button, int state, int x, int y) 
{
 
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
 	{
		
   boundaryFillfour(x,maxWd-y);
	
    }
	glFlush();
	
}
void drawKa(void)
{

	
	glColor3f(1.0f,0.0f,0.0f);
	
	drawPoly(fp);
	drawPoly(fp2);
        
}

void main(int argc, char** argv)
{
	fp=fopen ("Poly1Ka.txt","r");
fp2=fopen ("Poly2Ka.txt","r");
if ( fp == NULL|| fp2 == NULL)
    {
        printf( "Could not open file" ) ;
        return;
    }
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(100, 150);
glutCreateWindow("Boundary filled Ka");
myInit();
glutDisplayFunc(drawKa);

glutMouseFunc(mouseClicks);//register callback for mouse

glutMainLoop();
fclose(fp);
    fclose(fp2);
}
