#include <iostream>
#include <vector>
#include "Exer14_34.h"
using std::cout;
using std::endl;
using std::vector;
int main()
{
    FinalGrade fg;
    vector<int> v = {99, 92, 60, 83, 76, 0, 11, 22, 73,  90, 56};
    for(auto p = v.begin(); p != v.end(); ++p)
    {
        cout << "student " << p - v.begin() << ":\t";
        cout << fg(*p > 60, "pass", "fail") << endl;
    }
    return 0;
}
