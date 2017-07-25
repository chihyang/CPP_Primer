#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data& combine(const Sales_data& rhs);
    string isbn() const { return bookNo; }
};
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
int main()
{
    Sales_data total;
    double price = 0;
    if(cin >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> price)
        {
            trans.revenue = price * trans.units_sold;
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                cout << total.bookNo << " "
                     << total.units_sold << " "
                     << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " "
             << total.units_sold << " "
             << total.revenue << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    return 0;
}
