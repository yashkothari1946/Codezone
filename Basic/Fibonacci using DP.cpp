//FIBONACCI SEQUENCE USING DYNAMIC PROGRAMMING
#include<bits/stdc++.h>
using namespace std;
long long arr[50];
long long fibo(long long n){
  if(n<=1){
    arr[n]=n;
    return arr[n];
  }
  arr[n]=fibo(n-1)+fibo(n-2);
  return arr[n];
}
int main(){
  long long test;
  fibo(50);
  cin>>test;
  cout<<arr[test];
}
