// Warning: this is for illustration. Don't use this way.
#include <string>
#include <algorithm>
#include <memory>
using std::string;
// declare a function template with the same name as make_shared, thus the compiler
// knows that make_shared<string>(str) is a call to a function and it would find
// the standard library function make_shared by argument-dependent lookup.
template <typename T>
void make_shared(const T&);
int main()
{
    string str = "This is a string";
    auto it = find(str.begin(), str.end(), 'i'); // ok: needn't using declaration, ADL works
    std::shared_ptr<string> sp = make_shared<string>(str); // error: why ADL doesn't work
    return 0;
}
// Note: exception for argument-dependent lookup: we must use std::make_shared
// no matter what kind of arguments are passed. Because the parameter of
// make_shared is a function parameter pack(section 16.4, page 700), we have to
// offer explicit template arguments for it. Once we offer explicit template
// arguments, the whole statement doesn't maintain the form of function call:
//  foo<int>();
// We all know that a name followed by a call operator with zero or more arguments
// is a function call. But now <int> is between the name and call operator. How
// does the compiler know that foo is still a function name before it sees the
// declaration of foo? As a result, it doesn't even try to find the name.
//
// Alternatively, we can declare a template function named make_shared but takes
// difference template parameter and function parameter. As long as the compiler
// knows that make_shared is a function template. It will begin argument-dependent
// lookup. But to be honest, this is not a good way. We had better ALWAYS use
// using declaration in source files.
//
// Reference:
// https://stackoverflow.com/questions/2953684/why-doesnt-adl-find-function-templates
// https://stackoverflow.com/questions/34352188/argument-dependent-lookup-and-function-templates
// http://en.cppreference.com/w/cpp/language/adl
