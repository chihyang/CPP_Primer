#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
using std::cout;
using std::cin;
using std::endl;
using std::istringstream;
using std::string;
using std::stack;
using std::map;
using std::minus;
using std::function;
// arithmetic operations, just for illustration
// ordinary function
int add(int i, int j) { return i + j; }
// lambda, which generates an unnamed function-object class
auto mod = [](int i, int j){ return i % j; };
// function-object class
struct divide {
	int operator()(int i, int j) { return i / j; }
};
// operator map
map<string, function<int(int, int)>> binops = {
	{"+", add},                 // function pointer
	{"-", minus<int>()},        // library function object
	{"*", [](int i, int j){ return i * j;}}, // unnamed lambda
	{"/", divide()},            // user-defined function object
	{"%", mod} };               // named lambda object
// operator priority map
map<char, int> priority = {
	{'(', 0},
	{'+', 1},
	{'-', 1},
	{'*', 2},
	{'/', 2},
	{'%', 2} };
// convert infix expression to suffix expression
string to_suffix(const string&);
// eliminate white spaces from expression
string strip(const string&);
// calculate suffix expression
int calc(const string &expr);
int main()
{
	string exp;
	cout << "input an expression, support +, -, *, /, and % only:" << endl;
	while(getline(cin, exp)) 
	{
		exp = to_suffix(strip(exp));
		cout << exp << endl;
		cout << calc(exp) << endl;
	}
	return 0;
}
// convert a infix expression to a suffix expression
string to_suffix(const string &expr)
{
	string expression;
	stack<char> stk;
	for(auto c : expr)
	{
		if(isdigit(c))
			expression.push_back(c);
		else {
			expression.push_back(' '); // meets an operator, add an separator to the expression
			if(stk.empty() || c == '(') // empty or meet ')', push into stack 
				stk.push(c);
			else if(c != ')') { // meet operator except ')', process according to stack operator priority
				while(!stk.empty() && priority[c] <= priority[stk.top()]) {
					expression.push_back(stk.top());
					stk.pop();
					expression.push_back(' ');
				}
				stk.push(c);
			}
			else { // meet ')', pop all of the operators except '('
				while(stk.top() != '(') {
					expression.push_back(stk.top());
					stk.pop();
					expression.push_back(' ');
				}
				stk.pop(); // pop '('
			}
		}
	}
	// pop all of the remaining operators in stack
	while(!stk.empty()) {
		expression.push_back(' '); // add separator space
		expression.push_back(stk.top());
		stk.pop();
	}
	return expression;
}
// eliminate white spaces from input expressions 
string strip(const string &input)
{
	string output;
	for(auto c : input)
		if(!isspace(c))
			output.push_back(c);
	return output;
}
// calculate the suffix expression
int calc(const string &suffix)
{
	string unit;
	istringstream is(suffix);
	stack<int> stk;
	while(is >> unit)
	{
		if(binops.find(unit) == binops.end()) { // numbers, push into stack
			stk.push(stoi(unit));
		}
		else { // operators, calculate
			if(!stk.empty()) {
				int rhs = stk.top();
				stk.pop();
				int lhs = stk.top();
				stk.pop();
				stk.push(binops[unit](lhs,rhs));
			}
		}
	}
	int ret = stk.top();
	stk.pop();
	return ret;
}
// Note: this program doesn't check the validity of data, which should be added
// later.