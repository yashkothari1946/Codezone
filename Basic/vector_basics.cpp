#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout<<"VECTOR\n"<<endl;
    int i=0;
    vector<string> s;
    s.push_back(" Vector");                     //push_back
    s.push_back(" World");
    s.push_back(" Guys");
    s.pop_back();                               //pop_back
    cout << s.at(0) << s.at(1)<< endl;
    cout << s.front() << endl;                  //front
    cout << s.back() << endl;                   //end
    s.insert(s.begin()+2," Guys");              //insert
    for(i=0;i < s.size();i++)
    {cout << s.at(i) ;}                        //at

    return 0;
}
