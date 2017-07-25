#include <iostream>
#include <vector>
#include <memory>
#include "Exer15_28_29_Bulk_quote.h"
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;
int main()
{
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Bulk_quote>("978-7-121-20038-0", 128.0, 6, 0.05));
    basket.push_back(make_shared<Bulk_quote>("7-115-13771-4", 59.0, 10, 0.15));
    basket.push_back(make_shared<Bulk_quote>("978-7-111-40701-0", 128.0, 10, 0.2));
    basket.push_back(make_shared<Bulk_quote>("978-0-87779-855-2", 56.0, 5, 0.1));
    double sum = 0.0;
    for(const auto &c : basket)
        sum += c->net_price(10);
    cout << sum << endl;
    return 0;
}
