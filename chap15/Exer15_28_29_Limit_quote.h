#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H
#include <cstddef>
#include <utility>
#include "Exer15_28_29_Disc_quote.h"
class Limit_quote : public Disc_quote {
public:
    // inherited constructor
    using Disc_quote::Disc_quote;
    Limit_quote() = default;
    // overrides the base version in order to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;
    void debug() const override;
    // copy-control members
    Limit_quote(const Limit_quote &lq) : Disc_quote(lq) {}
    Limit_quote(Limit_quote &&lq) : Disc_quote(std::move(lq)) {}
    Limit_quote& operator=(const Limit_quote&);
    Limit_quote& operator=(Limit_quote&&);
    ~Limit_quote()=default; // virtual by inheritance
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
Limit_quote& Limit_quote::operator=(const Limit_quote &rhs)
{
    Disc_quote::operator=(rhs);
    return *this;
}
Limit_quote& Limit_quote::operator=(Limit_quote &&rhs)
{
    if(this != &rhs)
        Disc_quote::operator=(std::move(rhs));
    return *this;
}
#endif
