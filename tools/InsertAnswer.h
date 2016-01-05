#ifndef TOOL_INSERT_ANSWER_H
#define TOOL_INSERT_ANSWER_H
#include <windows.h>
#include <cstddef>
#include <string>
#include <vector>
#ifndef UNICODE
	typedef std::string String;
#else 
	typedef std::wstring String;
#endif
void DisplayErrorBox(LPTSTR lpszFunction);
bool isCPPSrc(const String&);
int GetSrcFile(const TCHAR *path, std::vector<String> &src);
std::vector<std::size_t> analysis(const String&);
#endif