#include <stdio.h>
#include <stdlib.h>


struct node
{
    int no;
    struct node *next;
};



void create(struct node *head)
{
  struct node*temp;
  int i,n;

  printf("\nEnter number of elements:");
  scanf("%d",&n);

  printf("\nEnter elements:");
  scanf("%d",&head->no);
  for(i=0;i<n-1;i++)
  {
        temp=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&temp->no);
        head->next=temp;
        head=head->next;
  }
    head->next=NULL;
}



void display(struct node*head)
{

  while(head->next!=NULL)
  {
      printf("%d\n",head->no);
      head=head->next;
  }
    printf("%d\n",head->no);
}



struct node* insertion_start(struct node* head)
{
    struct node*temp=NULL;

    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter new element:");
    scanf("%d",&temp->no);
    temp->next=head;
    head=temp;

   return head;
}


void insertn(struct node *head)
{
    int val;
    struct node*temp=NULL;

    printf("\nEnter element after which new element has to be inserted:");
    scanf("%d",&val);

        while(head->no!=val)
        {
            head=head->next;
        }

        if(head->no==val)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter new element:");
            scanf("%d",&temp->no);
            temp->next=head->next;
            head->next=temp;
        }
}




struct node* deleter(struct node *head)
{
   int k,val;

   printf("\n1.Delete any node except first node \n");
   printf("2.Delete first node\n");
   printf("\nEnter choice\n");
   scanf("%d",&k);
   printf("\n");
   switch(k)

   {
      case 1:

      printf("\nEnter element :");
      scanf("%d",&val);

      while(head->next->no!=val)
      {

        head=head->next;

      }

       head->next=head->next->next;
      break;

     case 2:

      head=head->next;
      break;

   }

    return head;

}


void display_reverse(struct node *head)
{

  if(head==NULL)
  return;

  else
  display_reverse(head->next);

  printf("%d\n",head->no);

}


struct node* reverse_list(struct node *head)
{
   struct node *prev,*next,*current;

   prev=NULL;
   next=NULL;
   current=head;

   while(current!=NULL)
   {

     next=current->next;
     current->next=prev;
     prev=current;
     current=next;

   }
   head=prev;
   return head;

}

int main()
{
    struct node *head;
    int ch,m;
    head=NULL;
    head=(struct node*)malloc(sizeof(struct node));

    create(head);


  do
  {
    printf("\nList of operations:");
    printf("\n1.Display ");
    printf("\n2.Insertion of node at start");
    printf("\n3.Insertion of node after any intermediate element");
    printf("\n4.Deletion of node ");
    printf("\n5.Display in reverse ");
    printf("\n6.Reverse the list");

    printf("\n\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:

     display(head);
     break;


     case 2:

     head=insertion_start(head);
     display(head);
     break;


     case 3:

     insertn(head);
     display(head);
     break;


     case 4:

     head=deleter(head);
     display(head);
     break;


     case 5:

     display_reverse(head);
     break;


     case 6:
     head=reverse_list(head);
     display(head);
     break;


    default:
    printf("Invalid choice!!!  Choose options between 1-6");

   }

    printf("\nDo u want to perform another operation?(0/1)");
    scanf("%d",&m);

  }

    while(m==1);

    return 0;
}
