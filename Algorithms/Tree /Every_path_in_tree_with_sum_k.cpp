// link : https://cdnpractice.geeksforgeeks.org/problems/k-sum-paths/1
// A binary tree and a number k are given. Print the count of every path in the tree with sum of the nodes in the path as k.
//
// Input:
// First line consists of T test cases. First line of every test case consists of N, denoting the number of Node is Binary tree. Second line consists of N spaced 3 elements denoting the Parent node, Child Node and a character denoting left or right child. Third line of every test case consists of a integer K.
//
// Output:
// Return the Count of number of paths in tree.
//
// Constraints:
// 1<=T<=20
// 1<=N<=100
//
// Example:
// Input:
// 1
// 4
// 1 3 L 3 2 L 3 -1 R -1 1 R
// 4
// Output:
// 2

#include<bits/stdc++.h>
using namespace std;
// binary tree node
struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void print(vector<int>& v,int i){
  for(int j=i;j<v.size();j++){
    cout<<v[j]<<" ";
  }
  cout<<"\n";
}

void printKUtil(Node *root,vector<int>& v,int k){
  if(!root)return;
  v.push_back(root->data);
  printKUtil(root->left,v,k);
  printKUtil(root->right,v,k);

  int f=0;
  for(int j=v.size()-1;j>=0;j--){
    f+=v[j];
    if(f==k){
      print(v,j);
    }
  }
  v.pop_back();
}

void printKPath(Node *root,int k){
  vector<int> v;
  printKUtil(root,v,k);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printKPath(root, k);

    return 0;
}
