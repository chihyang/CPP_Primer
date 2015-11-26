#include <iostream>
#include <vector>
#include <memory>
#include "Exer15_30_Bulk_quote.h"
#include "Exer15_30_Basket.h"
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;
int main()
{
	Basket basket;
	for(std::size_t i = 0; i != 10; ++i)
		basket.add_item(Bulk_quote("978-7-121-20038-0", 128.0, 6, 0.05));
	for(std::size_t i = 0; i != 10; ++i)
		basket.add_item(Bulk_quote("7-115-13771-4", 59.0, 10, 0.15));
	for(std::size_t i = 0; i != 10; ++i)
		basket.add_item(Bulk_quote("978-7-111-40701-0", 128.0, 10, 0.2));
	for(std::size_t i = 0; i != 10; ++i)
		basket.add_item(Bulk_quote("978-0-87779-855-2", 56.0, 5, 0.1));
	basket.total_receipt(cout);
	return 0;
}
// Note: one drawback of this program is that we have to add ten identical books,
// that's useless, maybe we can use multimap to store the number of an item. Thus
// we needn't allocate space for every sale item.