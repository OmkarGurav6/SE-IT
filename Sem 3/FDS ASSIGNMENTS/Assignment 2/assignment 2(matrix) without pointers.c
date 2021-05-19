#include <stdio.h>
#include<stdlib.H>

 /*entering elements of two matrices*/
 void accept(int a[10][10],int p,int q)
 {
  int i,j;
  printf("Enter elements of first matrix\n");
   {
       for(i=0;i<p;i++)
    {
      for(j=0;j<q;j++)
        scanf("%d",&a[i][j]);
    }
   }
 }


/*addition of two matrices*/
void addition(int a[10][10],int p,int q)
 {
  int m,n,i,j,b[10][10];
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d",&m,&n);

  printf("Enter elements of second matrix\n");
   {
       for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        scanf("%d",&b[i][j]);
    }
   }

  if(p==m & q==n)
  {
   int c[10][10],i,j;
   printf("Sum of two matrices is :\n\n");
   for(i=0;i<m;i++)
    {
     for(j=0;j<n;j++)
      {
        c[i][j]=a[i][j]+b[i][j];
        printf("%d ",c[i][j]);
      }
     printf("\n");
    }
  }
  else
    printf("Addition can not be performed");
 }


/*multiplication of two matrices*/
void multiplication(int a[10][10],int p,int q)
{
  int m,n,i,j,b[10][10];
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d",&m,&n);

  printf("Enter elements of second matrix\n");
   {
       for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        scanf("%d",&b[i][j]);
    }
   }

  if(m==q)
   {
     int c[10][10],i,j,k,sum=0;
     printf("Multiplication  of two matrices is :\n\n");
     for(i=0;i<p;i++)
      {
         for(j=0;j<n;j++)
         {
           for(k=0;k<m;k++)
            {
              sum+=a[i][k]*b[k][j];
            }
         c[i][j]=sum;
         printf("%d  ",c[i][j]);
         sum=0;
        }
      printf("\n");
     }
  }
  else
    printf("Multiplication can not be performed\n");
}

/*transpose of matrix*/
void transpose(int a[10][10],int p,int q)
{ int i,j;
  if(p==q)
  {
    int trans[10][10],i,j;
    for(i=0;i<p;i++)
      {
       for(j=0;j<q;j++)
        {
          trans[i][j]=a[j][i];
        }
      }

  printf("Transpose of matrix is :\n");
  for(i=0;i<p;i++)
      {
       for(j=0;j<q;j++)
        {
          printf(" %d ",trans[i][j]);
        }
        printf("\n");
      }
  }
  else
    printf("Transpose can not be determined");
}

/*saddle point of matrix*/
int saddlepoint(int a[10][10],int p,int q)
{   int min,col,i,j,k;

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
           printf("\nThe saddle point is %d and its positon in matrix is (%d,%d)\n", min,i,col);
           return 2;
        }
     }
   return -1;
}

/*main function*/
int main()
 {
  int p,q,i,j,f,a[10][10],m,ch;

  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d",&p,&q);

  accept(a,p,q);
  do
  {
    printf("\n1.Addition\n");
    printf("2.Multiplication\n");
    printf("3.Transpose\n");
    printf("4.Saddle point\n\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);

   switch(ch)
   {
     case 1:
     addition(a,p,q);
     break;

     case 2:
     multiplication(a,p,q);
     break;

     case 3:
     transpose(a,p,q);
     break;

     case 4:
     m=saddlepoint(a,p,q);
     if(m==-1)
        printf("\nSaddle point not found\n");
     break;

   }
    printf("Do u want to choose another option?(0/1)");
    scanf("%d",&f);
  }
   while(f==1);



  return 0;
 }
