
/*

NAME:Omkar Gurav

ROLL NO.:8048

A business house has several offices in different countries; they want to lease phone lines to connect them with each other and
the phone company charges different rent to connect different pairs of cities. Business house want to connect all its offices with
a minimum total cost. Solve the problem by suggesting appropriate data structures

*/


#include <iostream>
#include <string.h>

using namespace std;

class office
{
    char country[40];

    public:

    void read();
    void display();
    int match(office o);
    void copy1(office o);
};


void office::read()                      //function to accept name of country
{
    cout<<"\nEnter name of country :";
    cin>>country;
}


void office::display()                 //function to display name of country
{
    cout<<country;
}


int office::match(office o)            //function to chechk if name of countries is same
{
    int f;

    f=strcmp(country,o.country);

    if(f==0)
        return 1;
     else
        return 0;

}


void office::copy1(office o)             //function to copy name of country
{
    strcpy(country,o.country);
}


class node
{
    public:

    office o;
    int cost;
    node *next;

    node()
    {
        cost=0;
        next=NULL;
    }
};


class network
{
    node list1[30];
    int n;

    public:

    network()
    {
        n=0;
    }

    void add_office();
    int search1_office(office o1);
    void add_line();
    int check_link(int a,office o2);
    void display_offices();
    void minimum_cost();
};


int network::search1_office(office o1)           //function to search if country is already added or not
{
    int i;

    for(i=0;i<n;i++)
    {
        if(list1[i].o.match(o1))
            return i;
    }

    return -1;
}


void network::add_office()                      //function to add office
{
    office temp;

    temp.read();

    if(search1_office(temp)==-1)
    {
        list1[n++].o.copy1(temp);
        cout<<"\nOffice has been added";
    }

    else
        cout<<"\nOfice has been already added";

}


int network::check_link(int a,office o2)              //function to check if phone line is already present between 2 countries
{
    node *ptr;

    ptr=list1[a].next;

    while(ptr!=NULL)
    {
        if(ptr->o.match(o2))
            return 1;
        ptr=ptr->next;
    }

    return 0;
}


void network::add_line()                //function to add phone lines
{
    int i,s1=0,s2=0,j,cost;
    office country1,country2;
    node *temp,*link;

    cout<<"\nCountry list :";

    for(i=0;i<n;i++)
    {
        cout<<"\n"<<i+1<<".";
        list1[i].o.display();
    }

    country1.read();
    s1=search1_office(country1);

    if(s1!=-1)                              //if country1 is already present in the network
    {
        j=1;

        cout<<"\n\nOther offices in different countries :";

        for(i=0;i<n;i++)
        {
            if(i!=s1)
            {
                cout<<"\n"<<i+1<<".";
                list1[i].o.display();
            }
        }

        country2.read();

        s2=search1_office(country2);

        if(s2!=-1)                                     //if country2 is already present in the network
        {

           if(check_link(s1,country2) == 0)            //if phone line is not present between country1 and country2
           {
              cost=0;

              cout<<"\nEnter the cost of phone line :";
              cin>>cost;

              temp=new node;

              temp->cost=cost;
              temp->o.copy1(country2);
              temp->next=NULL;

              link= &list1[s1];

              while(link->next!=NULL)
                link=link->next;

              link->next=temp;

              temp=new node;

              temp->cost=cost;
              temp->o.copy1(country1);
              temp->next=NULL;

              link= &list1[s2];

              while(link->next!=NULL)
                link=link->next;

              link->next=temp;

              cout<<"\nPhone line is added";
           }

           else
              cout<<"\nPhone line already exist";
        }

         else
            cout<<"\nOffice is not present in the network";

    }

     else
        cout<<"\nOffice is not present in the network";

}


void network::display_offices()            //function to display list of offices
{

	int na=1,i;

	node *temp;

	for(i=0;i<n;i++)
	{
		cout<<"\n\nOffice "<<na++<<":";

		list1[i].o.display();

		temp=list1[i].next;

		cout<<"\nIs connected to:\n";

		if(temp!=NULL)
		{
			while(temp!=NULL)
			{
				cout<<"\n\t";
				temp->o.display();
				cout<<"\tCost :"<<temp->cost;
				temp=temp->next;
			}
		}

		else
			cout<<"No other offices!";
	}
}


