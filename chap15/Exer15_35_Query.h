// abstract class acts as a base for concrete query types; all members are private
#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include <iostream>
#include <string>
#include <memory>
#include "Exer15_35_TextQuery.h"
class Query_base {
    friend class Query;
protected:
    Query_base() {
        #ifndef NDEBUG
        std::cerr << "Query_base::Query_base()" << std::endl;
        #endif
    }
    using line_no = TextQuery::line_no; // used in eval functions
    virtual ~Query_base() = default;
private:
    // eval returns the QueryResult that matches this Query
    // virtual QueryResult eval(const TextQuery&) const = 0;
    // rep is a string representing of the query
    virtual std::string rep() const = 0;
};
// interface class to manage the Query_base inheritance hierarchy
class Query {
    // these operators access to the shared_ptr constructor
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&); // builds a new WordQuery
    // interface functions: call the corresponding Query_base operations
    // QueryResult eval(const TextQuery &t) const
    //     { return q->eval(t); }
    std::string rep() const {
        #ifndef NDEBUG
        std::cerr << "Query::rep()" << std::endl;
        #endif
        return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query) : q(query) {
        #ifndef NDEBUG
        std::cerr << "Query::Query(shared_ptr<Query_base>)" << std::endl;
        #endif
    }
    std::shared_ptr<Query_base> q;
};
// output result
std::ostream& operator<<(std::ostream &os, const Query &query)
{
    // Query::rep makes a virtual call through its Query_base pointer to rep()
    return os << query.rep();
}
class WordQuery : public Query_base {
    friend class Query; // Query uses the WordQuery constructors
    WordQuery(const std::string &s) : query_word(s) {
        #ifndef NDEBUG
        std::cerr << "WordQuery::WordQuery(const string&)" << std::endl;
        #endif
    }
    // concrete class: WordQuery defines all inherited pure virtual functions
    // QueryResult eval(const TextQuery &t) const
    //    { return t.query(query_word); }
    std::string rep() const {
        #ifndef NDEBUG
        std::cerr << "WordQuery::rep()" << std::endl;
        #endif
        return query_word;
    }
    std::string query_word; // word for which to search
};
// constructor of Query that takes a string parameter
inline Query::Query(const std::string &s) : q(new WordQuery(s))
{
    #ifndef NDEBUG
    std::cerr << "Query::Query(const string&)" << std::endl;
    #endif
}
class NotQuery : public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query &q) : query(q) {
        #ifndef NDEBUG
        std::cerr << "NotQuery::NotQuery(const Query)" << std::endl;
        #endif
    }
    // concrete class: NotQuery defines all inherited pure virtual functoins
    std::string rep() const {
        #ifndef NDEBUG
        std::cerr << "NotQuery::rep()" << std::endl;
        #endif
        return "~(" + query.rep() + ")";
    }
    // QueryResult eval(const TextQuery&) const;
    Query query;
};
// allocate a new NotQuery object and bind the resulting NotQuery pointer to a shared_ptr<Query_base>
inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) :
        lhs(l), rhs(r), opSym(s) {
            #ifndef NDEBUG
            std::cerr << "BinaryQuery::BinaryQuery(const Query&, const Query&, string)" << std::endl;
            #endif
        }
    // abstract class: BinaryQuery doesn't define eval
    std::string rep() const {
        #ifndef NDEBUG
        std::cerr << "BinaryQuery::rep()" << std::endl;
        #endif
        return "(" + lhs.rep() + " "
                   + opSym + " "
                   + rhs.rep() + ")";
    }
    Query lhs, rhs;    // right and left-hand operand
    std::string opSym; // name of the operator
};
class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right) :
        BinaryQuery(left, right, "&") {
            #ifndef NDEBUG
            std::cerr << "AndQuery::AndQuery(const Query&, const Query&)" << std::endl;
            #endif
        }
    // concrete class: AndQuery inherits rep and defines the remaining pure virtual
    // QueryResult eval(const TextQuery&) const;
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right) :
        BinaryQuery(left, right, "|") {
            #ifndef NDEBUG
            std::cerr << "OrQuery::OrQuery(const Query&, const Query&)" << std::endl;
            #endif
        }
    // QueryResult eval(const TextQuery&) const;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
#endif
