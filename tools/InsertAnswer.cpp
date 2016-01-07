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
using std::cout;
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
	cout << "Analyse file names in the directory " << argv[1] << "... ";
	ExerSet sources;
	get_source(argv[1], sources);
	cout << "Done!" << endl;
	String readme_file = argv[1] + String("\\README.md");
	Fstream inOut(readme_file, Fstream::in);
	if (!inOut) {
		cerr << "Unable to open README.md file!" << endl;
		return -1;
	}
	cout << "Process the README.md file... ";
	size_t cnt = 0;                // counter for exercise number
	vector<String> file;           // store the contents of the file
	String line;                   // store the contents of current line
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
	// process the last answer
	if (sources.find(cnt) != sources.end()) {
		file.push_back(TEXT("\n") + format(sources[cnt]) + TEXT("\n"));
	}
	// ready to write to the original file
	inOut.clear();
	inOut.close();
	inOut.open(readme_file, Fstream::out);
	if (!inOut) {
		cerr << "Fail to write the original file!" << endl;
		return -1;
	}
	for (const auto &l : file) {
		inOut << l << TEXT("\n");
	}
	cout << "Done!" << endl;
	return 0;
}
