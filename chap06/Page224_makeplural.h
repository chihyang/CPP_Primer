// This function will be used frequently by subsequent chapters.
#include <string>
using std::string;
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
