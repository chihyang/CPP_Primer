#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H
#include <cstddef>
#include "Exer15_15_Disc_quote.h"
class Limit_quote : public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string &book, double price, std::size_t qty, double disc) :
        Disc_quote(book, price, qty, disc) {}
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;
    void debug() const override;
};
inline
double Limit_quote::net_price(std::size_t cnt) const
{
    if(cnt <= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
inline void Limit_quote::debug() const
{
    std::cout << "std::string bookNo\n"
              << "double price\n"
              << "std::size_t max_qty\n"
              << "double discount\n"
              << std::endl;
}
#endif
