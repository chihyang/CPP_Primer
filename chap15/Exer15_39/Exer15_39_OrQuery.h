#ifndef OR_QUERY_H
#define OR_QUERY_H
#include <memory>
#include "Exer15_39_TextQuery.h"
#include "Exer15_39_BinaryQuery.h"
#include "Exer15_39_Query.h"
class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right) :
        BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery&) const;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
#endif
