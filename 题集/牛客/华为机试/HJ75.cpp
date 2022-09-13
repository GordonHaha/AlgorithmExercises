// https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int m = str1.length(), n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int maxLen = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        cout << maxLen << endl;
    }
    return 0;
}