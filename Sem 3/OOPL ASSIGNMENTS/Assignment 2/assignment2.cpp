#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class book
{
    char *title,*author,*publisher;
    float *price;
    int *stock;


    public:
    static int suc_transaction;
    static int unsuc_transaction;
    static int total_count;

    book()                                       //default constructor
    {
        title = new char[50];
        author = new char[50];
        publisher = new char[50];
        price = new float;
        stock = new int;
    }

    //function for adding book
    void add()
    {
        cout<<"\nEnter name of book:";
        cin>>title;
        cout<<"\nEnter name of author of book:";
        cin>>author;
        cout<<"\nEnter name of publisher of book:";
        cin>>publisher;
        cout<<"\nEnter price of book:";
        cin>>*price;
        cout<<"\nEnter stock of book:";
        cin>>*stock;
        total_count+=*stock;
    }


    //function to display details
    void display()
    {

      cout<<left<<setw(20)<<title<<left<<setw(20)<<author<<left<<setw(20)<<publisher<<left<<setw(10)<<*price<<left<<setw(10)<<*stock;
      cout<<"\n"<<endl;
    }

    //function for searching book
    int search(char a[])
    {
       if(strcmp(a,title))
        return 0;
       else return 1;
    }

    //function for updating details
    void update_details()
    {
        total_count-=*stock;
        cout<<"\nEnter updated name of book:";
        cin>>title;
        cout<<"\nEnter updated name of author of book";
        cin>>author;
        cout<<"\nEnter updated name of publisher of book:";
        cin>>publisher;
        cout<<"\nEnter updated price of book:";
        cin>>*price;
        cout<<"\nEnter updated stock of book:";
        cin>>*stock;
        total_count+=*stock;
    }

    //function for purchasing book
    void purchase()
    {
      int c;
      cout<<"\nEnter number of copies want to buy:";
      cin>>c;

      if(c<=*stock)
      {
          *stock=*stock-c;
          cout<<"\nBook bought successfully";
          total_count=total_count-c;
          suc_transaction++;
      }
      else
      {
          cout<<"\nRequired number of copies are not available in stock";
          unsuc_transaction++;
      }

    }

    //static function for displaying transaction history
    static void transaction()
    {
        cout<<"\nSuccessful transactions:"<<suc_transaction;
        cout<<"\nUnsuccessful transactions:"<<unsuc_transaction;
    }

};

int book::total_count;
int book::suc_transaction;
int book::unsuc_transaction;

//main function
int main()
{
   book b[50];
   int ch,i=0,f,a;
   char titlebuy[50];

   do
   {
       cout<<"\n1.Add book \n2.Display book details\n3.Update book details \n4.Search book by title \n5.Buy a book \n6.Transaction History\n";
       cout<<"\nEnter choice\n";
       cin>>ch;

       switch(ch)

       {
        case 1:
          b[i].add();
          i++;
          break;

        case 2:
            cout<<left<<setw(20)<<"Title"<<left<<setw(20)<<"Author"<<left<<setw(20)<<"Publisher"<<left<<setw(10)<<"Price"<<left<<setw(10)<<"Stock\n"<<endl;
            for(int j=0;j<i;j++)
                b[j].display();
            break;


        case 3:
            cout << "\nEnter name of book you want to update\n";
            cin >> titlebuy;

            for(a=0;a<i;a++)
                {
                    if(b[a].search(titlebuy))
                  {
                    b[a].update_details();
                    cout<<left<<setw(20)<<"title"<<left<<setw(20)<<"Author"<<left<<setw(20)<<"Publisher"<<left<<setw(10)<<"Price"<<left<<setw(10)<<"Stock";
                    b[a].display();
                    break;
                  }
                }
            if(a==i)
                cout<<"\nBook is not in stock";
            break;


        case 4:
            cout << "\nEnter name of book you want to search\n";
            cin >> titlebuy;

            for(a=0;a<i;a++)
                {
                    if(b[a].search(titlebuy))
                  {
                    cout<<left<<setw(20)<<"title"<<left<<setw(20)<<"Author"<<left<<setw(20)<<"Publisher"<<left<<setw(10)<<"Price"<<left<<setw(10)<<"Stock";
                    b[a].display();
                    break;
                  }
                }
            if(a==i)
                cout<<"\nBook is not in stock";
            break;


        case 5:
            cout << "\nEnter name of book you want to buy\n";
            cin >> titlebuy;

            for(a=0;a<i;a++)
                {
                    if(b[a].search(titlebuy))
                  {
                    b[a].purchase();
                    break;
                  }
                }
            if(a==i)
                cout<<"\nBook is not in stock";
            break;

        case 6:
            cout<<"\nTransaction record\n";
            book::transaction();
            break;
      }
      cout<<"\nDo u want to choose another option? (0/1)";
       cin>>f;
    }
   while(f==1);

   return 0;
}
