// Query class family from exercise 15.41 and 15.42.
#include <cstddef>
#include <algorithm>
#include <iterator>
#include <set>
#include <memory>
#include "Exer19_06_07_08_Query.h"
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
// returns the intersection of its operands' result sets
QueryResult AndQuery::eval(const TextQuery &text) const
{
	// virtual calls through the Query operands to get result sets for the operands
	auto left = lhs.eval(text), right = rhs.eval(text);
	// set to hold the intersection of left and right
	auto ret_lines = std::make_shared<std::set<line_no>>();
	// writes the intersection of two ranges to a destination iterator
	// destination iterator in this call adds elements to ret_lines
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
	                      std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}
// returns the lines not in its operand's result set
QueryResult NotQuery::eval(const TextQuery &text) const
{
	// virtual call to eval through the Query operand
	auto result = query.eval(text);
	// start out with an empty set
	auto ret_lines = std::make_shared<std::set<line_no>>();
	// we have to iterate through the lines on which our operand appears
	auto beg = result.begin(), end = result.end();
	// for each line in the input file, if that line is not in result,
	// add that line number to ret_lines
	auto sz = result.get_file()->size();
	for(std::size_t n = 0; n != sz; ++n) {
		// if we haven't processed all the lines in result
		// check whether this line is present
		if (beg == end || *beg != n)
			ret_lines->insert(n); // if not in result, add this line
		else
			++beg; // otherwise get the next line number in result if there is one
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}