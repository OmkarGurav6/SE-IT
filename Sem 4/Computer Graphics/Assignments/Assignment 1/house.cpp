
#include<GL/glut.h>


void Init()
{

 glClearColor(1.0,1.0,1.0,0.0);    //background colour
 glColor3f(0.0,0.0,1.0);           //drawing colour
 glPointSize(10.0);
 glMatrixMode(GL_PROJECTION);      //specify which matrix is current matrix and sets mode
 glLoadIdentity();                 // replace the current matrix with the identity matrix
 gluOrtho2D(0.0,640.0,0.0,480.0);

}


void Display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_LINE_LOOP);

 glVertex2i(40,40);
 glVertex2i(40,200);
 glVertex2i(200,250);
 glVertex2i(400,200);
 glVertex2i(400,40);
 glEnd();

 glBegin(GL_LINE_STRIP);
 glVertex2i(100,220);
 glVertex2i(100,250);
 glVertex2i(140,250);
 glVertex2i(140,230);
 glEnd();

 glBegin(GL_LINE_STRIP);
 glVertex2i(180,40);
 glVertex2i(180,160);
 glVertex2i(220,160);
 glVertex2i(220,40);
 glEnd();

 glBegin(GL_LINE_LOOP);

 glVertex2i(280,120);
 glVertex2i(280,160);
 glVertex2i(320,160);
 glVertex2i(320,120);

 glEnd();

 glFlush();

}


int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_RGB);
 glutInitWindowSize(640,480);
 glutInitWindowPosition(100,150);
 glutCreateWindow("house");
 glutDisplayFunc(Display);
 Init();
 glutMainLoop();
}
