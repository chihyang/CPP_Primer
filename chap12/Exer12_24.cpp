#include <iostream>
#include <cstring>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    size_t sz = 8;
    string str;
    while(getline(cin, str))
    {
        char* ch_ptr = new char[str.size() + 1];
        strcpy(ch_ptr, str.c_str());
        cout << ch_ptr << endl;
        delete[] ch_ptr;
    }
    return 0;
}
