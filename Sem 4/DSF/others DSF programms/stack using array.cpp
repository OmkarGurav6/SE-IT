#include <iostream>

using namespace std;

int a[100],n=5,top=-1;

void push(int val)
{
    if(top==n-1)
        cout<<"\nStack is full";
    else
    {
        top++;
        a[top]=val;
    }
}

void pop()
{
    if(top==-1)
        cout<<"\nStack is empty";
    else
    {
        cout<<"\nElement "<< a[top] <<" is popped";
        top--;
    }
}

void display()
{
    int i;

    if(top>=0)
    {
       cout<<"\nStack elements are:";

       for(i=top;i>=0;i--)
       {
           cout<< a[i] <<" ";
           cout<<endl;
       }
    }

    else

        cout<<"\nStack is empty";
}

int main()
{
  int ch,val,f;

  do
  {
    cout<<"\n1.Push in stack";
    cout<<"\n2.Pop from stack";
    cout<<"\n1.Display stack";
    cout<<"\nEnter choice:";
    cin>>ch;

    switch(ch)
    {
     case 1:

     cout<<"\nEnter element :";
     cin>>val;

     push(val);
     break;

     case 2:

     pop();
     break;

      case 3:

     display();
     break;


    }

    cout<<"\nDo u want to choose another option?(0/1):";
    cin>>f;

  }

  while(f==1);

  return 0;


}
