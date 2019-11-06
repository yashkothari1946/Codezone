//SINGLY AND DOUBLY LINKED LIST
#include <bits/stdc++.h>
using namespace std;
struct Node {
   int data;
   struct Node *llink; struct Node *rlink;
};typedef struct Node node;
node *start = NULL,*temp,*newnode;

void insert_last(){
  int val;
  cout<<"Enter value : ";cin>>val;
  newnode = (node *)malloc(sizeof(node));
  newnode->data = val;
  temp=start;
  if(start==NULL){
    newnode->llink=NULL; newnode->rlink=NULL;
    start=newnode;
  }else{
    while(temp->rlink!=NULL){
      temp=temp->rlink;
    }
    newnode->llink=temp;  newnode->rlink=temp->rlink;
    temp->rlink=newnode;
  }
}
void insert_left(int position){
  int val; cout<<"Enter value : "; cin>>val;
  newnode = (node *)malloc(sizeof(node));
  newnode->data = val;
  temp=start;
  if(start==NULL){
    newnode->llink=NULL; newnode->rlink=NULL;
    start=newnode;
  }else{
    while(temp->data!=position){
      temp=temp->rlink;
    }
    newnode->rlink=temp; newnode->llink=temp->llink;
    temp->llink->rlink=newnode;
    temp->llink=newnode;
  }
}
void insert_right(int position){
  int val; cout<<"Enter value : "; cin>>val;
  newnode = (node *)malloc(sizeof(node));
  newnode->data = val;
  temp=start;
  if(start==NULL){
    newnode->llink=NULL;  newnode->rlink=NULL;
    start=newnode;
  }else{
    while(temp->data!=position){
      temp=temp->rlink;
    }
    newnode->rlink=temp->rlink;  newnode->llink=temp;
    temp->rlink->llink=newnode;
    temp->rlink=newnode;
  }
}
void display(){
  temp=start;
  while(temp->rlink!=NULL){
    cout<<temp->data<<"-->";
    temp=temp->rlink;
  }cout<<temp->data<<"-->";cout<<"\n";
  while(temp!=NULL){
    cout<<temp->data<<"<--";
    temp=temp->llink;
  }cout<<"\n";
}
void pop(){
  int val; cout<<"Element to be popped : "; cin>>val;
  temp=start;
  while(temp->data!=val){
    temp=temp->rlink;
  }
  if(temp->rlink==NULL && temp->llink==NULL){
    start=NULL;
  }else if(temp->llink==NULL){
    temp->rlink->llink=NULL;
    start=temp->rlink;
  }else if(temp->rlink==NULL){
        temp->llink->rlink=NULL;
  }else{
    temp->rlink->llink=temp->llink;
    temp->llink->rlink=temp->rlink;
  }
}

int main() {
      int choice=1,pos;
      cout<<"Enter choice : \n1.insert_last\n2.insert_left\n3.insert_right\n4.display\n5.pop\n6.exit\n";
      while(choice<=5){
        cin>>choice;
        switch(choice){
          case 1:insert_last();break;
          case 2:cout<<"left of :";cin>>pos;insert_left(pos);break;
          case 3:cout<<"right of :";cin>>pos;insert_right(pos);break;
          case 4:display();break;
          case 5:pop();break;
        }
      }
}
