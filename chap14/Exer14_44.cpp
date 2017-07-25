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
// operator priority(in stack) map
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
int calc(const string&);
// check the validity of an expression
bool check(const string&);
int main()
{
    cout << "input an expression, support +, -, *, /, and % only, or q to quit: " << endl;
    while(true)
    {
        string exp;
        if(!(getline(cin, exp)) || strip(exp) == "q")
            break;
        else {
            if(check(exp)) {
                exp = to_suffix(strip(exp));
                cout << calc(exp) << endl;
            }
            else
                cout << "illegal or incomplete expression! continue or hit q to quit: " << endl;
        }
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
            expression.push_back(' '); // meets an operator, adds an separator to the expression
            if(stk.empty() || c == '(') // empty or meet ')', pushes into stack
                stk.push(c);
            else if(c != ')') { // meets operator except ')', processes according to stack operator priority
                while(!stk.empty() && priority[c] <= priority[stk.top()]) {
                    expression.push_back(stk.top());
                    stk.pop();
                    expression.push_back(' ');
                }
                stk.push(c);
            }
            else { // meets ')', pops up all of the operators except '('
                while(stk.top() != '(') {
                    expression.push_back(stk.top());
                    stk.pop();
                    expression.push_back(' ');
                }
                stk.pop(); // pops up '('
            }
        }
    }
    // pops up all of the remaining operators in stack
    while(!stk.empty()) {
        expression.push_back(' '); // add separator space
        expression.push_back(stk.top());
        stk.pop();
    }
    return expression;
}
// eliminate white spaces from the input expression
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
// Note: data check is added, but might not cover all exceptions; calls for further test
// eg: 1 () 2 * 3 is a wrong expression, but won't be found.
bool check(const string &expr)
{
    // check if parentheses are paired
    auto cnt_left = count(expr.cbegin(), expr.cend(), ')');
    auto cnt_right = count(expr.cbegin(), expr.cend(), '(');
    if(cnt_left != cnt_right)
        return false;
    if(expr.find("(") > expr.find(")"))
        return false;
    // find if any other illegal characters exist
    auto illegal_pos = expr.find_first_not_of("+-*/%().0123456789 \t");
    if(illegal_pos != string::npos) {
        string s(illegal_pos + 1, ' ');
        s[illegal_pos] = '^';
        cout << s << endl;
        return false;
    }
    // check if the last non white space character is a digit
    // it is worth nothing that this also covers the case that no operators are
    // input, thus the last position of an operator is string::npos, which is -1
    // and converted to the largest unsigned value
    if(expr.find_last_of("+-*/%") > expr.find_last_of("0123456789"))
        return false;
    return true;
}
