/*To find cross product and dot product*/
#include<stdio.h>
struct vctor
{
       int x,y,z;
       }v1,v2,cproduct;

int main()
{
    int dprod;
    printf("Enter x,y,z components for vector 1:");
    scanf("%d,%d,%d",&v1.x,&v1.y,&v1.z);
    printf("Enter x,y,z components for vector 2:");
    scanf("%d,%d,%d",&v2.x,&v2.y,&v2.z);
    cproduct.x=v1.y*v1.z-v2.y*v1.z;
    cproduct.y=v2.x*v1.z-v1.x*v2.z;
    cproduct.z=v1.x*v2.y-v2.x*v1.y;
    dprod=v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
    printf("\nDot product=%d",dprod);
    printf("\nCross product=%di +%dj + %dk",cproduct.x,cproduct.y,cproduct.z);
    getch();
    return 0;
}
   
