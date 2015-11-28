#include <set>
#include <memory>
#include "Exer15_39_TextQuery.h"
#include "Exer15_39_Query.h"
#include "Exer15_39_OrQuery.h"
// returns the union of its operands' result sets
QueryResult OrQuery::eval(const TextQuery &text) const
{
	// virtual calls through Query members, lhs and rhs
	// the calls to eval return the QueryResult for each operand
	auto left = lhs.eval(text), right = rhs.eval(text);
	// copy the line numbers from the left-hand operand into the result set
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	// insert lines from the right-hand operand
	ret_lines->insert(right.begin(), right.end());
	// returns the new QueryResult representing the union of lhs and rhs
	return QueryResult(rep(), ret_lines, left.get_file());
}