#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
int main()
{
    ostream *old_tie = cin.tie(nullptr);
    ostream *new_tie = cin.tie(&cerr);
    // tie(ostream *) will return an ostream pointer that points to the
    // previously tied object
    if(!new_tie)
        (*old_tie) << "cin is now tied to nothing" << endl; // old_tie points to cout
    cin.tie(old_tie);
    return 0;
}
