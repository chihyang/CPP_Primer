#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::uppercase;
using std::nouppercase;
using std::left;
using std::right;
using std::setw;
using std::sqrt;
int main()
{
	// specifying the notation of floating numbers
	cout << left
	     << setw(20) << "default format: " << 100 * sqrt(2.0) << '\n'
	     << setw(20) << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
	     << setw(20) << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
	     << setw(20) << "hexadecimal: " << uppercase << hexfloat << 100 * sqrt(2.0) << nouppercase << '\n' 
		 // result has problem, see below
	     << setw(20) << "use defaults: " << defaultfloat << 100 * sqrt(2.0)
	     << right
	     << endl;
	return 0;
}