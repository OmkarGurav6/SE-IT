

#include<math.h>
#include<iostream>
#include<GL/glut.h>

using namespace std;


float a[10][3],res[3][3],res1[3][3];


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

  glColor3f(0.2,0.3,0.4);
  for(i=-1200;i<=1200;i+=2)
   {
     plot(i,0);
     plot(0,i);

   }

}


void mul(float a[3][3],float b[3][3],float res[3][3])       //function for multiplication of two matrices
{
    int sum=0,i,j,k;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            res[i][j]=sum;
            sum=0;
        }
    }

}


void plotm(float res[3][3])               //function to plot result matrix
{

    int i;

    glBegin(GL_LINE_LOOP);

    for(i=0;i<3;i++)
        glVertex2i(res[i][0],res[i][1]);

    glEnd();
    glFlush();
}


void display1()                           //function to draw triangle
{
    display();

    int si,i,j;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<"Enter the co-ordinates of vertex "<<i<<endl;
            cin>>a[i][j];
        }
    }

    glColor3f(1,0,0);

    glBegin(GL_LINE_LOOP);

    glVertex2f(a[0][0],a[0][1]);
    glVertex2f(a[1][0],a[1][1]);
    glVertex2f(a[2][0],a[2][1]);

    glEnd();

    glFlush();

}


void translate(int tx,int ty)                 //function for translation of object
{

    float tra[3][3];

    tra[0][0]=1;
    tra[0][1]=0;
    tra[0][2]=0;
    tra[1][0]=0;
    tra[1][1]=1;
    tra[1][2]=0;
    tra[2][0]=tx;
    tra[2][1]=ty;
    tra[2][2]=1;

    mul(a,tra,res);

    plotm(res);
}



void scaling(int tx,int ty)                     //function for scaling of object
{

    float sc[3][3];

    sc[0][0]=tx;
    sc[0][1]=0;
    sc[0][2]=0;
    sc[1][0]=0;
    sc[1][1]=ty;
    sc[1][2]=0;
    sc[2][0]=0;
    sc[2][1]=0;
    sc[2][2]=1;

    mul(a,sc,res);

    plotm(res);
}


void rotation()                                   //function for rotation of object
{
    float angle,rot[3][3];

    int ch;

    cout<<"\n1.Clockwise rotation";
    cout<<"\n2.Anticlockwise rotation\n";
    cin>>ch;

    cout<<"\nEnter angle :";
    cin>>angle;

    angle=(3.14*angle)/180;


    if(ch==1)
    {
        rot[0][0]=cos(angle);
        rot[0][1]=-1*sin(angle);
        rot[0][2]=0;
        rot[1][0]=sin(angle);
        rot[1][1]=cos(angle);
        rot[1][2]=0;
        rot[2][0]=0;
        rot[2][1]=0;
        rot[2][2]=1;
    }

    else

    {
        rot[0][0]=cos(angle);
        rot[0][1]=sin(angle);
        rot[0][2]=0;
        rot[1][0]=-1*sin(angle);
        rot[1][1]=cos(angle);
        rot[1][2]=0;
        rot[2][0]=0;
        rot[2][1]=0;
        rot[2][2]=1;
    }

    mul(a,rot,res);

    plotm(res);
}


void reflection()                               //function for reflection of object
{
   int ch,f,i,j;
   float ref[3][3];

   do
   {
   cout<<"\n1.Reflection about x axis";
   cout<<"\n2.Reflection about y axis";
   cout<<"\n3.Reflection about origin";
   cout<<"\n4.Reflection about x=y line\n";

   cin>>ch;

   for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
     {
        ref[i][j]=0;
     }
   }


   if(ch==1)
   {
     ref[0][0]=1;
     ref[1][1]=-1;
     ref[2][2]=1;
   }


   if(ch==2)
   {
     ref[0][0]=-1;
     ref[1][1]=1;
     ref[2][2]=1;
   }

   if(ch==3)
   {
     ref[0][0]=-1;
     ref[1][1]=-1;
     ref[2][2]=1;
   }

   if(ch==4)
   {
     ref[0][1]=1;
     ref[1][0]=1;
     ref[2][2]=1;
   }

   mul(a,ref,res);

   plotm(res);

   cout<<"\nDo u want to choose another option?  (0/1)";
   cin>>f;
   }

   while(f==1);
}


void shear()                                 //function for shear of object
{

    int ch,x1,y1,i,j;
    float sh[3][3];

    cout<<"\n1.x shear";
    cout<<"\n2.y shear\n";

    cin>>ch;

    for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
     {
        sh[i][j]=0;
     }
    }


   if(ch==1)
   {
     cout<<"\nEnter x shear factor :";
     cin>>x1;


     sh[0][0]=1;
     sh[1][1]=1;
     sh[2][2]=1;
     sh[1][0]=x1;

   }


   if(ch==2)
   {
     cout<<"\nEnter y shear factor :";
     cin>>y1;


     sh[0][0]=1;
     sh[1][1]=1;
     sh[2][2]=1;
     sh[0][1]=y1;

   }

   mul(a,sh,res);

   plotm(res);
}


