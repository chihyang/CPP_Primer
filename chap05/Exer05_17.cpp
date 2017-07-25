#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> v1 = {0, 1, 3, 2}, v2 = {0, 1, 1, 2, 3, 5, 8};
    bool match = false;
    auto len = (v1.size() <= v2.size()) ? v1.size() : v2.size();
    decltype(len) i = 0;
    for(; i < len && v1[i] == v2[i]; ++i)
    { /* No operation is needed. */}
    match = !(i < len);
    if(match)
        cout << "v1 and v2 match." << endl;
    else
        cout << "v1 and v2 don't match." << endl;
    return 0;
}
