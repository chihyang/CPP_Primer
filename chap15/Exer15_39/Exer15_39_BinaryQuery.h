#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H
#include <string>
#include "Exer15_39_Query_base.h"
#include "Exer15_39_Query.h"
class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) : 
	    lhs(l), rhs(r), opSym(s) {}
	// abstract class: BinaryQuery doesn't define eval
	std::string rep() const {
		return "(" + lhs.rep() + " "
	               + opSym + " "
	               + rhs.rep() + ")";
	}
	Query lhs, rhs;    // right and left-hand operand
	std::string opSym; // name of the operator
};
#endif