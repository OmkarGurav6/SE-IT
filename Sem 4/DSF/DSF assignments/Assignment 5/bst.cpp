

/*
Problem statement:

5. Implement binary search tree and perform following operations:
a. Insert
b. Delete
c. Search
d. Mirror image
e. Display
f. Display level wise

*/


#include <iostream>

using namespace std;


class treenode                             //class for treenode
{
  public:

  int data;
  treenode *left;
  treenode *right;

  treenode()
  {
     left=NULL;
     right=NULL;
  }

};


class tree                                 //class for tree
{
  treenode *root;

  public:

  void insert1(int x);
  void create();
  void inorder(treenode *root);
  void preorder(treenode *root);
  void postorder(treenode *root);
  void inorder();
  void preorder();
  void postorder();
  int search1(int x);
  void delete1(int x);
  void display_level();
  treenode* copy1(treenode *root);
  void mirror(tree t);

  tree()
  {
      root=NULL;
  }

};


class queue1                         //class for queue
{
   public:

   treenode *a[30];
   int f,r;

   queue1()
   {
       f=-1;
       r=-1;
   }

   void enqueue(treenode *x);
   treenode* dequeue();

};

void queue1::enqueue(treenode *x)               //function to insert node in queue
{
  if(r==-1)
     r=f=0;

  else
    r=r+1;

  a[r]=x;
}

treenode* queue1::dequeue()                 //function to remove data from queue
{
    treenode *temp=a[f];

    if(r==-1)
        return 0;

    else
    if(r==f)
        r=f=-1;

    else
        f=f+1;

    return temp;

}


void tree::display_level()
{
   queue1 q1;

   treenode *t1,*t=root;

   if(t==NULL)
    return ;

   q1.enqueue(t);

   while(q1.r!=-1)
   {
      t1=q1.dequeue();
       cout<<"\t"<<t1->data;

      if(t1->left!=NULL)
        q1.enqueue(t1->left);

       if(t1->right!=NULL)
        q1.enqueue(t1->right);
   }
}

void tree::create()                     //function to create binary search tree
{
  int i,n,x;

  cout<<"\nEnter number of elements u want to enter:";
  cin>>n;

  cout<<"\nEnter data row-wise";

  for(i=0;i<n;i++)
  {
    cout<<"\nEnter data :";
    cin>>x;

    insert1(x);

  }
}


void tree::insert1(int x)              //function to insert data in BST
{
    treenode *temp,*head,*p;

    temp=new treenode;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL)
    {
       root=temp;
    }

    else
    {
        head=root;

        while(head!=NULL)                        //loop for checking if data is already present
        {
            p=head;

            if(x < head->data)
                head=head->left;

            else if(x > head->data)
                  head=head->right;
           else
             break;
        }

        if(head==p)
          cout<<"\nData already present";

        else if(x < p->data)
            p->left=temp;

        else
           p->right=temp;
    }
}


void tree::inorder()
{
  inorder(root);
}


void tree::inorder(treenode *root)              //function for inorder traversal of BST
{

  if(root!=NULL)
  {
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
  }

}


void tree::preorder()
{
  preorder(root);
}


void tree::preorder(treenode *root)             //function for preorder traversal of BST
{
  if(root!=NULL)
  {
     cout<<root->data<<"\t";
     preorder(root->left);
     preorder(root->right);
  }

}


void tree::postorder()
{
  postorder(root);
}


void tree::postorder(treenode *root)            //function for postorder traversal of BST
{
  if(root!=NULL)
  {
     postorder(root->left);
     postorder(root->right);
     cout<<root->data<<"\t";
  }

}


int tree::search1(int x)                       //function to search data
{
    treenode *k;
    k=root;

    while(k!=NULL)
    {
        if(k->data==x)
            return 1;
        else
            if(k->data < x)
            k=k->right;
        else
            k=k->left;
    }

    return 0;
}


