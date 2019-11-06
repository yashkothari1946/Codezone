//BFS & DFS Tree Traversals
#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  struct node *llink,*rlink;
};typedef struct node node;
node *root=NULL,*newnode;
queue<node*> q;
void BFS(node *r){
    q.push(r);
    while(!q.empty()){
      cout<<q.front()->data<<" ";
      if(q.front()->llink!=NULL)
      q.push(q.front()->llink);
      if(q.front()->rlink!=NULL)
      q.push(q.front()->rlink);
      q.pop();
    }
}
void DFS(node *r){
  if(r==NULL){
    return ;
  }else{
    DFS(r->llink);
    cout<<r->data<<" ";
    DFS(r->rlink);
  }
}
void create(int data){
  newnode=(node *)malloc(sizeof(node));
  newnode->data=data;
  newnode->llink=NULL;
  newnode->rlink=NULL;
}
int main(){
  int elem;
  create(1);root=newnode;
  create(2);root->llink=newnode;
  create(3);root->rlink=newnode;
  create(4);root->llink->llink=newnode;
  create(5);root->llink->rlink=newnode;
  create(6);root->rlink->llink=newnode;
  create(7);root->rlink->rlink=newnode;
  BFS(root);
  cout<<"\n";
  DFS(root);
}
