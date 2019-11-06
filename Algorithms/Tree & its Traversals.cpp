//Traversals and Tree
#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  struct node *rlink,*llink;
};
typedef struct node node;
node *root=NULL;
node *temp,*newnode;
void create_node(){
  newnode=(node *)malloc(sizeof(node));
  cout<<"Enter value";
  cin>>newnode->data;
  newnode->rlink=NULL;
  newnode->llink=NULL;
}
void inorder(node *next){
  if(next==NULL)
    return;
  inorder(next->llink);
  cout<<next->data<<" ";
  inorder(next->rlink);
}
void postorder(node *next){
  if(next==NULL)
    return;
  postorder(next->llink);
  postorder(next->rlink);
  cout<<next->data<<" ";
}
void preorder(node *next){
  if(next==NULL)
    return;
  cout<<next->data<<" ";
  preorder(next->llink);
  preorder(next->rlink);
}
int main(){
  int entries,i;
  cin>>entries;
  for(i=1;i<=entries;i++){
    create_node();
    temp=root;
    if(temp==NULL){
      root = newnode;
    }else{
      if(temp->llink==NULL){
        temp->llink=newnode;
      }else if(temp->rlink==NULL){
        temp->rlink=newnode;
      }else{
        temp=temp->llink;
        if(temp->llink==NULL){
          temp->llink=newnode;
        }else if(temp->rlink==NULL){
          temp->rlink=newnode;
        }
      }
    }
  }
  inorder(root);cout<<"\n";
  postorder(root);cout<<"\n";
  preorder(root);cout<<"\n";
}
