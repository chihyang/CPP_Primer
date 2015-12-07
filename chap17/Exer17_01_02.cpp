// Warning: this is for verification. It cannot compile.
// The problem lies in line 14.
#include <string>
#include <vector>
#include <utility>
#include <tuple>
using std::string;
using std::vector;
using std::pair;
using std::tuple;
int main()
{
	tuple<int, int, int> threeI(10, 20, 30);
	tuple<int, int, int> threeI2 = {10, 20, 30}; // error, explicit constructor
	tuple<string, vector<string>, pair<string, int>> strFamily;
	return 0;
}