#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
    // What if two words repeated the same times?
    // Consider this situation: in a challenge game, if you want to be a new 
    // champion, you have to do even better than the last one. Just doing as 
	// well as him/her is not enough. So the champion is always the first that
	// surmounts the others.
	string s, sLast, sMax;
	int cntNow = 0, cntMax = 0;
	while(cin >> s)
	{
		if(s == sLast)
			++cntNow;
		else
			cntNow = 1;
		if(cntNow > cntMax)
		{
			sMax = s;
			cntMax = cntNow;
		}
		sLast = s;
	}
	if(!sMax.empty())
	{
		if(cntMax > 1)
			cout << sMax << " occurred " << cntMax << " times." << endl;
		else
			cout << "No duplicated words." << endl;
	}
	else
		cout << "Nothing is input!" << endl;
	return 0;
}