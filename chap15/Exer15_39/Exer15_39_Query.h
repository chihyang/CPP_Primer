// interface class to manage the Query_base inheritance hierarchy
#ifndef QUERY_H
#define QUERY_H
#include <iostream>
#include <memory>
#include <string>
#include "Exer15_39_TextQuery.h"
#include "Exer15_39_WordQuery.h"
class Query {
	// these operators access to the shared_ptr constructor
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string &s) : q(new WordQuery(s)) {}; // builds a new WordQuery
	// interface functions: call the corresponding Query_base operations
	QueryResult eval(const TextQuery &t) const 
	    { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q;
};
std::ostream& operator<<(std::ostream&, const Query&);
#endif