#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::istream;
using std::ostream;
using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
istream& restoreData(ifstream& is, const string &ifile, vector<string> &v)
{
    string str;
    is.open(ifile);
    if(is)
    {
        while(is >> str)
        {
            v.push_back(str);
        }
    }
    return is;
}
int main(int argc, char* argv[])
{
    ifstream in;
    vector<string> vec;
    if(argc == 2)
    {
        restoreData(in, argv[1], vec);
    }
    // basic error prompt.
    else if(argc < 2)
    {
        cerr << "Please offer a file name!" << endl;
        return -1;
    }
    else
    {
        cerr << "Too many input arguments!" << endl;
        return -1;
    }
    if(!vec.empty())
        for(const auto &s : vec)
            cout << s << endl;
    return 0;
}
