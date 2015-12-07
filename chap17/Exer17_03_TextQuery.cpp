// TextQuery class source file from exercise 12.30
#include "Exer17_03_TextQuery.h"
// read the input file and build the std::map of lines to line numbers
TextQuery::TextQuery(std::ifstream& is) : file(new std::vector<std::string>)
{
	std::string text;
	while(getline(is, text))        //for each line in the file
	{
		file->push_back(text);      // remember this line of text
		int n = file->size() - 1;    // the current line number
		std::istringstream line(text);   // separate the line into words
		std::string word;
		while(line >> word)         // for each word in that line
		{
			// if word isn't already in wm, subscripting adds a new entry
			auto &lines = wm[word]; // lines is a std::shared_ptr
			if(!lines)  // that pointer is null the first time we see word
				lines.reset(new std::set<line_no>);  // allocate a new std::set
			lines->insert(n);        // insert this line number
		}
	}
}
TextQuery::QueryResult TextQuery::query(const std::string& sought) const
{
	// we'll return a pointer to this std::set if we don't find sought
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	//use find and not a subscript to avoid adding words to wm!
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file); // not found
	else
		return QueryResult(sought, loc->second, file);
}
std::ostream& 
print(std::ostream &os, const TextQuery::QueryResult &qr)
{
	// if the word was found, print the count and all occurrences
	os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << " "
	   << make_plural(std::get<1>(qr)->size(), "time", "s") << std::endl;
	// print each line in which the word appeared
	for(auto num : *(std::get<1>(qr)))
		os << "\t(line " << num + 1 << ") "
	       << *((std::get<2>(qr))->begin() + num) << std::endl;
	return os;
}
std::string make_plural(size_t ctr, const std::string &word, const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}