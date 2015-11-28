#ifndef AND_QUERY_H
#define AND_QUERY_H
#include <memory>
#include "Exer15_39_TextQuery.h"
#include "Exer15_39_BinaryQuery.h"
#include "Exer15_39_Query.h"
class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) : 
	    BinaryQuery(left, right, "&") {}
	// concrete class: AndQuery inherits rep and defines the remaining pure virtual
	QueryResult eval(const TextQuery&) const;
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
#endif