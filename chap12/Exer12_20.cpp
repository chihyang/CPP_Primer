#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Exer12_19_StrBlob.h"
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::out_of_range;
using std::runtime_error;
int main(int argc, char* argv[])
{
    if(argc != 2)
        return -1;
    ifstream is(argv[1]);
    string line;
    StrBlob text({});
    StrBlobPtr text_ptr(text);
    try
    {
        while(getline(is, line))
        {
            text.push_back(line);
        }
        size_t line_num = 0;
        while(line_num < text.size())
        {
            cout << (line_num + 1) << "\t" << text_ptr.deref() << endl;
            ++line_num;
            text_ptr.incr();
        }
    }
    catch(out_of_range out)
    {
        cout << out.what() << endl;
    }
    catch(runtime_error run)
    {
        cout << run.what() << endl;
    }
    return 0;
}
