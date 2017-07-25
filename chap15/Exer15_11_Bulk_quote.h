#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include <cstddef>
#include <string>
#include "Exer15_11_Quote.h"
class Bulk_quote : public Quote { // Bulk_quote inherits from Quote
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;
    void debug() const override;
private:
    std::size_t min_qty = 0; // minimum purchase for the discount to apply
    double discount = 0.0; // fraction discount to apply
};
inline Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
    Quote(book, p), min_qty(qty), discount(disc) {}
// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= min_qty)
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
