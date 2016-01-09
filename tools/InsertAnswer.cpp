#include "InsertAnswer.h"
#include <windows.h>
#include <tchar.h>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <codecvt>
#include <locale>
using std::size_t;
using std::endl;
using std::vector;
#ifndef UNICODE
typedef std::fstream Fstream;
auto &TCERR = std::cerr;
auto &TCOUT = std::cout;
#else
typedef std::wfstream Fstream;
auto &TCERR = std::wcerr;
auto &TCOUT = std::wcout;
#endif
int _tmain(int argc, TCHAR* argv[])
{
	if (argc != 2) {
		TCERR << TEXT("\nUsage: ") << argv[0] << TEXT(" <directory name>\n") << endl;
		return -1;
	}
	TCOUT << TEXT("Analyse file names in the directory ") << argv[1] << "... ";
	ExerSet sources;
	if(!get_source(argv[1], sources)) {
		TCOUT << TEXT("Done!") << endl;
	} else {
		TCOUT << TEXT("Failed!") << endl;
	}
	String readme_file = argv[1] + String(TEXT("\\README.md"));
	// open file for reading
	Fstream inOut(readme_file, Fstream::in);
	// locale for processing uft-8 texts, from stackoverflow
	const std::locale empty_locale = std::locale::empty();
	typedef std::codecvt_utf8<wchar_t> converter_type;
	const converter_type* converter = new converter_type;
	const std::locale utf8_locale = std::locale(empty_locale, converter);
	inOut.imbue(utf8_locale);
	if (!inOut) {
		TCERR << TEXT("Unable to open README.md file!") << endl;
		return -1;
	}
	TCOUT << TEXT("Process the README.md file... ");
	size_t cnt = 0;                // counter for exercise number
	vector<String> file;           // store the contents of the file
	String line;                   // store the contents of current line
	while (getline(inOut, line)) {
		if (line.size() > 2 && line.substr(0,2) == TEXT("##")) {
			// if the exercise has source files, format the names of source files
			// and insert them to the the README.md file
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
		TCERR << TEXT("Fail to write the original file!") << endl;
		return -1;
	}
	for (const auto &l : file) {
		inOut << l << "\n";
	}
	TCOUT << TEXT("Done!") << endl;
	return 0;
}
