#include <string>
#include <vector>
struct Base1 {
	void print(int) const {} // public by default
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};
struct Base2 {
	void print(double) const; // public by default
protected:
	float fval;
private:
	double dval;
};
struct Derived : public Base1 {
	void print(std::string) const; // public by default
protected:
	std::string sval;
	double dval;
};
struct MI : public Derived, public Base2 {
	void print(std::vector<double>) const; // public by default
	void print(int i) { Base1::print(i); }
protected:
	int *ival;
	std::vector<double> dvec;
};
int main()
{
	MI mi;
	mi.print(42);
	return 0;
}