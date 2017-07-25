struct A {
public:
    A();
private:
    int val = 0;
};
inline A::A() = default; // if we use = default, there needn't be a function body
int main()
{
    A a;
    return 0;
}
// Note: if we use = default, it seems that there can't be a function body, a
// initializer list or default arguments. Definition on page 306 says:
// = default is a syntax used after the parameter list of the declaration of the
// default constructor inside a class to signal to the compiler it should generate
// the constructor, even if the class has other constructors.
// But it seems only a constructor without zero parameter could be declared as
// default. If = default is added to a constructor that has default arguments(s),
// the program won't compile. It's really confusing. This problem needs more
// consideration.

// PS: Chapter 13 has a more detailed explanation on this problem:
// We can use =default only on member functions that have a synthesized version.
// See page 506 for more details. Simply speaking, when we use default, we are
// requiring the compiler to generate this function, thus of course we needn't
// write function body. Moreover, default needn't appear inside a class. It can
// also appear outside the class along with function definition--although called
// "definition", this definition is special: it has no function body, just a
// function declaration followed by =default and a semicolon.
