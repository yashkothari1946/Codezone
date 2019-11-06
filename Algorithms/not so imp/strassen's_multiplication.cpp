#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
ll min(ll a,ll b){
  return a<b?a:b;
}
void split(int **sub,int **arr,int a,int b,int c,int d){
  for(int i=a;i<c;i++){
    for(int j=b;j<d;j++){
      sub[i-a][j-b]=arr[i][j];
    }
  }
}
void join(int **sub,int **arr,int a,int b,int c,int d){
  for(int i=a;i<c;i++){
    for(int j=b;j<d;j++){
      arr[i][j]=sub[i-a][j-b];
    }
  }
}
int** add(int **first,int **second,int n){
  int **sub=new int*[n];
  for(int i=0;i<n;i++){
    sub[i]=new int[n];
    for(int j=0;j<n;j++){
      sub[i][j]=first[i][j]+second[i][j];
    }
  }
  return sub;
}
int** sub(int **first,int **second,int n){
  int **sub=new int*[n];
  for(int i=0;i<n;i++){
    sub[i]=new int[n];
    for(int j=0;j<n;j++){
      sub[i][j]=first[i][j]-second[i][j];
    }
  }
  return sub;
}
int** strassen(int **first,int **second,int n){
  int **ans=new int*[n];
  for(int i=0;i<n;i++){
    ans[i]=new int[n];
    for(int j=0;j<n;j++)
      ans[i][j]=0;
  }
  if(n==1){
    ans[0][0]=first[0][0]*second[0][0];
    return ans;
  }

  int **A11=new int*[n/2];for(int i=0;i<n/2;i++)A11[i]=new int[n/2];
  int **A12=new int*[n/2];for(int i=0;i<n/2;i++)A12[i]=new int[n/2];
  int **A21=new int*[n/2];for(int i=0;i<n/2;i++)A21[i]=new int[n/2];
  int **A22=new int*[n/2];for(int i=0;i<n/2;i++)A22[i]=new int[n/2];
  int **B11=new int*[n/2];for(int i=0;i<n/2;i++)B11[i]=new int[n/2];
  int **B12=new int*[n/2];for(int i=0;i<n/2;i++)B12[i]=new int[n/2];
  int **B21=new int*[n/2];for(int i=0;i<n/2;i++)B21[i]=new int[n/2];
  int **B22=new int*[n/2];for(int i=0;i<n/2;i++)B22[i]=new int[n/2];

  //Order and arrangement should be same
  split(A11,first,0,0,n/2,n/2);
  split(A12,first,0,n/2,n/2,n);
  split(A21,first,n/2,0,n,n/2);
  split(A22,first,n/2,n/2,n,n);
  split(B11,second,0,0,n/2,n/2);
  split(B12,second,0,n/2,n/2,n);
  split(B21,second,n/2,0,n,n/2);
  split(B22,second,n/2,n/2,n,n);

  //Order and arrangement should be same
  int **M1=strassen(add(A11,A22,n/2),add(B11,B22,n/2),n/2);
  int **M2=strassen(add(A21,A22,n/2),B11,n/2);
  int **M3=strassen(A11,sub(B12,B22,n/2),n/2);
  int **M4=strassen(A22,sub(B21,B11,n/2),n/2);
  int **M5=strassen(add(A11,A12,n/2),B22,n/2);
  int **M6=strassen(sub(A21,A11,n/2),add(B11,B12,n/2),n/2);
  int **M7=strassen(sub(A12,A22,n/2),add(B21,B22,n/2),n/2);

  //Order and arrangement should be same
  join(add(sub(add(M1,M4,n/2),M5,n/2),M7,n/2),ans,0,0,n/2,n/2);
  join(add(M3,M5,n/2),ans,0,n/2,n/2,n);
  join(add(M2,M4,n/2),ans,n/2,0,n,n/2);
  join(add(sub(add(M1,M3,n/2),M2,n/2),M6,n/2),ans,n/2,n/2,n,n);

  return ans;
}

int main() {
	fast;
	ll n;
	cin>>n;
  cout<<"First Matric : \n";
  int **arr1=new int*[n];
	for(ll i=0;i<n;i++){
    arr1[i]=new int[n];
    for(int j=0;j<n;j++){
      cin>>arr1[i][j];
    }
  }

  cout<<"Second Matrix : \n";
  int **arr2=new int*[n];
  for(ll i=0;i<n;i++){
    arr2[i]=new int[n];
    for(int j=0;j<n;j++){
      cin>>arr2[i][j];
    }
  }

  int **ans =strassen(arr1,arr2,n);

  cout<<"Final Matrix : \n";
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<ans[i][j]<<" ";
    }cout<<"\n";
  }

	return 0;
}
// 4

// 2 3 1 6
// 4 0 0 2
// 4 2 0 1
// 0 3 5 2

// 3 0 4 3
// 1 2 0 2
// 0 3 1 4
// 5 1 3 2
