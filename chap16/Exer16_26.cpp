#include <vector>
using std::vector;
class NoDefault {
public:
    NoDefault(int i) : val(i) {}
private:
    int val;
};
template class vector<NoDefault>;
int main()
{
    return 0;
}
