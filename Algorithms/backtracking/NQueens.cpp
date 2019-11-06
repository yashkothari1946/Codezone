#include <bits/stdc++.h>
using namespace std;

bool issafe(int **chess,int row,int col,int n){
  for(int i=0;i<col;i++){
    if(chess[row][i]==1)return false;
  }
  int j=col;
  for(int i=row;i>=0 && j>=0;){
    if(chess[i][j]==1){
      return false;
    }
    i--;j--;
  }
  j=col;
  for(int i=row;i<n && j>=0;){
    if(chess[i][j]==1){
      return false;
    }
    i++;j--;
  }
  return true;
}

bool check(int **chess,int row,int col,int n){
  if(col==n)return true;
  for(int i=0;i<n;i++){
    if(issafe(chess,i,col,n)){
      chess[i][col]=1;
      if(check(chess,i,col+1,n)==true){
        return true;
      }
      chess[i][col]=0;
    }
  }
  return false;
}

void solve(int **chess,int n){
  int col=0;
  if(check(chess,0,col,n)){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<chess[i][j]<<" ";
      }cout<<"\n";
    }
  }else{
    cout<<"Not Possible\n";
  }
}

int main(){
    int n;
    cin>>n;
    int **chess=new int*[n];
    for(int i=0;i<n;i++){
      chess[i]=new int[n];
      for(int j=0;j<n;j++){
        chess[i][j]=0;
      }
    }
    solve(chess,n);
    return 0;
}
