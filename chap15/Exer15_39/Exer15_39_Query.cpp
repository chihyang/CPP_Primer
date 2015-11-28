#include "Exer15_39_Query.h"
// constructor of Query that takes a string parameter
// inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}
std::ostream& operator<<(std::ostream &os, const Query &query)
{
	// Query::rep makes a virtual call through its Query_base pointer to rep()
	return os << query.rep();
}