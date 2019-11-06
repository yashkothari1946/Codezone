// We have to paint n boards of length {A1, A2, .. An}. There are k painters available and each takes 1 unit time to paint
// 1 unit of board. The problem is to find the minimum time to get this job done under the constraints that any painter will
// only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.
// Examples :
// Input : k = 2, A = {10, 10, 10, 10}
// Output : 20.
// Here we can divide the boards into 2 equal sized partitions, so each painter gets 20 units of board and the total time taken is 20.
// Input : k = 2, A = {10, 20, 30, 40}
// Output : 60.
// Here we can divide first 3 boards for one painter and the last board for second painter.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void total_sum(ll block[],ll n,ll *minn,ll *maxx){
  ll sum=0,la=0;
  for(int i=0;i<n;i++){
    sum+=block[i];
    if(la<block[i])la=block[i];
  }
  *minn=la;
  *maxx=sum;
}

ll number_of_workers(ll block[],ll n , ll sum){
  ll curr=0;
  ll workers=1;;
  for(ll i=0;i<n;i++){
    curr+=block[i];
    if(curr>sum){
      curr=block[i];
      workers++;
    }
  }
  return workers;
}

ll painters(ll block[],ll n,ll k){
  ll l,h,mid;
  total_sum(block,n,&l,&h);
  while(l<h){
    mid=(l+h)/2;
    if(number_of_workers(block,n,mid)<=k){
      h=mid;
    }else{
      l=mid+1;
    }
  }
  return l;
}

int main() {
  ll avail_painters,n;
  cin>>n>>avail_painters;
  ll block[n];
  for(int i=0;i<n;i++){
    cin>>block[i];
  }
  cout<<painters(block,n,avail_painters)<<"\n";

}
