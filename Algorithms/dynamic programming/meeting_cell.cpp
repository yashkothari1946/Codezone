// Iahub starts with workout located at line 1 and column 1. He needs to finish with workout a[n][m].
// After finishing workout a[i][j], he can go to workout a[i + 1][j] or a[i][j + 1].
// Similarly, Iahubina starts with workout a[n][1] and she needs to finish with workout a[1][m].
// After finishing workout from cell a[i][j], she goes to either a[i][j + 1] or a[i - 1][j].
// There is one additional condition for their training.
// They have to meet in exactly one cell of gym. At that cell, none of them will work out.
// They will talk about fast exponentiation (pretty odd small talk) and then both of them will move to the next workout.
// If a workout was done by either Iahub or Iahubina, it counts as total gain.
// Please plan a workout for Iahub and Iahubina such as total gain to be as big as possible. Note, that Iahub and Iahubina can perform workouts with different speed, so the number of cells that they use to reach meet cell may differs.
// input
// 3 3
// 100 100 100
// 100 1 100
// 100 100 100
// output
// 800

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int

int  ways(int **calorie,int n,int m){
  int boystart[n+2][m+2],boyend[n+2][m+2],girlstart[n+2][m+2],girlend[n+2][m+2];
  memset(boystart,0,sizeof(boystart));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      boystart[i][j]=calorie[i-1][j-1]+max(boystart[i-1][j],boystart[i][j-1]);
    }
  }
  memset(boyend,0,sizeof(boyend));
  for(int i=n;i>0;i--){
    for(int j=m;j>0;j--){
      boyend[i][j]=calorie[i-1][j-1]+max(boyend[i+1][j],boyend[i][j+1]);
    }
  }
  memset(girlstart,0,sizeof(girlstart));
  for(int i=n;i>0;i--){
    for(int j=1;j<=m;j++){
      girlstart[i][j]=calorie[i-1][j-1]+max(girlstart[i+1][j],girlstart[i][j-1]);
    }
  }
  memset(girlend,0,sizeof(girlend));
  for(int i=1;i<=n;i++){
    for(int j=m;j>0;j--){
      girlend[i][j]=calorie[i-1][j-1]+max(girlend[i-1][j],girlend[i][j+1]);
    }
  }
  int ans=0;
  for(int i=2;i<n;i++){
    for(int j=2;j<m;j++){
      int ans1=boystart[i-1][j]+boyend[i+1][j] + girlstart[i][j-1]+girlend[i][j+1];
      int ans2=boystart[i][j-1]+boyend[i][j+1] + girlstart[i+1][j]+girlend[i-1][j];
      ans=max(ans,max(ans1,ans2));
    }
  }
  return ans;

}

int main() {
	fast;
  int n,m;
  cin>>n>>m;
  int **calorie=new int*[n];
  for(int i=0;i<n;i++){
    calorie[i]=new int[m];
    for(int j=0;j<m;j++){
      cin>>calorie[i][j];
    }
  }

  cout<<ways(calorie,n,m)<<"\n";
	return 0;
}
