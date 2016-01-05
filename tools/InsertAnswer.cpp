#include <windows.h>
#include <tchar.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "InsertAnswer.h"
using std::cerr;
using std::endl;
using std::vector;
int _tmain(int argc, TCHAR* argv[])
{
	if (argc != 2) {
		cerr << "\nUsage: " << argv[0] << " <directory name>\n" << endl;
		return -1;
	}
	ExerSet sources;
	get_source(argv[1], sources);
	for(const auto &s : sources) {
		std::cout << "Exercise " << s.first << ":\t";
		for(const auto &r: s.second)
			std::cout << r << " ";
		std::cout << std::endl;
	}
	return 0;
}
