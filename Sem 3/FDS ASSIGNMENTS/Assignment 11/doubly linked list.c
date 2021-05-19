#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[20];
    int rn,age;

    struct node * prev;
    struct node * next;
};

void create(struct node * head)
{
  int n,i;
  struct node *temp;

  printf("\nEnter number of records u want to enter:");
  scanf("%d",&n);

  printf("\nEnter name:");
  scanf("%s",&head->name);

  printf("\nEnter roll no:");
  scanf("%d",&head->rn);

  printf("\nEnter age:");
  scanf("%d",&head->age);

  for(i=0;i<n-1;i++)
  {
      temp=(struct node*)malloc(sizeof(struct node));

      printf("\nEnter name:");
      scanf("%s",&temp->name);

      printf("\nEnter roll no:");
      scanf("%d",&temp->rn);

      printf("\nEnter age:");
      scanf("%d",&temp->age);

       temp->prev=head;
       temp->next = NULL;
       head->next=temp;
       head=head->next;

  }
  head->next=NULL;

}


void displayf(struct node *head)
{
        while(head != NULL)
        {
            printf("\n\nName     :%s",head->name);
            printf("\nRoll no  :%d",head->rn);
            printf("\nAge      :%d",head->age);

            head=head->next;
        }
}


void displayb(struct node *head)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;

    while(temp->next!= NULL)
    {
            temp=temp->next;
    }

    while (temp!= head)
    {
         printf("\n\nName     :%s",temp->name);
         printf("\nRoll no  :%d",temp->rn);
         printf("\nAge      :%d",temp->age);

        temp= temp->prev;
    }

         printf("\n\nName     :%s",temp->name);
         printf("\nRoll no  :%d",temp->rn);
         printf("\nAge      :%d",temp->age);

}


struct node* insertn(struct node *head)
{
   struct node *temp,*t;
   temp=(struct node*)malloc(sizeof(struct node));
   t=head;
   int ch,r;

   printf("\n1.Insertion before first node");
   printf("\n2.Insertion after any node except last node");
   printf("\n1.Insertion after last node");
   printf("\nChoose the option:");
   scanf("%d",&ch);

   switch(ch)
   {
      case 1:

      printf("\nEnter name:");
      scanf("%s",&temp->name);

      printf("\nEnter roll no:");
      scanf("%d",&temp->rn);

      printf("\nEnter age:");
      scanf("%d",&temp->age);

      temp->prev=NULL;
      temp->next=head;
      head->prev=temp;
      head=temp;
      return head;
      break;


      case 2:

      printf("\nEnter roll no after which u want to add new node:");
      scanf("%d",&r);

      while(head->rn!=r)
      {
          head=head->next;
      }

      if(head->rn==r)
      {
          printf("\nEnter name:");
          scanf("%s",&temp->name);

          printf("\nEnter roll no:");
          scanf("%d",&temp->rn);

          printf("\nEnter age:");
          scanf("%d",&temp->age);

          temp->next=head->next;
          head->next=temp;
          temp->prev=head;
      }

      if (temp->next!= NULL)
        temp->next->prev = temp;
      break;


      case 3:


      printf("\nEnter name:");
      scanf("%s",&temp->name);

      printf("\nEnter roll no:");
      scanf("%d",&temp->rn);

      printf("\nEnter age:");
      scanf("%d",&temp->age);

      while(head->next!=NULL)
      {
          head=head->next;
      }

      temp->prev=head;
      temp->next=NULL;
      head->next=temp;
      break;

   }

   return t;

}


struct node* deletes(struct node *head)
{
  struct node *temp;
  temp=head;
  int r,ch;

   printf("\n1.Delete first node");
   printf("\n2.Delete any node except first and last node");
   printf("\n3.Delete last node");
   printf("\nChoose the option:");
   scanf("%d",&ch);

   switch(ch)
  {
     case 1:

     head->next->prev=NULL;
     head=head->next;
     return head;
     break;

     case 2:

     printf("\nEnter roll no. whose record  u want to delete:");
     scanf("%d",&r);

     while(head->rn!=r)
     {
      head=head->next;
     }

      head->prev->next=head->next;
      head->next->prev=head->prev;
      head->next=NULL;
      head->prev=NULL;
      break;

      case 3:

      while(head->next!=NULL)
      {
          head=head->next;
      }

      head->prev->next=NULL;
      break;

  }

    return temp;

}

struct node* modify(struct node *head)
{
    struct node *temp;
    temp=head;

   int r;

   printf("\nEnter roll no. whose record u want to modify:");
   scanf("%d",&r);

   while(head->rn!=r)
   {
      head=head->next;
   }

   if(head->rn==r)
   {

       printf("\nEnter name:");
       scanf("%s",&head->name);

       printf("\nEnter roll no:");
       scanf("%d",&head->rn);

       printf("\nEnter age:");
       scanf("%d",&head->age);

   }

  return temp;
}



int main()
{
    int m,ch;

    struct node *head;
    head=NULL;

    head=(struct node*)malloc(sizeof(struct node));

    create(head);

    do
  {
    printf("\nList of operations:");
    printf("\n1.Insert a record");
    printf("\n2.Delete a record");
    printf("\n3.Modify a record");
    printf("\n4.Display list forward ");
    printf("\n5.Display list backward ");

    printf("\n\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {

     case 1:

     head=insertn(head);
     displayf(head);
     break;

     case 2:

     head=deletes(head);
     displayf(head);
     break;

     case 3:

     head=modify(head);
     displayf(head);
     break;


     case 4:

     displayf(head);
     break;

     case 5:

     displayb(head);
     break;

    default:
    printf("Invalid choice!!!  Choose options between 1-5");

   }

    printf("\nDo u want to perform another operation?(0/1)");
    scanf("%d",&m);

  }

    while(m==1);
    return 0;
}
