// abstract class acts as a base for concrete query types; all members are private
#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include <cstddef>
#include <string>
#include <utility>
#include "Exer15_41_42_TextQuery.h"
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no; // used in eval functions
	virtual ~Query_base() = default;
private:
	// eval returns the QueryResult that matches this Query
	virtual QueryResult eval(const TextQuery&) const = 0;
	// rep is a string representing of the query
	virtual std::string rep() const = 0;
};

class WordQuery : public Query_base {
	friend class Query; // Query uses the WordQuery constructors
	WordQuery(const std::string &s) : query_word(s) {}
	// concrete class: WordQuery defines all inherited pure virtual functions
	QueryResult eval(const TextQuery &t) const
	   { return t.query(query_word); }
	std::string rep() const { return query_word; }
	std::string query_word; // word for which to search
};

class Query {
	// these operators access to the shared_ptr constructor
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string &s) : q(new WordQuery(s)), cnt(new std::size_t(1)) {}; // builds a new WordQuery
	// interface functions: call the corresponding Query_base operations
	QueryResult eval(const TextQuery &t) const 
	    { return q->eval(t); }
	std::string rep() const { return q->rep(); }
	// copy-control operations
	Query(const Query &query) : q(query.q), cnt(query.cnt) { ++*cnt; }
	Query(Query &&query) noexcept : q(query.q), cnt(query.cnt) { query.q = 0; }
	Query& operator=(const Query&);
	Query& operator=(Query&&) noexcept;
	~Query();
private:
	// Query(std::shared_ptr<Query_base> query) : q(query) {}
	Query(Query_base *query) : q(query), cnt(new std::size_t(1)) {}
	Query_base *q;
	std::size_t *cnt; // reference counter
	// std::shared_ptr<Query_base> q;
};
inline
Query& Query::operator=(const Query &rhs)
{
	++*rhs.cnt;
	if(--*cnt == 0)
	{
		delete q;
		delete cnt;
	}
	q = rhs.q;
	cnt = rhs.cnt;
	return *this;
}
inline
Query& Query::operator=(Query &&rhs) noexcept
{
	if(this != &rhs) {
		cnt = rhs.cnt;
		q = rhs.q;
		rhs.q = 0;
	}
	return *this;
}
inline
Query::~Query()
{
	if(--*cnt == 0) {
		delete q;
		delete cnt;
	}
}
inline std::ostream& operator<<(std::ostream &os, const Query &query)
{
	// Query::rep makes a virtual call through its Query_base pointer to rep()
	return os << query.rep();
}

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

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right) :
	    BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const;
};

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) : 
	    BinaryQuery(left, right, "&") {}
	// concrete class: AndQuery inherits rep and defines the remaining pure virtual
	QueryResult eval(const TextQuery&) const;
};

class NotQuery : public Query_base {
	friend Query operator~(const Query&);
	NotQuery(const Query &q) : query(q) {}
	// concrete class: NotQuery defines all inherited pure virtual functoins
	std::string rep() const {}
	QueryResult eval(const TextQuery&) const;
	Query query;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return (new OrQuery(lhs, rhs));
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return (new AndQuery(lhs, rhs));
}

inline Query operator~(const Query &operand)
{
	return (new NotQuery(operand));
}
// function table
// we have to provide another lambda to create a function table
// auto neg = [](const Query &operand, const Query &place_holder) { return ~(operand); };
// extern std::map<std::string, std::function(Query(const Query&, const Query&))> query_ops = {
	// {"&", operator&},
	// {"|", operator|},
	// {"~", neg} };
#endif