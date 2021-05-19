#include<stdio.h>
#include<stdlib.h>

/*entering elements*/
void accept(int a[],int b)
{
  int i,j;

  printf("\nEnter the elements of set : ");

  for(i=0;i<b;i++)
  {
	scanf("%d",&a[i]);
	for(j=0;j<i;j++)
	{
      if(a[i]==a[j])
		{
          printf("Enter another number : ");
          i--;
          break;
		}
    }
  }
  printf("\n\nThe set is:");
  for(i=0;i<b;i++)
 {
	printf(" %d " ,a[i]);
 }
}

/*union of sets*/
int  unon(int a[],int b[],int i,int j,int c[])
{
    int m,n,flag=0,k=0;

    for(m=0;m<i;m++)
    {
     c[k]=a[m];
     k++;
    }

    for(m=0;m<j;m++)
	{
      flag=0;
      for(n=0;n<i;n++)
		{
          if(b[m]==c[n])
			{
             flag=1;
             break;
			}
		}

      if(flag==0)
      {
       c[k]=b[m];
       k++;
      }
	}

	for(m=0;m<k;m++)
	{
     printf(" %d ",c[m]);
	}
  return 0;
}

/*intersection of sets*/
int intersection(int a[],int b[],int x,int y,int c[])
{
 int i,j,m=0;
 for(i=0;i<x;i++)
 {
  for(j=0;j<y;j++)
	{
     if(a[i]==b[j])
      {
        c[m]=b[j];
        m++;
        break;
      }
	}
 }

 for(i=0;i<m;i++)
 {
  printf(" %d ",c[i]);
 }
 return 0;
}

/*difference of sets*/
int difference(int a[],int b[],int m,int n,int c[])
{
  int i,j,flag,x=0;
  for(i=0;i<m;i++)
 {
	flag=0;
	for(j=0;j<n;j++)
	{
     if(a[i]==b[j])
      {
        flag=1;
        break;
      }
	}

	if(flag==0)
	{
      c[x]=a[i];
      x++;
	}
 }

 for(j=0;j<x;j++)
 {
  printf(" %d ",c[j]);
 }
 printf("\nNumber of elements = %d",x);
 printf("\n");
 return x;
}


void main()
{
  int i,j,k,ch,p,q,r,s,a,m,t;

  printf("\nEnter the size of  set: ");
  scanf("%d",&i);
  while(i<0)
  {
      printf("\nInvalid size!!!Enter again");
      scanf("%d",&i);
  }

  int array1[i],array3[20],array4[20],array5[10],array6[10],array7[10];
  accept(array1,i);

  printf("\nEnter the size of  set: ");
  scanf("%d",&j);
  while(j<0)
  {
      printf("\nInvalid size!!!Enter again");
      printf("\nEnter the size of  set: ");
      scanf("%d",&j);
  }
  int array2[j];
  accept(array2,j);
  printf("\n");

  do
 {
  printf("\nList of operations:");
  printf("\n1.Union ");
  printf("\n2.Intersection ");
  printf("\n3.A-B ");
  printf("\n4.B-A ");
  printf("\n5.Symmetric difference ");
  printf("\n6.Exit ");
  printf("\n\nEnter your choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
   printf("\nUnion of sets is:");
   r=unon(array1,array2,i,j,array3);
   break;

   case 2:
   printf("\nIntersection of sets is:");
   s=intersection(array1,array2,i,j,array4);
   break;

   case 3:
   printf("\nDifference of sets is:");
   p=difference(array1,array2,i,j,array5);
   break;

   case 4:
   printf("\nDifference of sets is:");
   q=difference(array2,array1,j,i,array6);
   break;

   case 5:
   printf("\nSymmetric Difference of sets is:");
   t=unon(array5,array6,p,q,array7);
   break;

   case 6:
   exit(0);
   break;

   default:
   printf("Invalid choice!!!  Choose options between 1-6");

  }
   printf("\nDo u want to perform another operation?(0/1)");
   scanf("%d",&m);
 }
 while(m==1);
}
