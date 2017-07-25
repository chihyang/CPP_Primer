#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int> v1 = {2, 4, 6, 8, 9, 11};
    vector<int> v2 = {2, 4, 6, 8, 2};
    if(v1 == v2)
        std::cout << "v1 == v2" << std::endl;
    else if(v1 < v2)
        std::cout << "v1 < v2" << std::endl;
    else
        std::cout << "v1 > v2" << std::endl;
    return 0;
}
