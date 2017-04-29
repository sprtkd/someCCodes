#include <stdio.h>
#include <GL/glut.h>
#define maxHt 640.0
#define maxWd 480.0

#define gap 8
#define sizept 1

void myInit(void)
{
     glClearColor(1.0,1.0,1.0,0.0);
     glColor3f(0.0f,0.0f,1.0f);
     glPointSize(sizept);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,maxHt,0.0,maxWd);
}

void normalisePoint(int *x, int *y)
{
int j,k;
j=*x;
k=*y;
     
*x=((j/gap)*gap) +(gap/2);
*y=((k/gap)*gap) +(gap/2);
printf(" -> %d, %d",*x,*y);     
}


void myDisplay(void)
{
     int i,j;
     glClear(GL_COLOR_BUFFER_BIT);
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
     glFlush();
     
}

void mouseClicks(int button, int state, int x, int y) 
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
    int X1, Y1;
	X1 = x;
	Y1 = maxWd - y;
	glPointSize(gap);
	glColor3f(1.0f,0.0f,0.0f);
	printf("\nRegistered ptX = %d, Y = %d ",X1, Y1);
	glBegin(GL_POINTS);
    normalisePoint(&X1,&Y1);
	glVertex2i(X1, Y1);
	glEnd();
	
	
    }
    glFlush();
}


void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(100, 150);
glutCreateWindow("GraphPaper");
glutDisplayFunc(myDisplay);
myInit(); 
glutMouseFunc(mouseClicks);//register callback for mouse
glutMainLoop();
}
