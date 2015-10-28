// Warning: This is for illustration. It has an runtime error.
// The problem lies in line 18.
#include <iostream>
#include <string>
#include <cstddef>
using std::cout;
using std::endl;
using std::string;
using std::size_t;
int main()
{
	string s1 = "pi = 987;123";
	string s2 = "0x124a";
	string s3 = "3.14e3";
	string s4 = ".1415926";
	size_t index = s1.find(";");
	size_t *p = &index;
	int i1 = stoi(s1.substr(s1.find_first_of("+-0123456789")), p, 8); // invalid
	int i2 = stoi(s2, nullptr, 8);
	double d1 = stod(s3);
	double d2 = stod(s4);
	cout << i1 << " " << i2 << " " << d1 << " " << d2 << " " << endl;
	return 0;
}
// Note: conversion is very flexible and smart. If we just provide a string, the 
// result is 987, all the characters after semicolon(included) is ignored; if we
// provide the index of semicolon, the result keeps the same; only if we provide 
// base such as 8 the result will be invalid_argument, because 9 is not a number
// in Octal. But if we provide a base that contains digit 9, the result will be
// valid. Moreover, if we substitute "1" for "9" in s1 and keep the other 
// arguments, the result is 1. Because 8 is a invalid digit in octal and thus 
// ignored.