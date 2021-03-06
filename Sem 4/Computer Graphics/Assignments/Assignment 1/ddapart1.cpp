
#include<iostream>
using namespace std;
#include<GL/glut.h>




void myInit(void)
{
	glClearColor(0,0,0,0);                 //sets background color to black
	glColor3f(1,1,1);                      //sets drawing color to white
	glPointSize(5);                        //sets point size to 5 by 5 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-600,600,-600,600);
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


void plot(float x, float y)         //function to plot point
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}



void  display()                     //function to plot axes
{
  int i;

  for(i=-1200;i<=1200;i+=2)
   {
     plot(i,0);
     plot(0,i);

   }

}

void ddaln(float x1,float y1,float x2,float y2)          //function to draw simple line using dda
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


void ddalndsh(float x1,float y1,float x2,float y2)      //function to draw dash line using dda
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

      if(i%9>4)
      plot(x,y);


   }

}


void ddalndot(float x1,float y1,float x2,float y2)          //function to draw dotted line using dda
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

       if(i%9==0)
       plot(x,y);
   }

}


void menu(int item)                   //function to choose type of line
{
	float x1,x2,y1,y2;

	if(item==1)
	{

      cout<<"\nEnter coordinates of starting point:";
      cin>>x1>>y1;

     do
     {
      cout<<"\nEnter coordinates of end point:";
      cin>>x2>>y2;
     }

     while(x2==x1 && y2==y1);

     glClear(GL_COLOR_BUFFER_BIT);       //clears the screen
     display();
     ddaln(x1,y1,x2,y2);
     glFlush();

	}

	if(item==2)
	{

      cout<<"\nEnter coordinates of starting point:";
      cin>>x1>>y1;

     do
     {
      cout<<"\nEnter coordinates of end point:";
      cin>>x2>>y2;
     }

     while(x2==x1 && y2==y1);

     glClear(GL_COLOR_BUFFER_BIT);       //clears the screen
     display();
     ddalndsh(x1,y1,x2,y2);
     glFlush();

	}

	if(item==3)
	{

      cout<<"\nEnter coordinates of starting point:";
      cin>>x1>>y1;

     do
     {
      cout<<"\nEnter coordinates of end point:";
      cin>>x2>>y2;
     }

     while(x2==x1 && y2==y1);

     glClear(GL_COLOR_BUFFER_BIT);         //clears the screen
     display();
     ddalndot(x1,y1,x2,y2);
     glFlush();

	}

	if(item==4)
	{
		exit(0);
	}
}


int main(int argc,char **argv)
{
	glutInit(&argc, argv);                     //initializes the toolkit
	glutInitDisplayMode(GLUT_RGB);            //sets display mode
	glutInitWindowSize(600,600);              //sets the window size
	glutInitWindowPosition(100,150);          //sets the window position on the screen
	glutCreateWindow("Menu");                //creates window with atitle
	myInit();

    glutDisplayFunc(display);               //registers the draw function
	glutCreateMenu(menu);                   //creates menu
	glutAddMenuEntry("Simple Line",1);      //add menu
	glutAddMenuEntry("Dashed Line",2);
	glutAddMenuEntry("Dotted Line",3);
	glutAddMenuEntry("EXIT",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);      //attach right mouse button to menu
	glutMainLoop();
}


