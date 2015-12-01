#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "Exer16_19.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
int main()
{
	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	deque<string> dq = { "like", "a", "thunderbolt", "he", "falls" };
	string s("Templates");
	print(vec);
	cout << endl;
	print(dq);
	cout << endl;
	print(s);
	cout << endl;
	return 0;
}