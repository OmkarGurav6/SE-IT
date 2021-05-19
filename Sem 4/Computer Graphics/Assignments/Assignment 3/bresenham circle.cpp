
#include<iostream>
#include<GL/glut.h>

using namespace std;

void myInit(void)
{
	glClearColor(1,1,1,1);                  //sets background color to white
	glColor3f(0,0,0);                       //sets drawing color to black
	glPointSize(5);                         //sets point size to 5 by 5 pixels
	glMatrixMode(GL_PROJECTION);            //specify which matrix is current matrix and sets mode
	glLoadIdentity();                       // replace the current matrix with the identity matrix
	gluOrtho2D(-600,600,-600,600);
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

  glColor3f(1,0.5,0);
  for(i=-1200;i<=1200;i+=2)
   {
     plot(i,0);
     plot(0,i);

   }

}

void simplecircle(float r,int h,int k)           //function to draw simple circle
{
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


void olympic(float r,int h,int k)                   //function to draw olympic ring
{
	int i;

	float x;

	for(i=0;i<3;i++)
	{
	    if(i==0)
	      glColor3f(0,0,1);
        if(i==1)
	      glColor3f(0,0,0);
        if(i==2)
	      glColor3f(1,0,0);

		simplecircle(r,h,k);
		x=1.5*r;
		h=h+x;
	}

	h=h-(1.5*x);
	k=k-x;

	for(i=0;i<2;i++)
	{
	    if(i==0)
	      glColor3f(0,1,0);
        if(i==1)
	      glColor3f(1,1,0);
		simplecircle(r,h,k);
		x=1.5*r;
		h=h-x;
	}
}


void concentric(float r,int h,int k)                  //function to draw cocentric circles
{
	int n;
	cout<<"\nEnter the number of circles:";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		simplecircle(r,h,k);
		r=r+25;
	}

}


void spiral(int h,int k)                              //function to draw spiral
{
	int x,y,r,d;

	plot(h,k);

	for(r=0;r<=200;r+=25)
	{
		x=0;
		y=r;
		d=3-(2*r);

		while(x<=y)
		{
			if(d<=0)
			{
				d=d+(4*x)+6;
			}
			else
			{
				d=d+ 4*(x-y) +10;
				y--;
			}
			x++;

			if(r%10==0)
			{
				plot(x+h,y+k);
				plot(y+h,x+k);
				plot(-y+h,x+k);
				plot(-x+h,y+k);
			}
			else
			{
				h+=25;
				plot(-x+h,-y+k);
				plot(-y+h,-x+k);
				plot(y+h,-x+k);
				plot(x+h,-y+k);
				h-=25;
			}
		}
	}
}


void menu(int item)                                      //function to choose option
{
	int h,k;
	float r;

	if(item==1)
	{
	    do
        {
            cout<<"\nEnter the radius: ";
		    cin>>r;
        }
		while(r<=0);

		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
		glClear(GL_COLOR_BUFFER_BIT);                          //clears the screen
        display();
        glColor3f(0,0,0);
		simplecircle(r,h,k);
        glFlush();
	}


	if(item==2)
	{
		 do
        {
            cout<<"\nEnter the radius: ";
		    cin>>r;
        }
		while(r<=0);

		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
        glClear(GL_COLOR_BUFFER_BIT);                          //clears the screen
        display();
		olympic(r,h,k);
        glFlush();
	}


	if(item==3)
	{
		 do
        {
            cout<<"\nEnter the radius: ";
		    cin>>r;
        }
		while(r<=0);

		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
		glClear(GL_COLOR_BUFFER_BIT);                          //clears the screen
        display();
        glColor3f(0,0,0);
		concentric(r,h,k);
		glFlush();
	}


	if(item==4)
	{
		cout<<"\nEnter the co-ordinates of the center: ";
		cin>>h>>k;
		glClear(GL_COLOR_BUFFER_BIT);                          //clears the screen
        display();
        glColor3f(0,0,0);
		spiral(h,k);
		glFlush();
	}

	if(item==5)
	{
		exit(0);
	}
}


int main(int argc,char** argv)
{

    glutInit(&argc, argv);                                        //initializes the toolkit
	glutInitDisplayMode(GLUT_RGB);                                //sets display mode
	glutInitWindowSize(600,600);                                   //sets the window size
	glutInitWindowPosition(100,150);                              //sets the window position on the screen
	glutCreateWindow("Bresenham Circle");                           //creates window with a title
	myInit();


	glutDisplayFunc(display);                                   //registers the display function
	glutCreateMenu(menu);                                      //creates menu
	glutAddMenuEntry("Simple Circle",1);                         //add menu
    glutAddMenuEntry("Olympic Rings",2);
    glutAddMenuEntry("Concentric Circles",3);
    glutAddMenuEntry("Spiral",4);
    glutAddMenuEntry("Exit",5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);                        //attach right mouse button to menu
	glutMainLoop();

	return 0;

}
