#ifndef TOOL_INSERT_ANSWER_H
#define TOOL_INSERT_ANSWER_H
#include <windows.h>
#include <string>
#include <set>
#ifndef UNICODE
	typedef std::string String;
#else 
	typedef std::wstring String;
#endif
void DisplayErrorBox(LPTSTR lpszFunction);
bool isCPPSrc(const String&);
int GetSrcFile(const TCHAR *path, std::set<String> &src);
#endif