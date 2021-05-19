

/*Problem statement:

3. Create Binary tree and perform following operations:
a. Insert
b. Display
c. Depth of a tree
d. Display leaf-nodes
e. Create a copy of a tree
*/


#include<stdlib.h>
#include<iostream>

using namespace std;


class node
{
  public:

  int data;
  node *left,*right;

  node()
  {
    left=NULL;
    right=NULL;
  }

};


class tree
{

 public:

 node *root,*copyroot;
 int leafc;

 tree()
 {
   root=NULL;
   leafc=0;
 }

 node *insert();
 void display(node *root);
 void postorder(node *root);
 void preorder(node *root);
 void inorder(node *root);
 int depth(node *root);
 void leaf(node *root);
 node *copy1();
 node *cp(node *root);

};


node* tree::insert()
{

  node *temp=new node;
  int f,l;

  cout<<"\nEnter data:";
  cin>>temp->data;

  temp->left=NULL;
  temp->right=NULL;

  if(root==NULL)
  {
     root=temp;
  }

  cout<<"\nDo u want to add data at left side of " <<temp->data<<" :";
  cout<<"\n1.Yes";
  cout<<"\n2.No\n";
  cin>>f;

  if(f==1)
  {
    temp->left=insert();
  }

  else if(f!=1 && f!=2)
  {
    cout<<"\nInvalid choice";
  }


  cout<<"\nDo u want to add data at right side of " <<temp->data<<":";
  cout<<"\n1.Yes";
  cout<<"\n2.No\n";
  cin>>l;

  if(l==1)
  {
    temp->right=insert();
  }

  else if(l!=1 && l!=2)
  {
    cout<<"\nInvalid choice";
  }

  return temp;

}


void tree::display(node *root)
{
  int ch;

  cout<<"\n1.Preorder traversal";
  cout<<"\n2.Postorder traversal";
  cout<<"\n3.Inorder traversal";
  cout<<"\nEnter your choice:";

  cin>>ch;

  switch(ch)
  {

    case 1:

    preorder(root);
    break;


    case 2:

    postorder(root);
    break;


    case 3:

    inorder(root);
    break;

  }

}


void tree::preorder(node *root)
{

  if(root!=NULL)
  {
     cout<<root->data<<"\t";
     preorder(root->left);
     preorder(root->right);
  }

}


void tree::postorder(node *root)
{

  if(root!=NULL)
  {
     postorder(root->left);
     postorder(root->right);
     cout<<root->data<<"\t";
  }

}


void tree::inorder(node *root)
{

  if(root!=NULL)
  {
     inorder(root->left);
     cout<<root->data<<"\t";
     inorder(root->right);
  }

}


int tree::depth(node *root)
{
    int h=0,h1=0;

    if(root==NULL)
    {
        return 0;
    }

    if(root->left==NULL && root->right==NULL)
    {
        return 0;
    }

    h=depth(root->left);
    h1=depth(root->right);

    return ((max(h,h1))+1);

}


void tree::leaf(node *root)
{
    if(root!=NULL)
    {
        if(root->left==NULL && root->right==NULL)
        {
            leafc++;
           cout<<"\n"<<root->data<<endl;
        }

        leaf(root->left);
        leaf(root->right);

    }
}


node* tree::copy1()
{
    copyroot=cp(root);
    return copyroot;
}

node* tree::cp(node *root)
{
    node *temp;

    if(root!=NULL)
    {
        temp=new node;
        temp->left=NULL;
        temp->right=NULL;
        temp=root;
    }

    if(root->left!=NULL)
    {
        temp->left=cp(root->left);
    }

    if(root->right!=NULL)
    {
        temp->right=cp(root->right);
    }

    return temp;
}


int main()
{
  int r,t1,ht;
  tree t;


  do
  {
    cout<<"\n1.Insert data";
    cout<<"\n2.Display";
    cout<<"\n3.Depth of tree";
    cout<<"\n4.Display leaf nodes of tree";
    cout<<"\n5.Copy of tree";
    cout<<"\nEnter choice:";
    cin>>t1;

    switch(t1)

    {
      case 1:

      t.root=t.insert();

      break;

      case 2:

      t.display(t.root);

      break;

      case 3:

      ht=t.depth(t.root);
      cout<<"\nDepth of tree is "<<ht<<endl;

      break;

      case 4:

      cout<<"\nLeaf nodes are :";
      t.leaf(t.root);
      cout<<"\nNo. of leaf nodes is "<<t.leafc<<endl;

      break;

      case 5:

      t.copy1();
      t.display(t.copyroot);

      break;

    }

   cout<<"\nDo u want to choose another option?  (0/1):";
   cin>>r;

  }

  while(r==1);

  return 0;


}
