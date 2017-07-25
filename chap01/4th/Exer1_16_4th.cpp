// Expired: this is an exercise from 4th edition.
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    int lower, upper;
    if(v1 <= v2)
    {
        std::cout << v2 << std::endl;
    }
    else
    {
        std::cout << v1 << std::endl;
    }
    return 0;
}
