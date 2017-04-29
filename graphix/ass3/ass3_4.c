#include <stdio.h>
#include <GL/glut.h>
#define maxHt 640
#define maxWd 480


void myInit(void)
{

glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0f,0.0f,0.0f);
glPointSize(12.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-320.0,320.0,-240.0,240.0);

}

void myDisplay(void)
{ 
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS); 
glVertex2i(0,0);//this is the origin of window

glEnd();
glFlush();
}

void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(100, 150);
glutCreateWindow("OriginAtCenter");
glutDisplayFunc(myDisplay);
myInit(); 
glutMainLoop();
}
