#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
int main()
{
    vector<string> story = { "the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle" };
    elimDups(story);
    for(const auto &s : story)
        cout << s << " ";
    cout << endl;
    // we cannot put isShorter into sort, or the first order will be length rather than alphabet
    stable_sort(story.begin(), story.end(), isShorter);
    for(const auto &s : story)
        cout << s << " ";
    cout << endl;
    return 0;
}
