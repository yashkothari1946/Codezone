//C++ implementation
#include <bits/stdc++.h>
using namespace std;
//Constructing tree
struct Node {
	int data;
	struct Node *left,*right;
	Node(int el){
		data=el;
		left=NULL;right=NULL;
	}
};
typedef struct Node Node;
Node *root=NULL;

//Constructing tree
void getparent(Node *n,int el,Node **temp){
	if(n==NULL)return;
	if(n->data==el){
		*temp=n;
	}
	getparent(n->left,el,temp);
	getparent(n->right,el,temp);
}

//Constructing tree
void create(){
	int el;
	cin>>el;
	Node *p = new Node(el);
	if(root==NULL){
		root=p;
	}else{
		Node *temp;
		int ch;
		cin>>ch;
		getparent(root,ch,&temp);
		if(temp->left==NULL){
			temp->left=p;
		}
		else{
			temp->right=p;
		}
	}
}
//Inorder traversal of tree
void print(Node *n){
	if(n!=NULL){
		print(n->left);
		cout<<n->data<<" ";
		print(n->right);
	}
}
//Height of tree from nth node
int height(Node *n){
	if(n==NULL)return 0;
	return max( height(n->left),height(n->right) )+1;
}

//Code For calculating max time in seconds when burnt at node with value k
int diameter(Node *n,int el,int *maxx){
	if(n!=NULL ){
		if(n->data==el)return  1;
		else {
			if(diameter(n->left,el,maxx)>0){
				if(*maxx<1+diameter(n->left,el,maxx)+height(n->right) )
								*maxx=1+diameter(n->left,el,maxx)+height(n->right);
				return 1+diameter(n->left,el,maxx);
			}else if(diameter(n->right,el,maxx)>0) {
				if(*maxx<1+diameter(n->right,el,maxx)+height(n->left) )
								*maxx=1+diameter(n->right,el,maxx)+height(n->left);
				return 1+diameter(n->right,el,maxx);
			}
			return 0;
		}
	}
	return 0;
}

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		create();
	}
	print(root);
	cout<<"\n";
	int k;
	cin>>k;
	int maxx=0;
	diameter(root,k,&maxx);
	cout<<"Time taken will be : "<<maxx<<"\n";
}


//It is working fine . I made the tree to make it understandable.
