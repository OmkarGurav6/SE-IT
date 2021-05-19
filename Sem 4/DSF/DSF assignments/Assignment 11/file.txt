
/*

NAME:Omkar Gurav

ROLL NO.:8048

Department maintains a student information. The file contains roll number, name, division and address.
Write a program to create a sequential file to store and maintain student data.
It should allow the user to add, delete information of student. Display information of particular student.
If record of student does not exist an appropriate message is displayed. If student record is found it should display the student details.

*/

#include <iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

class student
{
    int roll_no;
    char name[40],address[100],div;

    public:

    void getdata();
    void display();
    void modify();
    void search1();
    void delete1();
};


void student::getdata()                       //function to get input
{
   ofstream fout;
   fout.open("FILE.txt",ios::out |ios::app);

   cout<<"\n\nEnter name of student     :";
   cin>>name;

   cout<<"\nEnter roll no. of student :";
   cin>>roll_no;

   cout<<"\nEnter division of student :";
   cin>>div;

   cout<<"\nEnter address of student  :";
   cin>>address;

   fout<<name<<"\t"<<roll_no<<"\t"<<div<<"\t"<<address<<endl;

   fout.close();
}


void student::display()                   //function to display output
{
    ifstream fin;
    fin.open("FILE.txt");

    while(!fin.eof())
    {
        fin>>name>>roll_no>>div>>address;

        if(fin.eof()==1)
            break;

        cout<<"\n"<<left<<setw(15)<<name<<left<<setw(5)<<roll_no<<left<<setw(5)<<div<<left<<setw(50)<<address<<endl;
    }

    fin.close();
}


void student::modify()            //function to modify record contents
{
    int rn,c,f,flag=0;

    ifstream fin;
    ofstream fout;

    fin.open("FILE.txt");
    fout.open("MODIFIED_FILE.txt");

    cout<<"Enter roll no of record to be modified : ";
    cin>>rn;

    while(!fin.eof())
    {
        fin>>name>>roll_no>>div>>address;

        if(fin.eof()==1)
            break;

        if(roll_no==rn)
        {
          flag=1;

          do
          {

           cout<<"\n1.Name\n2.Roll no\n3.Division\n4.Address ";
           cout<<"\nEnter option u want to modify :";
           cin>>c;

           switch(c)
           {
             case 1:

             cout<<"Enter name : ";
             cin>>name;

             break;

             case 2:

             cout<<"Enter roll no. : ";
             cin>>roll_no;

             break;

             case 3:

             cout<<"Enter division : ";
             cin>>div;

             break;

             case 4:

             cout<<"Enter address : ";
             cin>>name;

             break;

           }
            cout<<"\n\nDo u want to select another option  to modify ? (0/1)  :";
            cin>>f;

          }

          while(f==1);

        }
                 fout<<name<<"\t"<<roll_no<<"\t"<<div<<"\t"<<address<<endl;

    }

     if(flag==0)
        cout<<"\n\nRecord is not present !!!";

     fin.close();
     fout.close();

     remove("FILE.txt");
     rename("MODIFIED_FILE.txt", "FILE.txt");

}


void student::search1()              //function to search record
{
    int rn,flag=0;

    ifstream fin;

    fin.open("FILE.txt");

    cout<<"\nEnter roll no. of student whose record u want to search :";
    cin>>rn;

    while(!fin.eof())
    {
         fin>>name>>roll_no>>div>>address;

         if(fin.eof()==1)
            break;

        if(rn==roll_no)
         {
            flag=1;

            cout<<"\n"<<left<<setw(15)<<"Name"<<left<<setw(5)<<"Rn"<<left<<setw(5)<<"Div"<<left<<setw(50)<<"Address"<<endl;
            cout<<"\n"<<left<<setw(15)<<name<<left<<setw(5)<<roll_no<<left<<setw(5)<<div<<left<<setw(50)<<address<<endl;
         }
    }

    if(flag==0)
       cout<<"\n\nRecord is not present !!!";

    fin.close();

}


void student::delete1()          //function to delete record
{
     ifstream fin;
     ofstream fout;

     int rn,flag=0;

     fin.open("FILE.txt");
     fout.open("DELETE_FILE.txt");

     cout<<"Enter roll no. of student whose record u want to delete : ";
     cin>>rn;

     while(!fin.eof())
     {
            fin>>name>>roll_no>>div>>address;

            if(fin.eof()==1)
                break;

            if(rn!=roll_no)
			{
				fout<<name<<"\t"<<roll_no<<"\t"<<div<<"\t"<<address<<endl;
            }

            else
              flag=1;
     }

     if(flag==1)
          cout<<"\n\nRecord is deleted ";
     else
          cout<<"\n\nRecord is not present !!!";

     fin.close();
     fout.close();

     remove("FILE.txt");
     rename("DELETE_FILE.txt","FILE.txt");
}


