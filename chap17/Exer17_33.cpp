// Note: this file uses data file ./data/map and ./data/input
#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <ctime>
#include <stdexcept>
using std::size_t;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::map;
using std::default_random_engine;
using std::uniform_real_distribution;
using std::runtime_error;
map<string, vector<string>> buildMap(ifstream &map_file)
{
	map<string, vector<string>> trans_map;
	string key, value;
	while(map_file >> key && getline(map_file, value))
	{
		if(value.size() > 1) {
			string word;
			istringstream is(value);
			while(is >> word)
			trans_map[key].push_back(word); // using white space as separator
		}
		else
			throw runtime_error("no rule for " + key + " at " + __func__);
	}
	return trans_map;
}
const string& transform(const string &s, const map<string, vector<string>> &m)
{
	// static object to generate random numbers
	static default_random_engine e(time(0));
	static uniform_real_distribution<double> u(0, 1);
	auto map_it = m.find(s);
	if(map_it != m.cend()) {
		size_t select = map_it->second.size() * u(e); // truncated, won't be out of range
		return map_it->second[select];
	}
	else
		return s;
}
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while(getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while(stream >> word)
		{
			// process leading space
			if(firstword)
				firstword = false;
			else
				cout << " ";
			// process word
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}
int main(int argc, char *argv[])
{
	if(argc != 3)
		return -1;
	for (size_t i = 0; i < 10; ++i) {
		ifstream map_file(argv[1]), input_file(argv[2]);
		try
		{
			word_transform(map_file, input_file);
		}
		catch(runtime_error err)
		{
			cout << "Error: " << err.what() << endl;
		}
	}
	return 0;
}