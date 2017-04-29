#include <stdio.h>
#include <GL/glut.h>
#define maxHt 640
#define maxWd 480

int cX=20,cY=10, XAxisGlobal=100, YAxisGlobal=70;


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


void drawEllipse(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	//graph
	glBegin(GL_LINES);
		glVertex2i( -maxHt/2,0);
		glVertex2i( maxHt/2,0);
	glEnd();
	glBegin(GL_LINES);
		glVertex2i(0,-maxWd/2);
		glVertex2i(0,maxWd/2);
	glEnd();
	//graph--end---
    int xK, yK, xtempi, ytempi;
    int Pk;
    
    glColor3f(0.0f,0.0f,1.0f);
    glPointSize(1.0);
    glBegin(GL_POINTS);
	//first part
    xK=0;
    yK=YAxisGlobal;
    Pk = (YAxisGlobal*YAxisGlobal)-(XAxisGlobal*XAxisGlobal*YAxisGlobal)+(XAxisGlobal*XAxisGlobal/4);
    while(yK*XAxisGlobal*XAxisGlobal >= xK*YAxisGlobal*YAxisGlobal)
	{
		xtempi = xK;
		ytempi = yK;
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


		xtempi = xK;
		ytempi = -yK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);
		 	
		
		if(Pk <= 0)
		{
			Pk = Pk + (2*YAxisGlobal*YAxisGlobal*(xK+1)) +(YAxisGlobal*YAxisGlobal);
		}
		else
		{
			Pk = Pk + (2*YAxisGlobal*YAxisGlobal*(xK+1)) +(YAxisGlobal*YAxisGlobal) - (2*XAxisGlobal*XAxisGlobal*(yK - 1));
			yK = yK - 1;

		}

		xK = xK + 1;

	}
    //second part
    
    xK=0;
    yK=XAxisGlobal;
    Pk = (XAxisGlobal*XAxisGlobal)-(YAxisGlobal*YAxisGlobal*XAxisGlobal)+(YAxisGlobal*YAxisGlobal/4);
    while(yK*YAxisGlobal*YAxisGlobal >= xK*XAxisGlobal*XAxisGlobal)
	{
		xtempi = yK;
		ytempi = xK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);


		xtempi = -yK;
		ytempi = xK;
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
		 	
		
		if(Pk <= 0)
		{
			Pk = Pk + (2*XAxisGlobal*XAxisGlobal*(xK+1)) +(XAxisGlobal*XAxisGlobal);
		}
		else
		{
			Pk = Pk + (2*XAxisGlobal*XAxisGlobal*(xK+1)) +(XAxisGlobal*XAxisGlobal) - (2*YAxisGlobal*YAxisGlobal*(yK - 1));
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
glutCreateWindow("Draw a Ellipse");
myInit();
glutDisplayFunc(drawEllipse);

glutMainLoop();
}
