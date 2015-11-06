#ifndef STRBLOB_H
#define STRBLOB_H
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using std::string;
using std::vector;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::out_of_range;
class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	// add and remove elements
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	// elements access
	string& front();
	string& back();
	// const versions of front and back required by exercise 12.2
	const string& front() const;
	const string& back() const;
	// return reference count
	const size_type use_count() const { return data.use_count(); }
private:
	shared_ptr<vector<string>> data;
	// throws msg if data[i] isn't valid
	void check(size_type i, const string &msg) const;
};
// constructor
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : 
    data(make_shared<vector<string>>(il)) {};
void StrBlob::check(size_type i, const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);
}
// add and remove elements
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
// elements access
string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	data->front();
}
string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	data->back();
}
const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	data->front();
}
const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	data->back();
}
#endif