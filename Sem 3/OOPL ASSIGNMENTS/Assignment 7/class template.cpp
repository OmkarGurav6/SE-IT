#include<iostream>
using namespace std;

template<class T>
class matrix
{
  T a[10][10],b[10][10];
  int p,q,i,j,m,n;

  public:
  void accept();
  void display();
  void addition();
  void multiplication();
  void transpose();
  int saddle();

};

template<class T>
void matrix<T>::accept()
{

  cout<<"Enter number of rows and columns of first matrix\n";
  cin>>p>>q;
  cout<<"Enter elements of first matrix\n";

    for(i=0;i<p;i++)
    {
      for(j=0;j<q;j++)
        cin>>a[i][j];
    }

}

template<class T>
void matrix<T>::display()
{

  cout<<"Elements of first matrix\n";

    for(i=0;i<p;i++)
    {
      for(j=0;j<q;j++)
        cout<<" "<<a[i][j];
        cout<<"\n";
    }
    cout<<"\n";

}


template<class T>
void matrix<T>::addition()
{
   cout<<"Enter number of rows and columns of second matrix\n";
   cin>>m>>n;
   cout<<"Enter elements of second matrix\n";

       for(i=0;i<m;i++)
       {
         for(j=0;j<n;j++)
          cin>>b[i][j];
       }


   if(p==m && q==n)

   {
     T c[50][50];
     cout<<"Sum of two matrices is :\n\n";
     for(i=0;i<m;i++)
     {
      for(j=0;j<n;j++)
       {
         c[i][j]=a[i][j]+b[i][j];
         cout<<" "<<c[i][j];
       }
      cout<<"\n";
    }
  }
   else
   cout<<"Addition can not be performed";
}


template<class T>
void matrix<T>::multiplication()
{

  cout<<"Enter number of rows and columns of second matrix\n";
  cin>>m>>n;

  cout<<"Enter elements of second matrix\n";

    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
       cin>>b[i][j];
    }


  if(m==q)
   {
     T c[50][50],sum=0;
     int k;

     cout<<"Multiplication  of two matrices is :\n\n";
     for(i=0;i<p;i++)
     {
         for(j=0;j<n;j++)
         {
           for(k=0;k<m;k++)
            {
              sum+=a[i][k]*b[k][j];
            }
         c[i][j]=sum;
         cout<<" "<<c[i][j];
         sum=0;
        }
      cout<<"\n";
     }
  }
  else
    cout<<"Multiplication can not be performed\n";

}


template<class T>
void matrix<T>::transpose()
{

    if(p==q)
  {
    T trans[50][50];
    for(i=0;i<p;i++)
    {
      for(j=0;j<q;j++)
        {
          trans[i][j]=a[j][i];
        }
    }

   cout<<"Transpose of matrix is :\n";
   for(i=0;i<p;i++)
   {
       for(j=0;j<q;j++)
        {
           cout<<" "<<trans[i][j];
        }
        cout<<"\n";
   }
  }
  else
    cout<<"Transpose can not be determined";

}



template<class T>
int matrix<T>::saddle()
{
  T min;
  int col,i,j,k;

     for(i=0;i<p;i++)
     {
        min=a[i][0];
        col=0;
        for(j=1;j<q;j++)
        {
            if(min>a[i][j])
            {
                min=a[i][j];
                col=j;
            }
        }

        for(k=0;k<p;k++)
            if(min<a[k][col])
            break;

        if(k==p)
        {
           cout<<"\nThe saddle point is "<<min<<" and its positon in matrix is ("<<i<<","<<col<<")";
           return 2;
        }
     }
   return -1;
}


int main()
{
  int ch,f,g,m;
  do
  {
    cout<<"\n1.int type";
    cout<<"\n2.float type";
    cout<<"\nChoose option:";
    cin>>g;

    switch(g)
    {
      case 1:
      matrix<int>m1;
      m1.accept();
      m1.display();

      do
      {
        cout<<"\n1.Addition of two matrices";
        cout<<"\n2.Multiplication of two matrices";
        cout<<"\n3.Transpose of matrix";
        cout<<"\n4.Saddle point of matrix";
        cout<<"\nChoose option:";
        cin>>ch;

       switch(ch)
       {
         case 1:
         m1.addition();
         break;

         case 2:
         m1.multiplication();
         break;

         case 3:
         m1.transpose();
         break;

         case 4:
         m=m1.saddle();
          if(m==-1)
          cout<<"\nSaddle point not found\n";
         break;

       }
        cout<<"\nDo u want to choose other option? (0/1)";
        cin>>f;
     }
     while(f==1);
     break;



     case 2:
     matrix<float>m2;
     m2.accept();
     m2.display();

      do
      {
        cout<<"\n1.Addition of two matrices";
        cout<<"\n2.Multiplication of two matrices";
        cout<<"\n3.Transpose of matrix";
        cout<<"\n4.Saddle point of matrix";
        cout<<"\nChoose option:";
        cin>>ch;

       switch(ch)
       {
         case 1:
         m2.addition();
         break;

         case 2:
         m2.multiplication();
         break;

         case 3:
         m2.transpose();
         break;

         case 4:
         m=m2.saddle();
          if(m==-1)
          cout<<"\nSaddle point not found\n";
         break;
       }
        cout<<"\nDo u want to choose other option? (0/1)";
        cin>>f;
     }
      while(f==1);
      break;
     }
     cout<<"\nDo u want to choose other option? (0/1)";
     cin>>f;
  }
   while(f==1);

  return 0;
}
