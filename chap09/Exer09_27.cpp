#include <iostream>
#include <forward_list>
using std::cout;
using std::endl;
using std::forward_list;
int main()
{
    forward_list<int> flst = { 12, 73, 35, 13, 65, 86, 0 };
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while(curr != flst.end())
    {
        if(*curr % 2)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }
    for(const auto &ele : flst) // output the remaining elements
        cout << ele << " ";
    cout << endl;
    return 0;
}
