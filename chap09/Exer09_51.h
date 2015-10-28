// Note: this is a quite complicated implementation, it's a temporary solution.
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
using std::out_of_range;
vector<string> MONALL{ "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
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
// mdy.
Date::Date(const string& date)
{
	unsigned year_temp = 0, month_temp = 0, day_temp = 0;
	if(date.empty())
		throw invalid_argument("Argument shouldn't be empty");
	vector<string> split; // store non-white-spaces and non-separators
	string str;
	// filter white spaces and separators
	for(const auto &c : date)
	{
		if(!(isspace(c) || c == ',' || c == '-' || c == '/' || c == '.'))
			str.push_back(c);
		else
		{
			if(!str.empty())
			{
				split.push_back(str);
				str.clear();
			}
		}
	}
	split.push_back(str);
	if(split.size() != 3)
		throw invalid_argument("Not a valid date.");
	// if month begins with a letter, it might be a month in English
	if(isalpha(split[0][0]))
	{
		for(auto &c : split[0])
			c = toupper(c);
		for(decltype(MONALL.size()) m = 0; m <= MONALL.size(); ++m)
		{
			if(MONALL[m].find(split[0]) == 0) // abbreviation or full
			{
				month_temp = m + 1;
				break;
			}
		}
	}
	// or month should be a numeric value
	else if(isdigit(split[0][0]))
		month_temp = stoi(split[0]);
	// or the input month is wrong
	else
		throw invalid_argument("Month is invalid.");
	day_temp = stoi(split[1]);
	year_temp = stoi(split[2]);
	// Judge is a date is legal
	if(month_temp != 2 && (( month_temp <= 7 && month_temp % 2) || !(month_temp % 2)))
	{
		if(day_temp > 31)
			throw invalid_argument("Date is invalid.");
	}
	else if(month_temp == 2)
	{
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
	}
	else
	{
		if(day_temp > 31)
			throw out_of_range("Date is out of range.");
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