//Prefix, Postfix & Infix Expressions
#include <bits/stdc++.h>
using namespace std;
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  } return false;
}
string expToexp(string exp) {
  stack<string> s;
  int length = exp.size();
  int choice;
  cout<<"Enter choice : \n1.Given string is prefix \n2.Given string is postfix\n";
  cin>>choice;
  if(choice == 1){
    for (int i = length - 1; i >= 0; i--) {
      if (isOperator(exp[i])) {
        string op1 = s.top();   s.pop();
        string op2 = s.top();   s.pop();
        string temp = "(" + op1 + exp[i] + op2 + ")";      //prefix to infix  1
        //string temp = op1 + op2 + exp[i];        //prefix to postfix  2
        s.push(temp);
      }
      else {
        s.push(string(1, exp[i]));
      }
    }
  }else{
      for (int i=0; exp[i]!='\0'; i++) {
        if (isOperator(exp[i])) {
            string op1 = s.top();   s.pop();
            string op2 = s.top();   s.pop();
            // string temp = exp[i] + op2 + op1;       //postfix to prefix 3
            string temp = "(" + op2 + exp[i] + op1 + ")" ;  //postfix to infix 4
            s.push(temp);
        }
        else{
               s.push(string(1, exp[i]));
        }
      }
  }
  return s.top();
}

int main() {
  // string exp = "*-A/BC-/AKL";           //prefix
  // string exp = "((A-(B/C))*((A/K)-L))"; //infix
  string exp = "ABC/-AK/L-*";      //postfix
  // cout << "Infix : " << expToexp(exp)<<"\n";       //1
  // cout << "Postfix : " << expToexp(exp)<<"\n";  //2
  // cout << "Prefix : " << expToexp(exp);         //3
  cout << "Infix : " << expToexp(exp);          //4
  return 0;
}
