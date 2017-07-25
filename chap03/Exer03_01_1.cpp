// Page 13, exercise 1.9
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int sum1 = 0;
    // while loop
    int j = 50;
    while(j <= 100)
    {
        sum1 += j;
        j++;
    }
    cout << "The sum of 50 to 100 is:" << sum1 << endl;
    return 0;
}