int main()
{
    student s;

    int ch,fa,n,i,l;

    cout<<"\nEnter no. of student :";
    cin>>n;

    for(i=0;i<n;i++)
        s.getdata();

    do
    {
        cout<<"\n\n1.Display record";
        cout<<"\n2.Add record";
        cout<<"\n3.Modify record";
        cout<<"\n4.Search record";
        cout<<"\n5.Delete record";
        cout<<"\n\nEnter choice :";
        cin>>ch;

        switch(ch)

        {
           case 1:

           cout<<"\n"<<left<<setw(15)<<"Name"<<left<<setw(5)<<"Rn"<<left<<setw(5)<<"Div"<<left<<setw(50)<<"Address"<<endl;
           s.display();

           break;


           case 2:

           cout<<"\nEnter no. of records u want to add :";
           cin>>l;

           for(i=0;i<l;i++)
             s.getdata();

           break;


           case 3:

           s.modify();

           break;


           case 4:

           s.search1();

           break;


           case 5:

           s.delete1();

           break;

        }

        cout<<"\n\nDo u want to select another option ? (0/1)  :";
        cin>>fa;
    }

    while(fa==1);

    return 0;
}


/*

OUTPUT:


Enter no. of student :4


Enter name of student     :omkar

Enter roll no. of student :48

Enter division of student :A

Enter address of student  :Bhausingji_road,near_bhavani_mandap,Kolhapur


Enter name of student     :maitreya

Enter roll no. of student :84

Enter division of student :A

Enter address of student  :paud_road,near_krishna_hospital,Pune


Enter name of student     :yatish

Enter roll no. of student :1

Enter division of student :A

Enter address of student  :near_paud_road,kothrud,Pune


Enter name of student     :shubham

Enter roll no. of student :57

Enter division of student :A

Enter address of student  :near_fc_road,Pune


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :1

Name           Rn   Div  Address

omkar          48   A    Bhausingji_road,near_bhavani_mandap,Kolhapur

maitreya       84   A    paud_road,near_krishna_hospital,Pune

yatish         1    A    near_paud_road,kothrud,Pune

shubham        57   A    near_fc_road,Pune


Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :2

Enter no. of records u want to add :1


Enter name of student     :prasad

Enter roll no. of student :43

Enter division of student :A

Enter address of student  :near_jm_road,Pune


Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :1

Name           Rn   Div  Address

omkar          48   A    Bhausingji_road,near_bhavani_mandap,Kolhapur

maitreya       84   A    paud_road,near_krishna_hospital,Pune

yatish         1    A    near_paud_road,kothrud,Pune

shubham        57   A    near_fc_road,Pune

prasad         43   A    near_jm_road,Pune


Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :3
Enter roll no of record to be modified : 6


Record is not present !!!

Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :3
Enter roll no of record to be modified : 2


Record is not present !!!

Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :3
Enter roll no of record to be modified : 84

1.Name
2.Roll no
3.Division
4.Address
Enter option u want to modify :1
Enter name : abhishek


Do u want to select another option  to modify ? (0/1)  :1

1.Name
2.Roll no
3.Division
4.Address
Enter option u want to modify :3
Enter division : B


Do u want to select another option  to modify ? (0/1)  :0


Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :1

Name           Rn   Div  Address

omkar          48   A    Bhausingji_road,near_bhavani_mandap,Kolhapur

abhishek       84   B    paud_road,near_krishna_hospital,Pune

yatish         1    A    near_paud_road,kothrud,Pune

shubham        57   A    near_fc_road,Pune

prasad         43   A    near_jm_road,Pune


Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :4

Enter roll no. of student whose record u want to search :7


Record is not present !!!

Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :4

Enter roll no. of student whose record u want to search :1

Name           Rn   Div  Address

yatish         1    A    near_paud_road,kothrud,Pune


Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :5
Enter roll no. of student whose record u want to delete : 75


Record is not present !!!

Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :5
Enter roll no. of student whose record u want to delete : 48


Record is deleted

Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :1

Name           Rn   Div  Address

abhishek       84   B    paud_road,near_krishna_hospital,Pune

yatish         1    A    near_paud_road,kothrud,Pune

shubham        57   A    near_fc_road,Pune

prasad         43   A    near_jm_road,Pune


Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :5
Enter roll no. of student whose record u want to delete : 43


Record is deleted

Do u want to select another option ? (0/1)  :1


1.Display record
2.Add record
3.Modify record
4.Search record
5.Delete record

Enter choice :1

Name           Rn   Div  Address

abhishek       84   B    paud_road,near_krishna_hospital,Pune

yatish         1    A    near_paud_road,kothrud,Pune

shubham        57   A    near_fc_road,Pune


Do u want to select another option ? (0/1)  :0


*/
