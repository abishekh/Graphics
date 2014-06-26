#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
typedef float Matrix3x3[3][3];
Matrix3x3 thematrix;

struct points
{
	float x;
	float y;
};
struct points p[3]={50,50,150,50,100,150};
void matrixidentity(Matrix3x3 m)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m[i][j]=(i==j);
}
void matrixmultiply(Matrix3x3 a, Matrix3x3 b)
{
	int r,c;
	Matrix3x3 tmp;
	for(r=0;r<3;r++)
		for(c=0;c<3;c++)
			tmp[r][c]=a[r][0]*b[0][c]+a[r][1]*b[1][c]+a[r][2]*b[2][c];
		for(r=0;r<3;r++)
			for(c=0;c<3;c++)
				 b[r][c]=tmp[r][c];
}
void translate2(int tx,int ty)
{
	Matrix3x3 m;
	matrixidentity(m);
	m[0][2]=tx;
	m[1][2]=ty;
	matrixmultiply(m,thematrix);
}
void reflection2(int x)
{
	Matrix3x3 m;
	matrixidentity(m);
	switch(x)
	{
		case 0: m[1][2]=-1;
			break;
		case 1:m[0][0]=1;
			break;
	}
	matrixmultiply(m,thematrix);
}
void scale2(float sx,float sy,struct points pt)
{
	Matrix3x3 m;
	matrixidentity(m);
	m[0][0]=sx;
	m[0][2]=(1-sx)*pt.x;
	m[1][1]=sy;
	m[1][2]=(1-sy)*pt.y;
	matrixmultiply(m,thematrix);
}
void rotate2(float a,struct points pt)
{
	Matrix3x3 m;
	matrixidentity(m);
	m[0][0]=cos(a);
	m[0][1]=-sin(a);
	m[0][2]=pt.x*(1-cos(a))+pt.y*sin(a);
	m[1][0]=sin(a);
	m[1][1]=cos(a);
	m[1][2]=pt.y*(1-cos(a))-pt.x*sin(a);
	matrixmultiply(m,thematrix);
};
void transformp(int np)
{
	int k;
	float tmp;
	for(k=0;k<np;k++)
	{
		tmp=thematrix[0][0]*p[k].x +thematrix[0][1]*p[k].y+thematrix[0][2];
		p[k].y=thematrix[1][0]*p[k].x+thematrix[1][1]*p[k].y+thematrix[1][2];
		p[k].x=tmp;
	}
}
void display()
{
	int i;
	for(i=0;i<3;i++)
		printf("x=%f,y=%f\n",p[i].x,p[i].y);
}
void main()
{
	int n,i,tx,ty,an,sx,sy;
	int sw;
	struct points refpt={100,100};
	clrscr();

	matrixidentity(thematrix);
	printf("\n\t\tTransformations");
	printf("\n\t1.Translation");
	printf("\n\t2.Rotation");
	printf("\n\t3.Scaling");
	printf("\nSpecify the transformations ");
	scanf("%d",&sw);
        	printf("\n\nBefore transformation ");
	display();
	
	switch(sw)
	{
		case 1:	printf("\n\nEnter the transformations value tx,ty ");
			scanf("%d%d",&tx,&ty);
			translate2(tx,ty);
			break;
		case 2: printf("\n\nEnter the rotation angle ");
                	scanf("%d",&an);
			rotate2(an,refpt);
                	break;
		case 3: printf("\n\nEnter the scaling value sx,sy");
                	scanf("%d%d",&sx,&sy);
			scale2(sx,sy,refpt);
			break;

                default:printf("Wrong input ");
	}

	transformp(3);
	printf("\n\nAfter Transformations ");
	display();
	getch();
}