#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, twoChCnt = 0;
    char chNow, chLast = '\0';
    // If we just count the number of vowels or "ff", "fl", "fi", it's easy.
    // If we have to count the number of vowels and "ff", "fl", "fi", we have to
    // cope with characters carefully, because the vowel 'i' appears in both
    // cases.
    while(cin >> chNow)
    {
        switch(chNow){
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
            ++iCnt;
            if(chLast == 'f')
                ++twoChCnt;
            break;
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        case 'f':
        case 'l':
            if(chLast == 'f')
                ++twoChCnt;
            break;
        default:
            break;
        }
        chLast = chNow;
    }
    cout << "Number of vowel a: \t" << aCnt << endl;
    cout << "Number of vowel e: \t" << eCnt << endl;
    cout << "Number of vowel i: \t" << iCnt << endl;
    cout << "Number of vowel o: \t" << oCnt << endl;
    cout << "Number of vowel u: \t" << uCnt << endl;
    cout << "Number of ff, fl and fi: " << twoChCnt << endl;
    return 0;
}
