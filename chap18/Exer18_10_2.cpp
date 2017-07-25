#include <iostream>
#include "Exer18_09_Sales_data.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
int main()
{
    Sales_data item1, item2, sum;
    while (cin >> item1 >> item2) {
        try {
            sum = item1 + item2;
            cout << sum << endl;
        } catch(const isbn_mismatch &e) {
            cerr << e.what() << ": left isbn(" << e.left
                 << ") right isbn(" << e.right << ")" << endl;
        }
    }
    return 0;
}
