#include<iostream>
using namespace std;

class shape
{
  public:

  double s1,s2;
  void accept()
  {
    cout<<"\nEnter dimensions\n";
    cin>>s1;
    cout<<"\n";
    cin>>s2;
    while(s1<=0 || s2<=0)
    {
        cout<<"\nDimensions should be greater than 0 !!!\nEnter again\n";
        cin>>s1;
        cout<<"\n";
        cin>>s2;
    }
  }

  virtual void compute_area()=0;
};


class triangle:public shape
{
 public:

 void compute_area()
 {
   cout<<"\nArea of triangle is "<<(0.5*s1*s2);
 }

};


class rectangle:public shape
{
  public:

  void compute_area()
  {
    cout<<"\nArea of rectangle is "<<(s1*s2);
  }
};


int main()
{
  shape *s;
  triangle t;
  rectangle r;
  int f,ch;
  do
  {
    cout<<"\n1.Area of triangle";
    cout<<"\n2.Area of rectangle";
    cout<<"\nChoose option:";
    cin>>ch;

    switch(ch)
    {
     case 1:
     s=&t;
     s->accept();
     s->compute_area();
     break;

     case 2:
     s=&r;
     s->accept();
     s->compute_area();
     break;
    }


   cout<<"\nDo u want to choose other option? (0/1)";
   cin>>f;

  }
  while(f==1);

  return 0;
}
