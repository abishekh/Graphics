#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#define Round(a) ((int)(a+0.5))
int gm=DETECT,gd;
struct points
{
	int x;
	int y;
}p1,p2;
struct win
{
	int x;
	int y;
}winMin,winMax;
float u1=0,u2=1;
int clipTest(float p, float q)
{
	float r;
	int retval=1;
	if(p<0.0)
	{
		r=q/p;
		if(r>u2)
			retval=0;
		else
			if(r>u1)
		u1=r;
	}
	else
		if(p>0.0)
		{
			r=q/p;
		if(r<u1)
			retval=0;
		else
		if(r<u2)
			u2=r;
		}
	else
	/* p=0, so line is prallel to this clipping edge*/
	if(q<0.0)
	/* Line is outside clipping edge*/
	retval=0;
	return(retval);
}
void clipline()
{
	
	float dx=p2.x-p1.x,dy;
	if(clipTest(-dx,p1.x-winMin.x))
	if(clipTest(dx,winMax.x-p1.x))
	{
		dy=p2.y-p1.y;
		if(clipTest(-dy,p1.y-winMin.y))
		if(clipTest(dy,winMax.y-p1.y))
		{
			if(u2<1.0)
			{
				p2.x=p1.x+u2*dx;
				p2.y=p1.y+u2*dy;
			}
			if(u1>0.0)
			{
				p1.x+=u1*dx;
				p1.y+=u1*dy;
			}
			line(Round(p1.x),Round(p1.y),Round(p2.x),Round(p2.y));
		}
	}
}
void main()
{
	int i;
	clrscr();
	initgraph(&gm,&gd,"c:\\tc");
	setbkcolor(BLACK);
	winMin.x=100;
	winMax.x=400;
	winMin.y=100;
	winMax.y=400;
	printf("Enter the cordinates of the line ");
	scanf("%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y);
	printf("Before Clipping ");
	rectangle(100,100,400,400);
	line(p1.x,p1.y,p2.x,p2.y);
	getch();
	cleardevice();
	printf("After Clipping ");
	rectangle(100,100,400,400);
	clipline();
	getch();
}
        