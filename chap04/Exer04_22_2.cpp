// if version
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main()
{
    vector<int> v = {99, 92, 60, 83, 76, 0, 11, 22, 73,  90, 56};
    for(auto p = v.begin(); p != v.end(); ++p)
    {
        if(*p > 90)
            cout << "high pass" << " ";
        if(*p > 75 && *p <= 90)
            cout << "pass" << " ";
        if(*p > 60 && *p <= 75)
            cout << "low pass" << " ";
        if(*p <= 60)
            cout << "fail" << " ";
    }
    cout << endl;
    return 0;
}
