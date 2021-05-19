#include <iostream>
using namespace std;

class personal_record
{
    public:
    char name[40],email[40];
    int age;

    void get_personal_data()
    {
      cout<<"\n\nEnter name: ";
      cin>>name;
      cout<<"\nEnter email: ";
      cin>>email;
      cout<<"\nEnter age: ";
      cin>>age;
    }
};

class professional_record
{
    public:
    int salary,exp;
    char skills[50];

    void get_professional_data()
    {
      cout<<"\nEnter salary: ";
      cin>>salary;
      cout<<"\nEnter work experience: ";
      cin>>exp;
      cout<<"\nEnter skills: ";
      cin>>skills;
    }

};

class academic_record
{
    public:
    float cgpa;
    char degree[50],college[50];

    void getdata()
    {
       cout<<"\nEnter CGPA: ";
       cin>>cgpa;
       cout<<"\nEnter degree: ";
       cin>>degree;
       cout<<"\nEnter college: ";
       cin>>college;
    }
};


class biodata:public personal_record,public professional_record,public academic_record
{
   public:
   void create()
   {
       cout<<"\nEmployee info\n\nPERSONAL DETAILS\n Name                  :"<<name;
       cout<<"\nEmail                 :"<<email;
       cout<<"\nAge                   :"<<age;

       cout<<"\n\nPROFESSIONAL DETAILS";
       cout<<"\nSalary                :"<<salary;
       cout<<"\nWork experience       :"<<exp;
       cout<<"\nProfessional skills   :"<<skills;

       cout<<"\n\nACADEMIC DETAILS";
       cout<<"\nCGPA                  :"<<cgpa;
       cout<<"\nDegree                :"<<degree;
       cout<<"\nCollege               :"<<college;
   }
};



int main()
{
    biodata b[20];
    int n,i;

    cout<<"\nEnter number of records: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
      b[i].get_personal_data();
      b[i].get_professional_data();
      b[i].getdata();
    }

   for(i=0;i<n;i++)
     b[i].create();
    return 0;
}
