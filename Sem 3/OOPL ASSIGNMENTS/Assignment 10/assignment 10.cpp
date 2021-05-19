#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class employee
{
 char name[20];
 int id_no;
 int salary;
 int experience;
 char skills[20];

 public:

 void getdata();
 void display();

};

void employee::getdata()
{

 cout<<"\nEnter details of employee: ";
 cout<<"\nEnter name of employee:";
 cin>>name;

 cout<<"\nEnter id no. of employee:";
 cin>>id_no;

 cout<<"\nEnter salary of employee:";
 cin>>salary;

 cout<<"\nEnter experience of employee in years:";
 cin>>experience;

 cout<<"\nEnter skills of employee:";
 cin>>skills;

}

void employee::display()
{

  cout<<"\nName       : "<<name;
  cout<<"\n\nId no      : "<<id_no;
  cout<<"\n\nSalary     : "<<salary;
  cout<<"\n\nExperience : "<<experience;
  cout<<"\n\nSkills     : "<<skills;

}



int main()
{
  employee e[50];
  int i,n;
  fstream f;

  cout<<"\nEnter number of records u want to enter:";
  cin>>n;

  f.open("employee.bin",ios:: binary| ios::out);

  for(i=0;i<n;i++)
  {
    e[i].getdata();
    f.write((char *)&e[i],sizeof(e[i]));
  }

  f.close();


  f.seekg(0);

  cout<<"\nReading from file";

  f.open("employee.bin",ios:: binary| ios::in);

   cout<<"\n\nRecord:";

  for(i=0;i<n;i++)
  {

  f.read((char*)&e[i],sizeof(e[i]));
  e[i].display();
  }

  f.close();
  return 0;
}
