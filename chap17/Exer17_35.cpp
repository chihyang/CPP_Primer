#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::uppercase;
using std::nouppercase;
using std::sqrt;
int main()
{
    // specifying the notation of floating numbers
    cout << "default format: " << 100 * sqrt(2.0) << '\n'
         << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
         << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << "hexadecimal: " << uppercase << hexfloat << 100 * sqrt(2.0) << nouppercase << '\n'
         << "use defaults: " << defaultfloat << 100 * sqrt(2.0)
         << "\n\n";
    return 0;
}
