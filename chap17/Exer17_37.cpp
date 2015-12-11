// Warning: this is for verification. It cannot work properly.
// This program uses data file ./data/paragraph.
#include <cstddef>
#include <cstring>
#include <iostream>
#include <fstream>
using std::size_t;
using std::cout;
using std::endl;
using std::ifstream;
int main(int argc, char* argv[])
{
	if(argc != 2)
		return -1;
	ifstream is(argv[1]);
	char sink[80] = {'\0'};
	size_t size = 80;
	char delim = '\n';
	while(is.getline(sink, size, delim)) {
		cout.write(sink, size);
		memset(sink, '\0', size);
	}
	return 0;
}
// Note: once is.getline reads (size - 1) characters, it seems that the state of
// the stream is not good. Empty line is not read. But we reset sink every time 
// after finish using it, so the empty line could be output normally.