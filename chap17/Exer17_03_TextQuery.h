// TextQuery class header from exercise 12.30
#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <tuple>
std::string make_plural(size_t, const std::string&, const std::string&);
class QueryResult;
class TextQuery{
public:
    using line_no = std::vector<std::string>::size_type;
    // replace QueryResult with tuple, required by exercise 17.33
    using QueryResult = std::tuple<std::string,
                                   std::shared_ptr<std::set<line_no>>,
                                   std::shared_ptr<std::vector<std::string>>>;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
std::ostream& print(std::ostream&, const TextQuery::QueryResult&);
#endif
