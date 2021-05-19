
#include<GL/glut.h>
#include<iostream>

using namespace std;

void myInit(void)
{
	glClearColor(0,0,0,0);                                   //sets background color to black
	glColor3f(1,1,1);                                         //sets drawing color to black
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


void plot(int x,int y)                     //function to plot point
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}


void  display()                               //function to draw axes
{
  int i;

  for(i=-1200;i<=1200;i+=2)
   {
     plot(i,0);
     plot(0,i);

   }

}

void bresenhams_line(int x1,int y1,int x2,int y2)             //function to draw simple line using bresenham
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


void pattern()
{
    glClear(GL_COLOR_BUFFER_BIT);

    display();
    glColor3f(0,1,1);                               //sets drawing color to purple
	//square 1
	bresenhams_line(250,250,450,250);
	bresenhams_line(450,250,450,100);
	bresenhams_line(450,100,250,100);
	bresenhams_line(250,100,250,250);
	//diamond
	bresenhams_line(350,250,450,175);
	bresenhams_line(350,250,250,175);
	bresenhams_line(250,175,350,100);
	bresenhams_line(350,100,450,175);
	//square 2
	bresenhams_line(400,213,400,137);
	bresenhams_line(400,137,300,137);
	bresenhams_line(300,137,300,213);
	bresenhams_line(300,213,400,213);

}


int main(int argc,char **argv)
{
	glutInit(&argc, argv);                                        //initializes the toolkit
	glutInitDisplayMode(GLUT_RGB);                                //sets display mode
	glutInitWindowSize(600,600);                                   //sets the window size
	glutInitWindowPosition(100,150);                              //sets the window position on the screen
	glutCreateWindow("Pattern");
	myInit();

    glutDisplayFunc(pattern);                                      //registers the display function
	glutMainLoop();
}
