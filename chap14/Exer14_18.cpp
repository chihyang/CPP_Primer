#include <iostream>
#include "String.h"
#include "StrVec.h"
#include "StrBlob.h"
using std::cout;
using std::endl;
int main()
{
    String str1("Hello"), str2("Hello");
    if(str1 < str2)
        cout << "str1 < str2" << endl;
    else if(str1 == str2)
        cout << "str1 == str2" << endl;
    else
        cout << "str1 > str2" << endl;
    StrVec v1{"This", "is", "a", "new", "day"}, v2{"This", "is", "new", "day"};
    if(v1 < v2)
        cout << "v1 < v2" << endl;
    else if(v1 == v2)
        cout << "v1 == v2" << endl;
    else
        cout << "v1 > v2" << endl;
    return 0;
}
// Note: as the header file shows, if we use things like iterator, we can easily
// write codes without worrying about elements type. In fact, we when overload
// relational operators, we don't have to explicitly write underlying elements
// type of String of StrVec. We just use auto to get the type.
