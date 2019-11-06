//FACTOTAIL USING DYNAMIC PROGRAMMING
#include<bits/stdc++.h>
using namespace std;
long long arr[26];
long long factorial(long long n){
  if(n<1){
    arr[0]=1;
    return arr[n];
  }arr[n]=n*factorial(n-1);
  return arr[n];
}
int main(){
  long long test;
  factorial(25);
  cin>>test;
  cout<<arr[test];
}
