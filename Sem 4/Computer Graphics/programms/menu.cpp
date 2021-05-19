
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>

using namespace std;

 float x1,x2,y1,y2,dx,dy,x,y;
 void dda1();
  void dda12();

int sign(float i)
{
   if(i<0)
        return -1;
   else
   if(i>0)
    return 1;

    else
        return 0;

}

void menu(int option)
{
    if(option==1)
        glutDisplayFunc(dda1);

     if(option==2)
        glutDisplayFunc(dda12);


    if(option==3)
       exit(0);

}


void plot(float x,float y)
{
    glBegin(GL_POINTS);

    glVertex2f(x,y);

    glEnd();
    glFlush();
}

void dda1()          /*normal line*/
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

   for(i=0;i<+length;i++)
   {

       x=x+dx;
       y=y+dy;

        plot(x,y);
   }


}



void dda12()       /*dash line*/
{

   float dx,dy,length,x,y;
   int i,dash,space;

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

   for(i=0;i<+length;i++)
   {
       dash=0;

       while(dash<5)
       {
           x=x+dx;
           y=y+dy;

          plot(x,y);
          dash++;
       }

       space=0;

       while(space<=2)
       {
          x=x+dx;
          y=y+dy;

          space++;
       }

   }



}



void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glFlush();
}


void init()
{
    glClearColor(0,0,0,0);
    glColor3f(1,1,1);

    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0,640,0,480);
}


int main(int argc,char **argv)
{
  cout<<"\nEnter coordinates of starting point:";
  cin>>x1>>y1;

  do
  {
      cout<<"\nEnter coordinates of end point:";
      cin>>x2>>y2;
  }

  while(x2==x1 && y2==y1);


   glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB);

  glutInitWindowPosition(100,100);
  glutInitWindowSize(400,400);

  glutCreateWindow("dda");

  init();

   glutDisplayFunc(display1);

  glutCreateMenu(menu);
  glutAddMenuEntry("Normal line",1);
  glutAddMenuEntry("Dash line",2);
  glutAddMenuEntry("Exit",3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);




  glutMainLoop();
}
