// The first line consists of an integer T, the number of test cases.
// For each test case the first line consists of an integer N, the number of activities.
// Then the next N lines contains two integers m and n, the start and end time of each activity.
// You have to find max possible activities that can be performed given that from index l to r he can only do 1 activity.
// Input Constraints
// 1 <= T <=10   1 <= N <= 100000  0 <= start < end <= 1000000
// Example
// Sample Input:
// 3
// 3
// 3 9
// 2 8
// 6 9
// 4
// 1 7
// 5 8
// 7 8
// 1 8
// 6
// 7 9
// 0 10
// 4 5
// 8 9
// 4 10
// 5 7
// Sample Output:
// 1
// 2
// 3


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
  ll t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    int x,y;
    for(int i=0;i<n;i++){
      cin>>x>>y;
      if(x>y)swap(x,y);
      v.push_back(make_pair(y,x));
    }
    sort(v.begin(),v.end());
    int res=1,fin=v[0].first;
    for(int i=1;i<n;i++){
      if(v[i].second>=fin){
        fin=v[i].first;
        res++;
      }
    }
    cout<<res<<"\n";
  }
}
