#include <iostream>
#include <vector>
using std::vector;
int main()
{
	int some_val = 3;
	vector<int> iv{2, 3, 5, 8, 9};
	vector<int>::iterator mid = iv.begin() + iv.size() / 2;
	vector<int>::difference_type dif = mid - iv.begin();
	for(vector<int>::iterator iter = iv.begin(); iter != mid; ++iter)
	{
		if(*iter == some_val)
		{
			++dif;
			// output element mid refers to before insertion
			std::cerr << *mid << " " << std::endl;
			++(iter = iv.insert(iter, 2 * some_val)); // if not, iter also becomes invalid
			// output element mid refers to after insertion
			std::cerr << *mid << " " << std::endl;
			mid = dif + iv.begin();
			// reassign mid
			std::cerr << *mid << " " << std::endl;
		}
	}
	return 0;
}
// Note: from the result, we can see after insertion, the whole vector is moved
// to another place in memory, so that mid refers to an invalid address. To fix 
// this problem, we have reassign mid to refer to the original mid point of iv.