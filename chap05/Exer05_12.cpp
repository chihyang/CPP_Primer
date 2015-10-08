#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	unsigned twoChCnt = 0;
	char chNow, chLast = '\0';
	while(cin >> chNow)
	{
		if(chLast == 'f')
			if(chNow == 'f' || chNow == 'l' || chNow == 'i')
				++twoChCnt;
		chLast = chNow;
	}
	cout << "Number of ff, fl and fi: " << twoChCnt << endl;
	return 0;
}