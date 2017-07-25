#ifndef NOT_QUERY_H
#define NOT_QUERY_H
#include <string>
#include <memory>
#include "Exer15_39_TextQuery.h"
#include "Exer15_39_Query_base.h"
#include "Exer15_39_Query.h"
class NotQuery : public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query &q) : query(q) {}
    // concrete class: NotQuery defines all inherited pure virtual functoins
    std::string rep() const {}
    QueryResult eval(const TextQuery&) const;
    Query query;
};
inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
#endif
