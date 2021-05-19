

#include<iostream>
#include<math.h>
#include<iostream>
#include<GL/glut.h>
using namespace std;

GLfloat oldx=-0.9,oldy=0.7;

void drawkoch(GLfloat dir,GLfloat len,GLint iter)              //function to create koch curve
{

  GLdouble dirRad = 0.0174533 * dir;
  GLfloat newX = oldx + len * cos(dirRad);
  GLfloat newY = oldy + len * sin(dirRad);

 if (iter==0)
 {
   glVertex2f(oldx, oldy);
   glVertex2f(newX, newY);
   oldx = newX;
   oldy = newY;
 }

 else
 {

  iter--;
  drawkoch(dir, len, iter);
  dir += 60.0;
  drawkoch(dir, len, iter);
  dir -= 120.0;
  drawkoch(dir, len, iter);
  dir += 60.0;
  drawkoch(dir, len, iter);
 }
}


void mydisplay()                                   //display function
{
	int n;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(1.0f,0.0f,0.0f);

	cout<<"\nEnter the number of iteration\n";      //Input no. of iterations from user
	cin>>n;

	if(n<=3)
	{
       	drawkoch(0.0,0.05,n);                       //print koch curve
     	drawkoch(-120.0,0.05,n);
     	drawkoch(120.0,0.05,n);
   }
   else
   {
         cout<<"Invalid no. of iterations!!!Exit of program.";
         exit(0);                                                           //Exit of program
   }
	glEnd();
	glFlush();
}

int main(int argc,char **argv)                                              //main function
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("koch");
	glutDisplayFunc(mydisplay);                                            //call to display function
	glutMainLoop();

}
