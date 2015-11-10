#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
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
string make_plural(size_t, const string&, const string&);
class QueryResult;
class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};
class QueryResult{
friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s,
	            shared_ptr<set<TextQuery::line_no>> p,
				shared_ptr<vector<string>> f) :
		sought(s), lines(p), file(f) { }
	// members required by exercise 12.33
	set<TextQuery::line_no>::iterator begin(const string& sought) { return lines->begin();}
	set<TextQuery::line_no>::iterator end(const string& sought) { return lines->end();}
	shared_ptr<vector<string>> get_file() { return file; }
private:
	string sought;
	shared_ptr<set<TextQuery::line_no>> lines;
	shared_ptr<vector<string>> file;
};
// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
	string text;
	while(getline(is, text))        //for each line in the file
	{
		file->push_back(text);      // remember this line of text
		int n = file->size() - 1;    // the current line number
		istringstream line(text);   // separate the line into words
		string word;
		while(line >> word)         // for each word in that line
		{
			// if word isn't already in wm, subscripting adds a new entry
			auto &lines = wm[word]; // lines is a shared_ptr
			if(!lines)  // that pointer is null the first time we see word
				lines.reset(new set<line_no>);  // allocate a new set
			lines->insert(n);        // insert this line number
		}
	}
}
QueryResult TextQuery::query(const string& sought) const
{
	// we'll return a pointer to this set if we don't find sought
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	//use find and not a subscript to avoid adding words to wm!
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file); // not found
	else
		return QueryResult(sought, loc->second, file);
}
ostream& print(ostream& os, const QueryResult& qr)
{
	// if the word was found, print the count and all occurrences
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << make_plural(qr.lines->size(), "time", "s") << endl;
	// print each line in which the word appeared
	for(auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") "
	       <<*(qr.file->begin() + num) << endl;
	return os;
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}