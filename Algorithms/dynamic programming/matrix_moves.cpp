// Matrix paths possible to i,j when some cells are blocked.

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int

int  ways(int **matrix,int n,int m){
  int dp[n+1][m+1];memset(dp,0,sizeof(dp));
  dp[0][1]=1;dp[1][0]=1;
  if(matrix[0][0]==-1)return 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(matrix[i-1][j-1]==-1){dp[i][j]=0;continue;}
      dp[i][j]=dp[i-1][j]+dp[i][j-1];
      if(i==1 &&j==1)dp[i][j]=1;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cout<<dp[i][j]<<" ";
    }cout<<"\n";
  }
  return dp[n][m];
}

int main() {
	fast;
  int n,m;
  cin>>n>>m;
  int **matrix=new int*[n];
  for(int i=0;i<n;i++){
    matrix[i]=new int[m];
    for(int j=0;j<m;j++){
      cin>>matrix[i][j];
    }
  }

  cout<<ways(matrix,n,m)<<"\n";
	return 0;
}
