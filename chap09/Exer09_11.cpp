#include <iostream>
#include <vector>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;

int main()
{
    list<int> li1{3, 6, 4, 5, 9};
    vector<int> vi1{8, 9, 10, 1, 2};
    vector<double> vd1(li1.begin(), li1.end());
    vector<double> vd2(vi1.begin(), vi1.end());
    for(auto d : vd1)
        cout << d << " ";
    cout << endl;
    for(auto d : vd2)
        cout << d << " ";
    cout << endl;
    return 0;
}
