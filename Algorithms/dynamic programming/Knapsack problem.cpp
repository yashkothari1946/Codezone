#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int topdown[1000][1000];
int knapSack_topdown(int capacity,int wt[],int val[],int n,int index){
  if(topdown[index][capacity]!=-1)return topdown[index][capacity];
  if(index>=n || capacity==0)return 0;
  else if(wt[index]<=capacity){
    return topdown[index][capacity]=max(val[index]+knapSack_topdown(capacity-wt[index],wt,val,n,index+1),knapSack_topdown(capacity,wt,val,n,index+1));
  }else{
    return topdown[index][capacity]=knapSack_topdown(capacity,wt,val,n,index+1);
  }
}

int knapSack_bottom_up(int capacity,int wt[],int val[],int n){
  for(int i=0;i<=n;i++){
    for(int j=0;j<=capacity;j++){
      if(i==0 || j==0)dp[i][j]=0;
      else if(wt[i-1]<=j){
        dp[i][j]=max( val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j] );
      }else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][capacity];
}

int main(){
  int val[] = {60, 105, 120, 40};
    int wt[] = {11, 10, 30, 20};
    int  W = 50;
    memset(dp,-1,sizeof(dp));
    memset(topdown,-1,sizeof(topdown));
    int n = sizeof(val)/sizeof(val[0]);
    printf("Bottom Up Approach : %d\n", knapSack_bottom_up(W, wt, val, n));
    printf("Top Down Approach : %d\n", knapSack_topdown(W, wt, val, n,0));
    return 0;
}
