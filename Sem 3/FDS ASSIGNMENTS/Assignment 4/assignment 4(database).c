#include<stdio.h>
#include<stdlib.h>


 struct student
 {
  char name[20],branch[20];
  int rn,marks;
 };

 /*creating record*/
 void create(struct student s[50],int n)
 {
  int i;

  for(i=0;i<n;i++)
  {
   printf("\nEnter name of the student:");
   scanf("%s",s[i].name);
   printf("Enter branch of student:");
   scanf("%s",s[i].branch);
   printf("Enter roll no. of student:");
   scanf("%d",&s[i].rn);
   printf("Enter marks of student: ");
   scanf("%d",&s[i].marks);
  }
 }


/*display record*/
 void display(struct student s[50],int n)
 {
  int i;

  printf("....................................Record...................................\n\n");
  for(i=0;i<n;i++)
  {
    printf("\n\nName  : %s\n",s[i].name);
    printf("Branch  : %s\n",s[i].branch);
    printf("Roll no.  : %d\n",s[i].rn);
    printf("Marks  : %d\n",s[i].marks);
  }
 }

/*add record*/
 void add(struct student s[50],int n)
 {
    int i,loc,r;

    printf("Enter the roll no after which u want to add new record :");
    scanf("%d",&r);

    for(i=0;i<n;i++)
    {
        if(r==s[i].rn)
        {
            loc=i+1;
        }
    }

    for(i=n;i>=loc;i--)
    {
        s[i]=s[i-1];
    }

    printf("\nEnter details to be added [name,branch,roll no,marks]\n");
    scanf("%s%s%d%d",s[loc].name,s[loc].branch,&s[loc].rn,&s[loc].marks);

    n=n+1;

    printf("\n\n\nDisplaying Information:");
    for(i=0;i<n;i++)
    {
      printf("\nName: %s ",s[i].name);
      printf("\nBranch  : %s",s[i].branch);
      printf("\nRoll no.: %d",s[i].rn);
      printf("\nMarks: %d\n", s[i].marks);
    }
 }

/*search record*/
 void search(struct student s[50],int n)
 {
    int ch,i,r,flag=0;
    char b[30],m[30];
        printf("\nSelect by which option you want to search");
        printf("\n1.Roll no");
        printf("\n2.Name");
        printf("\n3.Branch");
    printf("\nEnter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:

        printf("\nEnter the roll no you want to search: ");
        scanf("%d",&r);
        for(i=0;i<n;i++)
        {
            if(s[i].rn==r)
            {
                flag=1;
                printf("\n Name: %s",s[i].name);
                printf("\n Branch: %s",s[i].branch);
                printf("\n Roll no :%d",s[i].rn);
                printf("\n Marks :%d\n",s[i].marks);
                break;
            }
        }
        if(flag==0)
        printf("\n not found");
        break;

      case 2:

        printf("\nEnter the name you want to search: ");
        scanf("%s",m);
        for(i=0;i<n;i++)
        {
            if(strcmp(s[i].name,m)==0)
            {
                flag=1;
                printf("\n Name: %s",s[i].name);
                printf("\n Branch: %s",s[i].branch);
                printf("\n Roll no :%d",s[i].rn);
                printf("\n Marks :%d\n",s[i].marks);
                break;
            }
        }
        if(flag==0)
        printf("\n not found");
        break;

      case 3:

        printf("\nEnter the branch you want to search: ");
        scanf("%s",b);
        for(i=0;i<n;i++)
        {
            if(strcmp(s[i].branch,b)==0)
            {
                flag=1;
                printf("\n Name: %s",s[i].name);
                printf("\n Branch: %s",s[i].branch);
                printf("\n Roll no :%d",s[i].rn);
                printf("\n Marks :%d\n",s[i].marks);
                break;
            }
        }
        if(flag==0)
        printf("\n not found");
        break;
    }
 }

/*modify record*/
 void modify(struct student s[50],int n)
 {
     int i,loc,r,ch;

    printf("Enter the roll no of student whose record u want to modify:");
    scanf("%d",&r);

     for(i=0;i<n;i++)
    {
        if(r==s[i].rn)
        {
            loc=i;

             printf("\nSelect data which u want to modify");
        printf("\n1.Roll no");
        printf("\n2.Name");
        printf("\n3.Branch");
        printf("\n4.Marks\n");
    printf("\nEnter your choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:

      printf("\nEnter new roll no:");
      scanf("%d",&s[loc].rn);
      for(i=0;i<n;i++)
     {
      printf("\nName: %s ",s[i].name);
      printf("\nBranch  : %s",s[i].branch);
      printf("\nRoll no.: %d",s[i].rn);
      printf("\nMarks: %d\n", s[i].marks);
     }
      break;

      case 2:

      printf("\nEnter new name:");
      scanf("%s",s[loc].name);
      for(i=0;i<n;i++)
     {
      printf("\nName: %s ",s[i].name);
      printf("\nBranch  : %s",s[i].branch);
      printf("\nRoll no.: %d",s[i].rn);
      printf("\nMarks: %d\n", s[i].marks);
     }
        break;

      case 3:

      printf("\nEnter new branch:");
      scanf("%s",s[loc].branch);
      for(i=0;i<n;i++)
     {
      printf("\nName: %s ",s[i].name);
      printf("\nBranch  : %s",s[i].branch);
      printf("\nRoll no.: %d",s[i].rn);
      printf("\nMarks: %d\n", s[i].marks);
     }
        break;

     case 4:

      printf("\nEnter new marks:");
      scanf("%d",&s[loc].marks);
      for(i=0;i<n;i++)
     {
      printf("\nName: %s ",s[i].name);
      printf("\nBranch  : %s",s[i].branch);
      printf("\nRoll no.: %d",s[i].rn);
      printf("\nMarks: %d\n", s[i].marks);
     }
        break;
    }
    }
    }


 }

/*delete record*/
 void delete(struct student s[50],int n)
 {
     int k,i,r,loc;
    printf("\nEnter roll no of student whose data you want to delete data\n");
    scanf("%d",&r);

    for(i=0;i<n;i++)
    {
        if(r==s[i].rn)
        {
            loc=i;
        }
    }

    for(i=loc;i<+n;i++)
    {
        s[i]=s[i+1];
    }

    n=n-1;

    printf("\n\n\nDisplaying Information:");
    for(i=0;i<n;i++)
    {
     printf("\nName: %s ",s[i].name);
     printf("\nBranch  : %s",s[i].branch);
     printf("\nRoll no.: %d",s[i].rn);
     printf("\nMarks: %d\n", s[i].marks);
    }
 }


/*main function*/
 int main()
 {
  int i,n,ch,f;
  struct student s[100];
  printf("Enter number of students for record\n");
  scanf("%d",&n);
  create(s,n);

  do
  {
   printf("\n1.Display record\n");
   printf("2.Add record\n");
   printf("3.Search record\n");
   printf("4.Modify record\n");
   printf("5.Delete record\n");
   printf("Choose the option\n");
   scanf("%d",&ch);

   switch(ch)
   {
    case 1:
    display(s,n);
    break;

    case 2:
    add(s,n);
    break;

    case 3:
    search(s,n);
    break;

    case 4:
    modify(s,n);
    break;

    case 5:
    delete(s,n);
    break;

   }
  printf("Do u want to choose another operation?(0/1)\n");
  scanf("%d",&f);
  }
  while(f==1);

  return 0;
 }
