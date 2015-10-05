#include <iostream>
using std::cout;
using std::endl;
int main()
{
	int ia = -30 * 3 + 21 / 5;
	int ib = -30 + 3 * 21 / 5;
	int ic = 30 /3 * 21 % 5;
	int id = -30 / 3 * 21 % 4;
	cout << ia << " " << ib << " " << ic <<" " << id << " " << endl;
	return 0;
}