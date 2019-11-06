#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void inOrder(struct Node *root){
  stack<Node *> s;
  Node *curr = root;
  while (curr != NULL || s.empty() == false){
      while (curr !=  NULL){
          s.push(curr);
          curr = curr->left;
      }
      curr = s.top();
      s.pop();
      cout << curr->data << " ";
      curr = curr->right;
  }
}

void preorder(struct Node *root){
  stack<Node *> s;
  Node *curr = root;
  while (curr != NULL || s.empty() == false){
      while (curr !=  NULL){
        cout << curr->data << " ";
          s.push(curr);
          curr = curr->left;
      }
      curr = s.top();
      s.pop();
      curr = curr->right;
  }
}

void postorder(struct Node *root){
  if (root == NULL) return;
  stack<Node *> s1, s2;
  s1.push(root);
  Node* node;
  while (!s1.empty()) {
      node = s1.top();
      s1.pop();
      s2.push(node);
      if (node->left)
          s1.push(node->left);
      if (node->right)
          s1.push(node->right);
  }
  while (!s2.empty()) {
      node = s2.top();
      s2.pop();
      cout << node->data << " ";
  }
}

int main(){
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);cout<<"\n";
    preorder(root);cout<<"\n";
    postorder(root);cout<<"\n";
    return 0;
}
