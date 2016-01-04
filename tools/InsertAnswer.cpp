#include <windows.h>
#include <tchar.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include "InsertAnswer.h"
using std::system;
using std::cerr;
using std::endl;
using std::set;
int _tmain(int argc, TCHAR* argv[])
{
	if (argc != 2) {
		cerr << "\nUsage: " << argv[0] << " <directory name>\n" << endl;
		return -1;
	}
	set<String> sources;
	GetSrcFile(argv[1], sources);
	return 0;
}
