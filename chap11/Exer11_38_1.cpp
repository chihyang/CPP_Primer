#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <unordered_map>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::size_t;
using std::unordered_map;
int main(int argc, char *argv[])
{
    if(argc != 2)
        return -1;
    ifstream is(argv[1]);
    // count the number of times each word occurs in the input
    unordered_map<string, size_t> word_count; // empty map from string to size_t
    string word;
    while(is >> word)
        ++word_count[word]; // fetch and increment the counter for word
    cout << "Bucket count:\t" << word_count.bucket_count() << endl;
    cout << "Maximum bucket count:\t" << word_count.max_bucket_count() << endl;
    cout << "Average number:\t" << word_count.load_factor() << endl;
    cout << "Average bucket size:\t" << word_count.max_load_factor() << endl;
    for(const auto &w : word_count) // for each element in the map
        // print the result
        cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;
    return 0;
}
