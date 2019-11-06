#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct node{
	ll data;
	struct node *llink,*rlink;
};
typedef struct node node;
node* start=NULL;
void getNodeParent(node *root,node **temp,ll d){
	if(root==NULL){
		return ;
	}
	if(root->data==d){
		*temp=root;
	}
	getNodeParent(root->llink,temp,d);
	getNodeParent(root->rlink,temp,d);
}

void create(){
	ll a,b;
	char c;
	cin>>a>>b>>c;
	node *t=(node *)malloc(sizeof(node));
	t->data=b;
	t->llink=NULL;
	t->rlink=NULL;
	node *temp;
	if(start==NULL){
		start=t;
	}else{
			getNodeParent(start,&temp,a);
			if(c=='L'){
				temp->llink=t;
			}else{
				temp->rlink=t;
			}
	}
}

void print(node *nod){
	if(nod!=NULL){
		print(nod->llink);
		cout<<nod->data<<" ";
		print(nod->rlink);
	}
}

int height(node *t){
	if(t==NULL){
		return 0;
	}else{
		return max(height(t->llink),height(t->rlink))+1;
	}
}
void newtree(){
	node *t=(node *)malloc(sizeof(node));
	t->data=1;
	t->llink=NULL;
	t->rlink=NULL;
	start=t;
}

void mirror(node *root){
	if(root!=NULL){
		mirror(root->llink);
		mirror(root->rlink);
		swap(root->rlink,root->llink);
	}
}

int main() {
	ll t;
	cin>>t;
	newtree();
	for(ll i=0;i<t;i++){
		create();
	}
	print(start);
	cout<<"\n";
	mirror(start);
	print(start);
	cout<<"\n";
	cout<<height(start)<<" ";
}
