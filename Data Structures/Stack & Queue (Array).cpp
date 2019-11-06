//STACK AND QUEUE USING ARRAY
#include<bits/stdc++.h>
using namespace std;
long long qu[10],front,rear;
long long st[10],top;
void st_push(long long num){
  if(top==10){
    printf("Stack full !!\n");
  }else{
    st[top]=num;top++;
  }
}
void st_pop(){
  if(top==0){
    printf("Stack Empty !!\n");
  }else{
    top--;
  }
}
void qu_push(long long num){
  if(rear==10){
    printf("Queue Full !!\n");
  }else{
    qu[rear]=num;rear++;
  }
}
void qu_pop(){
  if(rear==0){
    printf("Queue Empty !!\n");
  }else{
    for(long i=0;i<rear-1;i++){
      qu[i]=qu[i+1];
      rear--;
    }
  }
}
int main(){
  top=0;front=0;rear=0;
  long long test,choice,in;
  cin>>test;
  while(test--){
    cout<<"Choices : \n1.Push\n2.Pop\n"; cin>>choice;
    if(choice == 1){
      cin>>in;
      st_push(in);
      for(int i=0;i<top;i++){
        cout<<"-->"<<st[i];
      }cout<<"\n";
    }
    else{st_pop();}
  }//Similarly check for queue inputs
}
