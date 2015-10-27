// Warning: This is for illustration. It has runtime error.
// The problem lies in line 19.
#include <iostream>
#include <vector>
#include <cassert>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
int main()
{
	vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	auto iter = vi.begin();
	while(iter != vi.end())
	{
		assert(iter > vi.end());
		if(*iter % 2)
		{
			iter = vi.insert(iter, *iter++);
			iter += 2;
		}
		else
		{
			iter = vi.erase(iter);
		}
	}
	for(auto &i : vi)
		cout << i << " ";
	cout << endl;
	return 0;
}
// Note: when using dereference and postfix increment at the same time, we must 
// note that operands can be evaluated in any order. So it's easy to cause 
// unexpected overflow error. Here because compiler evaluates left-hand operand,
// iter skips elements and will finally be out of range. If we change line 20 to
// iter += 1, the program works. BUT it's not recommended, because potential 
// problems caused by evaluation order still exist. We can't make sure the program
// can be compiled by any compiler.