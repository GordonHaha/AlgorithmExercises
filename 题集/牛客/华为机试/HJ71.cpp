// https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int m = str1.length(), n = str2.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            char ch1 = str1[i - 1];
            dp[i][0] = dp[i - 1][0] && (ch1 == '*');
            for (int j = 1; j <= n; j++)
            {
                char ch2 = str2[j - 1];
                if (ch1 == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    if (isalpha(ch2))
                    {
                        dp[i][j] = dp[i - 1][j - 1] && (ch1 == '?' || (ch2 == ch1 || ch2 == (ch1 + ('A' - 'a')) || ch2 == (ch1 - ('A' - 'a'))));
                    }
                    else if (isdigit(ch2))
                    {
                        dp[i][j] = dp[i - 1][j - 1] && (ch1 == '?' || ch1 == ch2);
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j - 1] && (ch1 == ch2);
                    }
                }
            }
        }
        if (dp[m][n])
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}