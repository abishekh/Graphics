
#include<stdio.h>
#include<graphics.h>
void clip_left();
void clip_right();
void clip_bottom();
void clip_top();
int n,p,x,y,i,j;
char flag;
float dx,dy;
int xmin,xmax,ymin,ymax;
int x1,y1,x2,y2,maxx,maxy;
float m;
int a[10][10],b[10][10],c[10][10],d[10][10],e[10][10];

void main()
{
	int gm=DETECT,gd;

	initgraph(&gm,&gd,"c:\\tc");
	maxx=getmaxx();
	maxy=getmaxy();
	printf("Enter the number of edges of polygon ");
	scanf("%d",&n);
	printf("Enter the cordinates ");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[i][0],&a[i][1]);

	}
	a[n][0]=a[0][0];
	a[n][1]=a[0][1];
	xmin=100;
	ymin=100;
	xmax=400;
	ymax=400;
	cleardevice();
	outtextxy(250,10,"Before Clipping");
	rectangle(xmin,maxy-ymin,xmax,maxy-ymax);
	for(i=0;i<n;i++)
		line(a[i][0],maxy-a[i][1],a[i+1][0],maxy-a[i+1][1]);
	getch();
	cleardevice();
       	clip_left();
	clip_right();
       	clip_bottom();
	clip_top();
}

