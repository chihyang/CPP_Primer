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