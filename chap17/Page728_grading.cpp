#include <bitset>
using std::bitset;
int main()
{
    bool status;
    // version using bitwise operators
    unsigned long quizA = 0;      // this value is used as a collection of bits
    quizA |= 1UL << 27;           // indicate student number 27 passed
    status = quizA & (1UL << 27); // check how student number 27 did
    quizA &= ~(1UL << 27);        // student number 27 failed
    // equivalent actions using the bitset library
    bitset<30> quizB;    // allocate one bit per student; all bits initialized to 0
    quizB.set(27);       // indicate student number 27 passed
    status = quizB[27];  // check how student number 27 did
    quizB.reset(27);     // student number 27 failed
    return 0;
}
