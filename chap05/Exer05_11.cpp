#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned blkCnt = 0, tabCnt = 0, nlCnt = 0;
	char ch;
	while(cin.get(ch))// Here we use some out-of-scope function to read black
	// tab and newline.
	{
		if(isalpha(ch))
		{
			ch = tolower(ch);
			if(ch == 'a')
				++aCnt;
			if(ch == 'e')
				++eCnt;
			if(ch == 'i')
				++iCnt;
			if(ch == 'o')
				++oCnt;
			if(ch == 'u')
				++uCnt;	
		}
		if(ch == ' ')
			++blkCnt;
		if(ch == '\t')
			++tabCnt;
		if(ch == '\n')
			++nlCnt;
	}
	cout << "Number of vowel a: \t" << aCnt << endl;
	cout << "Number of vowel e: \t" << eCnt << endl;
	cout << "Number of vowel i: \t" << iCnt << endl;
	cout << "Number of vowel o: \t" << oCnt << endl;
	cout << "Number of vowel u: \t" << uCnt << endl;
	cout << "Number of blank: \t" << blkCnt << endl;
	cout << "Number of tab: \t" << tabCnt << endl;
	cout << "Number of new line: \t" << nlCnt << endl;
	return 0;
}