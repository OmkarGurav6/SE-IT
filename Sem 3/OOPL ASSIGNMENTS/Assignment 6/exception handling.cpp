#include<iostream>
using namespace std;

class base
{
  double a,b,result;

  public:
  void getdata();
  void calculate();
};

void base::getdata()
{
  cout<<"\nEnter two no.:";
  cin>>a>>b;
}

void base::calculate()
{
  if(b!=0)
  {
      result=a/b;
      cout<<"\nResult: "<<result;
  }
  else
  {
      throw (b);
  }
}



int main()
{
    int k;
 do
 {

  base g;
  g.getdata();

  try
  {
       g.calculate();
  }

  catch(double b)
  {
   cout<<"\nError occured";
  }
  cout<<"\nEnd of program";

  cout<<"\n\nDo u want to perform again?  (0/1)";
  cin>>k;
 }

  while(k==1);
  return 0;
}
