#include <iostream>
#include <sstream>
#include <string>
using std::istream;
using std::istringstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;
istream& read(istream& is)
{
    string word;
    while(!is.eof())
    {
        is >> word;
        cout << word << endl;
    }
    is.clear();
    return is;
}
int main()
{
    string str = "John has a book.";
    istringstream is(str);
    read(is);
    return 0;
}
