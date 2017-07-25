#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::istream_iterator;
using std::ostream_iterator;
int main()
{
    map<string, vector<string>> family;
    string patronymic;
    string child;
    ostream_iterator<string> os(cout, " ");
    while(cin >> patronymic)
    {
        while(cin >> child)
        {
            family[patronymic].push_back(child);
        }
        cin.clear(); // clear for next input
    }
    for(const auto &w : family)
    {
        cout << w.first << ":\n";
        copy(w.second.cbegin(), w.second.cend(), os);
        cout << endl;
    }
    return 0;
}
// ******QUESTION******
// Q: Can we use istream_iterator here?
// A: No.
// Explanation: first, if an istream_iterator is defined, we ALWAYS have to use
// it for reading values from standard input, we can't write this way:
//
//  istream_iterator<string> is(cin), eof;
//  while(cin >> patronymic)
//  {
//      while(is != eof)
//          family[patronymic].push_back(*is++);
//      cin.clear(); // clear for next input
//  }
//
// Compile the code above and input some strings, we'll find the result is not
// what we want:
//
// ******Result compiled by cl and g++******
// A
// 1 2 3
// ^Z
// ^Z
// 1:
// A 2 3
//
// This is possibly because istream_iterators are permitted to use lazy
// evaluation(see page 405), thus influencing the result.
//
// Moreover, even if we use istream_iterator at both inner loop and outer loop,
// still we cannot do what we want. Because that way we have to compare is and eof
// at both inner and outer loop, but when in inner loop is == eof, so is the one
// at outer loop. Thus once the inner loop is terminated, outer loop will, too.
// We may use the state of cin as termination condition, but this doesn't solve
// the lazy evaluation problem.
