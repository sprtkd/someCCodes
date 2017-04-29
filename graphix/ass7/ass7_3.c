#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define maxHt 1200
#define maxWd 600
#define maxLns 10000

typedef struct line
{
	int x1,x2,y1,y2;
}LINE;

int Poly1SideCount=0,Poly2SideCount=0;
LINE poly1lines[maxLns],poly2lines[maxLns];
FILE *fp,*fp2;

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



void drawandreflectPt(int px, int py)
{
	
	glBegin(GL_POINTS);
		glVertex2i( px,py);
		glVertex2i( (int)(maxHt)-px,py);
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
			drawandreflectPt(xtempi,ytempi);     
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
             
            drawandreflectPt(xtempi,ytempi);        
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



void drawPolyKA()
{
	glPointSize(3.0);
	glColor3f(0.0f,0.0f,1.0f);
	glBegin(GL_POINTS);
		glVertex2i( 0,0);
	glEnd();
	int i;
	for(i=0; i<Poly1SideCount; i++)
	{
		drawLineBresenham(poly1lines[i].x1,poly1lines[i].y1,poly1lines[i].x2,poly1lines[i].y2 );
	}
	
	for(i=0; i<Poly2SideCount; i++)
	{
		drawLineBresenham(poly2lines[i].x1,poly2lines[i].y1,poly2lines[i].x2,poly2lines[i].y2 );
	}
}


void myDisplay(void)
{ 
glClear(GL_COLOR_BUFFER_BIT);
drawBitmapText("Original",0,0,0);
drawBitmapText("Reflection",maxHt/2.0,0,0);
glBegin(GL_LINES);
		glVertex2i( (int)(maxHt/2.0),0);
		glVertex2i( (int)(maxHt/2.0),(int)(maxWd));
	glEnd(); 
drawPolyKA();
glFlush();

}


void storePolyKa()
{

	int count=0,x1,y1,x2,y2;
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
			poly1lines[Poly1SideCount].x1 = x1;
			poly1lines[Poly1SideCount].y1 = y1;
			poly1lines[Poly1SideCount].x2 = x2;
			poly1lines[Poly1SideCount].y2 = y2;
			Poly1SideCount++;
		}
	}
	
	count=0;
	while(!feof(fp2) )
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
			fscanf(fp2, "%d,%d",&x1,&y1);
		}
		else
		{
			fscanf(fp2, "%d,%d",&x2,&y2);
			printf("\n%d,%d",x2,y2);
			poly2lines[Poly2SideCount].x1 = x1;
			poly2lines[Poly2SideCount].y1 = y1;
			poly2lines[Poly2SideCount].x2 = x2;
			poly2lines[Poly2SideCount].y2 = y2;
			Poly2SideCount++;
		}
	}
	
	printf("\nPolygons stored!");
		
		
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
storePolyKa();
    
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(maxHt,maxWd);
glutInitWindowPosition(0, 0);
glutCreateWindow("Reflection of Ka");
glutDisplayFunc(myDisplay);
myInit();
glutMainLoop();
fclose(fp);
}
