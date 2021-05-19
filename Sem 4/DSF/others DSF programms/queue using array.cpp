#include <iostream>

using namespace std;


class queue1
{
    int a[15],f,r;

   public:

   queue1()
   {
       r=-1;
       f=-1;
   }

   void insert1(int x);
   void display();
   int delete1();

};



void queue1::insert1(int x)
{

    if(r==4)
      cout<<"\nQueue is full";
    else
        if(r==-1)
       {
         f=r=0;
         a[r]=x;
       }

       else
       {
           r++;
           a[r]=x;
       }

}


int queue1::delete1()
{
    int x;

    x=a[f];

    if(r==-1)
    {
        return -1;
    }

    else
     if(f==r)
    {
        f=-1;
        r=-1;
    }

    else

        f++;
    return x;
}


void queue1::display()
{
    int i;

    if(f==-1)
    {
        cout<<"\nQueue is empty";
    }
    else
    {
     cout<<"\nElements are:";

    for(i=f;i<=r;i++)
    {
        cout<<a[i]<<endl;
    }
    }

}


int main()
{
    queue1 q;
  int ch,f,x;

  do
  {

   cout<<"\n1.Insert element";
   cout<<"\n2.Delete element";
   cout<<"\n3.Display ";
   cout<<"\nEnter choice:";
   cin>>ch;

   switch(ch)


   {
     case 1:

     cout<<"\nEnter element:";
     cin>>x;

     q.insert1(x);

     break;

     case 2:

       x=q.delete1();

    if(x==-1)
        cout<<"\nQueue is empty";
     else
       cout<<"\nDeleted data:"<<x;


     case 3:

      q.display();

    break;



   }

    cout<<"\nDo u want to choose another option?(0/1):";
    cin>>f;


  }

  while(f==1);


    return 0;
}
