#include <stdio.h>
#include <stdlib.h>

struct student
{
    int rn,marks;
    char name[30],branch[30];
};

 /*creating record*/
 void create(struct student s[50],int n)
 {
  int i;
  FILE *fp;
  fp=fopen("STUDENT","wb");

   if(fp==NULL)
    {
        printf("ERROR");
        exit(0);
    }
   else

  {

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
  fwrite(&s,sizeof(s),1,fp);
  }
       fclose(fp);
 }



void display(struct student s[50],int n)
 {
   FILE *fp;
   fp=fopen("STUDENT","rb");

   if(fp==NULL)
    {
        printf("ERROR");
        exit(0);
    }

    else
    {
        int i;
      printf("....................................Record...................................\n\n");

      for(i=0;i<n;i++)
      {
        fread(&s,sizeof(s),1,fp);
        printf("\n\nName  : %s\n",s[i].name);
        printf("Branch  : %s\n",s[i].branch);
        printf("Roll no.  : %d\n",s[i].rn);
        printf("Marks  : %d\n",s[i].marks);
      }
      fclose(fp);
   }

 }


 void add(struct student s[50],int n)
{
    FILE *fp;
    fp=fopen("STUDENT","wb");
    int b,loc,i;
    if(fp==NULL)
    {
        printf("ERROR");
        exit(0);
    }

    else
    {
      printf("Enter the location where u want to add new record :");
      scanf("%d",&loc);

      for(i=n;i>=loc;i--)
      {
        s[i]=s[i-1];
      }
      printf("\nEnter details to be added at that location[name,branch,roll no,marks]\n");
      scanf("%s%s%d%d",s[loc-1].name,s[loc-1].branch,&s[loc-1].rn,&s[loc-1].marks);

      printf("\n\n\nDisplaying Information:");
      for(i=0;i<n+1;i++)
      {
        printf("\nName: %s ",s[i].name);
        printf("\nBranch  : %s",s[i].branch);
        printf("\nRoll no.: %d",s[i].rn);
        printf("\nMarks: %d\n", s[i].marks);
      }
      fwrite(&s[i],sizeof(struct student),1,fp);

     fclose(fp);
    }
}


void search(struct student s[50],int n)
{
  FILE *fp;
  fp=fopen("STUDENT","rb");

   if(fp==NULL)
    {
        printf("ERROR");
        exit(0);
    }

    else
    {

      int r,i,flag=0;
      printf("\nEnter the roll no you want to search: ");
      scanf("%d",&r);
      while(fread(&s[i],sizeof(struct student),1,fp)==1)
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

    }
    fclose(fp);
}


void modify(struct student s[50],int n)
{
     FILE *fp;
  fp=fopen("STUDENT","rb");

   if(fp==NULL)
    {
        printf("ERROR");
        exit(0);
    }

    else
    {
       int n,i;
       printf("Enter the roll no. whose record u want to modify:");
       scanf("%d",&n);

        while(fread(&s[i],sizeof(struct student),1,fp)==1)
      {
        if(s[i].rn==n)
            {
             printf("\nEnter new roll no:");
             scanf("%d",&s[i].rn);
             printf("\nEnter new name:");
             scanf("%s",s[i].name);
             printf("\nEnter new branch:");
             scanf("%s",s[i].branch);
             printf("\nEnter new marks:");
             scanf("%d",&s[i].marks);
             fwrite(&s[i],sizeof(struct student ),1,fp);

             printf("\n\nName  : %s\n",s[i].name);
             printf("Branch  : %s\n",s[i].branch);
             printf("Roll no.  : %d\n",s[i].rn);
             printf("Marks  : %d\n",s[i].marks);
           }

       else
       printf("\n not found");
     }
    }
     fclose(fp);
}


void delete(struct student s[50],int n)
{
     FILE *fp,*ft;
  fp=fopen("STUDENT","rb");
  ft=fopen("STUDENT 1","wb");
   if(fp==NULL)
    {
        printf("ERROR");
        exit(0);
    }

    else
    {
      int n,i,flag=0;
      printf("Enter the roll no. whose record u want to delete:");
      scanf("%d",&n);

      while(fread(&s[i],sizeof(struct student),1,fp)==1)
      {
        if(s[i].rn==n)
        {
         printf("\nRecord is deleted");
         flag=1;
        }

        else
        {
	    fwrite(&s[i],sizeof(struct student),1,ft);
        }
         if(flag==0)
         printf("\nNot found");
        remove("STUDENT");
	rename("STUDENT 1","STUDENT");

      }

    }
     fclose(fp);
     fclose(ft);
}



void main()
{
    struct student s[50];
    int f,n;
    char ch;
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


}
