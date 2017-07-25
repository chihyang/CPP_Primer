// Warning: this is for verification. It cannot compile.
#include <cstddef>
class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0); // conversion from int
    operator int() const { return val; } // conversion to int
private:
    std::size_t val;
};
SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs)
{
    return lhs.val + rhs.val;
}
int main()
{
    SmallInt s1, s2;
    // uses overloaded operator+
    SmallInt s3 = s1 + s2;
    // error: ambiguous call; whether to convert s3 to int and then call built-in addition operator or
    // convert 0 SmallInt and then to call overloaded addition operator?
    int i = s3 + 0;
    return 0;
}
