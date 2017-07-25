#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include <map>
using std::cout;
using std::endl;
using std::ifstream;
using std::size_t;
using std::string;
using std::map;
int main(int argc, char *argv[])
{
    if(argc != 2)
        return -1;
    ifstream is(argv[1]);
    map<string, size_t> word_count;
    string word;
    while(is >> word)
    {
        auto ret = word_count.insert({word, 1});
        if(!ret.second)
            ++ret.first->second;
    }
    for(const auto &w : word_count)
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    return 0;
}
