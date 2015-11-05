#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <stdexcept>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::unordered_map;
using std::runtime_error;
unordered_map<string, string> buildMap(ifstream &map_file)
{
	unordered_map<string, string> trans_map;
	string key, value;
	while(map_file >> key && getline(map_file, value))
	{
		if(value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key + " at " + __func__);
	}
	return trans_map;
}
const string& transform(const string &s, const unordered_map<string, string> &m)
{
	auto map_it = m.find(s);
	if(map_it != m.cend())
		return map_it->second;
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
	ifstream map_file(argv[1]), input_file(argv[2]);
	try
	{
		word_transform(map_file, input_file);
	}
	catch(runtime_error err)
	{
		cout << "Error: " << err.what() << endl;
	}
	return 0;
}