void tree::delete1(int x)                     //function to delelte data
{
    treenode *T,*p1,*parent;
     int f=0,data;

    T=root;

    while(T!=NULL)                            //loop for searching data
    {
        if(T->data == x)
        {
            f=1;
             break;
        }

        else
        if(T->data < x)
        {
            parent=T;
            T=T->right;
        }

        else
        if(T->data > x)
        {
             parent=T;
             T=T->left;
        }
    }

    if(f==0)
    {
         cout<<"\nData is not present in BST";
            return;
    }

    if(T->left==NULL && T->right==NULL)              //deleting leaf node
    {
        if(T==root)
            root=NULL;

        else
        {
            if(T==parent->left)                     //if node is left child of parent
              parent->left=NULL;
            else
              parent->right=NULL;
        }
       delete T;
    }

    else if(T->left==NULL)                      //deleting node of degree 1 when there is no left child
    {
        if(T==root)
            root=root->right;

        else
        {
            if(parent->right==T)                 //if node of degree 1 is right child of parent
              parent->right=T->right;
            else
              parent->left=T->right;
        }
        delete T;
    }

     else if(T->right==NULL)                      //deleting node of degree 1 when there is no right child
    {
        if(T==root)
            root=root->left;

        else
        {
            if(parent->right==T)                 //if node of degree 1 is right child of parent
              parent->right=T->left;
            else
              parent->left=T->left;
        }
        delete T;
    }

    else                                      //deleting node of degree 2
    {
        p1=T->right;

        while(p1->left!=NULL)                  //loop for searching most left node of right subtree of deleting node
        {
            parent=p1;
            p1=p1->left;
        }

        data=p1->data;

        if(parent==T)                        //if right child of deleting node doesn't have left child
        {
            if(p1->right==NULL)
            {
                parent->right=NULL;
                delete p1;                  //Here p1 is right child of deleting node
            }

            else
            {
                parent->right=p1->right;
                delete p1;
            }
        }

        else
        if(p1->right==NULL)                 //if right child of deleting node doesn't have right child
        {
            parent->left=NULL;
            delete p1;                      //Here p1 is left most node of right subtree
        }

        else
        {
            parent->left=p1->right;
            delete p1;
        }
        T->data=data;
    }
    cout<<"\nData is deleted";
}


treenode* tree::copy1(treenode *rt)
{
    treenode *t=new treenode;

    t->data=rt->data;

    if(rt->left!=NULL)
        t->left=copy1(rt->left);

    if(rt->right!=NULL)
        t->right=copy1(rt->right);

    return t;
}


void tree::mirror(tree t)
{
    treenode *T,*temp;

    queue1 q;

    root=copy1(t.root);
    if(root!=NULL)
        q.enqueue(root);

    while(q.r!=-1)
    {
        T=q.dequeue();
        temp=T->left;
        T->left=T->right;
        T->right=temp;

        if(T->left!=NULL)
            q.enqueue(T->left);
        if(T->right!=NULL)
            q.enqueue(T->right);

    }
    t.root=NULL;
}


int main()
{
    tree t1,m;

    int f,ch,x;
    t1.create();

    do
    {
      cout<<"\n1.Insert";
      cout<<"\n2.Delete";
      cout<<"\n3.Search";
      cout<<"\n4.Mirror image";
      cout<<"\n5.Display";
      cout<<"\n6.Display levelwise";
      cout<<"\nEnter your choice :";
      cin>>ch;

     switch(ch)

     {

      case 1:

      cout<<"\nEnter data u want to insert:";
      cin>>x;
      t1.insert1(x);


      break;


      case 2:

      cout<<"\nEnter data u want to delete:";
      cin>>x;
      t1.delete1(x);

      break;


      case 3:

      int c;

      cout<<"\nEnter data u want to search:";
      cin>>x;

      c=t1.search1(x);

      if(c==0)
        cout<<"\nData is not present in binary search tree";
      else
        cout<<"\nData is found";

      break;


      case 4:

      m.mirror(t1);
      cout<<"\n1.Inorder traversal:\n";
      m.inorder();

      cout<<"\n1.Preorder traversal:\n";
      m.preorder();

      cout<<"\n1.Postorder traversal:\n";
      m.postorder();

      break;


      case 5:

      cout<<"\n1.Inorder traversal:\n";
      t1.inorder();

      cout<<"\n1.Preorder traversal:\n";
      t1.preorder();

      cout<<"\n1.Postorder traversal:\n";
      t1.postorder();

      break;


      case 6:

      t1.display_level();

      break;

     }

    cout<<"\nDo u want to choose another option?  (0/1)";
    cin>>f;

    }

    while(f==1);


    return 0;
}


