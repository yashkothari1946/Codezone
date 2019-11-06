#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1="Hello World Guys ";
    string s2("Hello World Guys ",13);
    string s3(s1,0,16);
    string s4("I am copied");
    cout <<s1 <<"\n"<< s2 <<"\n"<< s3 << "\n" <<  s4<< "\n" <<endl;

    s1.append(" and i am appended ");                          //append
    s2.assign("I am assigned ");                               //assign
    copy(s4.begin(),s4.end(),s3.begin());                      //copy
    s4.erase(1,3);                                             //erase
    cout <<s1 <<"\n"<< s2 <<"\n"<< s3 << "\n" <<  s4<< "\n" << s1.find("World") <<endl;    //find

    s4.insert(2,"am inserted as well as ");                    //insert
    cout << s4 <<endl;
     return 0;
}
