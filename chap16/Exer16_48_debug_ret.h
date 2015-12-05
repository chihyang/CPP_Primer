#ifndef EXER16_48_DEBUG_RET_H
#define EXER16_48_DEBUG_RET_H
#include <iostream>
#include <sstream>
#include <string>
// declare all of the overloaded functions first to avoid silently instantiated template version
// print any type we don't otherwise handle
template <typename T> std::string debug_ret(const T&);
template <typename T> std::string debug_ret(T*);
std::string debug_ret(const std::string&);
std::string debug_ret(const char*);
std::string debug_ret(char*);
template <typename T> std::string debug_ret(const T &t)
{
	std::cout << "debug_ret(const T&)" << std::endl;
	std::ostringstream ret;
	ret << t; // uses T's output operator to print a representation of t
	return ret.str(); // return a copy of the string to which ret is bound
}
// print pointers as their pointer value, followed by the object ot which the pointer points
// NB: this function will not work properly with char*, because char* has its own version of output operator
template <typename T> std::string debug_ret(T *p)
{
	std::cout << "debug_ret(T*)" << std::endl;
	std::ostringstream ret;              // print the pointer's own value
	ret << "pointer: " << p;
	if(p)
		ret << " " << debug_ret(*p); // print the value to which p points
	else
		ret << " null pointer";          // or indicate that the p is null
	return ret.str(); // return a copy of the string to which ret is bound
}
// print strings include inside double quotes
std::string debug_ret(const std::string &s)
{
	std::cout << "debug_ret(const string&)" << std::endl;
	return '"' + s + '"';
}
// convert the character pointers to string and call the string version of debug_ret
std::string debug_ret(const char *p)
{
	std::cout << "debug_ret(const char*)" << std::endl;
	// if the declaration for the version that takes a const string& is not in scope
	// the return will call debug_ret(const T&) with T instantiated to string
	return debug_ret(std::string(p));
}
std::string debug_ret(char *p)
{
	std::cout << "debug_ret(char*)" << std::endl;
	return debug_ret(std::string(p));
}
#endif