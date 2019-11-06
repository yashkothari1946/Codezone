#include <iostream>
#include <list>
using namespace std;

int main()
{
    cout<<"LIST\n"<<endl;
    list<int> l;
    l.push_back(2);
    l.push_back(8);
    l.push_back(16);
    l.push_back(32);

    l.insert(++l.begin(),2,4);
                                  //insert
    for(list<int>::iterator it=l.begin();it!=l.end() ;it++)          //method 1 of printing a list
     cout << *it << " ";

    l.remove(4);
    cout << "\nI have removed both 4's by reverse()" <<endl;
    cout<<"reversed list" << endl;                                 //reverse
    l.reverse();
    for(list<int>::iterator it=l.begin();it!=l.end() ;it++)
    cout << *it << " ";


    return 0;
}
