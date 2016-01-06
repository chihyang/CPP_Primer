#include <windows.h>
#include <tchar.h>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "InsertAnswer.h"
using std::size_t;
using std::cerr;
using std::endl;
using std::fstream;
using std::wfstream;
using std::vector;
#ifndef UNICODE
typedef fstream Fstream;
#else
typedef wfstream Fstream;
#endif
int _tmain(int argc, TCHAR* argv[])
{
	if (argc != 2) {
		cerr << "\nUsage: " << argv[0] << " <directory name>\n" << endl;
		return -1;
	}
	String readme_file = argv[1] + String("\\README.md");
	Fstream inOut(readme_file, Fstream::app | Fstream::in | Fstream::out);
	if (!inOut) {
		cerr << "Unable to open README.md file!" << endl;
		return -1;
	}
	// auto beg_mark = inOut.tellg(); // remember the beginning of the file
	size_t cnt = 0;                // counter for exercise number
	vector<String> file;           // store the contents of the file
	String line;                   // store the contents of current line
	ExerSet sources;
	get_source(argv[1], sources);
	while (getline(inOut, line)) {
		if (line.size() > 2 && line.substr(0,2) == TEXT("##")) {
			// if the exercise has source file, format the name of source file 
			// and insert it to the the file
			if (sources.find(cnt) != sources.end()) {
				file.push_back(format(sources[cnt]) + TEXT("\n"));
			}
			++cnt;
		}
		file.push_back(line);
	}
	inOut.clear();
	inOut.seekp(0, Fstream::beg);  // return to the beginning of the file
	for (const auto &l : file) {
		inOut << l << TEXT("\n");
	}
	return 0;
}
