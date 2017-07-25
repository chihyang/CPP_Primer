#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::begin;
using std::end;
int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    list<int> il(begin(ia), end(ia));
    vector<int> iv(begin(ia), end(ia));
    auto iter = il.begin();
    while(iter != il.end())
    {
        if(*iter % 2)
            iter = il.erase(iter);
        else
            ++iter;
    }
    for(auto it = iv.begin(); it != iv.end();)
    {
        if(!(*it % 2))
            it = iv.erase(it);
        else
            ++it;
    }
    cout << "list after removing odd elements: ";
    for(const auto &i : il)
        cout << i << " ";
    cout << endl;
    cout << "vector after removing even elements: ";
    for(const auto &i : iv)
        cout << i << " ";
    cout << endl;
    return 0;
}
