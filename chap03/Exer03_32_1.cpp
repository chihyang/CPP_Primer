#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    int array[10], array2[10];
    for(int i = 0; i < 10; ++i)
        array[i] = i;
    for(int i = 0; i < 10; ++i)
        array2[i] = array[i];
    return 0;
}
