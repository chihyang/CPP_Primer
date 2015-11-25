#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H
#include <cstddef>
#include <string>
#include <utility>
#include "Exer15_15_Quote.h"
class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc):
	    Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(std::size_t) const = 0;
	std::pair<std::size_t, double> discount_policy() const
	    { return {quantity, discount}; }
protected:
	std::size_t quantity = 0; // purchase size for the discount to apply
	double discount = 0.0; // fractional discount to apply
};
#endif