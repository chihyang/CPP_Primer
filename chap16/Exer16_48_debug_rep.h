#ifndef EXER16_48_DEBUG_RET_H
#define EXER16_48_DEBUG_RET_H
#include <iostream>
#include <sstream>
#include <string>
// declare all of the overloaded functions first to avoid silently instantiated template version
// print any type we don't otherwise handle
template <typename T> std::string debug_rep(const T&);
template <typename T> std::string debug_rep(T*);
std::string debug_rep(const std::string&);
std::string debug_rep(const char*);
std::string debug_rep(char*);
template <typename T> std::string debug_rep(const T &t)
{
    std::cout << "debug_rep(const T&)" << std::endl;
    std::ostringstream ret;
    ret << t; // uses T's output operator to print a representation of t
    return ret.str(); // return a copy of the string to which ret is bound
}
// print pointers as their pointer value, followed by the object ot which the pointer points
// NB: this function will not work properly with char*, because char* has its own version of output operator
template <typename T> std::string debug_rep(T *p)
{
    std::cout << "debug_rep(T*)" << std::endl;
    std::ostringstream ret;              // print the pointer's own value
    ret << "pointer: " << p;
    if(p)
        ret << " " << debug_rep(*p); // print the value to which p points
    else
        ret << " null pointer";          // or indicate that the p is null
    return ret.str(); // return a copy of the string to which ret is bound
}
// print strings include inside double quotes
std::string debug_rep(const std::string &s)
{
    std::cout << "debug_rep(const string&)" << std::endl;
    return '"' + s + '"';
}
// convert the character pointers to string and call the string version of debug_rep
std::string debug_rep(const char *p)
{
    std::cout << "debug_rep(const char*)" << std::endl;
    // if the declaration for the version that takes a const string& is not in scope
    // the return will call debug_rep(const T&) with T instantiated to string
    return debug_rep(std::string(p));
}
std::string debug_rep(char *p)
{
    std::cout << "debug_rep(char*)" << std::endl;
    return debug_rep(std::string(p));
}
#endif
