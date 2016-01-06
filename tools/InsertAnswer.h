#ifndef TOOL_INSERT_ANSWER_H
#define TOOL_INSERT_ANSWER_H
#include <windows.h>
#include <cstddef>
#include <string>
#include <vector>
#include <map>
#ifndef UNICODE
	typedef std::string String;
#else 
	typedef std::wstring String;
#endif
typedef std::map<std::size_t, std::vector<String>> ExerSet;
void DisplayErrorBox(LPTSTR lpszFunction);
bool iscpp(const String&);
int get_source(const TCHAR *path, ExerSet&);
std::vector<std::size_t> analysis_filename(const String&);
String format(const std::vector<String> &);
#endif