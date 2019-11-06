#include<bits/stdc++.h>
using namespace std;
int parent[100001];
int size[100001];
void makeset(int i){
    parent[i]=i;
    size[i]=0;
}
int find(int parent[],int i){
    if(parent[i]==i)
        return i;
    return (parent[i]=find(parent,parent[i]));
}

void Union(int parent[],int x,int y){
    
    int xset=find(parent,x);
    int yset=find(parent,y);
    if(xset!=yset){
       if(size[xset]<size[yset])
         swap(xset,yset);
       parent[yset]=xset;
       size[xset]+=size[yset]+1;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int num,rel;
    cin>>num>>rel;
    for(int i=1;i<=num;i++)
        makeset(i);
    int a,b;
    for(int i=0;i<rel;i++){
        cin>>a>>b;
        Union(parent,a,b);
    }
    for(int i=1;i<=num;i++)
        cout<<size[find(parent,i)]<<" ";

}
