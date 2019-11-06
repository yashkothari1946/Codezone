// BFS & DFS in directed Graph
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[4];
bool visited[4];
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}
queue<int> q;
void BFS(bool visited[],vector<int> adj[]){
  visited[0]=true;
  q.push(0);
  int s=q.front();
  cout<<s<<" ";
  while(!q.empty()){
    for(auto x : adj[s]){
      if(visited[x]==false){
        visited[x]=true;
        cout<<x<<" ";
        q.push(x);
      }
    }
    q.pop();
    s=q.front();
  }
  cout<<"\n";
}
void DFS(int s){
  if(visited[s]==false){
    cout<<s<<" ";visited[s]=true;
    for(auto x : adj[s]){
      if(visited[x]==false){
        DFS(x);
      }
    }
  }
}
int main(){
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 3);
    fill(visited,visited+4,false);
    BFS(visited,adj);
    cout<<"\n";
    fill(visited,visited+4,false);
    DFS(3);
    cout<<"\n";
    return 0;
}
