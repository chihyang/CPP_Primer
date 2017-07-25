#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H
#include <cstddef>
#include "Exer15_01_Quote.h"
class Limit_quote : public Quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string&, double, std::size_t, double);
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;
private:
    std::size_t max_qty = 0; // maximum purchase for the discount to apply
    double discount = 0.0; // fraction discount to apply
};
inline Limit_quote::Limit_quote(const std::string &book, double p, std::size_t qty, double disc) :
    Quote(book, p), max_qty(qty), discount(disc) {}
double Limit_quote::net_price(std::size_t cnt) const
{
    if(cnt <= max_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
#endif
