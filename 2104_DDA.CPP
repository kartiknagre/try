#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
class lyn
{
private:
int x1,y1,x2,y2;
public:
void drawdda(float,float,float,float);
void drawbrs(int,int,int,int);
int sign(int);
};
void lyn::drawdda(float x1,float y1,float x2,float y2)
{
int dx,dy,len,a,b,x,y,i=0;
float maxx,maxy;
maxx=getmaxx();
maxy=getmaxy();
/*cout<<"Enter coordinates of starting vertex:";
cin>>x1>>y1;
cout<<"Enter coordinates of ending point vertex:";
cin>>x2>>y2;*/
x1=x1+maxx/2;
x2=x2+maxx/2;
y1=maxy/2-y1;
y2=maxy/2-y2;
cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
a=abs(x2-x1);
b=abs(y2-y1);

if(a>b)
	len=a;
else
	len=b;

dx=((x2-x1)/len);
dy=((y2-y1)/len);

x=x1+0.5;
y=y1+0.5;

while(i<=len)
{
	putpixel(int(x),int(y),3);
	x=x+dx;
	y=y+dy;
	i++;
}
}
int lyn::sign(int x)
{
if(x<0)
	return -1;
else
return 1;
}
void lyn::drawbrs(int x1,int y1,int x2,int y2)
{
int x,y,dx,dy,s1,s2,temp,interchange,e,i;
/*cout<<"Enter coordinates of starting vertex:";
cin>>x1>>y1;
cout<<"Enter coordinates of ending point vertex:";
cin>>x2>>y2;  */
x=x1;
y=y1;
dx=abs(x2-x1);
dy=abs(y2-y1);
s1=sign(x2-x1);
s2=sign(y2-y1);

if(dy>dx)
{
temp=dx;
dx=dy;
dy=temp;
interchange=1;
}
else
 interchange=0;

e=2*dy-dx;

for(i=1;i<=dx;i++)
{
putpixel(x,y,2);
while(e>=0)
{
if(interchange==1)
	x=x+s1;
else
	y=y+s2;
e=e-2*dx;
}
if(interchange==1)
	y=y+s2;
else
	x=x+s1;
e=e+2*dy;
}
}
int main()
{
int gd=DETECT,gmode;
initgraph(&gd,&gmode,"C:\\tc\\bgi");
lyn l;
l.drawdda(0,0,100,100);
//l.drawbrs(120,80,120,120);
//l.drawdda(80,80,80,120);
//l.drawbrs(80,120,120,120);
getch();
return 0;
}


