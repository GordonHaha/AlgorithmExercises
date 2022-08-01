// https://www.nowcoder.com/practice/3cd4621963e8454594f00199f4536bb1
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int l, r;
    int maxLen = -1;
    for (int i = 1; i < str.length(); i++)
    {
        l = i - 1, r = i;
        while (l >= 0 && r < str.length() && str[l] == str[r])
        {
            l--, r++;
        }
        maxLen = max(maxLen, r - l - 1);

        if (i == str.length() - 1)
            break;

        l = i - 1, r = i + 1;
        while (l >= 0 && r < str.length() && str[l] == str[r])
        {
            l--, r++;
        }
        maxLen = max(maxLen, r - l - 1);
    }
    cout << maxLen << endl;
    return 0;
}