#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include <cstddef>
#include <string>
#include "Page617_Disc_quote.h"
class Bulk_quote : public Disc_quote { // Bulk_quote inherits from Quote
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
	    Disc_quote(book, price, qty, disc) {}
	// overrides the base version in order to implement the bulk purchase discount policy
	double net_price(std::size_t) const override;
	void debug() const override;
};
// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
inline void Bulk_quote::debug() const
{
	std::cout << "std::string bookNo\n"
	          << "double price\n"
	          << "std::size_t min_qty\n"
	          << "double discount\n"
	          << std::endl;  
}
#endif