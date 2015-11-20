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
using std::endl;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::shared_ptr;
class QueryResult;
ostream& print(ostream&, const QueryResult&);
class TextQuery{
friend class QueryResult;
friend ostream& print(ostream&, const QueryResult&);
public:
	using line_num = vector<string>::size_type;
	explicit TextQuery(ifstream &infile);
	QueryResult query(const string&);
private:
	vector<string> text;
	map<string, set<line_num>> word_line;
};
class QueryResult{
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(const string& s, TextQuery::line_num cnt, TextQuery *text) : query_word(s), occurences(cnt), query_result(text) {}
private:
	const string query_word;
	TextQuery::line_num occurences = 0;
	// This is wrong.
	shared_ptr<TextQuery> query_result;
};
TextQuery::TextQuery(ifstream &infile)
{
	string line, word;
	line_num curr_line = 0;
	while(getline(infile, line))
	{
		istringstream word_breakup(line);
		text.push_back(line);
		while(word_breakup >> word)
		{
			(word_line[word]).insert(curr_line);
		}
		++curr_line;
	}
}
QueryResult TextQuery::query(const string& str)
{
	line_num cnt = 0;
	auto find_rst = word_line.find(str);
	if(find_rst != word_line.end())
	{
		for(auto iter = find_rst->second.cbegin(); iter != find_rst->second.cend(); ++iter)
		{
			string output_line = text[*iter];
			istringstream is(output_line);
			vector<string> line_breakup;
			string out_word;
			while(is >> out_word)
				line_breakup.push_back(out_word);
			cnt += count(line_breakup.cbegin(), line_breakup.cend(), str);
		}
	}
	return QueryResult(str, cnt, this);
}
ostream& print(ostream& os, const QueryResult& q_rst)
{
	os << "element occurs " << q_rst.occurences << " times" << endl;
	if(q_rst.query_result.use_count() > 0)
	{	
		shared_ptr<TextQuery> query_ptr = q_rst.query_result;
		auto iter = (query_ptr->word_line).find(q_rst.query_word);
		for(auto it = iter->second.cbegin(); it != iter->second.cend(); ++it)
			os << "(line " << *it << ") " << ((query_ptr->text)[*it]) << endl;
	}
	return os;
}