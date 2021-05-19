

#include<iostream>
#include<math.h>
#include<GL/glut.h>

using namespace std;

int k=0;
float a[32][2];


void myInit(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320,320,-240,240);
     glClear(GL_COLOR_BUFFER_BIT);

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
	glFlush();
}



void  display()
{
  int i;

  for(i=-640;i<=640;i+=2)
   {
     plot(i,0);
     plot(0,i);

   }

}


void ddaln(float x1,float y1,float x2,float y2)
{
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



void mymouse(GLint button,GLint state,GLint x,GLint y)
{

     if(state==GLUT_DOWN)
       {
           if(button==GLUT_LEFT_BUTTON)
 	      {

		    a[k][0]=(float)(x-320);
 		    a[k][1]=(float)(240-y);
  		    glBegin(GL_POINTS);

		    glVertex2f(a[k][0],a[k][1]);
		    cout<<"Points are:("<<a[k][0]<<a[k][1]<<")"<<endl;

		    glEnd();

		    k++;

	       glFlush();

	      }

	      if(button==GLUT_RIGHT_BUTTON)
	      {

		     for(int i=0;i<k-1;i++)
            {
               ddaln(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
            }

             ddaln(a[k-1][0],a[k-1][1],a[0][0],a[0][1]);

	        k=0;

            glFlush();
		}
	}
}



void menu(GLint option)
{
    switch(option)
    {
      case 1:

      display();
      glColor3f(0.0,1.0,0.0);
      glutMouseFunc(mymouse);

      break;


      case 2:

       display();
      glColor3f(0.0,0.0,1.0);
      glutMouseFunc(mymouse);

      break;


      case 3:

       display();
      glColor3f(1.0,0.0,0.0);
      glutMouseFunc(mymouse);

      break;

    }

  glFlush();

}

void display1()
{


}

int main(int argc,char **argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(640,480);
     glutCreateWindow("POLYGON");
      myInit();

     glutDisplayFunc(display1);
     glutCreateMenu(menu);
     glutAddMenuEntry("green",1);
     glutAddMenuEntry("blue",2);
     glutAddMenuEntry("red",3);
     glutAttachMenu(GLUT_MIDDLE_BUTTON);
     glutMainLoop();

  return 0;
}
