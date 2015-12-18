// Warning: this header has inherent error. See notes in Exer12_27.cpp.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
class QueryResult;
std::ostream& print(std::ostream&, const QueryResult&);
class TextQuery{
friend class QueryResult;
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_num = std::vector<std::string>::size_type;
	explicit TextQuery(std::ifstream &infile);
	QueryResult query(const std::string&);
private:
	std::vector<std::string> text;
	std::map<std::string, std::set<line_num>> word_line;
};
class QueryResult{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(const std::string& s, TextQuery::line_num cnt, TextQuery *text) : query_word(s), occurences(cnt), query_result(text) {}
private:
	const std::string query_word;
	TextQuery::line_num occurences = 0;
	// This is wrong.
	std::shared_ptr<TextQuery> query_result;
};
TextQuery::TextQuery(std::ifstream &infile)
{
	std::string line, word;
	line_num curr_line = 0;
	while(getline(infile, line))
	{
		std::istringstream word_breakup(line);
		text.push_back(line);
		while(word_breakup >> word)
		{
			(word_line[word]).insert(curr_line);
		}
		++curr_line;
	}
}
QueryResult TextQuery::query(const std::string& str)
{
	line_num cnt = 0;
	auto find_rst = word_line.find(str);
	if(find_rst != word_line.end())
	{
		for(auto iter = find_rst->second.cbegin(); iter != find_rst->second.cend(); ++iter)
		{
			std::string output_line = text[*iter];
			std::istringstream is(output_line);
			std::vector<std::string> line_breakup;
			std::string out_word;
			while(is >> out_word)
				line_breakup.push_back(out_word);
			cnt += count(line_breakup.cbegin(), line_breakup.cend(), str);
		}
	}
	return QueryResult(str, cnt, this);
}
std::ostream& print(std::ostream& os, const QueryResult& q_rst)
{
	os << "element occurs " << q_rst.occurences << " times" << std::endl;
	if(q_rst.query_result.use_count() > 0)
	{	
		std::shared_ptr<TextQuery> query_ptr = q_rst.query_result;
		auto iter = (query_ptr->word_line).find(q_rst.query_word);
		for(auto it = iter->second.cbegin(); it != iter->second.cend(); ++it)
			os << "(line " << *it << ") " << ((query_ptr->text)[*it]) << std::endl;
	}
	return os;
}