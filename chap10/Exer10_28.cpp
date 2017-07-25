#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
using std::cout;
using std::endl;
using std::deque;
using std::list;
using std::vector;
using namespace std::placeholders;
void print(const int &i, char c = ' ')
{
    cout << i << c;
}
int main()
{
    vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> ivec2;
    list<int> ilst;
    deque<int> idq;
    copy(ivec.cbegin(), ivec.cend(), back_inserter(ivec2));
    copy(ivec.cbegin(), ivec.cend(), front_inserter(ilst));
    copy(ivec.cbegin(), ivec.cend(), inserter(idq, idq.begin()));
    cout << "ivec, original:\t";
    for_each(ivec.cbegin(), ivec.cend(), bind(print, _1, ' '));
    cout << endl;
    cout << "ivec2, back_inserter:\t";
    for_each(ivec2.cbegin(), ivec2.cend(), bind(print, _1, ' '));
    cout << endl;
    cout << "ilst, front_insert:\t";
    for_each(ilst.cbegin(), ilst.cend(), bind(print, _1, ' '));
    cout << endl;
    cout << "idq, inserter:\t";
    for_each(idq.cbegin(), idq.cend(), bind(print, _1, ' '));
    cout << endl;
    return 0;
}
