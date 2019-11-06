#include <iostream>
#include <utility>
#include <set>
#include <map>
using namespace std;

int main()
{


    /*
            ______    _______    __________   _______
           |      |   |      |       |        |     |
           |______|   |______|       |        |_____|
           |          |      |       |        |\
           |          |      |   ____|_____   | \
    */
    int check;
    cout << "PAIR" <<endl;
    pair <int, char> p;
    pair <int, char> p1(2, 'b');
    p = make_pair(1, 'a');
    cout << p.first << ' ' <<  p.second << endl;
    cout << p1.first << ' ' << p1.second << endl;

    /*
                _____      ______    ___________
               |           |              |
               |_____      |____          |
                     |     |              |
               ______|     |______        |

    */
    cout << "\n"<<"SET" <<endl;
    set <int> s;
    set <int>::iterator it;
    int a=10,i=0;
    for(i=0;i<5;i++)
    {a--;s.insert(a);}
    a=8;
    s.insert(a);
    for(it = s.begin();it != s.end();++it)
        cout << *it << ' ';
        it=s.find(6);
    cout  << endl;

    /*
                     ______     ______
          |\    /|  |      |   |      |
          | \  / |  |______|   |______|
          |  \/  |  |      |   |
          |      |  |      |   |
    */

    cout<< "\n"<<"MAP"<<endl;
    multimap<char,int> mp;
    multimap<char,int> ::iterator ite;
    mp.insert(pair<char,int> ('a',5));
      mp.insert(pair<char,int> ('a',4));
    ite = mp.begin();
    cout<<  "key= "<< ite->first <<" value= " << ite->second <<endl;
    ite++;
     cout<<  "key= "<< ite->first <<" value= " << ite->second <<endl;
     ite++;
     ite=mp.find('a');
    cout<<  "key= "<< ite->first <<" value= " << ite->second <<endl;
    cout<< mp.count('a')<<endl;




    return 0;
}
