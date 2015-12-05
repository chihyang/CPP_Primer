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
	std::ostringstream ret;
	ret << t; // uses T's output operator to print a representation of t
	return ret.str(); // return a copy of the string to which ret is bound
}
// print pointers as their pointer value, followed by the object ot which the pointer points
// NB: this function will not work properly with char*, because char* has its own version of output operator
template <typename T> std::string debug_rep(T *p)
{
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
	return '"' + s + '"';
}
// convert the character pointers to string and call the string version of debug_rep
std::string debug_rep(const char *p)
{
	// if the declaration for the version that takes a const string& is not in scope
	// the return will call debug_rep(const T&) with T instantiated to string
	return debug_rep(std::string(p));
}
std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}
// function to end the recursion and print the last element
// this function must be declared before the variadic version of print is defined
template <typename T>
std::ostream& print(std::ostream &os, const T &t)
{
	return os << t; // no separator after the last element in the pack
}
// this version of print will be called for all but the last element in the pack
template <typename T, typename... Args>
std::ostream& print(std::ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";           // print the first argument
	return print(os, rest...); //recursive call; print the other arguments
}
// call debug_rep on each argument in the call to print
template <typename... Args>
std::ostream& errorMsg(std::ostream &os, const Args&... rest)
{
	// print(os, debug_rep(a1), debug_rep(a2),..., debug_rep(an)
	return print(os, debug_rep(rest)...);
}
#endif