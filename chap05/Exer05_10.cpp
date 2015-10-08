#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while(cin >> ch)
	{
		switch(ch){
			case 'a':
			case 'A':
				++aCnt;
			case 'e':
			case 'E':
				++eCnt;
			case 'i':
			case 'O'
				++iCnt;
			case 'o':
			case 'O':
				++oCnt;
			case 'u':
			case 'U':
				++uCnt;	
			case ' ':
				++blkCnt;
				break;
			case '\t':
				++tabCnt;
				break;
			case '\n':
				++nlCnt;
				break;
			default:
				break;
		}
	}
	cout << "Number of vowel a: \t" << aCnt << endl;
	cout << "Number of vowel e: \t" << eCnt << endl;
	cout << "Number of vowel i: \t" << iCnt << endl;
	cout << "Number of vowel o: \t" << oCnt << endl;
	cout << "Number of vowel u: \t" << uCnt << endl;
	return 0;
}