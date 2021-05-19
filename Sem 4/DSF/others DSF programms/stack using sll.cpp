#include <iostream>

using namespace std;


class node
{
  public:

  int data;
  node *next;
};



class stack1
{
  public:

  node *top;

  stack1()
  {
    top=NULL;
  }

  void push(int data);
  void pop();
  void display();

};



void stack1::push(int d)
{
    node *temp=new node;

        temp->data=d;
        temp->next=top;
        top=temp;

}


void stack1::pop()
{
    if(top==NULL)
    {
        cout<<"\nStack is empty";
    }
    else
    {
        cout<<"\nPopped element is:"<<top->data;
        top=top->next;

    }
}


void stack1::display()
{
    node *temp=new node;

    if(top==NULL)
    {
        cout<<"\nStack is empty";
    }
    else
    {
        temp=top;
        cout<<"\nStack elements are:";

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}



int main()
{
   stack1 s;
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

     s.push(val);
     break;

     case 2:

     s.pop();
     break;

      case 3:

     s.display();
     break;


    }

    cout<<"\nDo u want to choose another option?(0/1):";
    cin>>f;

  }

  while(f==1);

  return 0;

}