void clip_left()
{
	p=0,m=0,flag=0;
	for(i=0;i<n;i++)
        {
		dy=a[i+1][1]-a[i][1];
		dx=a[i+1][0]-a[i][0];
		if((dx!=0)&&(dy!=0))
			m=dy/dx;
		if((a[i][0]<xmin)&&(a[i+1][0]>=xmin))
			flag=0; //out to in
		if((a[i][0]>=xmin)&&(a[i+1][0]>=xmin))
			flag=1; //line is inside
		if((a[i][0]>=xmin)&&(a[i+1][0]<xmin))
			flag=2; //line in to out
		if((a[i][0]<xmin)&&(a[i+1][0]<xmin))
			flag=3; //line outside
               	switch(flag)
		{
			case 0:
				x=xmin;
				if(dy!=0)
					y=(int)(a[i][1]+m*(x-a[i][0]));
				else
					y=a[i][1];
				b[p][0]=x;
				b[p][1]=y;
				p++;
				b[p][0]=a[i+1][0];
				b[p][1]=a[i+1][1];
				p++;
				break;
			case 1:
				b[p][0]=a[i+1][0];
				b[p][1]=a[i+1][1];
				p++;
				break;
			case 2:
				x=xmin;
				if(dy!=0)
					y=(int)(a[i][1]+m*(x-a[i][0]));
				else
					y=a[i][1];
				b[p][0]=x;
				b[p][1]=y;
				p++;
		}
	}
	b[p][0]=b[0][0];
	b[p][1]=b[0][1];
	cleardevice();
	outtextxy(250,10,"LEFT Clipping");
	rectangle(xmin,maxy-ymin,xmax,maxy-ymax);
	for(i=0;i<p;i++)
	{
		line(b[i][0],maxy-b[i][1],b[i+1][0],maxy-b[i+1][1]);
	}
	getch();
}
void clip_right()
{
	n=p;
	m=0;
	p=0;  flag=0;
	for(i=0;i<n;i++)
	{
		
		dy=b[i+1][1]-b[i][1];
		dx=b[i+1][0]-b[i][0];
		if((dx!=0)&&(dy!=0))
			m=dy/dx;
		if((b[i][0]>xmax)&&(b[i+1][0]<=xmax))
			flag=0; //out to in
		if((b[i][0]<=xmax)&&(b[i+1][0]<=xmax))
			flag=1; //line is inside
		if((b[i][0]<=xmax)&&(b[i+1][0]>xmax))
			flag=2; //line in to out
		if((b[i][0]>xmax)&&(b[i+1][0]>xmax))
			flag=3; //line outside
		
		switch(flag)
		{
			case 0:
				x=xmax;
				if(dy!=0)
					y=(int)(b[i][1]+m*(x-b[i][0]));
				else
					y=b[i][1];
				c[p][0]=x;
				c[p][1]=y;
				p++;
				c[p][0]=b[i+1][0];
				c[p][1]=b[i+1][1];
				p++;
				break;
			case 1:
				c[p][0]=b[i+1][0];
				c[p][1]=b[i+1][1];
				p++;
				break;
			case 2:
				x=xmax;
				if(dy!=0)
					y=(int)(b[i][1]+m*(x-b[i][0]));
				else
					y=b[i][1];
				c[p][0]=x;
				c[p][1]=y;
				p++;
		}
	}
	c[p][0]=c[0][0];
	c[p][1]=c[0][1];

	cleardevice();
        outtextxy(250,10,"RIGHT Clipping");
        rectangle(xmin,maxy-ymin,xmax,maxy-ymax);
	for(i=0;i<p;i++)
	{
		line(c[i][0],maxy-c[i][1],c[i+1][0],maxy-c[i+1][1]);
	}
        getch();
}
void clip_bottom()
{
	n=p;
	m=0;
	p=0;  flag=0;
	for(i=0;i<n;i++)
	{
		dy=c[i+1][1]-c[i][1];
		dx=c[i+1][0]-c[i][0];
		if((dx!=0)&&(dy!=0))
			m=dy/dx;
		if((c[i][1]<ymin)&&(c[i+1][1]>=ymin))
			flag=0; //out to in
		if((c[i][1]>=ymin)&&(c[i+1][1]>=ymin))
			flag=1; //line is inside
		if((c[i][1]>=ymin)&&(c[i+1][1]<ymin))
			flag=2; //line in to out
		if((c[i][1]<ymin)&&(c[i+1][1]<ymin))
			flag=3; //line outside
		
		switch(flag)
		{
			case 0:
				y=ymin;
				if(dx!=0)
					x=abs((int)(c[i][0]+(1/m)*(y-c[i][1])));
				else
					x=c[i][0];
				d[p][0]=x;
				d[p][1]=y;
				p++;
				d[p][0]=c[i+1][0];
				d[p][1]=c[i+1][1];
				p++;
				break;
			case 1:
				d[p][0]=c[i+1][0];
				d[p][1]=c[i+1][1];
				p++;
				break;
			case 2:
				y=ymin;
				if(dx!=0)
					x=abs((int)(c[i][0]+(1/m)*(y-c[i][1])));
				else
					x=c[i][0];
				d[p][0]=x;
				d[p][1]=y;
				p++;
		}
	}
	d[p][0]=d[0][0];
	d[p][1]=d[0][1];
	cleardevice();
	outtextxy(250,10,"BOTTOM Clipping");
        rectangle(xmin,maxy-ymin,xmax,maxy-ymax);
	for(i=0;i<p;i++)
	{
		line(d[i][0],maxy-d[i][1],d[i+1][0],maxy-d[i+1][1]);
	}
        getch();
}
void clip_top()
{
	n=p;
	m=0;
	p=0;  flag=0;
	for(i=0;i<n;i++)
	{
		dy=d[i+1][1]-d[i][1];
		dx=d[i+1][0]-d[i][0];
		if((dx!=0)&&(dy!=0))
			m=dy/dx;
		if((d[i][1]>ymax)&&(d[i+1][1]<=ymax))
			flag=0; //out to in
		if((d[i][1]<=ymax)&&(d[i+1][1]<=ymax))
			flag=1; //line is inside
		if((d[i][1]<=ymax)&&(d[i+1][1]>ymax))
			flag=2; //line in to out
		if((d[i][1]>ymax)&&(d[i+1][1]>ymax))
			flag=3; //line outside
		
		switch(flag)
		{
			case 0:
				y=ymax;
				if(dx!=0)
					x=abs((int)(d[i][0]+(1/m)*(y-d[i][1])));
				else
					x=d[i][0];
				e[p][0]=x;
				e[p][1]=y;
				p++;
				e[p][0]=d[i+1][0];
				e[p][1]=d[i+1][1];
				p++;
				break;
			case 1:
				e[p][0]=d[i+1][0];
				e[p][1]=d[i+1][1];
				p++;
				break;
			case 2:
				y=ymax;
				if(dx!=0)
					x=abs((int)(d[i][0]+(1/m)*(y-d[i][1])));
				else
					x=d[i][0];
				e[p][0]=x;
				e[p][1]=y;
				p++;
		}
	}
	e[p][0]=e[0][0];
	e[p][1]=e[0][1];
	cleardevice();
	outtextxy(250,10,"TOP Clipping");
        rectangle(xmin,maxy-ymin,xmax,maxy-ymax);
	for(i=0;i<p;i++)
	{
		line(e[i][0],maxy-e[i][1],e[i+1][0],maxy-e[i+1][1]);
	}
        getch();
}

	