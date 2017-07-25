#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <memory>
using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;
using std::istream_iterator;
using std::back_inserter;
using std::vector;
using std::shared_ptr;
using std::make_shared;
shared_ptr<vector<int>> vec_create(const vector<int> &v = {})
{
    return (make_shared<vector<int>>(v));
}
shared_ptr<vector<int>> vec_read(shared_ptr<vector<int>> v)
{
    istream_iterator<int> is(cin), eof;
    copy(is, eof, back_inserter(*v)); // not an easy way, just a review of iterator and generic algorithms
    return v;
}
void vec_print(shared_ptr<vector<int>> v)
{
    ostream_iterator<int> os(cout, " ");
    copy(v->begin(), v->end(), os);
    cout << endl;
}
int main()
{
    auto v = vec_create();
    vec_read(v);
    vec_print(v);
    return 0;
}
