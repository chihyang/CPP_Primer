#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include "Exer16_20_print_iter.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;
int main()
{
    vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<string> dq = { "like", "a", "thunderbolt", "he", "falls" };
    list<string> lst = { "like", "a", "thunderbolt", "he", "falls" };
    string s("Templates");
    print(vec);
    cout << endl;
    print(dq);
    cout << endl;
    print(lst);
    cout << endl;
    print(s);
    cout << endl;
    return 0;
}
