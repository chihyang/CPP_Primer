#include <set>
#include "Sales_data.h"
using std::multiset;
bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
    return lhs.isbn() < rhs.isbn();
}
int main()
{
    multiset<Sales_data, bool(*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);
    multiset<Sales_data, bool(*)(const Sales_data&, const Sales_data&)>::iterator bookstore_it = bookstore.begin();
    return 0;
}
