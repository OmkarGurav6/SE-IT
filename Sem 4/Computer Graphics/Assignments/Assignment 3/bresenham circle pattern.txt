
#include<iostream>
#include<GL/glut.h>

using namespace std;

int h,k;
float r;

void myInit(void)
{
	glClearColor(1,1,1,1);                  //sets background color to white
	glColor3f(0,0,0);                       //sets drawing color to black
	glPointSize(5);                         //sets point size to 5 by 5 pixels
	glMatrixMode(GL_PROJECTION);            //specify which matrix is current matrix and sets mode
	glLoadIdentity();                       // replace the current matrix with the identity matrix
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

void plot(int x,int y)                //function to plot integer value point
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}


void  display()                                //function to plot axes
{
  int i;
  glColor3f(0,0,1);
  for(i=-1200;i<=1200;i+=2)
   {
     plot(i,0);
     plot(0,i);

   }

}



void ddaln(float x1,float y1,float x2,float y2)        //function to draw line
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


void simplecircle(float r,int h,int k)           //function to draw simple circle
{
     glColor3f(0,1,0);
	float d=3-(2*r);
	int x=0,y=r;

	plot(h,k);

	while(x<=y)
	{
		if(d<=0)
		{
			d=d+(4*x)+6;
		}
		else
		{
			d=d+(4*(x-y))+10;
			y=y-1;
		}
         x=x+1;

		plot(x+h,y+k);
		plot(y+h,x+k);
		plot(-y+h,x+k);
		plot(-x+h,y+k);
		plot(-x+h,-y+k);
		plot(-y+h,-x+k);
		plot(y+h,-x+k);
		plot(x+h,-y+k);
	}
}


void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);

    display();

    simplecircle(r,h,k);
	ddaln(h,k+r,h-(0.866*r),k-(r*0.5));
	ddaln(h-(0.866*r),k-(r*0.5),h+(0.866*r),k-(r*0.5));
	ddaln(h+(0.866*r),k-(r*0.5),h,k+r);

	simplecircle(r/2,h,k);


}

int main(int argc,char** argv)
{

    glutInit(&argc, argv);                                        //initializes the toolkit
	glutInitDisplayMode(GLUT_RGB);                                //sets display mode
	glutInitWindowSize(600,600);                                   //sets the window size
	glutInitWindowPosition(100,150);                              //sets the window position on the screen
	glutCreateWindow("Bresenham Pattern");                           //creates window with a title
	myInit();

     do
        {
            cout<<"\nEnter the radius: ";
		    cin>>r;
        }
		while(r<=0);

		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
	glutDisplayFunc(display1);                                   //registers the display function
	glutMainLoop();

	return 0;

}
