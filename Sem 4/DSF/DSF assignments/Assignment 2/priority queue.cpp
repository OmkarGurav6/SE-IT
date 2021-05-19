
/*Problem statement:

2. Implement priority queue as ADT using single linked list for servicing patients in an hospital with priorities as
i) Serious (top priority)
ii) medium illness (medium priority)
iii) General (Least priority).
*/


#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
 public:
 int prty;
 int id;
 char name[30];
 char bg[30];
 int age;

 node *next;
};

class queue
{
 public:

 node* push(node* head,int priority)
 {
  node *temp=new node;

  cout<<"\nEnter the name of the patient : ";
  cin>>head->name;

  cout<<"Enter Patient id : ";
  cin>>head->id;

  cout<<"Enter Patient's age : ";
  cin>>head->age;

  cout<<"Enter Patient's blood group : ";
  cin>>head->bg;

  head->prty=priority;

  head->next=temp;
  head=head->next;
  temp=NULL;
  return head;
 }

 node *pop(node *start)
 {
  node *p;
  p=start;
  start=start->next;
  free(p);
  return start;
 }

 void disp(node* head)
 {
  if(head==NULL)
  {
   cout<<"Queue is empty";
   return;
  }

  while(head->next!=NULL)
  {
   cout<<"\n\nName of the patient : "<<head->name;

   cout<<"\nPatient id : "<<head->id;

   cout<<"\nPatient's age : "<<head->age;

   cout<<"\nPatient's blood group : "<<head->bg;

   head=head->next;
  }
 }
};

int main()
{
 queue obj;

 node *head[3],*start[3],*p;

       for(int i=0;i<3;i++)
 {
   head[i]=new node;
  start[i]=new node;
  start[i]=head[i];
 }

 int ch,priority;

 for(;;)
 {
  cout<<"\n\nMENU\n1)Enter patient in queue\n2)Remove patient from queue\n3)Display\n4)Exit\nEnter your choice : ";
  cin>>ch;

  switch(ch)
  {
    case 1:

        cout<<"\nDISEASE CHART\n1)Cancer,Dengue,AIDS,Parkinson's Disease,Malaria.\n2)Cholera,Diarrhoea,Swine flu,Typhoid,Chicken pox\n3)Common Cold,Fever,Cough\n";
  cout<<"Enter number according to the disease chart :\n";
           cin>>priority;
           head[priority-1]=obj.push(head[priority-1],priority);
           break;

    case 2:start[priority-1]=obj.pop(start[priority-1]);
           break;

    case 3:cout<<"\n\n";

           for(int i=0;i<3;i++)
           obj.disp(start[i]);
           break;

    case 4:exit(0);
  }
 }
}
