#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <cstdio>
#include <cstddef>
#include <cctype>
#include <cwctype>
#include <vector>
#include <algorithm>
#include "InsertAnswer.h"
#pragma comment(lib, "User32.lib")
// Store the name of source file into the set src
int GetSrcFile(const TCHAR *path, std::vector<String> &src)
{
	WIN32_FIND_DATA ffd;
	TCHAR szDir[MAX_PATH];
	size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError=0;
	StringCchLength(path, MAX_PATH, &length_of_arg);
	// Check that the input path plus 3 is not longer than MAX_PATH.
	// Three characters are for the "\*" plus NULL appended below.
	if (length_of_arg > (MAX_PATH - 3))
	{
		_tprintf(TEXT("\nDirectory path is too long.\n"));
		return (-1);
	}
	// Prepare string for use with FindFile functions.  First, copy the
	// string to a buffer, then append '\*' to the directory name.
	StringCchCopy(szDir, MAX_PATH, path);
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));
	// Find the first file in the directory.
	hFind = FindFirstFile(szDir, &ffd);
	if (INVALID_HANDLE_VALUE == hFind) 
	{
		DisplayErrorBox(TEXT("FindFirstFile"));
		return dwError;
	} 
	// List all the files in the directory with some info about them.
	do {
		if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			if (isCPPSrc(ffd.cFileName)) {
				src.push_back(ffd.cFileName);
				_tprintf(TEXT("%s\n"), ffd.cFileName);
			}
		}
	} while (FindNextFile(hFind, &ffd) != 0);
	dwError = GetLastError();
	if (dwError != ERROR_NO_MORE_FILES)
	{
		DisplayErrorBox(TEXT("FindFirstFile"));
	}
	
	FindClose(hFind);
	return dwError;
}
// display error message
// this is a example from MSDN:
// https://msdn.microsoft.com/en-us/library/windows/desktop/aa365200%28v=vs.85%29.aspx
void DisplayErrorBox(LPTSTR lpszFunction) 
{ 
	// Retrieve the system error message for the last-error code
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError(); 
	
	FormatMessage(
	    FORMAT_MESSAGE_ALLOCATE_BUFFER | 
	    FORMAT_MESSAGE_FROM_SYSTEM |
	    FORMAT_MESSAGE_IGNORE_INSERTS,
	    NULL,
	    dw,
	    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
	    (LPTSTR) &lpMsgBuf,
	    0, NULL );
	
	// Display the error message and clean up
	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, 
	    (lstrlen((LPCTSTR)lpMsgBuf)+lstrlen((LPCTSTR)lpszFunction)+40)*sizeof(TCHAR)); 
	StringCchPrintf((LPTSTR)lpDisplayBuf, 
	    LocalSize(lpDisplayBuf) / sizeof(TCHAR),
	    TEXT("%s failed with error %d: %s"), 
	    lpszFunction, dw, lpMsgBuf); 
	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK); 
	
	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
}
// judge if a file is C++ source file
bool isCPPSrc(const String &filename)
{
	auto dot_pos = filename.find_last_of(TEXT("."));
	String ext;
	if (dot_pos != String::npos) {
		ext = filename.substr(dot_pos, filename.size() - 1);
		#ifndef UNICODE
			std::transform(ext.begin(), ext.end(), ext.begin(), std::towlower);
		#else 
			std::transform(ext.begin(), ext.end(), ext.begin(), std::tolower);
		#endif
	}
	if (ext == TEXT(".c") || ext == TEXT(".cc") || ext == TEXT(".cpp") || ext == TEXT(".h")) {
		return true;
	} else {
		return false;
	}
}
// analysis file name
std::vector<std::size_t> analysis(const String &filename)
{
	std::vector<std::size_t> exercise;
	auto end = filename.find_last_of(TEXT("_"));
	for (auto beg = filename.find_first_of(TEXT("_")), next = beg;
	    beg != end && beg != filename.size() - 1;
	    beg = next) {
		next = filename.find_first_of(TEXT("_"), beg + 1);
		if (next == String::npos)
			next = filename.find_last_of(TEXT("."));
		if(next - beg == 3) {
		#ifndef UNICODE
			if (std::isdigit(filename[beg + 1]) && std::isdigit(filename[beg + 2])) {
		#else
			if (std::iswdigit(filename[beg + 1]) && std::iswdigit(filename[beg + 2])) {
		#endif
				exercise.push_back(stoi(filename.substr(beg + 1, beg + 2)));
			}
		}
	}
	return exercise;
}