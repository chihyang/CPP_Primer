#include <iostream>
#include <list>
#include <vector>
using std::list;
using std::vector;
int main()
{
    list<int> lst1 = {2, 4, 6, 8, 9, 11};
    vector<int> v1 = {2, 4, 6, 8, 2};
    vector<int> v2(lst1.begin(), lst1.end());
    if(v1 == v2)
        std::cout << "lst1 == v1" << std::endl;
    else if(v1 < v2)
        std::cout << "lst1 < v1" << std::endl;
    else
        std::cout << "lst1 > v1" << std::endl;
    return 0;
}
