#include <iostream>
#include <string>
#include <regex>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;
using std::smatch;
int main()
{
    regex r("[^c]ei"); // construct an object to find pattern, only match 3-character words
    smatch results;   // define an object to hold the results of a search
    // define a string that has text that does and doesn't match pattern
    string test_str;
    cout << "input a word: " << endl;
    while (cin >> test_str) {
        // use r to find a match to pattern in test_str
        if(regex_search(test_str, results, r)) // if there is a match
            cout << "wrong spelling! \"ei\" is reversed." << endl;     // print the matching word
    }
    return 0;
}