void network::minimum_cost()            //function to implement prims algorithm to find out minimum cost of phone lines
{
  int visited[30],start[30],end1[30],end_vertex,i,j,k=0,of1=0,of2=0,min1,total_cost=0;
  node *temp;
  temp=new node;

  for(i=0;i<n;i++)
    visited[i]=0;

  for(i=0;i<n;i++)
  {
     cout<<"\n"<<i+1<<".";
     list1[i].o.display();
  }

  cout<<"\nEnter source office no. :";
  cin>>of1;

  while(of1<1 || of1>n)
  {
      cout<<"\n\nINVALID!!!  ENTER AGAIN :";
      cout<<"\nEnter source office no. :";
      cin>>of1;
  }

  visited[of1-1]=1;

  for(i=0;i<n-1;i++)
  {
      min1=999;

      for(j=0;j<n;j++)
      {
          if(visited[j]==1)               //if office is already visited
          {
              temp=list1[j].next;

              while(temp!=NULL)
              {
                  of2=search1_office(temp->o);

                  if(temp->cost < min1 && visited[of2]!=1)
                  {
                      min1=temp->cost;
                      end_vertex=of2;
                      start[k]=j;
                  }

                  temp=temp->next;
              }
          }
      }

      total_cost+=min1;
      end1[k]=end_vertex;
      visited[end_vertex]=1;
      k++;

  }

   cout<<"\n\nPath of phone line :";

    for(i=0;i<k;i++)
	{
		cout<<i+1<<".";
		list1[start[i]].o.display();
		cout<<"->";
		list1[end1[i]].o.display();
		cout<<endl;
	}

    cout<<"Total Cost : "<<total_cost;

}


int main()
{
    network n;

    int ch,fa,n1,i;

    cout<<"\nEnter no. of offices u want to add :";
    cin>>n1;

    for(i=0;i<n1;i++)
      n.add_office();

    do
    {
        cout<<"\n\n1.Add new office";
        cout<<"\n2.Add phone lines";
        cout<<"\n3.Display offices";
        cout<<"\n4.Minimum cost";
        cout<<"\n\nEnter your choice :";
        cin>>ch;

        switch(ch)

        {
           case 1:

           n.add_office();

           break;


           case 2:

           n.add_line();

           break;


           case 3:

           n.display_offices();

           break;


           case 4:

           n.minimum_cost();

           break;

        }

        cout<<"\n\nDo u want to choose another option ? (0/1) :";
        cin>>fa;
    }

    while(fa==1);

    return 0;
}


/*

OUTPUT:



Enter no. of offices u want to add :6

Enter name of country :a

Office has been added
Enter name of country :b

Office has been added
Enter name of country :a

Ofice has been already added
Enter name of country :c

Office has been added
Enter name of country :d

Office has been added
Enter name of country :e

Office has been added

1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :1

Enter name of country :f

Office has been added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :a


Other offices in different countries :
2.b
3.c
4.d
5.e
6.f
Enter name of country :b

Enter the cost of phone line :16

Phone line is added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :b


Other offices in different countries :
1.a
3.c
4.d
5.e
6.f
Enter name of country :c

Enter the cost of phone line :4

Phone line is added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :c


Other offices in different countries :
1.a
2.b
4.d
5.e
6.f
Enter name of country :d

Enter the cost of phone line :15

Phone line is added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :d


Other offices in different countries :
1.a
2.b
3.c
5.e
6.f
Enter name of country :e

Enter the cost of phone line :18

Phone line is added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :a


Other offices in different countries :
2.b
3.c
4.d
5.e
6.f
Enter name of country :e

Enter the cost of phone line :19

Phone line is added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :a


Other offices in different countries :
2.b
3.c
4.d
5.e
6.f
Enter name of country :f

Enter the cost of phone line :21

Phone line is added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :b


Other offices in different countries :
1.a
3.c
4.d
5.e
6.f
Enter name of country :f

Enter the cost of phone line :11

Phone line is added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :d


Other offices in different countries :
1.a
2.b
3.c
5.e
6.f
Enter name of country :f

Enter the cost of phone line :14

Phone line is added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :e


Other offices in different countries :
1.a
2.b
3.c
4.d
6.f
Enter name of country :f

Enter the cost of phone line :33

Phone line is added

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :2

Country list :
1.a
2.b
3.c
4.d
5.e
6.f
Enter name of country :b


Other offices in different countries :
1.a
3.c
4.d
5.e
6.f
Enter name of country :d

Enter the cost of phone line :6

Phone line is added


Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :3


Office 1:a
Is connected to:

        b       Cost :16
        e       Cost :19
        f       Cost :21

Office 2:b
Is connected to:

        a       Cost :16
        c       Cost :4
        f       Cost :11
        d       Cost :6

Office 3:c
Is connected to:

        b       Cost :4
        d       Cost :15

Office 4:d
Is connected to:

        c       Cost :15
        e       Cost :18
        f       Cost :14
        b       Cost :6

Office 5:e
Is connected to:

        d       Cost :18
        a       Cost :19
        f       Cost :33

Office 6:f
Is connected to:

        a       Cost :21
        b       Cost :11
        d       Cost :14
        e       Cost :33

Do u want to choose another option ? (0/1) :1


1.Add new office
2.Add phone lines
3.Display offices
4.Minimum cost

Enter your choice :4

1.a
2.b
3.c
4.d
5.e
6.f
Enter source office no. :1


Path of phone line :1.a->b
2.b->c
3.b->d
4.b->f
5.d->e
Total Cost : 55

Do u want to choose another option ? (0/1) :0


*/

