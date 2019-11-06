#include<bits/stdc++.h>
using namespace std;

void print_all(string s,int index,string curr){
  if(index==s.length())return;
  cout<<curr<<"\n";
  for(int i=index+1;i<s.length();i++){
    string next=curr+s[i];
    print_all(s,i,next);
  }
  return ;
}

int main(){
  string s;
  cin>>s;
  string curr="";
  print_all(s,-1,curr);
}
