#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
int main(int argc, char *argv[])
{
    if(argc != 2)
    {   cerr << "Wrong input!" << endl;
        return -1;
    }
    ifstream is(argv[1]);
    istream_iterator<string> is_iter(is), eof;
    ostream_iterator<string> os_iter(cout, " ");
    vector<string> vec;
    string str;
    while(is_iter != eof)
    {
        str = *is_iter++;
        vec.push_back(str);
    }
    for(const auto &s : vec)
        os_iter = s;
    cout << endl;
    return 0;
}
