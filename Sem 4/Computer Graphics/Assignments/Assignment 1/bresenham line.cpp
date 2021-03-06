
#include<GL/glut.h>
#include<iostream>

using namespace std;

void myInit(void)
{
	glClearColor(0,0,0,0);                  //sets background color to black
	glColor3f(1,1,1);                       //sets drawing color to white
	glPointSize(5);                         //sets point size to 5 by 5 pixels
	glMatrixMode(GL_PROJECTION);            //specify which matrix is current matrix and sets mode
	glLoadIdentity();                       // replace the current matrix with the identity matrix
	gluOrtho2D(-600,600,-600,600);
}


int sign(int i)                               //function to assign sign
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


void plot(int x,int y)                          //function to plot point
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}


void  display()                                //function to plot axes
{
  int i;

  for(i=-1200;i<=1200;i+=2)
   {
     plot(i,0);
     plot(0,i);

   }

}

void bresenhams_line(int x1,int y1,int x2,int y2)                 //function to draw simple line using bresenham
{
	int e,x,y,dx,dy,s1,s2,i,temp,interchange;

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
	{
		interchange=0;
	}

	e=2*dy-dx;
	plot(x,y);

	for(i=1;i<=dx;i++)
	{

		plot(x,y);
		while(e>=0)
		{
			if(interchange==1)
			{
				x=x+s1;
			}
			else
			{
				y=y+s2;
			}
		e=e-2*dx;
		}
	       if(interchange==1)
		{
			y=y+s2;
		}
		else
		{
			x=x+s1;
		}
		e=e+2*dy;
	}
}


void dashed(int x1,int y1,int x2,int y2)                         //function to draw dashed line using bresenham
{
	int e,x,y,dx,dy,s1,s2,i,temp,interchange;

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
	{
		interchange=0;
	}

	e=2*dy-dx;
	plot(x,y);

	for(i=1;i<=dx;i++)
	{
		if((i/10)%2==0)
		{
		 plot(x,y);
		}
		 while(e>=0)
		 {
			if(interchange==1)
			{
				x=x+s1;
			}
			else
			{
				y=y+s2;
			}
		 e=e-2*dx;
		 }
	        if(interchange==1)
		 {
			y=y+s2;
		 }
		 else
		 {
			x=x+s1;
		 }
		 e=e+2*dy;

	}


}

void dotted(int x1,int y1,int x2,int y2)                            //function to draw dotted line using bresenham
{
	int e,x,y,dx,dy,s1,s2,i,temp,interchange;

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
	{
		interchange=0;
	}

	e=2*dy-dx;
	plot(x,y);

	for(i=1;i<=dx;i++)
	{
		if(i%10==0)
		{
		 plot(x,y);
		}
		 while(e>=0)
		 {
			if(interchange==1)
			{
				x=x+s1;
			}
			else
			{
				y=y+s2;
			}
		 e=e-2*dx;
		 }
	        if(interchange==1)
		 {
			y=y+s2;
		 }
		 else
		 {
			x=x+s1;
		 }
		 e=e+2*dy;

	}


}


void dashed_dotted(int x1,int y1,int x2,int y2)                    //function to draw dash dotted line using bresenham
{
	int e,x,y,dx,dy,s1,s2,i,temp,interchange;

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
	{
		interchange=0;
	}

	e=2*dy-dx;
	plot(x,y);

	for(i=1;i<=dx;i++)
	{
		if((i/10)%4==0 || (i/10)%4==1)
		{
			plot(x,y);
		}
		else
		{
			if(i%30==0 || i%30==10 || i%30==20)
			{
				plot(x,y);
			}
		}

		 while(e>=0)
		 {
			if(interchange==1)
			{
				x=x+s1;
			}
			else
			{
				y=y+s2;
			}
		 e=e-2*dx;
		 }
	        if(interchange==1)
		 {
			y=y+s2;
		 }
		 else
		 {
			x=x+s1;
		 }
		 e=e+2*dy;

	}
}


void menu(int item)                                       //function to choose type of line
{
	int x1,x2,y1,y2;

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

     glClear(GL_COLOR_BUFFER_BIT);                      //clears the screen
     display();
     bresenhams_line(x1,y1,x2,y2);
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

     glClear(GL_COLOR_BUFFER_BIT);                    //clears the screen
     display();
     dashed(x1,y1,x2,y2);
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

     glClear(GL_COLOR_BUFFER_BIT);                  //clears the screen
     display();
     dotted(x1,y1,x2,y2);
     glFlush();

	}

	if(item==4)
	{
		cout<<"\nEnter coordinates of starting point:";
      cin>>x1>>y1;

     do
     {
      cout<<"\nEnter coordinates of end point:";
      cin>>x2>>y2;
     }

     while(x2==x1 && y2==y1);

     glClear(GL_COLOR_BUFFER_BIT);                          //clears the screen
     display();
     dashed_dotted(x1,y1,x2,y2);
     glFlush();

	}

	if(item==5)
    {
        exit(0);
    }
}


int main(int argc,char **argv)
{
	glutInit(&argc, argv);                                        //initializes the toolkit
	glutInitDisplayMode(GLUT_RGB);                                //sets display mode
	glutInitWindowSize(600,600);                                   //sets the window size
	glutInitWindowPosition(100,150);                              //sets the window position on the screen
	glutCreateWindow("Bresenham line");                           //creates window with atitle
	myInit();

    glutDisplayFunc(display);                                   //registers the draw function
	glutCreateMenu(menu);                                      //creates menu
	glutAddMenuEntry("Simple Line",1);                         //add menu
	glutAddMenuEntry("Dashed Line",2);
	glutAddMenuEntry("Dotted Line",3);
	glutAddMenuEntry("Dash dotted line",4);
	glutAddMenuEntry("EXIT",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);                        //attach right mouse button to menu
	glutMainLoop();
}

