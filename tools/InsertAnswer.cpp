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
	vector<String> sources;
	GetSrcFile(argv[1], sources);
	auto rst = analysis("Exer19_03_04.cpp");
	for(const auto &r: rst)
		std::cout << r << " ";
	std::cout << std::endl;
	return 0;
}
