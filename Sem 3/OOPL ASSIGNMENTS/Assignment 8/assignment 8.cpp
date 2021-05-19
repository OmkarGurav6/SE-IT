#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class student
{
   int age;
   char name[20],email[60];

   public:

   int rn;

   void getdata()
   {

       cout<<"\nEnter name: ";
       cin>>name;

       cout<<"\nEnter email: ";
       cin>>email;

       cout<<"\nEnter roll no: ";
       cin>>rn;

       cout<<"\nEnter age: ";
       cin>>age;

   }


   void display()
   {
           cout<<"\n"<<left<<setw(20)<<name<<left<<setw(40)<<email<<left<<setw(20)<<rn<<left<<setw(20)<<age<<endl;
   }

};



int main()
{
    student s[20];
    fstream f,temp;

    int i,n,ch,fa,a,sa,r,y;
    int b,c,d;

    do
    {
     cout<<"\n1.Create database \n2.Display database \n3.Add a record \n4.Delete a record \n5.Modify a record";
     cout<<"\nChoose the option:";
     cin>>ch;

     switch(ch)
     {

       case 1:

       cout<<"\nHow many records u want to enter: ";
       cin>>n;
       f.open("Student.dat",ios::out);

       for(i=0;i<n;i++)
       {
           s[i].getdata();
           f.write((char *) &s[i],sizeof(s[i]));
       }

       f.close();
       break;


       case 2:

        cout<<"\n"<<left<<setw(20)<<"Name"<<left<<setw(40)<<"Email"<<left<<setw(20)<<"Roll no"<<left<<setw(20)<<"Age"<<endl;

        f.open("Student.dat",ios::in);
        f.seekg(0);

        for(i=0;i<n;i++)
        {
           f.read((char *) &s[i],sizeof(s[i]));
           s[i].display();
        }

        f.close();
        break;


       case 3:

       cout<<"Enter the number of students you want to add:"<<endl;
	   cin>>a;

       f.open("Student.dat",ios::app|ios::out);

       for(i=n;i<n+a;i++)
	   {
	     s[i].getdata();
	     f.write((char *) &s[i],sizeof(s[i]));
	   }

	   f.close();
	   n=n+a;

	   cout<<"\n"<<left<<setw(20)<<"Name"<<left<<setw(40)<<"Email"<<left<<setw(20)<<"Roll no"<<left<<setw(20)<<"Age"<<endl;

        f.open("Student.dat",ios::in);
        f.seekg(0);

        for(i=0;i<n;i++)
        {
           f.read((char *) &s[i],sizeof(s[i]));
           s[i].display();
        }

        f.close();

       break;


       case 4:

       cout<<"\nEnter roll no of student whose database u want to delete:";
       cin>>sa;

	   f.open("Student.dat",ios::in);
	   temp.open("Temp.dat",ios::out);

	   f.seekg(0);

	   for(i=0;i<n;i++)
       {

		f.read((char *) &s[i],sizeof(s[i]));
		if(sa==s[i].rn)
        {
		     y=i;
        }

		else
		{
			temp.write((char *) &s[i],sizeof(s[i]));
        }

       }

	    temp.close();
	    f.close();

	    remove("Student.dat");
	    rename("Temp.dat","Student.dat");

	    for(i=y;i<n;i++)
	    {
		  s[i]=s[i+1];
	    }
	    n=n-1;
       break;

       case 5:

       {

       cout<<"\nEnter roll no of student whose database u want to modify:";
       cin>>r;

       f.open("Student.dat",ios::in|ios::ate|ios::out);
       f.seekg(0);

       for(i=0;i<n;i++)
       {
		 f.read((char *) &s[i],sizeof(s[i]));

		 if(r==s[i].rn)
         {
			s[i].getdata();
			b=f.tellp();
			c=sizeof(s[i]);
			  d=b-c;
			f.seekp(d);
			f.write((char *) &s[i],sizeof(s[i]));
			}
		 }
		f.close();
       break;
      }

     }

     cout<<"\nDo u want to choose another option (0/1):";
     cin>>fa;

    }

    while(fa==1);

    return 0;
}
