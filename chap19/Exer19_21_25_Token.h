// Warning: Visual Studio 2013 doesn't support union with class type member that has copy-control 
// operations. Use higher version or other compilers.
#ifndef EXER19_21_TOKEN_H
#define EXER19_21_TOKEN_H
#include <iostream>
#include <string>
#include <utility>
#include "Sales_data.h" // required by exercise 19.25
class Token {
	// overloaded output operator
	friend std::ostream& operator<<(std::ostream&, const Token&);
public:
	// copy control needed because our class has a union with a string member
	Token() : tok(INT), ival{0} {}
	Token(const Token &t) : tok(t.tok) { copyUnion(t); }
	// move constructor, required by exercise 19.23
	Token(Token &&t) : tok(std::move(t.tok)) { moveUnion(std::move(t)); }
	Token& operator=(const Token&);
	// move assignment operator, required by exercise 19.23
	Token& operator=(Token&&);
	// if the union holds a string, we must destroy it
	~Token() { freeUnion(); }
	// assignment operators to set the differing members of the union
	Token& operator=(const std::string&);
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);
	Token& operator=(const Sales_data&); // required by exercise 19.25
private:
	enum { INT, CHAR, DBL, STR, SALE } tok; // discriminant
	union {                           // anonymous union
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sdata; // Sales_data member, required by exercise 19.22
	}; // each Token object has an unnamed member of this unnamed union type
	// check the discriminant and copy the union member as appropriate
	void copyUnion(const Token&);
	void moveUnion(Token &&t);
	void freeUnion(); // free class type member of union
};
inline
void Token::freeUnion()
{
	if(tok == STR)
		sval.std::string::~string();
	if(tok == SALE)
		sdata.~Sales_data();
}
#endif