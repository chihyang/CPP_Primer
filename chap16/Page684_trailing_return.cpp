// Warning: this is for illustration. Template declarations and definitions should be put into header files.
// a trailing return lets us declare the return type after the parameter list is seen
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;
template <typename It>
auto fcn(It beg) -> decltype(*beg)
{
    // process the range
    return *beg; // return a reference to an element from the range
}
int main()
{
    vector<string> vec = { "old", "man", "and", "the", "sea" };
    for(auto b = vec.begin(); b != vec.end(); ++b)
        cout << fcn(b) << " ";
    cout << endl;
    return 0;
}
