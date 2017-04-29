#include <stdio.h>
#include <GL/glut.h>
#define maxHt 640
#define maxWd 480


int X1 = 0, Y1 = 0;

void myInit(void)
{

glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0f,0.0f,0.0f);
glPointSize(6.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,640.0,0.0,480.0);

}

void mouseClicks(int button, int state, int x, int y) 
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
    
	X1 = x;
	Y1 = maxWd - y;
	
	glBegin(GL_POINTS);
	glVertex2i(X1, Y1);
	glEnd();
	printf("\nRegistered ptX = %d, Y = %d ",X1, Y1);
	
    }
    glFlush();
}

void myDisplay(void)
{ 
glClear(GL_COLOR_BUFFER_BIT);
}




void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(100, 150);
glutCreateWindow("Draw Points");
glutDisplayFunc(myDisplay);
myInit();
glutMouseFunc(mouseClicks);//register callback for mouse
glutMainLoop();
}
