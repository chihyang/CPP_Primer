#include <iostream>
#include <stack>
#include <string>
using std::cout;
using std::endl;
using std::stack;
using std::string;
int main()
{
	string s("3+2*(8/4)+(15/(3+(4/(234+23)+8)/2))");
	string after; // store the result
	stack<string> expresion;
	string in_bracket;
	bool open;
	for(string::size_type i = 0; i != s.size(); ++i)
	{
		string ch(s.substr(i, 1));
		if(ch == "(")
		{
			if(!expresion.empty())
			{
				expresion.push(ch); // nested parenthesis is pushed into stack as a mark
			}
			open = true;
			after += ch;
			continue;
		}
		if(ch == ")")
		{
			while(!expresion.empty())
			{
				if(expresion.top() == "(")
				{
					expresion.pop();
					break;
				}
				in_bracket += expresion.top();
				expresion.pop();
			}
			open = !expresion.empty();
			after = after + in_bracket + ch;
			in_bracket.clear();
			continue;
		}
		if(open)
			expresion.push(ch);
		else
			after += ch;
	}
	cout << after << endl;
	return 0;
}