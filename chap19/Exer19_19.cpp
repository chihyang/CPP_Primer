#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Sales_data.h"
using std::size_t;
using std::cout;
using std::endl;
using std::vector;
using std::bind;
using std::placeholders::_1;
auto count_price(const std::vector<Sales_data> &vec, double price) -> decltype(vec.begin())
{
	auto f = bind(&Sales_data::avg_price, _1);
	return find_if(vec.begin(), vec.end(), [&](const Sales_data &s){ return price < f(s); });
}
int main()
{
	vector<Sales_data> vec = { Sales_data("978-7-121-20038-0", 12, 128.0),
	                           Sales_data("978-7-121-20038-0", 10, 98.0),
	                           Sales_data("978-7-121-20038-0", 12, 108.0)
	                         };
	auto it = count_price(vec, 98);
	cout << *it << endl;
	return 0;
}