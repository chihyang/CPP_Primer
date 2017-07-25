#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cerr << "Wrong input arguments!" << endl;
        return -1;
    }
    string ascender_descender("bdfhkltgjpqy");
    ifstream is(argv[1]);
    string word, picked;
    string::size_type len = word.size();
    while(is >> word)
    {
        string::size_type pos = 0;
        if((pos = word.find_first_of(ascender_descender, pos)) == string::npos)
        {
            if(word.size() > len)
            {
                len = word.size();
                picked = word;
            }
        }
    }
    cout << "The longest word that contains neither ascender nor descender in "
         << argv[1] << " is:\n" << picked << "\n"
         << "its length is: " << len << endl;
    return 0;
}