void  trans_scal()                                   //function for scaling of object about arbitary point
{
    float tra[3][3],tr[3][3],sc[3][3];

    int sx,sy,tx,ty;

    cout<<"\nEnter x co-ordinate of arbitary point:";
    cin>>tx;

    cout<<"\nEnter y co-ordinate of arbitary point:";
    cin>>ty;

    cout<<"\nEnter scaling factor tx :";
    cin>>sx;

    cout<<"\nEnter scaling factor ty :";
    cin>>sy;

    tr[0][0]=1;
    tr[0][1]=0;
    tr[0][2]=0;
    tr[1][0]=0;
    tr[1][1]=1;
    tr[1][2]=0;
    tr[2][0]=-tx;
    tr[2][1]=-ty;
    tr[2][2]=1;

    sc[0][0]=sx;
    sc[0][1]=0;
    sc[0][2]=0;
    sc[1][0]=0;
    sc[1][1]=sy;
    sc[1][2]=0;
    sc[2][0]=0;
    sc[2][1]=0;
    sc[2][2]=1;

    tra[0][0]=1;
    tra[0][1]=0;
    tra[0][2]=0;
    tra[1][0]=0;
    tra[1][1]=1;
    tra[1][2]=0;
    tra[2][0]=tx;
    tra[2][1]=ty;
    tra[2][2]=1;

    mul(tr,sc,res);

    mul(res,tra,res1);

    mul(a,res1,res);

    plotm(res);

}


void trans_rot()                                               //function for rotation of object about arbitary point
{
   float p1,p2,angle,tr1[3][3],tr[3][3];

    cout<<"enter the arbritary x co-ordinate: "<<endl;
    cin>>p1;
    cout<<"enter the arbritary y co-ordinate: "<<endl;
    cin>>p2;

    tr[0][0]=1;
	tr[0][1]=0;
	tr[0][2]=0;
	tr[1][0]=0;
	tr[1][1]=1;
	tr[1][2]=0;
	tr[2][0]=-p1;
	tr[2][1]=-p2;
	tr[2][2]=1;

     float rolm[3][3];

    cout<<"enter the angle for clockwise rotation "<<endl;
    cin>>angle;

    angle=angle*(3.142/180);

    rolm[0][0]=cos(angle);
    rolm[1][1]=cos(angle);
    rolm[2][2]=1;

    rolm[0][1]=-1*sin(angle);
    rolm[0][2]=0;
    rolm[1][0]=sin(angle);
    rolm[1][2]=0;
    rolm[2][0]=0;
    rolm[2][1]=0;


    tr1[0][0]=1;
	tr1[0][1]=0;
	tr1[0][2]=0;
	tr1[1][0]=0;
	tr1[1][1]=1;
	tr1[1][2]=0;
	tr1[2][0]=p1;
	tr1[2][1]=p2;
	tr1[2][2]=1;

    mul(tr,rolm,res);

    mul(res,tr1,res1);

    mul(a,res1,res);

    plotm(res);
}


void menu(int item)                                      //function to choose option
{
	int tx,ty,sx,sy;

	if(item==1)
	{
	    glClear(GL_COLOR_BUFFER_BIT);

	    display();
	    display1();

	    do
        {
	    cout<<"\nEnter translation factor tx :";
	    cin>>tx;
        }
        while(tx==0);

        do
        {
	    cout<<"\nEnter translation factor ty :";
	    cin>>ty;
        }
        while(ty==0);

        glColor3f(0.0,1.0,0.0);
        translate(tx,ty);
	}


	if(item==2)
	{
	    glClear(GL_COLOR_BUFFER_BIT);

	    display();
	    display1();

	    do
        {
        cout<<"\nEnter scaling factor tx :";
	    cin>>sx;
        }
        while(sx<=0);

        do
        {
	    cout<<"\nEnter scaling factor ty :";
	    cin>>sy;
        }
        while(sy<=0);

	    glColor3f(0.0,1.0,0.0);
        scaling(sx,sy);
	}


	if(item==3)
	{
	    glClear(GL_COLOR_BUFFER_BIT);

	    display();

	    display1();

	    glColor3f(0.0,1.0,0.0);
        rotation();
	}


	if(item==4)
	{
        glClear(GL_COLOR_BUFFER_BIT);

	    display();

        display1();

        glColor3f(0.0,1.0,0.0);
        reflection();
	}


	if(item==5)
	{
	    glClear(GL_COLOR_BUFFER_BIT);

	    display();

        display1();

        glColor3f(0.0,1.0,0.0);
        shear();
	}


	if(item==6)
	{
	    glClear(GL_COLOR_BUFFER_BIT);

	    display();

	    display1();

	    glColor3f(0.0,1.0,0.0);
	    trans_scal();
	}

	if(item==7)
	{
	   glClear(GL_COLOR_BUFFER_BIT);

       display();

	   display1();

	   glColor3f(0.0,1.0,0.0);
	   trans_rot();
	}


	if(item==8)
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
    glutCreateWindow("Transformation");                           //creates window with a title
    myInit();


    glutDisplayFunc(display);                                   //registers the display function
    glutCreateMenu(menu);                                      //creates menu
    glutAddMenuEntry("Translation",1);                         //add menu
    glutAddMenuEntry("Scaling",2);
    glutAddMenuEntry("Rotation",3);
    glutAddMenuEntry("Reflection",4);
    glutAddMenuEntry("Shear",5);
    glutAddMenuEntry("Translation and scaling",6);
    glutAddMenuEntry("Translation and rotation",7);
    glutAddMenuEntry("Exit",8);
    glutAttachMenu(GLUT_RIGHT_BUTTON);                        //attach right mouse button to menu
    glutMainLoop();

    return 0;

}
