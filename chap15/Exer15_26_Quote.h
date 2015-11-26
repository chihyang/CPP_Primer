#ifndef QUOTE_H
#define QUOTE_H
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
class Quote {
public:
	Quote() { std::cout << "Quote()" << std::endl; }
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price)
	    { std::cout<< "Quote(const string&, double)" << std::endl; }
	std::string isbn() const { return bookNo; }
	// return the total sales price for the specified number of items
	// derived class will override and apply different discount algorithms
	virtual double net_price(std::size_t n) const
	    { return n * price; }
	virtual void debug() const;
	// copy control members
	Quote(const Quote &q) : bookNo(q.bookNo), price(q.price)
	    { std::cout << "Quote(const Quote&)" << std::endl; }
	Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
	    { std::cout << "Quote(Quote&&)" << std::endl; }
	Quote& operator=(const Quote&);
	Quote& operator=(Quote&&) noexcept;
	virtual ~Quote() { std::cout << "~Quote()" << std::endl; } // dynamic binding for the destructor
private:
	std::string bookNo; // ISBN number of this item
protected:
	double price = 0.0; // normal, undiscounted price
};
// calculate and print the price for the given number of copies, applying any discount
double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	// depending on the type of the object bound to the item parameter
	// calls either Quote::net_price or Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() // calls Quote::isbn
	   << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}
inline void Quote::debug() const
{
	std::cout << "std::string bookNo\n"
	          << "double price\n"
	          << std::endl;  
}
inline Quote& Quote::operator=(const Quote &rhs)
{
	// self-assignment is safe, we don't need to worry about it
	bookNo = rhs.bookNo;
	price = rhs.price;
	std::cout << "Quote& operator=(const Quote&)" << std::endl; 
	return *this;
}
inline Quote& Quote::operator=(Quote &&rhs) noexcept
{
	if(this != &rhs)
	{
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
	}
	std::cout << "Quote& operator=(Quote&&)" << std::endl; 
	return *this;
}
#endif