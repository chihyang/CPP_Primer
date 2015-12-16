// TextQuery class from exercise 15.41 and 15.42.
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
std::string make_plural(size_t, const std::string&, const std::string&);
class QueryResult;
class TextQuery{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
class QueryResult{
	friend std::ostream& print(std::ostream&, const QueryResult&, TextQuery::line_no, TextQuery::line_no);
public:
	QueryResult(std::string s,
	            std::shared_ptr<std::set<TextQuery::line_no>> p,
				std::shared_ptr<std::vector<std::string>> f) :
		sought(s), lines(p), file(f) { }
	// members required by exercise 12.33
	std::set<TextQuery::line_no>::iterator begin() const { return lines->begin();}
	std::set<TextQuery::line_no>::iterator end() const { return lines->end();}
	std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};
#endif