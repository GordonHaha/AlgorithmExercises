// https://www.nowcoder.com/practice/539054b4c33b4776bc350155f7abd8f5
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int eCnt = 0, spaceCnt = 0, numCnt = 0, otherCnt = 0;
    for (char c : s)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            eCnt++;
        }
        else if (c == ' ')
        {
            spaceCnt++;
        }
        else if (c >= '0' && c <= '9')
        {
            numCnt++;
        }
        else
        {
            otherCnt++;
        }
    }
    cout << eCnt << endl
         << spaceCnt << endl
         << numCnt << endl
         << otherCnt;
    return 0;
}