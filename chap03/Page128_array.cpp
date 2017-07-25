#include <iostream>
#include <cstddef>
using std::cout;
using std::cin;
using std::endl;
using std::endl;
int main()
{
    constexpr size_t rowCnt = 3, colCnt = 4;
    size_t cnt = 0;
    int ia[rowCnt][colCnt];
    // Warning: in range for, be sure to use reference!
    // Or the program won't compile
    for(auto &row : ia)
        for(auto &col : row)
        {
            col = cnt;
            ++cnt;
        }
    for(auto &row : ia)
    {
        for(auto &col : row)
        {
            cout << col << "\t";
        }
        cout << endl;
    }
    return 0;
}
