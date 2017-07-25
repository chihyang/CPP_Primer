#include <iostream>
#include "Sales_data.h"
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
int main()
{
    Sales_data total(cin);
    if(!total.isbn().empty())
    {
        Sales_data trans;
        while(read(cin, trans))
        {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    return 0;
}
