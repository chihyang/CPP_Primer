#include <iostream>
#include <string>
#include <utility>
#include "Exer19_21_25_Token.h"
#include "Sales_data.h"
std::ostream& operator<<(std::ostream &os, const Token &t)
{
	switch(t.tok) {
		case Token::INT: os << t.ival; break;
		case Token::CHAR: os << t.cval; break;
		case Token::DBL: os << t.dval; break;
		case Token::STR: os << t.sval; break;
		case Token::SALE: os << t.sdata; break;
	}
	return os;
}
// assignment
Token& Token::operator=(int i)
{
	freeUnion();                 // if we have a string or Sales_data, free it
	ival = i;                    // assign to the appropriate member
	tok = INT;                   // update the discriminant
	return *this;
}
Token& Token::operator=(char c)
{
	freeUnion();                 // if we have a string or Sales_data, free it
	cval = c;                    // assign to the appropriate member
	tok = CHAR;                  // update the discriminant
	return *this;
}
Token& Token::operator=(double d)
{
	freeUnion();                 // if we have a string or Sales_data, free it
	dval = d;                    // assign to the appropriate member
	tok = DBL;                   // update the discriminant
	return *this;
}
Token& Token::operator=(const std::string &s)
{
	std::string stmp = s;                    // copy the string
	freeUnion();                             // free the resources if necessary
	new(&sval) std::string(std::move(stmp)); // move the string
	tok = STR;
	return *this;
}
Token& Token::operator=(const Sales_data &item)
{
	Sales_data itmp = item;                  // copy the Sales_data
	freeUnion();                             // free the resources if necessary
	new(&sdata) Sales_data(std::move(itmp)); // otherwise construct a string
	tok = SALE;
	return *this;
}
// common operations for copy
void Token::copyUnion(const Token &t)
{
	switch (t.tok) {
		case Token::INT: ival = t.ival; break;
		case Token::CHAR: cval = t.cval; break;
		case Token::DBL: dval = t.dval; break;
		// to copy a string, construct it using placement new
		case Token::STR: new(&sval) std::string(t.sval); break;
		// to copy a Sales_data, construct it using placement new
		case Token::SALE: new(&sdata) Sales_data(t.sdata); break;
	}
}
// common operations for move
void Token::moveUnion(Token &&t)
{
	switch (t.tok) {
		case Token::INT: ival = std::move(t.ival); break;
		case Token::CHAR: cval = std::move(t.cval); break;
		case Token::DBL: dval = std::move(t.dval); break;
		case Token::STR: new(&sval) std::string(std::move(t.sval)); break;
		// to copy a Sales_data, construct it using placement new
		case Token::SALE: new(&sdata) Sales_data(std::move(t.sdata)); break;
	}
}
// copy assignment operator
Token& Token::operator=(const Token &t)
{
	// if this object holds a string and t doesn't, we have to free the old string
	if (tok == STR && t.tok != STR) sval.std::string::~string();
	if (tok == SALE && t.tok != SALE) sdata.~Sales_data();
	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else if (tok == SALE && t.tok == SALE)
		sdata = t.sdata;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}
// move assignment operator
Token& Token::operator=(Token &&t) noexcept
{
	if(this != &t) {
		freeUnion();
		moveUnion(std::move(t));
		tok = std::move(t.tok);
	}
	return *this;
}