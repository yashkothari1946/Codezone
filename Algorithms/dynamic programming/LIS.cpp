
// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
int LIS(int seq[],int n){
  int lis[n],maxx=0;
  fill(lis,lis+n,1);
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(seq[i]>seq[j])
      lis[i]=max(lis[i],lis[j]+1);
    }
    maxx=max(maxx,lis[i]);
  }
  for(int i=0;i<n;i++){
    cout<<lis[i]<<" ";
  }cout<<"\n";
  return maxx;
}
int main() {
	fast;
  int n;
  cin>>n;
  int seq[n];
  for(int i=0;i<n;i++){
    cin>>seq[i];
  }
  cout<<LIS(seq,n)<<"\n";

	return 0;
}
