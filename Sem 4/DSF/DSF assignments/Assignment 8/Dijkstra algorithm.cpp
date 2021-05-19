
/*

NAME:Omkar Gurav

ROLL NO.:8048

Represent a given graph using adjacency matrix /adjacency list and
find the shortest path using Dijkstra's algorithm (single source all destination).
*/

#include <iostream>

using namespace std;


class graph                            //class graph
{
    int n,distance[30][30];
    char name[30][30];

    public:

    void getdata();
    void create();
    void dijkstra();
    int select(int dis[],int n,int found[]);

};


void graph::getdata()                                       //function for getting inputs
{
    int i,j;

    cout<<"\n\nEnter no. of cities u want to enter (2 to 30) :";
    cin>>n;

    while(n<=1 || n>30)
    {
       cout<<"\nINVALID!!!  ENTER AGAIN";
       cout<<"\n\nEnter no. of cities u want to enter (2 to 30) :";
       cin>>n;
    }

    for(i=0;i<n;i++)
    {
        cout<<"\nEnter name of city "<<i+1<<" :";
        cin>>name[i];
    }

    for(i=0;i<n;i++)
    {
          for(j=0;j<n;j++)
          {
            distance[i][j]=999;
          }
    }
}


void graph::create()                                 //function to create graph
{
    int i,c,v1,v2,ch,dis;

    do
    {
        cout<<"\nDo u want to represent graph \n1.Directed \n2.Undirected \n";
        cin>>c;
    }
    while(c!=1 && c!=2);

    do
    {
        cout<<"\nDo u want to add path ? (0/1) :";
        cin>>ch;

        if(ch==1)
        {
           for(i=0;i<n;i++)
          {
            cout<<"\n"<<i+1<<"."<<name[i];
          }

          cout<<"\n\nEnter no. of first city :";
          cin>>v1;

         while(v1<=0 || v1>n)
         {
            cout<<"\nINVALID!!!  ENTER AGAIN";
            cout<<"\n\nEnter no. of first city :";
            cin>>v1;
         }

         cout<<"\nEnter no. of second city :";
         cin>>v2;

         while(v2<=0 || v2>n ||v2==v1)
         {
            cout<<"\nINVALID!!!  ENTER AGAIN";
            cout<<"\n\nEnter no. of second city :";
            cin>>v2;
         }

         cout<<"\nEnter distance between cities :";
         cin>>dis;

         while(dis<=0 || dis>999)
         {
             cout<<"\nINVALID!!!  ENTER AGAIN";
             cout<<"\nEnter distance between cities :";
             cin>>dis;
         }

         distance[v1-1][v2-1]=dis;                             //storing distance between 2 cities in matrix

         if(c==2)                                              //for undirected graph
            distance[v2-1][v1-1]=dis;

        }

    }
    while(ch == 1);

}


int graph::select(int dis[],int n,int found[])
{
  int min1=999,i,p=-1;

  for(i=0;i<n;i++)
  {
      if(dis[i]<min1 && found[i]==0)
      {
          min1=dis[i];
          p=i;
      }
  }

  return p;
}


void graph::dijkstra()                                              //function for implementation of dijkstra algorithm
{
   int source,destination,found[n],dis[n],i,j,path[n][n+1],u,x,ch,f;

    for(i=0;i<n;i++)
    {
        cout<<"\n"<<i+1<<"."<<name[i];
    }

   cout<<"\n\nEnter source city :";
   cin>>source;

   while(source<=0 || source>n)
   {
       cout<<"\n\nINVALID!!!  ENTER AGAIN";
       cout<<"\n\nEnter source city :";
       cin>>source;
   }

   for(i=0;i<n;i++)
   {
       found[i]=0;

       dis[i]=distance[source-1][i];

       if(dis[i]!=999)                         //if city is not near source city
       {
           path[i][0]=1;
           path[i][1]=source-1;
       }

       else
        path[i][0]=0;
   }

   found[source-1]=1;
   dis[source-1]=0;

   for(i=0;i<n-2;i++)
   {
      u=select(dis,n,found);

      found[u]=1;

      for(j=0;j<n;j++)                                   //loop to update distance of every city from source city
      {
          if(found[j]==0)
          {
              if(dis[u]+distance[u][j] < dis[j])
				{
					path[j][0]=path[u][0];

					for(x=1;x<=path[u][0];x++)
					 {
						path[j][x]=path[u][x];
					 }

					path[j][++path[j][0]]=u;
					dis[j]=dis[u]+distance[u][j];
				}
          }
      }
   }

  /* for(i=0;i<n;i++)
   {
       for(j=0;j<n;j++)
       {
           cout<<"\t"<<path[i][j];
       }
       cout<<"\n";
   }
  */
     do
      {
        for(i=0;i<n;i++)
        {
           cout<<"\n"<<i+1<<"."<<name[i];
        }

       cout<<"\n\nEnter destination city :";
       cin>>destination;

       while(destination<=0 || destination>n)
       {
         cout<<"\n\nINVALID!!!  ENTER AGAIN";
         cout<<"\n\nEnter destination city :";
         cin>>destination;
       }

       if(path[destination-1][0]!=0)
       {
            cout<<"\nCITY \t DISTANCE \t PATH";
			cout<<"\n\n"<<name[destination-1]<<"\t  "<<dis[destination-1]<<"\t\t  ";

			for(i=1;i<path[destination-1][0];i++)
			{
				cout<<name[path[destination-1][i]]<<"->";
			}

			cout<<name[path[destination-1][i]]<<"->"<<name[destination-1];
       }

       else
        cout<<"\n\nNo path available";

       cout<<"\nDo u want to find distance of another city from "<<name[source-1]<<" ?(0/1) :";
       cin>>f;

      }

      while(f==1);
}


