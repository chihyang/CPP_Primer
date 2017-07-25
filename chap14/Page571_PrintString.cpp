#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::ostream;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
class PrintString {
public:
    PrintString(ostream &o = cout, char c = ' ') : os(o), sep(c) {}
    void operator()(const string &s) const { os << s << sep; }
private:
    ostream &os; // stream on which to write
    char sep; // character to print after each output
};
int main()
{
    vector<string> vs = {"Like", "a", "thunderbolt", "he", "falls"};
    string s = "This is a string";
    PrintString printer; // uses the default; print to cout
    printer(s); // prints s followed by a space on cout
    PrintString errors(cerr, '\n'); // prints s followed by a new line on cerr
    errors(s);
    for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
    return 0;
}
