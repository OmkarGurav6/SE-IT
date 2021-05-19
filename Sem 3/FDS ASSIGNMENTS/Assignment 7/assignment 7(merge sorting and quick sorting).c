#include<stdio.h>


void merge(int a[],int l,int m,int r,int n)
{
  int s1=m-l+1,s2=r-m,i,j,k;
  int L[s1],R[s2];
  static int c;

      for(i=0;i<s1;i++)
      {
        L[i]=a[l+i];
      }

      for(j=0;j<s2;j++)
     {
       R[j]=a[m+1+j];
     }

     i=0;j=0;k=l;
     while(i<s1 && j<s2)
     {
      if(L[i]<=R[j])
      {
        a[k]=L[i];
        i++;
      }
      else
     {
       a[k]=R[j];
       j++;
     }
      k++;
     }

    while(i<s1)
    {
       a[k]=L[i];
       i++;
       k++;
    }

    while(j<s2)
    {
       a[k]=R[j];
       j++;
       k++;
    }

    printf("\n\nAfter pass %d :",c);
    c++;
    for(i=0;i<n;i++)
    {
      printf(" %d ",a[i]);
    }
      printf("\n");
}


void mergesort(int a[],int l,int r,int n)
{
          if(l<r)
        {
          int m=(l+r)/2;

          mergesort(a,l,m,n);
          mergesort(a,m+1,r,n);
          merge(a,l,m,r,n);
        }
        else
            return;
}


int qsort(int a[],int l,int r,int n)
{
    int pivot=a[l],i=l,j=r;
    int temp;
    static int c;
    while(i<j)
    {

        while(a[i]<=pivot && i<r)
        {
          i++;
        }

        while(a[j]>pivot)
        {
          j--;
        }

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }

    }

    temp=a[l];
    a[l]=a[j];
    a[j]=temp;

    printf("\n\nAfter pass %d :",c);
    c++;
    for(i=0;i<n;i++)
    {
      printf(" %d ",a[i]);
    }
      printf("\n");



    return (j);

}

void quicksort(int a[],int l,int r,int n)
{
    if(l<r)
    {
        int p=qsort(a,l,r,n);

        quicksort(a,l,p-1,n);
        quicksort(a,p+1,r,n);

    }
}



int main()
{
  int a[50],i,n,l=0,ch,f;
  printf("Enter  number of elements:");
  scanf("%d",&n);
  int r=n-1;
  printf("\nEnter elements:");
  for(i=0;i<n;i++)
  {
      scanf("%d",&a[i]);
  }

  do
    {
    printf("\n1.Merge sorting with recursion\n");
    printf("2.Quick sorting with recursion\n");
    printf("\nEnter your choice\n");
    scanf("%d",&ch);
    printf("\n");

    switch(ch)

    {

     case 1:
     mergesort(a,l,r,n);
     break;


     case 2:
     quicksort(a,l,r,n);
     printf("\n\nsorted array:");
     for(i=0;i<n;i++)
     {
      printf(" %d ",a[i]);
     }
      printf("\n");
      break;

    }
    printf("\nDo u want to choose other option?  (0/1)");
    scanf("%d",&f);
   }
   while(f==1);

  return 0;
}
