
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#define round(a) ((int) (a+.5))
int gm = DETECT,gd;
int gx,gy;
int xa,xb,ya,yb,dx,dy,x,y,xe,dy2,dydx,p;
void main()
{
	clrscr();
	printf("Enter the values of xa,xb,ya,yb ");
	scanf("%d",&xa);
	scanf("%d",&xb);
	scanf("%d",&ya);
	scanf("%d",&yb);
	dx=abs(xb-xa);dy=abs(yb-ya);
	dy2=2*dy;dydx=2*(dy-dx);
	if(xa>xb)
	{
		x=xb;
		y=yb;
		xe=xa;
	}
	else
	{
	x=xa;
	y=ya;
	xe=xb;
	}
	initgraph(&gm,&gd,"c:\\tc");
	setbkcolor(BLACK);
        gx=getmaxy();
	putpixel(x,gx-y,5);
	while(x<xe)
	{
		x++;
		if(p<0)
			p+=dy2;
		else
		{
			y++;
			p+=dydx;
		}
		putpixel(x,gx-y,5);
	}
	getch();
	closegraph();
}
	