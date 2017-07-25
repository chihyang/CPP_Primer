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
    Sales_data& combine(const Sales_data& rhs);
    string isbn() const { return bookNo; }
    double avg_price() const;
};
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
double Sales_data::avg_price() const
{
    if(units_sold != 0)
        return revenue / units_sold;
    else
        return revenue;
}
// Why does the book use an ostream reference as return value rather than void?
// 'Cause only in this way can user have a better manipulation of the format.
ostream& print(ostream& os, const Sales_data& item)
{
    os << item.bookNo << " "
       << item.units_sold << " "
       << item.revenue << " "
       << item.avg_price();
    return os;
}
istream& read(istream &is, Sales_data& item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
Sales_data add(const Sales_data& item1, const Sales_data& item2)
{
    Sales_data sum = item1;
    sum.combine(item2);
    return sum;
}
int main()
{
    Sales_data total;
    if(read(cin, total))
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
