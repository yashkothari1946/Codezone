#include<bits/stdc++.h>
using namespace std;
//dynamic programming
int dp[100][100];
int longSub(string s,int i,int j){
  if(dp[i][j]!=-1)return dp[i][j];
  if(i>j)return dp[i][j]=0;
  if(i==j)return dp[i][j]=1;
  else if(i==(j-1) && s[i]==s[j])return dp[i][j]=2;
  else if(s[i]==s[j]){
    return dp[i][j]=longestSub(s,i+1,j-1)+2;
  }else{
      return dp[i][j]=max(longestSub(s,i+1,j),longestSub(s,i,j-1));
  }
}


//recursion
int longestSub(string s,int i,int j){
  if(i>j)return 0;
  if(i==j)return 1;
  else if(i==(j-1) && s[i]==s[j])return 2;
  else if(s[i]==s[j]){
    return longestSub(s,i+1,j-1)+2;
  }else{
      return max(longestSub(s,i+1,j),longestSub(s,i,j-1));
  }
}

int main(){
  string s;
  cin>>s;
  int len = s.length();
  cout<<longestSub(s,0,len-1)<<"\n";
  memset(dp,-1,sizeof(dp));
  cout<<longSub(s,0,len-1)<<"\n";
}
