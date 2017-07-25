#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <functional>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::size_t;
using namespace std::placeholders;
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
void elimDup(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
bool check_size(const string &s, string::size_type sz)
{
    return s.size() > sz;
}
void biggie(vector<string> &words, vector<string>::size_type sz)
{
    // put words in alphabetical order and remove duplicate
    elimDup(words);
    // sort words by size, but maintain alphabetical order for words of the same size
    stable_sort(words.begin(), words.end(),
               [sz](const string &a, const string &b) {return a.size() < b.size();});
    // output for comparison
    for_each(words.begin(), words.end(), [](const string &s) {cout << s << " ";});
    cout << endl;
    // count words with length larger than sz
    auto count = count_if(words.begin(), words.end(), bind(check_size, _1, sz));
    cout << count << " " << make_plural(count, "word", "s") << " of length "
         << sz << " or longer" << endl;
}
int main()
{
    vector<string> words = { "the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle" };
    string::size_type sz;
    while(cin >> sz)
    {
        vector<string> tests(words);
        biggie(words, sz);
    }
    return 0;
}
