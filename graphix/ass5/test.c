#include <stdio.h>
#include <GL/glut.h>
#define maxHt 640
#define maxWd 480

int cX=-30,cY=40, radGlobal=50;


void myInit(void)
{

glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-maxHt/2.0,maxHt/2.0,-maxWd/2.0,maxWd/2.0);
}



void shiftOriginToCenter(int *x, int *y)
{
	(*x) =  cX+(*x);
	(*y) = cY+(*y);
}


void drawCircle(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.0f);
    	glPointSize(2.0);
	glBegin(GL_POINTS);
		glVertex2i(cX, cY);
	glEnd();
    int Pk, xK, yK, xtempi, ytempi;
    xK=0;
    yK=radGlobal;
    Pk = 1 - radGlobal;
    
    glColor3f(0.0f,0.0f,1.0f);
    glPointSize(1.0);
	glBegin(GL_POINTS);
    while(yK >= xK)
	{
		xtempi = xK;
		ytempi = yK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);

		xtempi = yK;
		ytempi = xK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);

		xtempi = -yK;
		ytempi = xK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);

		xtempi = -xK;
		ytempi = yK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);

		xtempi = -xK;
		ytempi = -yK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);

		xtempi = -yK;
		ytempi = -xK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);

		xtempi = yK;
		ytempi = -xK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);

		xtempi = xK;
		ytempi = -yK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);
		 	
		
		if(Pk <= 0)
		{
			Pk = Pk + (2*xK) + 3;
		}
		else
		{
			Pk = Pk + (2*xK) -(2*yK) + 5;
			yK = yK - 1;
		}

		xK = xK + 1;

	}
    
       
    glEnd();
    glutSwapBuffers();
}

void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(100, 150);
glutCreateWindow("Draw a Circle with centre at (-30,40) and radius 50 points");
myInit();
glutDisplayFunc(drawCircle);

glutMainLoop();
}
