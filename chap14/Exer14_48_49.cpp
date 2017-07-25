#include <iostream>
#include "Exer14_48_49_Book.h"
int main()
{
    Book book1("Of Human Bondage", "W.Somerset Maugham", "978-0-553-21392-8");
    Book book2;
    if(book1)
        std::cout << "True" << std::endl;
    if(book2)
        std::cout << "True" << std::endl;
    bool bk = static_cast<bool>(book2); // meaningless conversion
    return 0;
}
