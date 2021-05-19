#include<stdio.h>
#include<stdlib.h>

/*Bubble sorting*/
void bubble_sort(char a[100][50],int n)
{

   int i,j,k,l;
   char temp[20],b[100][20];

   printf("1.Ascending order\n");
   printf("2.Descending order\n");
   printf("\nEnter prefernce\n");
   scanf("%d",&k);
   printf("\n");
   switch(k)
   {
        case 1:
        printf("\nUnsorted array:");
                   for(l=0;l<n;l++)
                   {
                    strcpy(b[l],a[l]);
                    printf(" %s ",b[l]);
                   }
        for(i=1;i<n;i++)
          {
             for(j=0;j<n-1;j++)
                  {
                     if(strcmp(b[j],b[j+1])>0)
                        {

                            strcpy(temp,b[j]);
                            strcpy(b[j],b[j+1]);
                            strcpy(b[j+1],temp);

                        }
                  }
                   printf("\n\nAfter pass %d :",i);
                   for(l=0;l<n;l++)
                   printf(" %s ",b[l]);
         }
         break;

         case 2:
         printf("\nUnsorted array:");
                   for(l=0;l<n;l++)
                   {
                    strcpy(b[l],a[l]);
                    printf(" %s ",b[l]);
                   }
         for(i=1;i<n;i++)
          {
             for(j=0;j<n-1;j++)
                  {
                     if(strcmp(b[j],b[j+1])<0)
                        {
                            strcpy(temp,b[j]);
                            strcpy(b[j],b[j+1]);
                            strcpy(b[j+1],temp);
                        }
                  }
                  printf("\n\nAfter pass %d :",i);
                   for(l=0;l<n;l++)
                    printf(" %s ",b[l]);
         }
         break;
   }
}

/*Insertion sorting*/
void insertion_sort(char a[100][50],int n)
{
     int k,i,j,min,max,l;
     char temp[20],b[100][50];

     printf("1.Ascending order\n");
     printf("2.Descending order\n");
     printf("\nEnter prefernce\n");
     scanf("%d",&k);
     printf("\n");
     switch(k)
     {
       case 1:
         printf("\nUnsorted array:");

         for(l=0;l<n;l++)
         {
          strcpy(b[l],a[l]);
          printf(" %s ",b[l]);
         }

        for(i=0;i<n-1;i++)
        {
            min=i;
            for(j=i+1;j<n;j++)
            {
             if(strcmp(b[j],b[min])<0)
                min=j;
            }
             strcpy(temp,b[min]);
             strcpy(b[min],b[i]);
             strcpy(b[i],temp);

              printf("\n\nAfter pass %d :",i);
              for(l=0;l<n;l++)
              printf(" %s ",b[l]);
        }
        break;

       case 2:
         printf("\nUnsorted array:");
         for(l=0;l<n;l++)
          {
           strcpy(b[l],a[l]);
           printf(" %s ",b[l]);
          }
        for(i=0;i<n-1;i++)
        {
            max=i;
            for(j=i+1;j<n;j++)
            {
             if(strcmp(b[j],b[max])>0)
                max=j;
            }
             strcpy(temp,b[max]);
             strcpy(b[max],b[i]);
             strcpy(b[i],temp);

              printf("\n\nAfter pass %d :",i);
              for(l=0;l<n;l++)
              printf(" %s ",b[l]);
        }
        break;
     }
}

/*Selection sorting*/
void selection_sort(char a[100][50],int n)
{
    int i,j,l,m;
    char k[20],b[100][50];
     printf("1.Ascending order\n");
     printf("2.Descending order\n");
     printf("\nEnter prefernce\n");
     scanf("%d",&m);
     printf("\n");
     switch(m)
     {
       case 1:
         printf("\nUnsorted array:");
         for(l=0;l<n;l++)
           {
           strcpy(b[l],a[l]);
           printf(" %s ",b[l]);
           }
         for(i=1;i<n;i++)
         {
             strcpy(k,b[i]);
             j=i-1;

             while(strcmp(b[j],k)>0 && j>=0)
             {
                 strcpy(b[j+1],b[j]);
                 j--;
             }
             strcpy(b[j+1],k);

              printf("\n\nAfter pass %d :",i);
              for(l=0;l<n;l++)
              printf(" %s ",b[l]);
         }
       break;

       case 2:
         printf("\nUnsorted array:");
         for(l=0;l<n;l++)
           {
           strcpy(b[l],a[l]);
           printf(" %s ",b[l]);
           }
         for(i=1;i<n;i++)
         {
             strcpy(k,b[i]);
             j=i-1;
             while(strcmp(b[j],k)<0 && j>=0)
             {
                 strcpy(b[j+1],b[j]);
                 j--;
             }
             strcpy(b[j+1],k);
              printf("\n\nAfter pass %d :",i);
              for(l=0;l<n;l++)
              printf(" %s ",b[l]);
         }
       break;
     }
}

/*Binary searching without recursion*/
int binary_search(char a[100][50],int l,int u,char x[20],int flag)
{
   int m;
   while(l<=u)
   {
      m=(l+u)/2;
      printf("\nl=%d  u=%d  m=%d",l,u,m);

      if(strcmp(x,a[m])==0)
      {
         return m;
      }

      if(flag==1)
      {
        if(strcmp(x,a[m])<0)
        u=m-1;

        else
        l=m+1;
      }

      else
      {
         if(strcmp(x,a[m])<0)
         l=m+1;

        else
        u=m-1;
      }

   }
    return -1;

}

/*Binary searching with recursion*/
int binary_searchn(char a[100][50],int l,int u,char x[20])
{
    int m=0;
    if(l<=u)
      {
        m=(l+u)/2;
        printf("\nl=%d  u=%d  m=%d",l,u,m);
        if(strcmp(x,a[m])<0)
            binary_searchn(a,l,m-1,x);
        else if(strcmp(x,a[m])>0)
            binary_searchn(a,m+1,u,x);
        else
            return m;
      }
    else
    {
      return -1;
    }
}


/*main function*/
void main()
{
  int i,n,ch,f,l=0,p,flag=1,t;

  printf("Enter  number of elements:");
  scanf("%d",&n);
  int u=n-1;
  char a[n][50],x[20];
  printf("\nEnter elements:");
  for(i=0;i<n;i++)
  {
      scanf("%s",a[i]);
  }

  do
  {
    printf("\n1.Bubble sorting\n");
    printf("2.Insertion sorting\n");
    printf("3.Selection sorting\n");
    printf("4.binary searching without recursion\n");
    printf("5.binary searching with recursion\n");
    printf("\nEnter your choice\n");
    scanf("%d",&ch);
    printf("\n");

    switch(ch)

    {
       case 1:
       flag=1;
       bubble_sort(a,n);
       break;

       case 2:
       selection_sort(a,n);
       break;

       case 3:
       insertion_sort(a,n);
       break;

       case 4:

       printf("\nEnter element u want to search:");
       scanf("%s",x);
       t=binary_search(a,l,u,x,flag);
       if(t==-1)
         printf("\nElement is not present");
         else
         {
              printf("\nElement is present at position %d",t+1);
         }
       break;

       case 5:
       bubble_sort(a,n);
       printf("\nEnter element u want to search:");
       scanf("%s",x);
       p=binary_searchn(a,l,u,x);
       if(p==-1)
        printf("\nElement is not present");
       else
        printf("\nElement is present at position %d",p+1);
       break;
    }
    printf("\nDo u want to choose another option?  (0/1)\n");
    scanf("%d",&f);
  }
  while(f==1);
}

