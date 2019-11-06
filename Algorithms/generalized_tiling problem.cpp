// Given a floor of size n x m and tiles of size 1 x m.
// The problem is to count the number of ways to tile the given floor using 1 x m tiles.
// A tile can either be placed horizontally or vertically.
// Both n and m are positive integers and 2 < = m.
// Example:
// input 7 4
// output : 5

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
int countWays(int n,int m){
  int count[n+1];
  fill(count,count+n+1,0);
  for(int i=1;i<=n;i++){
    if(i>m){
      count[i]=count[i-1]+count[i-m];
    }else if(i==m){
      count[i]=2;
    }else{
      count[i]=1;
    }
  }
  return count[n];
}

int main() {
	fast;
  int n,m;
  cin>>n>>m;
  cout<<countWays(n,m)<<"\n";
	return 0;
}
