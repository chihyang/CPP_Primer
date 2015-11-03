#include <iostream>
#include <map>
#include <vector>
using std::map;
using std::vector;
int main()
{
	map<int, vector<int>> mp;
	map<int, vector<int>>::key_type map_key; // note: key_type of a map is not const!!!
	map_key = 3;
	std::cout << map_key << std::endl;
	map_key = 4;
	std::cout << map_key << std::endl;
	return 0;
}