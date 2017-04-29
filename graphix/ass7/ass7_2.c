#include <stdio.h>
#include <math.h>
#include<time.h>
#include <GL/glut.h>
#define maxHt 1024
#define maxWd 700
#define maxLns 10000
#define thetaSpeed 0.01
#define delta 1

typedef struct line
{
	int x1,x2,y1,y2;
}LINE;

int PolySideCount=0,cx,cy;
LINE polylines[maxLns];
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

void rotatePt(int px, int py)
{
	int xf,yf;
	
	
	xf=cx + (int)((float)(px-cx)*cos(theta)) - ((float)(py-cy)*sin(theta));
	yf=cy+ (int)((float)(px-cx)*sin(theta)) + ((float)(py-cy)*cos(theta));	
	glBegin(GL_POINTS);
		glVertex2i( xf,yf);
	glEnd(); 
}



void drawLineBresenham(int x1,int y1,int x2,int y2)
{
	int Dx, Dy, Dxmul2, Dymul2, Pk, xtempi, ytempi;
	float lineSlope, xtemp, ytemp;
	
    
    Dx = abs(x2 - x1);
    Dy = abs(y2 - y1);
    Dxmul2 = 2*Dx;
    Dymul2 = 2*Dy;
    
    ytemp=(float)(y2-y1);
    xtemp=(float)(x2 - x1);
    lineSlope = (ytemp/xtemp);
    //printf("\nSlope=%f",lineSlope);
    
    
    if(lineSlope>=-1.0 && lineSlope <=1.0)
    {
    Pk = Dymul2-Dx;   
    if(x1>x2)
    {
      xtempi = x2;
      x2=x1;
      x1 = xtempi;
      ytempi = y2;
      y2 = y1;
      y1 = ytempi;
    }  
    for(xtempi = x1, ytempi = y1; xtempi <= x2; xtempi++)
    { 
			rotatePt(xtempi,ytempi);     
           if(Pk <0)
           {
                Pk = Pk + Dymul2;
           }
           else
           {
               Pk = Pk + Dymul2 - Dxmul2;
               if(lineSlope>=0.0 && lineSlope <=1.0)
                    ytempi = ytempi+1;
                else if(lineSlope<0.0 && lineSlope >=-1.0)
                    ytempi = ytempi-1;     
               
           }
                         
               
    }
    }
    else
    {
        Pk = Dxmul2-Dy;  
        if(y1>y2)
        {
      xtempi = x2;
      x2=x1;
      x1 = xtempi;
      ytempi = y2;
      y2 = y1;
      y1 = ytempi;
      }  
    for(xtempi = x1, ytempi = y1; ytempi <= y2; ytempi++)
    {
             
            rotatePt(xtempi,ytempi);        
           if(Pk <0)
           {
                Pk = Pk + Dxmul2;
           }
           else
           {
               Pk = Pk + Dxmul2 - Dymul2;
               if(lineSlope>1.0 )
                    xtempi = xtempi+1;
                else if(lineSlope<-1.0)
                    xtempi = xtempi-1;     
               
           }
                         
               
    }
    }
}



void drawPolydino()
{
	int i;
	for(i=0; i<PolySideCount; i++)
	{
		drawLineBresenham(polylines[i].x1,polylines[i].y1,polylines[i].x2,polylines[i].y2 );
	}
}


void rotateDino()
{
	glPointSize(3.0);
	glColor3f(0.0f,0.0f,1.0f);
	while(1)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		drawPolydino();
		glFlush();
		delay(delta); 
		theta=theta - thetaSpeed;
		if(theta >= (2.0*3.14159))
			theta = theta - (2.0*3.14159); 
	}
	
}

void mouseClicks(int button, int state, int x, int y) 
{
 
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
 	{
		//the next will be an infinite loop
		cx = x;
		cy = maxWd - y;
		rotateDino();
    }

	
}

void myDisplay(void)
{ 
glClear(GL_COLOR_BUFFER_BIT);
drawBitmapText("Click the centre",0,0,0);
glFlush();

}


void storePolyDino(FILE *f)
{

	int count=0,x1,y1,x2,y2;
	while(!feof(f) )
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
			fscanf(f, "%d,%d",&x1,&y1);
		}
		else
		{
			fscanf(f, "%d,%d",&x2,&y2);
			printf("\n%d,%d",x2,y2);
			polylines[PolySideCount].x1 = x1;
			polylines[PolySideCount].y1 = y1;
			polylines[PolySideCount].x2 = x2;
			polylines[PolySideCount].y2 = y2;
			PolySideCount++;
		}
	}
	
	printf("\nPolygon stored!");
		
		
}




void main(int argc, char** argv)
{
FILE *fp;
fp=fopen ("PolyDino.txt","r");
if ( fp == NULL )
    {
        printf( "Could not open file" ) ;
        return;
    }
    
storePolyDino(fp);
    
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(100, 150);
glutCreateWindow("Rotating Dinosaur");
glutDisplayFunc(myDisplay);
myInit();
glutMouseFunc(mouseClicks);//register callback for mouse
glutMainLoop();
fclose(fp);
}
