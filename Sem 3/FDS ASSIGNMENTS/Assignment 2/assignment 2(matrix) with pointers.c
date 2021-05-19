#include <stdio.h>
#include<stdlib.H>

 /*entering elements of two matrices*/
 void accept(int *a,int p,int q)
 {

  int i,j;
  printf("Enter elements of first matrix\n");
   {
       for(i=0;i<p;i++)
    {
      for(j=0;j<q;j++)
        scanf("%d",a+i*q+j);
    }
   }
 }


/*addition of two matrices*/
void addition(int *a,int p,int q)
 {
  int m,n,i,j;
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d",&m,&n);
  int *b=(int*)malloc(sizeof(int)*m*n);

   printf("Enter elements of second matrix\n");
   {
       for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        scanf("%d",b+i*n+j);
    }
   }

  if(p==m & q==n)
  {
   int i,j;
   int *c=(int*)malloc(sizeof(int)*m*n);

   printf("Sum of two matrices is :\n\n");
   for(i=0;i<m;i++)
    {
     for(j=0;j<n;j++)
      {
        *(c+i*n+j)=*(a+i*n+j)+*(b+i*n+j);
        printf("%d ",*(c+i*q+j));
      }
     printf("\n");
    }
  }
  else
    printf("Addition can not be performed\n");
 }


/*multiplication of two matrices*/
void multiplication(int *a,int p,int q)
{
  int m,n,i,j;
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d",&m,&n);
  int *b=(int*)malloc(sizeof(int)*m*n);

  printf("Enter elements of second matrix\n");
   {
       for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        scanf("%d",b+i*n+j);
    }
   }

  if(m==q)
   {
     int i,j,k,sum=0;
      int *c=(int*)malloc(sizeof(int)*m*n);
     printf("Multiplication  of two matrices is :\n\n");
     for(i=0;i<p;i++)
      {
         for(j=0;j<n;j++)
         {
           for(k=0;k<m;k++)
            {
              sum+=(*(a+i*n+k)*(*(b+k*n+j)));
            }
         *(c+i*n+j)=sum;
         printf("%d  ",*(c+i*n+j));
         sum=0;
        }
      printf("\n");
     }
  }
  else
    printf("Multiplication can not be performed\n");
}

/*transpose of matrix*/
void transpose(int *a,int p,int q)
{ int i,j;
  if(p==q)
  {
    int i,j;
    int *trans=(int*)malloc(sizeof(int)*p*q);
    for(i=0;i<p;i++)
      {
       for(j=0;j<q;j++)
        {
          *(trans+i*q+j)=*(a+j*q+i);
        }
      }

  printf("Transpose of matrix is :\n");
  for(i=0;i<p;i++)
      {
       for(j=0;j<q;j++)
        {
          printf(" %d ",*(trans+i*q+j));
        }
        printf("\n");
      }
  }
  else
    printf("Transpose can not be determined\n");
}

/*saddle point of matrix*/
int saddlepoint(int *a,int p,int q)
{   int i,j,k,min,col;

   for ( i = 0; i <p; i++ )
      {
        min = *(a+i+0);
        col=0;
         for ( j = 1; j < q; j++ )
           {
             if ( min>*(a+i+j))
               {
                  min =*(a+i+j);
                  col=j;
               }
           }


            for(k=0;k<p;k++)
             if (min <*(a+i+j))
             break;

         if ( k == p )
            {
              printf("\nThe saddle point is %d and its positon in matrix is (%d,%d)\n", min, i,col);
              return 2;
            }
      }

       return -1;
}

/*main function*/
int main()
 {
  int p,q,i,j,f,ch,k;

  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d",&p,&q);
   int *a=(int*)malloc(sizeof(int)*p*q);

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

0     case 2:
     multiplication(a,p,q);
     break;

     case 3:
     transpose(a,p,q);
     break;

     case 4:
     k=saddlepoint(a,p,q);
     if(k==-1)
         printf("\nThe saddle point is not present\n");
     break;

   }
    printf("Do u want to choose another option?(0/1)");
    scanf("%d",&f);
  }
   while(f==1);



  return 0;
 }
