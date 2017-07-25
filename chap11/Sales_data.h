// from exercise 7.21, we use header for Sales_data class.
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <iostream>
#include <string>
// substitute class for struct
class Sales_data {
    // friend
    friend std::istream& read(std::istream&, Sales_data&);
    friend std::ostream& print(std::ostream& os, const Sales_data& item);
    friend Sales_data add(const Sales_data& item1, const Sales_data& item2);
public:
    // constructor
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) {}
    explicit Sales_data(std::istream &is) { read(is, *this); }
    Sales_data& combine(const Sales_data& rhs);
    std::string isbn() const { return bookNo; }
    // member
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;
};
// declare friend functions outside class
std::istream& read(std::istream&, Sales_data&);
std::ostream& print(std::ostream& os, const Sales_data& item);
Sales_data add(const Sales_data& item1, const Sales_data& item2);
// member functions definition
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
// define avg_price as inline, required by exercise 7.26
inline double Sales_data::avg_price() const
{
    if(units_sold != 0)
        return revenue / units_sold;
    else
        return revenue;
}
// friend functions definition
std::istream& read(std::istream &is, Sales_data& item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
// Why does the book use an std::ostream reference as return value rather than void?
// 'Cause only in this way can user have a better manipulation of the format.
std::ostream& print(std::ostream& os, const Sales_data& item)
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
#endif
