
#include<iostream>

using namespace std;


class node
{
  public:

  int data;
  node *next;

  node(int x)
  {

    data=x;
    next=NULL;

  }

};


class queue1
{
 public:

 node *f,*r;

 queue1()
 {
   f=NULL;
   r=NULL;
 }


 void insert1(int x);
 int delete1();
 void display();


};


void queue1::insert1(int x)
{
   if(f==NULL)
    f=r=new node(x);

  else
  {
   r->next=new node(x);
   r=r->next;

  }

}


void queue1::display()
{
  node *p;

  if(f==NULL)

  {
       cout<<"\nQueue is empty";
       return ;
  }

  cout<<"\nElements are:";

   p=f;

   while(p!=NULL)
  {
     cout<<" "<<p->data;
     p=p->next;
  }

}


int queue1::delete1()
{

 node *p;
 int x;

 if(f==NULL)
  {
    return -1;
  }
 else
 {
   x=f->data;
   p=f;

   f=f->next;

  delete p;

  return x;
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

    break;


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
