// TextQuery class from exercise 12.30.
#ifndef EXER19_20_TEXT_QUERY_H
#define EXER19_20_TEXT_QUERY_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
std::string make_plural(size_t, const std::string&, const std::string&);
class TextQuery{
public:
    class QueryResult; // nested class to be defined later
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
// we're defining the QueryResult class that is a member of class TextQuery
class TextQuery::QueryResult{
    // in class scope, we don't have to qualify the name of the QueryResult parameters
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    // no need to define QueryResult::line_no; a nested class can use a member
    // of its enclosing class without needing to qualify the member's name
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) :
        sought(s), lines(p), file(f) { }
    // members required by exercise 12.33
    std::set<line_no>::iterator begin() const { return lines->begin();}
    std::set<line_no>::iterator end() const { return lines->end();}
    std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
inline std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
#endif
