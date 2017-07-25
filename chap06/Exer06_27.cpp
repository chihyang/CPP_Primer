#include <iostream>
#include <initializer_list>
using std::cout;
using std::endl;
using std::initializer_list;
int getSum(initializer_list<int> lst)
{
    int sum = 0;
    for(const auto &elem : lst)
        sum += elem;
    return sum;
}
int main()
{
    cout << "sum of 1, 2, 3, 4, 5, 6: ";
    cout << getSum({1, 2, 3, 4, 5, 6}) << endl;
    return 0;
}
