#include "Sales_item.h"
int main()
{
    Sales_item book1;
    Sales_item book2;
    std::cout << "Input two sale items:" << std::endl;
    std::cin >> book1 >> book2;
    std::cout << book1 + book2 << std::endl;
    return 0;
}
