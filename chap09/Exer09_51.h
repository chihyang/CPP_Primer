#ifndef EXER09_51_H
#define EXER09_51_H
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::invalid_argument;
static const vector<string> MONALL{ "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
                       "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
class Date{
public:
	Date() = default;
	Date(const string&);
	Date& print_date();
private:
	bool isleap(unsigned); // judge if a year is leap
	unsigned year = 1900;
	unsigned month = 1;
	unsigned day = 1;
};
// Date format could be surprisingly complicated. See the wiki page for more info:
// https://en.wikipedia.org/wiki/Date_format_by_country
// Here, the constructor can only take one argument. So I suppose the order is
// month-date-year.
Date::Date(const string& date) : Date()
{
	unsigned year_temp = 0, month_temp = 0, day_temp = 0;
	if(date.empty()) // empty string is invalid
		throw invalid_argument("Argument shouldn't be empty");
	vector<string> split; // put valid strings into a vector
	string str;
	// filter white spaces and separators
	for(const auto &c : date)
	{
		if(!(isspace(c) || c == ',' || c == '-' || c == '/' || c == '.'))
			str.push_back(c); // any separators above (including contiguous white spaces) are okay
		else
		{
			if(!str.empty())
			{
				split.push_back(str);
				str.clear();
			}
		}
	}
	split.push_back(str); // don't forget to push back the last result
	if(split.size() != 3)
		throw invalid_argument("Not a valid date.");
	// if month begins with a letter, it might be a month in English
	if(isalpha(split[0][0]))
	{
		for(auto &c : split[0])
			c = toupper(c); // convert month to upper case
		for(decltype(MONALL.size()) m = 0; m <= MONALL.size(); ++m)
		{
			if(MONALL[m].find(split[0]) == 0) // abbreviation or full
			{
				if(split[0].size() >= 3 && split[0].size() <= MONALL[m].size())
				{
					month_temp = m + 1;
					break;
				}
				else
					throw invalid_argument("Not a valid month.");
			}				
			if(m == 11)
				throw invalid_argument("Not a valid month.");
		}
	}
	// or month should be a numeric value
	else if(isdigit(split[0][0]))
	{
		month_temp = stoi(split[0]);
		if(month_temp < 1 || month_temp > 12)
			throw invalid_argument("Not a valid month.");
	}
	// or the input month is wrong
	else
		throw invalid_argument("Input is not a month.");
	day_temp = stoi(split[1]);
	year_temp = stoi(split[2]);
	// Judge if a date is legal
	switch(month_temp){
		case 2:	
			if(isleap(year_temp))
			{	
				if(day_temp > 29)
					throw invalid_argument("Date is invalid for leap year.");
			}
			else
			{
				if(day_temp > 28)
					throw invalid_argument("Date is invalid for non-leap year.");
			}
			break;
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(day_temp > 31)
				throw invalid_argument("Date is invalid.");
			break;
		case 4: case 6: case 9: case 11: default:
			if(day_temp > 30)
				throw invalid_argument("Date is out of range.");
			break;
	}
	year = year_temp;
	month = month_temp;
	day = day_temp;
}
Date& Date::print_date()
{
	cout << year << "-" << month << "-" << day << endl;
	return *this;
}
inline bool Date::isleap(unsigned y)
{
	return ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0));
}
#endif
// Note 1: basic thought is to split the argument into different substrings that
// contains no white spaces and then process each substring and verify if a date
// is legal.

// Note 2: the constructor above tries its best to handle exceptions, thus leading
// to throwing many exceptions at different places. This makes the constructor 
// ugly. So is it appropriate to throw exceptions in a constructor? The answer
// seems yes from 
// https://stackoverflow.com/questions/77639/when-is-it-right-for-a-constructor-to-throw-an-exception
// and
// https://stackoverflow.com/questions/810839/throwing-exceptions-from-constructors
// After all, to get a valid result, we have to judge whether an input that 
// represents a date is valid. If these exception handlers were not in a 
// constructor, we have to put them where a date input is required. That means
// we have to either write another function or do repeated work. 
//
// On the other hand, throwing exceptions in a constructor won't call destructor,
// which might lead to other problems. See the link below.
// https://www.byvoid.com/zhs/blog/cpp-constructor-exception
// The code above throws too many exceptions, think about other ways to improve 
// it.

// Note 3: should this constructor be declared as explicit?
// Consider a situation where we want to get the difference between two dates. 
// We might want to use a valid date string as a operand. Thus an implicit type
// conversion is required. So we shouldn't declare this constructor as explicit.