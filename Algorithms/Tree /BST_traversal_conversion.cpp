#include<bits/stdc++.h>
using namespace std;
// Check if a given array can represent Preorder Traversal of Binary Search Tree
// bool canRepresentBST(int pre[], int n) {
//     stack<int> s;
//     int root = INT_MIN;
//     for (int i=0; i<n; i++) {
//         if (pre[i] < root)
//             return false;
//         while (!s.empty() && s.top()<pre[i])
//         {
//             root = s.top();
//             s.pop();
//         }
//         s.push(pre[i]);
//     }
//     return true;
// }

void printin(int pre[],int n,int minval,int maxval,int &ind){
  if(ind==n)return ;
  if(pre[ind]<minval || pre[ind]>maxval)return;
  int index=ind;
  ind++;
  printin(pre,n,minval,pre[index],ind);
  cout<<pre[index]<<" ";
  printin(pre,n,pre[index],maxval,ind);

}

void findInorder(int pre[],int n){
  int minval=INT_MIN,maxval=INT_MAX;
  int ind=0;
  printin(pre,n,minval,maxval,ind);
  cout<<"\n";
}

void printpost(int pre[],int n,int minval,int maxval,int &ind){
  if(ind==n)return ;
  if(pre[ind]<minval || pre[ind]>maxval)return;
  int index=ind;
  ind++;
  printpost(pre,n,minval,pre[index],ind);
  printpost(pre,n,pre[index],maxval,ind);
  cout<<pre[index]<<" ";
}

void findPostOrder(int pre[],int n){
  int minval=INT_MIN,maxval=INT_MAX;
  int ind=0;
  printpost(pre,n,minval,maxval,ind);
  cout<<"\n";
}

int main(){
    int pre[] = { 40, 30, 35, 80, 100 };
    int n = sizeof(pre) / sizeof(pre[0]);
    findPostOrder(pre, n);
    findInorder(pre,n);
    return 0;
}
