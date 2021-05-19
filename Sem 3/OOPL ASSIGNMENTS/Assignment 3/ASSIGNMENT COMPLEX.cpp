#include <iostream>
using namespace std;

class complex
{
  float imag,real;

  public:
  complex()                            //default constructor
  {
    real=0;
    imag=0;
  }

  complex(float a,float b)             //parameterized constructor
  {
    real=a;
    imag=b;
  }

  void getdata();
  void display();

  friend complex operator+(complex x,complex y);
  friend complex operator-(complex x,complex y);

  complex operator*(complex x);
  complex operator/(complex x);
};

void complex::getdata()
{
  cout<<"Enter real and imaginary part of complex number:- "<<endl;
  cin>>real>>imag;
}

void complex::display()
{
  cout<<real<<"+("<<imag<<"i)\n\n";
}

complex operator+(complex x,complex y)
{
  complex m;
  m.real=x.real+y.real;
  m.imag=x.imag+y.imag;
  return m;
}

complex operator-(complex x,complex y)
{
  complex m;
  m.real=x.real-y.real;
  m.imag=x.imag-y.imag;
  return m;
}

complex complex::operator*(complex x)
{
  complex m;
  m.real=(real*x.real)-(imag*x.imag);
  m.imag=(real*x.imag)+(imag*x.real);
  return m;
}

complex complex::operator/(complex x)
{
  complex m;
  m.real=((real*x.real)+(imag*x.imag))/((x.real*x.real)+(x.imag*x.imag));
  m.imag=((imag*x.real)-(real*x.imag))/((x.real*x.real)+(x.imag*x.imag));
  return m;
}

int main()
{
  int choice,a;
  complex x,y,c;
  x.getdata();
  x.display();
  y.getdata();
  y.display();

  do
   {
    cout<<"Choose operation\n"<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n\n";
    cin>>choice;

    switch(choice)
     {
      case 1:
      c=x+y;
      cout<<"Addition is \n";
      c.display();
      break;

      case 2:
      c=x-y;
      cout<<"Subtraction is \n";
      c.display();
      break;

      case 3:
      c=x*y;
      cout<<"Multiplication is \n";
      c.display();
      break;

      case 4:
      c=x/y;
      cout<<"Division is \n";
      c.display();
      break;

      default:
      cout<<"Invalid choice!Choose option between 1-4";
      break;

     }
     cout<<"Do u want to perform another operation?  (0/1)";
     cin>>a;
   }
   while(a==1);
   return 0;
}
