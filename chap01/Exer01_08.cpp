//Comment test.
#include <iostream>
int main()
{
	//Right
	std::cout << "/*";
	std::cout << "*/";
	std::cout << /* "*/" /* "/*" */;
	//Wrong
	// std::cout << /* "*/" */;
	std::cout << /* "*/" */"; // This is a possible remedy.
	return 0;
}