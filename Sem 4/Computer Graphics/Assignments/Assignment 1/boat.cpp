
#include<iostream>
using namespace std;
#include<GL/glut.h>

float x1,y1,x2,y2;


void myInit(void)
{
	glClearColor(1,1,1,0);                    //sets background color to white
	glColor3f(0,0,0);                         //sets drawing color to black
	glPointSize(5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1200,1200,-1200,1200);
}


int sign(int i)
{
	if(i>0)
	{
		return 1;
	}
	else if(i==0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}


void plot(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}



void  display()
{
  int i;

  glColor3f(0,1,0);                        //sets drawing color to green
  for(i=-1200;i<=1200;i+=2)
   {
     plot(i,0);
     plot(0,i);

   }

}

void ddaln(float x1,float y1,float x2,float y2)
{
   glColor3f(1,0,0);                            //sets drawing color to red
   float dx,dy,length,x,y;
   int i;

   dx=abs(x2-x1);
   dy=abs(y2-y1);

   if(dx>=dy)
   {
       length=dx;
   }
   else
    length=dy;

   dx=(x2-x1)/length;
   dy=(y2-y1)/length;

   x=x1+(0.5*sign(dx));
   y=y1+(0.5*sign(dy));

   plot(x,y);

   for(i=0;i<length;i++)
   {
       x=x+dx;
       y=y+dy;

       plot(x,y);
   }

}


void display1()
{
   glClear(GL_COLOR_BUFFER_BIT);

    display();

   ddaln(600,400,1000,400);
   ddaln(1000,400,1200,600);
   ddaln(1200,600,1100,600);
   ddaln(1100,600,1100,800);
   ddaln(1100,800,700,600);
   ddaln(700,600,400,600);
   ddaln(400,600,600,400);
   ddaln(1100,600,700,600);

   glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Boat");
	myInit();

    glutDisplayFunc(display1);
	glutMainLoop();
}
