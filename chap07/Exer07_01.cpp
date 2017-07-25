#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
struct Sales_data {
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
const string isbn(const Sales_data &item)
{
    return item.bookNo;
}
void combine(Sales_data &item1, const Sales_data &item2)
{
    item1.units_sold += item2.units_sold;
    item1.revenue += item2.revenue;
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
            if(isbn(total) == isbn(trans))
                combine(total, trans);
            else
            {
                cout << total.bookNo << " "
                     << total.units_sold << " "
                     << total.revenue << endl;
                // For object copying, primer has more to say later. For now we
                // just need to know this is somewhat a way to use assignment.
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
