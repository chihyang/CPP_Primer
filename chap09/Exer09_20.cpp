#include <iostream>
#include <deque>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::list;
int main()
{
    list<int> nums = {1, 2, 4, 5, 9, 20, 21, 35, 485, 491, 20, 28, 79};
    deque<int> even, odd;
    for(auto iter = nums.begin(); iter != nums.end(); ++iter)
    {
        if(*iter % 2 == 0)
            even.emplace_back(*iter);
        else
            odd.emplace_back(*iter);
    }
    for(auto e : even)
        cout << e << " ";
    cout << endl;
    for(auto o : odd)
        cout << o << " ";
    cout << endl;
    return 0;
}
