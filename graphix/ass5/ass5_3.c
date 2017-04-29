#include <stdio.h>
#include <GL/glut.h>
#define maxHt 640
#define maxWd 480

//parabola along y axis
#define parabolaCx 0
#define parabolaCy 100
#define parabolaA 0.25
#define parabolaInvert -1//1 for no invert, -1 for invert
#define parabolaUpperLtX 10

void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-maxHt/2.0,maxHt/2.0,-maxWd/2.0,maxWd/2.0);

}

void shiftOriginToCenter(int *x, int *y)
{
	(*x) =  parabolaCx+(*x);
	(*y) = parabolaInvert*(parabolaCy+(*y));
}

void drawParabola()
{
     int xK, yK, xtempi, ytempi;
    int Pk;
    float temp;
     
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
	glColor3f(0.0f,0.0f,1.0f);
    glPointSize(2.0);
    glBegin(GL_POINTS);
    
    xK=0;
    yK=0;
    temp = 2.0*parabolaA;
    Pk = 1 - (int)temp;    
    //region 1         
    while((((float)xK) <= temp)&&(xK <= parabolaUpperLtX))
    {
        //printf("\n%d",xK);
        xtempi = xK;
		ytempi = yK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);

		xtempi = -xK;
		ytempi = yK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi); 
        
        if(Pk <= 0)
		{
			Pk = Pk + (2*xK) + 3;
            
		}
		else
		{
		
            Pk = Pk + (2*xK) + 3 -(4*parabolaA);
			yK = yK + 1;
		}  
           
       xK = xK + 1;   
    }
  
    //region 2
    temp = ((xK +0.5)*(xK +0.5)) - (4.0*parabolaA*(yK+1.0));
    Pk = (int)temp;
   while(xK <= parabolaUpperLtX)
    {
       //printf("\n%d",xK);
        xtempi = xK;
		ytempi = yK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);

		xtempi = -xK;
		ytempi = yK;
		shiftOriginToCenter(&xtempi,&ytempi);
		glVertex2i(xtempi, ytempi);     
         
        if(Pk <= 0)
		{
			Pk = Pk -(4*parabolaA) + (2*xK) +2;
			xK=xK+1;
            
		}
		else
		{
            Pk = Pk -(4*parabolaA);
			
		}   
           
      yK = yK + 1;   
    }
    
    
    glEnd();
    glutSwapBuffers();
}
     

void main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(150, 150);
glutCreateWindow("Draw a Parabola");
myInit();
glutDisplayFunc(drawParabola);
glutMainLoop();
}
