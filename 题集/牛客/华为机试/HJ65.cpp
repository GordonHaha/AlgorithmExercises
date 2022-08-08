// https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        if (str1.length() > str2.length())
        {
            swap(str1, str2);
        }
        int m = str1.length(), n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLen = 0, maxIndex = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > maxLen)
                    {
                        maxLen = dp[i][j];
                        maxIndex = i - 1;
                    }
                }
            }
        }
        cout << str1.substr(maxIndex - maxLen + 1, maxLen) << endl;
    }
    return 0;
}