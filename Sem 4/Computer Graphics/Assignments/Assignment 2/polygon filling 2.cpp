

#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define w 640
#define h 480
using namespace std;

float interiorcolor[3]={1,1,1};
float fillcolor[3]={0,0,0};
float readpixel[3];
int xi,y2;

void myInit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

int sign(int n)
{
	if(n<0)
	return -1;

	if(n>0)
	return 1;

	else
	return 0;
}

void plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();

}

void setpixel(int x,int y)
{
    glColor3fv(fillcolor);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();


}

void getpixel(int x,int y,float *color)
{
  glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}

void floodfill(int x,int y)
{
   getpixel(x,y,readpixel);
   if(readpixel[0]==interiorcolor[0] && readpixel[1]==interiorcolor[1] && readpixel[2]==interiorcolor[2])
    {
      setpixel(x,y);
      floodfill(x+1,y);
      floodfill(x,y+1);
      floodfill(x-1,y);
      floodfill(x,y-1);
      glEnd();
      glFlush();
    }
}

void mouse(int btn,int state,int x,int y)
{
  if((btn==GLUT_LEFT) && (state==GLUT_DOWN))
  {
     xi=x;
     y2=480-y;
     floodfill(xi,y2);
  }
}

void line(float x1,float y1,float x2,float y2)   //line drawing algorithm
{

	float x,y,Dx,Dy,e,temp;
	int s1,s2,interchange,i;
	x=x1;
	y=y1;

	Dx=abs(x2-x1);
	Dy=abs(y2-y1);
	s1=sign(x2-x1);
	s2=sign(y2-y1);

	if(Dy>Dx)
	{
		temp=Dx;
		Dx=Dy;
		Dy=temp;
		interchange=1;
	}

	else
	interchange=0;

	e=2*Dy-Dx;

	for(i=1;i<=Dx;i++)
	{
		plot(x,y);

		while(e>=0)
		{
			if(interchange==1)
			x=x+s1;

			else
			{
				y=y+s2;
			}

			e=e-2*Dx;
		}

		if(interchange==1)
		y=y+s2;

		else
		{
			x=x+s1;
		}

		e=e+2*Dy;
	}
}

void rotation(int x1,int y1,int x2,int y2)
{
	float angle;
	int x3,y3,x4,y4;
	angle=(3.14*45)/180;

	x3=x1*cos(angle)+y1*sin(-angle);
	y3=x1*sin(angle)+y1*cos(angle);
	x4=x2*cos(angle)+y2*sin(-angle);
	y4=x2*sin(angle)+y2*cos(angle);
      glColor3f(0.0,1.0,0.0);
      line(x3,y3,x4,y4);
}

void myDisplay()
{

	glColor3f(1.0,0.0,0.0);
	line(300,100,402,100);
	line(400,100,400,200);
	line(400,200,300,200);
	line(300,200,300,100);
	line(325,100,325,200);
	line(350,100,350,200);
    line(375,100,375,200);
	line(400,100,400,200);
	line(300,125,400,125);
	line(300,150,400,150);
	line(300,175,400,175);
	line(300,200,400,200);

	rotation(300,100,402,100);
	rotation(400,100,400,200);
	rotation(400,200,300,200);
	rotation(300,200,300,100);
	rotation(325,100,325,200);
	rotation(350,100,350,200);
	rotation(375,100,375,200);
	rotation(400,100,400,200);
	rotation(300,125,400,125);
	rotation(300,150,400,150);
	rotation(300,175,400,175);
	rotation(300,200,400,200);

	glEnd();
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640.0,480.0);
	glutInitWindowPosition(100.0,50.0);
	glutCreateWindow("Chess");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(mouse);
	myInit();
	glutMainLoop();
}
