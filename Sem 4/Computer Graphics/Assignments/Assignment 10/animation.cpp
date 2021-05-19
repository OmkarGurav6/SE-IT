

#include<iostream>
#include<cmath>
#include<GL/glut.h>

using namespace std;

float readpixel[3],theta2=6.284,theta3=4.56,theta4=4.88,theta=4.56,theta5=6.284;
int leftflag=1,rightflag=0;

void myinit()
{
   glClearColor(1.0,1.0,1.0,1.0);             //sets background color to white
   glColor3f(0.0,0.0,1.0);                    //sets drawing color to blue
   glPointSize(3.0);                           //sets point size to 3 by 3 pixels
   glMatrixMode(GL_PROJECTION);               //specify which matrix is current matrix and sets mode
   glLoadIdentity();                          // replace the current matrix with the identity matrix
   gluOrtho2D(0.0,400.0,0.0,400.0);
}


int sign(float v2,float v1)                 //function to assign sign
{
  float v=v2-v1;

    if(v<0)
      return -1;
    else if(v>0)
      return 1;
    else if(v==0)
      return 0;
}


float polarcoordinatex(float radius,float angle)      //function for finding out x polar co-ordinate
{
  float rx=radius*cos(angle);

  return rx;
}


float polarcoordinatey(float radius,float angle)     //function for finding out y polar co-ordinate
{
    float ry=radius*sin(angle);

  return ry;
}


void plot(float x,float y)   //function to plot point
{
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
}


void plotcircle(float x1,float y1,float h,float k)
{
    plot(x1+h,y1+k);
    plot(y1+h,x1+k);
    plot(-y1+h,x1+k);
    plot(-x1+h,y1+k);
    plot(-x1+h,-y1+k);
    plot(-y1+h,-x1+k);
    plot(y1+h,-x1+k);
    plot(x1+h,-y1+k);
}


void circle(float r1,float h1,float k1)              //function to draw circle
{
  float d,x,y,r;
     r=r1;
     d=3-2*r;
     x=0;
     y=r;
     while(x<=y)
      {
	if(d<=0)
	  {
	     d=d+4*x+6;
             x=x+1;
          }
        else
	  {
	     d=d+4*(x-y)+10;
	     x=x+1;
	     y=y-1;
	  }
        plotcircle(x,y,h1,k1);
      }
}


void bresenhamsline(float ux1,float uy1,float ux2,float uy2)      //function to draw line
{

  float dx,dy,x,y,e,temp;
  int interchange,i,s1,s2;
     dx=abs(ux2-ux1);
     dy=abs(uy2-uy1);
     s1=sign(ux2,ux1);
     s2=sign(uy2,uy1);
     x=ux1;
     y=uy1;

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
            plot(x,y);
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


void func1(float radius,float angle)
{
   float rx1,ry1,rx2,ry2;
     rx1=polarcoordinatex(radius,angle);
     ry1=polarcoordinatey(radius,angle);
     rx2=polarcoordinatex(radius-12.0,angle);
     ry2=polarcoordinatey(radius-12.0,angle);

     bresenhamsline(rx1+200.0,ry1+310.0,rx2+200.0,ry2+310.0);
}


void clockhand(float length,float angle)                //function to draw-: minutes,seconds and hours hand
{
   float rx,ry;
     rx=polarcoordinatex(length,angle);
     ry=polarcoordinatey(length,angle);
     bresenhamsline(200.0,310.0,rx+200.0,ry+310.0);
}


void frame()                                              //function to draw frame
{
   glColor3f(0.0,0.0,1.0);                             //sets drawing color to blue

     bresenhamsline(155.0,390.0,245.0,390.0);
     bresenhamsline(110.0,310.0,155.0,390.0);
     bresenhamsline(245.0,390.0,290.0,310.0);
     bresenhamsline(110.0,310.0,150.0,230.0);
     bresenhamsline(250.0,230.0,290.0,310.0);
     bresenhamsline(150.0,230.0,150.0,50.0);
     bresenhamsline(250.0,230.0,250.0,50.0);
     bresenhamsline(150.0,50.0,200.0,10.0);
     bresenhamsline(250.0,50.0,200.0,10.0);
     bresenhamsline(160.0,230.0,240.0,230.0);
     bresenhamsline(160.0,60.0,240.0,60.0);
     bresenhamsline(160.0,230.0,160.0,60.0);
     bresenhamsline(240.0,230.0,240.0,60.0);

     circle(60.0,200.0,310.0);

}


void clockstructure()                           // function to draw inner details of the clock
{
  float theta1=0.0,thetarad=0.0;
     glPointSize(1.0);                          //sets point size to 1 by 1 pixels
     glColor3f(1.0,0.0,0.0);                  //sets drawing color to red

     while(theta1<=330)
       {
           func1(57.0,thetarad);
           theta1=theta1+30.0;
           thetarad=(theta1*3.142)/180;
       }

     glPointSize(2.0);                          //sets point size to 2 by 2 pixels
     clockhand(40.0,theta2);
     clockhand(25.0,0.523);

     glPointSize(1.0);                         //sets point size to 1 by 1 pixels
     clockhand(42.0,theta5);
}


void pendulum()    	                          //function to draw pendulum
{
  float rx1,ry1,rx2,ry2,th,tk;

     glColor3f(1.0,0.0,0.0);                 //sets drawing color to red

     glPointSize(3.0);                      //sets point size to 3 by 3 pixels

     rx1=polarcoordinatex(106.0,theta);
     ry1=polarcoordinatey(106.0,theta);

     bresenhamsline(200.0,226.0,200.0+rx1,226.0+ry1);
     glColor3f(0.0,1.0,1.0);
     glPointSize(2.0);                     //sets point size to 2 by 2 pixels

     rx2=polarcoordinatex(117.0,theta);
     ry2=polarcoordinatey(117.0,theta);
     th=200.0+rx2;
     tk=226.0+ry2;

     circle(10.0,th,tk);

}


void display()
{
  glClear(GL_COLOR_BUFFER_BIT);                     //clears the screen

   frame();
   clockstructure();
   pendulum();

  glutSwapBuffers();
}


void timer(int t)
{
   glutTimerFunc(100,timer,2);

        if(theta<=theta3)
          {
             leftflag=1;
             rightflag=0;
          }
        if(theta>=theta4)
          {
             rightflag=1;
		   leftflag=0;
		}
        if(leftflag==1 && rightflag==0)
             theta=theta+0.032;
        if(rightflag==1 && leftflag==0)
             theta=theta-0.032;
        if(theta2==0.0)
            theta2=6.284;
        if(theta2!=0.0)
            theta2=theta2-0.00015;
        if(theta5==0.0)
            theta5=6.284;
        if(theta5!=0.0)
            theta5=theta5-0.011;

    glutPostRedisplay();
}


int main(int argc,char **argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutCreateWindow("Pendulum Clock");
	 glutInitWindowSize(400,400);
     glutDisplayFunc(display);
     glutTimerFunc(100,timer,2);
	 myinit();
	 glutMainLoop();

 return 0;
}
