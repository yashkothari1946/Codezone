// link : https://www.spoj.com/problems/MIXTURES/

// Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).
// He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.
// When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.
// Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.
// Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.
//
// Input
// There will be a number of test cases in the input.
// The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.
// The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.
//
// Output
// For each test case, output the minimum amount of smoke.
//
// Example
// Input:
// 2
// 18 19
// 3
// 40 60 20
//
// Output:
// 342
// 2400
//


#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int minsmoke(int color[],int i,int j){
  if(dp[i][j]!=-1)return dp[i][j];
  if(i>=j)return dp[i][j]=0;
  else{
    int minn=INT_MAX;
    for(int k=i;k<j;k++){
      minn=min(minn,minsmoke(color,i,k)+minsmoke(color,k+1,j) + ( (color[k]-color[i-1])%100 )*( (color[j]-color[k])%100 ) );
    }
    return dp[i][j]=minn;
  }
}
int main(){
  int n;
  while(cin>>n){
    int color[n+1];
    color[0]=0;
    for(int i=1;i<=n;i++){cin>>color[i];color[i]+=color[i-1];}
    memset(dp,-1,sizeof(dp));
    cout<<minsmoke(color,1,n)<<"\n";
  }
    return 0;
}
