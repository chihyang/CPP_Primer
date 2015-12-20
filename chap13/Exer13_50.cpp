#include <iostream>
#include <vector>
#include "Exer13_49_String.h"
using std::cout;
using std::endl;
using std::vector;
void foo(String x){}
void bar(const String& x){}
String baz()
{
	String ret("world");
	return ret;
}
int main()
{
	cout << "general test1:" << endl;
	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	s2 = s1;
	s2 = "Lord of the King";
	cout << "general test2:" << endl;
	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s4 = baz();
	cout << "vector test1:" << endl;
	vector<String> svec;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(baz());
	svec.push_back("good job");
	cout << "vector test2:" << endl;
	vector<String> v;
	for(int i = 0; i != 10; ++i)
		v.push_back("string");
	v.clear();
	if(v.empty())
		cout << "v is empty" << endl;
	return 0;
}
// ******results******
// general test1:
// String(const String&) is called
// String(const String&) is called
// String& operator=(const String&) is called
// String& operator=(String&&) is called
// general test2:
// String(const String&) is called
// vector test1:
// String(const String&) is called
// String(const String&) is called
// String(String&&) is called
// String(String&&) is called
// String(String&&) is called
// String(String&&) is called
// String(String&&) is called
// vector test2:
// String(String&&) is called
// ...(25 times in total)

// Note #1: part of the tests come from
// https://github.com/Mooophy/Cpp-Primer/blob/master/ch13/ex13_48.cpp
// which is quoted from 
// http://coolshell.cn/articles/10478.html

// Note #2: As the result shows, everywhere we use rvalue(literal), move constructor
// or move assignment is called.
