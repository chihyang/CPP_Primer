#ifndef BASKET_H
#define BASKET_H
#include <iostream>
#include <set>
#include <memory>
#include <utility>
#include "Exer15_30_Quote.h"
#include "Exer15_30_Bulk_quote.h"
class Basket {
public:
    // basket uses synthesized default constructor and copy-control members
    void add_item(const Quote &sale)
        { items.insert(std::shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote &&sale)
        { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
    // prints the total price for each book and the overall total for items in the basket
    double total_receipt(std::ostream&) const;
private:
    // function to compare shared_ptrs needed by the multiset member
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
        { return lhs->isbn() < rhs->isbn(); }
    // multiset to bold multiple quotes, ordered by the compare member
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};
double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0; // holds the running total
    // iter refers to the first element in a batch of element with the same ISBN
    // upper_bound returns an iterator to the element just past the end of that batch
    for (auto iter = items.cbegin();
              iter != items.cend();
              iter = items.upper_bound(*iter)) {
        // we know there's at least one element with this key in the Basket
        // prints the line item for this book
        sum += print_total(os, **iter, items.count(*iter));
        // **iter is the first object shared_ptr points to with a given ISBN
    }
    // print the final overall total
    os << "Total Sale: " << sum << std::endl;
    return sum;
}
#endif
