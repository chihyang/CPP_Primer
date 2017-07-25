#include <iostream>
#include <cstring>
#include <cstddef>
#include <string>
using std::cout;
using std::endl;
using std::size_t;
using std::string;
int main()
{
    // using C-style char array, we have a mass
    const char cstr1[] = "Like a thunderbolt";
    const char cstr2[] = " he falls.";
    auto len1 = strlen(cstr1), len2 = strlen(cstr2);
    char* ch_ptr = new char[len1 + len2 + 1]; // don't forget the null-terminator
    size_t sz = 0;
    strcpy(ch_ptr, cstr1);
    strcat(ch_ptr, cstr2);
    cout << ch_ptr << endl;
    delete[] ch_ptr; // once we forget this or use delete improperly, program has an error
    // using library string is much easier and readable
    string str1 = "Like a thunderbolt";
    string str2 = " he falls.";
    string strcat = str1 + str2;
    cout << strcat << endl;
    return 0;
}
