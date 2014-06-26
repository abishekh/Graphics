#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define LEFT 1
#define RIGHT 2
#define TOP 8
#define BOTTOM 4
#define inside(a) (!a)
#define reject(a,b) (a&b)
#define accept(a,b) (!(a|b))
int gm=DETECT,gd;
int maxx,maxy;
struct points
{
	int x;
	int y;
}p1,p2;
int xmin,xmax,ymin,ymax;
int cancel=0;
int sign(int m)
{
	return((m<0)?-1:(m>0)?1:0);
}
void dline(int xa,int ya,int xb,int yb,int col)
{
	int dx,dy,x,y,xe,dy2,dydx,p,sx,sy,temp;
	int e=0;
	int i=0;
	dx=abs(xb-xa);dy=abs(yb-ya);
	sx=sign(xb-xa);
	sy=sign(yb-ya);
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		e=1;
	}
	dy2=2*dy;dydx=2*(dy-dx);
	p=dy2-dx;
	x=xa;y=ya;
	putpixel(x,y,col);
	while(i<=dx)
	{
		i++;
		if(e==1)
			y+=sy;
		else
			x+=sx;
		if(p<0)
		{
			p+=dy2;
		}
		else
		{
			if(e==1)
				x+=sx;
			else
				y+=sy;
			p+=dydx;
		}
		putpixel(x,y,col);
	}

}
void drectangle()
{
	dline(xmin,maxy-ymin,xmin,maxy-ymax,10);
	dline(xmin,maxy-ymin,xmax,maxy-ymin,10);
	dline(xmin,maxy-ymax,xmax,maxy-ymax,10);
	dline(xmax,maxy-ymin,xmax,maxy-ymax,10);
}
int encode(struct points pt)
{
	int code=0;
	if(pt.x<xmin)
		code=code|LEFT;
	if(pt.x>xmax)
		code=code|RIGHT;
	if(pt.y<ymin)
		code=code|BOTTOM;
	if(pt.y>ymax)
		code=code|TOP;
	return(code);
}
void swappts(struct points *p1,struct points *p2)
{
	struct points tmp;
	tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}
void swapcodes(int *c1,int *c2)
{
	int tmp;
	tmp=*c1;
	*c1=*c2;
	*c2=tmp;
}
void clipline()
{
	int code1,code2;
	int done=0,draw=0;
	float m;
	while(!done)
	{
		code1=encode(p1);
		code2=encode(p2);
		if(accept(code1,code2))
		{
			done=1;
			draw=1;
		}
		else
			if(reject(code1,code2))
				done=1;
			else
			{
				if(inside(code1))
				{
					swappts(&p1,&p2);
					swapcodes(&code1,&code2);
				}
				if(p2.x!=p1.x)
					m=(p2.y-p1.y)/(p2.x-p1.x);
				if(code1 & LEFT)
				{
					p1.y+=(xmin-p1.x)*m;
					p1.x=xmin;
				}
				else if(code1 & RIGHT)
				{
					p1.y+=(xmax-p1.x)*m;
					p1.x=xmax;
				}
				else if(code1 &BOTTOM)
				{
					if(p2.x !=p1.x)
						p1.x+=(ymin-p1.y)/m;
					p1.y=ymin;
				}
				else if(code1 & TOP)
				{
					if(p2.x != p1.x)
						p1.x+=(ymax-p1.y)/m;
					p1.y=ymax;
				}
			
		}
	}
	if(!draw)
       	   cancel=1;
}
void main()
{
	clrscr();
	printf("Enter the cordinates of line (x1,y1) & (x2,y2)");
        scanf("%d%d%d%d",&p1.x,&p1.y,&p2.x,&p2.y);
	clrscr();
        initgraph(&gm,&gd,"x:\\tc");
	setbkcolor(BLACK);
	maxx=getmaxx();
	maxy=getmaxy();
	xmin=125;
	xmax=450;
	ymax=450;
	ymin=125;
	cleardevice();
	printf("\t\t\t\tBEFORE CLIPPING");
	rectangle(xmin,maxy-ymin,xmax,maxy-ymax);
	line(p1.x,maxy-p1.y,p2.x,maxy-p2.y);
	getch();
	clrscr();
	cleardevice();
	printf("\t\t\t\tAFTER CLIPPING");
	clipline();
	rectangle(xmin,maxy-ymin,xmax,maxy-ymax);
	if(!cancel)
		line(p1.x,maxy-p1.y,p2.x,maxy-p2.y);
	getch();
}