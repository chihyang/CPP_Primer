#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>
using std::size_t;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::tuple;
using std::make_tuple;
using std::get;
using std::tuple_size;
using std::tuple_element;
int main()
{
    tuple<size_t, size_t, size_t> threeD; // all three members set to 0
    // explicit constructor, can only direct initialization
    // both curly brackets and parentheses are ok
    tuple<string, vector<double>, int, list<int>>
        someVal{"constants", {3.14, 2.718}, 42, {0, 1, 2, 3, 4, 5}};
    // tuple that represents a bookstore transaction: ISBN, count, price per book
    auto item = make_tuple("0-999-78345-X", 3, 20.00);
    string book = get<0>(item);  // returns the first member of item
    auto cnt = get<1>(item);   // returns the second member of item
    auto price = get<2>(item); // returns the last member of item
    get<2>(item) *= 0.8;       // apply 20% discount
    cout << book << " " << cnt << " " << price << " " << get<2>(item) * get<1>(item) << endl;
    typedef decltype(item) trans; // trans is the type of item
    // returns the number of members in object's type trans
    size_t sz = tuple_size<trans>::value; // return 3
    // cnt has the same type as the secont member in item
    tuple_element<1, trans>::type cntr = get<1>(item); // cnt is an int
    cout << sz << " " << cntr << endl;
    return 0;
}
