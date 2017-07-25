#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
// To use read here, we must move read before class definition. But when we
// do this, read cannot access to Sales_data object. So we must declare
// Sales_data ahead of read.
struct Sales_data;
istream& read(istream&, Sales_data&);
struct Sales_data {
    // constructor
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &is) { read(is, *this); }
    // member
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
istream& read(istream &is, Sales_data& item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
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
Sales_data add(const Sales_data& item1, const Sales_data& item2)
{
    Sales_data sum = item1;
    sum.combine(item2);
    return sum;
}
int main()
{
    Sales_data total1; // use default constructor
    Sales_data total2("978-7-121-20038-0"); // use Sales_data(const string&)
    // use Sales_data(const string& s, unsigned n, double p)
    Sales_data total3("978-7-111-40701-0", 10, 128);
    Sales_data total4(cin); // use Sales_data(istream&)
    print(cout, total1) << endl;
    print(cout, total2) << endl;
    print(cout, total3) << endl;
    print(cout, total4) << endl;
    return 0;
}
