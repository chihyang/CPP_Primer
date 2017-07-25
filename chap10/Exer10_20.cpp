#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::size_t;
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
vector<string>::size_type count_size(vector<string> &words, vector<string>::size_type sz)
{
    auto count = count_if(words.begin(), words.end(),
               [sz](const string& s){return s.size() > sz;});
    return count;
}
int main()
{
    vector<string> words = { "the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle" };
    string::size_type sz;
    while(cin >> sz)
    {
        auto cnt = count_size(words, sz);
        cout << cnt  << " " << make_plural(cnt, "word", "s")
             << " longer than " << sz << endl;
        for_each(words.begin(), words.end(),
            [sz](const string& str){ if(str.size() > sz) cout << str << " ";});
        cout << endl;
    }
    return 0;
}
