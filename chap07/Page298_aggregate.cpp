#include "Exer07_49_Sales_data.h"
struct Data {
    Sales_data sdata;
};
int main()
{
    // Even if the member is class-type, as long as we provide an argument
    // corresponding to a construct, it's okay. There is an implicit class type
    // conversion(see page 294).
    Data val = {string("978-0590353403")};
    return 0;
}
