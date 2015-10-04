#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	char str1[] = "I'm string 1.";
	char str2[] = "I'm string 2.";
	const int len = strlen(str1) + strlen(str2) + 2;
	char str3[len];
	strcpy(str3, str1);
	strcat(str3, str2);
	cout << str3 << endl;
	return 0;
}