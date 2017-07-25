#include <cstddef>
#include <memory>
#include "Exer15_39_TextQuery.h"
#include "Exer15_39_Query.h"
#include "Exer15_39_NotQuery.h"
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
