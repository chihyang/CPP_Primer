#include <cstddef>
#include <iostream>
#include <string>
#include <bitset>
#include <stdexcept>
using std::size_t;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::bitset;
using std::overflow_error;
int main()
{
	bitset<32> bitvec(1U); // 32bits; low-order bit is 1, remaining bits are 0
	bool is_set = bitvec.any();      // true, one bit is set
	bool is_not_set = bitvec.none(); // false, one bit is set
	bool all_set = bitvec.all();     // false, only one bit is set
	size_t onBits = bitvec.count();  // return 1
	size_t sz = bitvec.size();       // return 32
	cout << onBits << "\n" << sz << endl;
	bitvec.flip();  // reverses the value of all the bits in bitvec 
	cout << bitvec << endl;
	bitvec.reset(); // sets all the bits to 0
	cout << bitvec << endl;
	bitvec.set();   // sets all the bits to 1
	cout << bitvec << endl;
	bitvec.flip(0);   // reverses the value of the first bit
	cout << bitvec << endl;
	bitvec.set(bitvec.size() - 1); // turns on the last bit
	cout << bitvec << endl;
	bitvec.set(0, 0); // turns on the first bit
	cout << bitvec << endl;
	bitvec.reset(3);  // turns on the third bit
	cout << bitvec << endl;
	bitvec.test(0);   // returns false because the first bit is off
	cout << bitvec << endl;
	bitvec[0] = 0;          // turn off the bit at position 0
	cout << bitvec << endl;
	bitvec[31] = bitvec[0]; // set the last bit to the same value as the first bit
	cout << bitvec << endl;
	bitvec[0].flip();       // flip the value of the bit at position 0
	cout << bitvec << endl;
	~bitvec[0];             // equivalent operation; flip the bit at position 0
	cout << bitvec << endl;
	bool b = bitvec[0];     // convert the value of bitvec[0] to bool
	try {
		bitset<128> bitvec3(~0ULL);
		unsigned long ulong  = bitvec3.to_ulong(); // error: overflow
	} catch(overflow_error err) {
		cout << err.what() << endl;
	}
	bitset<16> bits;
	cin >> bits; // read up to 16 1 or 0 character from cin
	cout << "bits: " << bits << endl; // print what we just reads
	return 0;
}