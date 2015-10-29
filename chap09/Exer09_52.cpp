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
	stack<string> expresion;
	string after_proess;
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
				after_proess += expresion.top();
				expresion.pop();
			}
			open = !expresion.empty();
			continue;
		}
		if(open)
			expresion.push(ch);
	}
	cout << after_proess << endl;
	return 0;
}