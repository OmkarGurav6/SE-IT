#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class b1
{
  char bg[20],dob[10];

 public:
 char name[20];
 void accept();
 void display();
};

void b1::accept()
{
 cout<<"\n\nEnter name:";
 cin>>name;

 cout<<"Enter date of birth:";
 cin>>dob;

 cout<<"Enter blood group:";
 cin>>bg;
}

void b1::display()
{
 cout<<left<<setw(10)<<name<<left<<setw(10)<<dob<<left<<setw(5)<<bg;
}


class b2
{
 float h,w;

 public:
 void accept();
 void display();
};

void b2::accept()
{
 cout<<"Enter height:";
 cin>>h;

 cout<<"Enter weight:";
 cin>>w;

}

void b2::display()
{
 cout<<left<<setw(5)<<h<<left<<setw(5)<<w;
}

class b3
{
 int ipn;
 char con_ad[100];

 public:
 void accept();
 void display();
};

void b3::accept()
{
 cout<<"Enter insurance policy no.:";
 cin>>ipn;

 cout<<"Enter contact address:";
 cin>>con_ad;
}

void b3::display()
{
 cout<<left<<setw(10)<<ipn<<left<<setw(40)<<con_ad;
}

class d:public b1,public b2,public b3
{
 char ph_no[20],lic[20];

 public:
 void accept();
 void display();
};


void d::accept()
{
 b1::accept();
 b2::accept();
 b3::accept();
 cout<<"Enter telephone no.:";
 cin>>ph_no;

 cout<<"Enter driving licence no.:";
 cin>>lic;
}


void d::display()
{

 b1::display();
 b2::display();
 b3::display();
 cout<<left<<setw(10)<<ph_no<<right<<setw(10)<<lic;
 cout<<"\n"<<endl;
}


/*main function*/
int main()
{
   int i,n,f,ch,loc,flag=0;
   char na[20];
   d D[20];
   do
   {
       cout<<"\n1.Build master table \n2.Display \n3.Insert a new entry \n4.Delete entry \n5.Edit \n6.Search for a record\n";
       cout<<"Enter your choice\n";
       cin>>ch;
       switch(ch)
       {
         /*case for building master table*/
         case 1:
         cout<<"\nEnter number of records you want to enter :";
         cin>>n;

         for(i=0;i<n;i++)
           D[i].accept();
         break;


         /*case for diplaying master table*/
         case 2:
         cout<<"\n.........................................................Master Table............................................\n";
         cout<<left<<setw(10)<<"Name"<<left<<setw(10)<<"Dob"<<left<<setw(5)<<"Bg"<<left<<setw(5)<<"Ht"<<left<<setw(5)<<"Wt"<<left<<setw(10)<<"Ipn"<<left<<setw(40)<<"Con_Address"<<left<<setw(10)<<"Ph_no"<<right<<setw(10)<<"License_no\n";
         cout<<"\n"<<endl;
         for(i=0;i<n;i++)
            D[i].display();
         break;


         /*case for entering new record*/
         case 3:
         cout<<"\nEnter location where u want to insert new record";
         cin>>loc;

          for(i=n;i>=loc;i--)
          {
             D[i]=D[i-1];
          }

         cout<<"\nEnter new record ";
          D[loc-1].accept();

          cout<<"\n...........................................Master Table............................................\n";
          cout<<left<<setw(10)<<"Name"<<left<<setw(10)<<"Dob"<<left<<setw(5)<<"Bg"<<left<<setw(5)<<"Ht"<<left<<setw(5)<<"Wt"<<left<<setw(10)<<"Ipn"<<left<<setw(40)<<"Con_Address"<<left<<setw(10)<<"Ph_no"<<right<<setw(10)<<"License_no\n";
          cout<<"\n"<<endl;

          for(i=0;i<n+1;i++)
            D[i].display();
          break;

          /*case for deleting record*/
          case 4:
          cout<<"\nEnter location whose record u want to delete";
          cin>>loc;

           for(i=loc-1;i<n-1;i++)
           {
             D[i]=D[i+1];
           }

           cout<<"\n...........................................Master Table............................................\n";
           cout<<left<<setw(10)<<"Name"<<left<<setw(10)<<"Dob"<<left<<setw(5)<<"Bg"<<left<<setw(5)<<"Ht"<<left<<setw(5)<<"Wt"<<left<<setw(10)<<"Ipn"<<left<<setw(40)<<"Con_Address"<<left<<setw(10)<<"Ph_no"<<right<<setw(10)<<"License_no\n";
           cout<<"\n"<<endl;

          for(i=0;i<n-1;i++)
            D[i].display();
          break;

          /*case for editing record*/
          case 5:
          cout<<"\nEnter location whose record u want to edit";
          cin>>loc;

          cout<<"\nEdit data ";
          D[loc-1].accept();

          cout<<"\n...........................................Master Table............................................\n";
          cout<<left<<setw(10)<<"Name"<<left<<setw(10)<<"Dob"<<left<<setw(5)<<"Bg"<<left<<setw(5)<<"Ht"<<left<<setw(5)<<"Wt"<<left<<setw(10)<<"Ipn"<<left<<setw(40)<<"Con_Address"<<left<<setw(10)<<"Ph_no"<<right<<setw(10)<<"License_no\n";
          cout<<"\n"<<endl;

          for(i=0;i<n;i++)
            D[i].display();
          break;

          /*case for searching record*/
          case 6:
          cout<<"\nEnter name for search:";
          cin>>na;
          for(i=0;i<n;i++)
          {
              if(strcmp(D[i].name,na)==0)
              {
                  cout<<"\n...........................................Master Table............................................\n";
                  cout<<left<<setw(10)<<"Name"<<left<<setw(10)<<"Dob"<<left<<setw(5)<<"Bg"<<left<<setw(5)<<"Ht"<<left<<setw(5)<<"Wt"<<left<<setw(10)<<"Ipn"<<left<<setw(40)<<"Con_Address"<<left<<setw(10)<<"Ph_no"<<right<<setw(10)<<"License_no\n";
                  cout<<"\n"<<endl;

                 D[i].display();
                 flag=1;
              }
          }
          if(flag==0)
            cout<<"\nRecord not found";
          break;
       }
       cout<<"\nDo u want to choose another option? (0/1)";
       cin>>f;
   }
   while(f==1);
   return 0;
}
