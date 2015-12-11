#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;
using std::noboolalpha;
using std::hex;
using std::dec;
using std::oct;
using std::showbase;
using std::noshowbase;
using std::uppercase;
using std::nouppercase;
using std::setprecision;
using std::scientific;
using std::fixed;
using std::hexfloat;
using std::defaultfloat;
using std::showpoint;
using std::noshowpoint;
using std::setw;
using std::left;
using std::right;
using std::internal;
using std::setfill;
using std::noskipws;
using std::skipws;
using std::setbase;
using std::sqrt;
int main()
{
	// format of bool values
	cout << "default bool values: " << true << " " << false
	     << "\nalpha bool values: " << boolalpha
	     << true << " " << false << endl;
	bool bool_val = cout.good();
	cout << boolalpha   // sets the internal state of cout
	     << bool_val
	     << noboolalpha // resets the internal state to default formatting
	     << '\n'
	     << endl;
	// base for integral values
	cout << "default: " << 20 << " " << 1024 << endl;
	cout << "octal: " << oct << 20 << " " << 1024 << endl;
	cout << "hex: " << hex << 20 << " " << 1024 << endl;
	cout << "decimal: " << dec << 20 << " " << 1024 << endl;
	cout << endl;
	// indicating base on the output
	cout << showbase;   // show the base when printing integral values
	cout << "default: " << 20 << " " << 1024 << endl;
	cout << "octal: " << oct << 20 << " " << 1024 << endl;
	cout << "hex: " << hex << 20 << " " << 1024 << endl;
	cout << "decimal: " << dec << 20 << " " << 1024 << endl;
	cout << noshowbase; // reset the state of the stream
	cout << uppercase << showbase << hex
	     << "printed in hexadecimal: " << 20 << " " << 1024
	     << nouppercase << noshowbase << dec << endl;
	cout << endl;
	// format of floating-point values
	// specify precision
	// cout.precision reports the current precision value
	cout << "Precision: " << cout.precision()
	     << ", Value: " << sqrt(2.0) << endl;
	// cout.precision(12) asks that 12 digits of precision be printed
	cout.precision(12);
	cout << "Precision: " << cout.precision()
	     << ", Value: " << sqrt(2.0) << endl;
	// alternative way to set precision using the setprecision manipulator
	cout << setprecision(3);
	cout << "Precision: " << cout.precision()
	     << ", Value: " << sqrt(2.0) << endl;
	cout << setprecision(6);
	cout << endl;
	// specifying the notation of floating numbers
	cout << "default format: " << 100 * sqrt(2.0) << '\n'
	     << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
	     << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
	     << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n' // result has problem, see below
	     << "use defaults: " << defaultfloat << 100 * sqrt(2.0)
	     << "\n\n";
	// printing the decimal point
	cout << 10.0 << endl;        // prints 10
	cout << showpoint << 10.0    // prints 10.0000
	     << noshowpoint << endl; // revert to default format for the decimal point
	cout << endl;
	// padding the output
	int i = -16;
	double d = 3.14159;
	// pad the forst column to use a minimum of 12 positions in the output
	cout << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';
	// pad the first column and left-justify all columns
	cout << left
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n'
	     << right; // restore normal justification
	// pad the first column and right-justify all columns
	cout << right
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';
	// pad the first column but put the padding internal to to field 
	cout << internal
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';
	// pad the first column, using # as the pad character
	cout << setfill('#')
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n'
	     << setfill(' '); // restore the normal pad character
	cout << endl;
	// controlling input formatting
	char ch;
	cin >> noskipws; // set cin so that it reads whitespace
	while (cin >> ch)
		cout << ch;
	cin >> skipws;   // reset cin to the default state so that it discards whitespace
	// setbase
	cout << setbase(16)
	     << "i: " << i << '\n'
	     << "d: " << d << '\n' // floating-point number is not influenced.
	     << setbase(10)
	     << endl;
	return 0;
}
// ******result of cout << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'******
// hexadecimal: 0x8.d6bde009b35cp+4(gcc/clang)
// hexadecimal: 0x1.1ad7bcp+7(cl)
// reason is unknown for now.