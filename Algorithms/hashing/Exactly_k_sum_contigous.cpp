//Contigous subarray with sum equal to k

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll max(ll a,ll b){
  return a>b?a:b;
}
ll check(ll arr[],ll n,ll k){
  map<ll,ll> um;
  ll sum=0,maxx=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum==k)maxx=max(maxx,i+1);
    if(um.find(sum-k)!=um.end()){
      maxx=max(maxx,i-um[sum-k]+1);
    }
    um[sum]=i+1;
  }
  return maxx;
}
int main() {
  freopen("testbig.txt","r",stdin);
  ll n,k;
  cin>>n>>k;
  ll arr[n];
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<check(arr,n,k)<<"\n";
}
