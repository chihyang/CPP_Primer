#ifndef WORD_QUERY_H
#define WORD_QUERY_H
#include <string>
#include "Exer15_39_TextQuery.h"
#include "Exer15_39_Query_base.h"
class WordQuery : public Query_base {
	friend class Query; // Query uses the WordQuery constructors
	WordQuery(const std::string &s) : query_word(s) {}
	// concrete class: WordQuery defines all inherited pure virtual functions
	QueryResult eval(const TextQuery &t) const
	   { return t.query(query_word); }
	std::string rep() const { return query_word; }
	std::string query_word; // word for which to search
};
#endif