int main()
{
    int fa;

    graph g;
    g.getdata();
    g.create();

    do
    {
      g.dijkstra();

      cout<<"\nDo u want to choose another city as source city ?  (0/1) :";
      cin>>fa;

    }
    while(fa==1);

    return 0;
}


/*

OUTPUT:

CASE 1:



Enter no. of cities u want to enter (2 to 30) :0

INVALID!!!  ENTER AGAIN

Enter no. of cities u want to enter (2 to 30) :-1

INVALID!!!  ENTER AGAIN

Enter no. of cities u want to enter (2 to 30) :1

INVALID!!!  ENTER AGAIN

Enter no. of cities u want to enter (2 to 30) :5

Enter name of city 1 :a

Enter name of city 2 :b

Enter name of city 3 :c

Enter name of city 4 :d

Enter name of city 5 :e

Do u want to represent graph
1.Directed
2.Undirected
2

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :1

Enter no. of second city :2

Enter distance between cities :15

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :2

Enter no. of second city :3

Enter distance between cities :20

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :3

Enter no. of second city :4

Enter distance between cities :25

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :1

Enter no. of second city :5

Enter distance between cities :5

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :2

Enter no. of second city :5

Enter distance between cities :10

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :3

Enter no. of second city :5

Enter distance between cities :9

Do u want to add path ? (0/1) :0

1.a
2.b
3.c
4.d
5.e

Enter source city :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :2

CITY     DISTANCE        PATH

b         15              a->b
Do u want to find distance of another city from a ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :3

CITY     DISTANCE        PATH

c         14              a->e->c
Do u want to find distance of another city from a ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :4

CITY     DISTANCE        PATH

d         39              a->e->c->d
Do u want to find distance of another city from a ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :5

CITY     DISTANCE        PATH

e         5               a->e
Do u want to find distance of another city from a ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :1


No path available
Do u want to find distance of another city from a ?(0/1) :0

Do u want to choose another city as source city ?  (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter source city :3

1.a
2.b
3.c
4.d
5.e

Enter destination city :1

CITY     DISTANCE        PATH

a         14              c->e->a
Do u want to find distance of another city from c ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :2

CITY     DISTANCE        PATH

b         19              c->e->b
Do u want to find distance of another city from c ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :4

CITY     DISTANCE        PATH

d         25              c->d
Do u want to find distance of another city from c ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :5

CITY     DISTANCE        PATH

e         9               c->e
Do u want to find distance of another city from c ?(0/1) :0

Do u want to choose another city as source city ?  (0/1) :0


CASE 2:



Enter no. of cities u want to enter (2 to 30) :5

Enter name of city 1 :a

Enter name of city 2 :b

Enter name of city 3 :c

Enter name of city 4 :d

Enter name of city 5 :e

Do u want to represent graph
1.Directed
2.Undirected
1

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :1

Enter no. of second city :2

Enter distance between cities :10

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :2

Enter no. of second city :4

Enter distance between cities :1

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :1

Enter no. of second city :3

Enter distance between cities :5

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :3

Enter no. of second city :2

Enter distance between cities :3

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :3

Enter no. of second city :5

Enter distance between cities :2

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :5

Enter no. of second city :4

Enter distance between cities :6

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :5

Enter no. of second city :1

Enter distance between cities :2

Do u want to add path ? (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter no. of first city :3

Enter no. of second city :4

Enter distance between cities :9

Do u want to add path ? (0/1) :0

1.a
2.b
3.c
4.d
5.e

Enter source city :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :1


No path available
Do u want to find distance of another city from a ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :2

CITY     DISTANCE        PATH

b         8               a->c->b
Do u want to find distance of another city from a ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :3

CITY     DISTANCE        PATH

c         5               a->c
Do u want to find distance of another city from a ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :4

CITY     DISTANCE        PATH

d         9               a->c->b->d
Do u want to find distance of another city from a ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :5

CITY     DISTANCE        PATH

e         7               a->c->e
Do u want to find distance of another city from a ?(0/1) :0

Do u want to choose another city as source city ?  (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter source city :4

1.a
2.b
3.c
4.d
5.e

Enter destination city :1


No path available
Do u want to find distance of another city from d ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :2


No path available
Do u want to find distance of another city from d ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :3


No path available
Do u want to find distance of another city from d ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :4


No path available
Do u want to find distance of another city from d ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :5


No path available
Do u want to find distance of another city from d ?(0/1) :0

Do u want to choose another city as source city ?  (0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter source city :3

1.a
2.b
3.c
4.d
5.e

Enter destination city :1

CITY     DISTANCE        PATH

a         4               c->e->a
Do u want to find distance of another city from c ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :2

CITY     DISTANCE        PATH

b         3               c->b
Do u want to find distance of another city from c ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :3


No path available
Do u want to find distance of another city from c ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :4

CITY     DISTANCE        PATH

d         4               c->b->d
Do u want to find distance of another city from c ?(0/1) :1

1.a
2.b
3.c
4.d
5.e

Enter destination city :5

CITY     DISTANCE        PATH

e         2               c->e
Do u want to find distance of another city from c ?(0/1) :0

Do u want to choose another city as source city ?  (0/1) :0



*/
