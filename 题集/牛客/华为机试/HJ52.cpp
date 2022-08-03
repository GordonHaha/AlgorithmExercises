// https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str1, str2;
    int distance = 0;
    while (cin >> str1 >> str2)
    {
        int m = str1.length(), n = str2.length();
        if (m * n == 0)
        {
            cout << 0 << endl;
            break;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    // 字符相等不操作
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // 删除操作
                    int del = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                    // 修改操作
                    int mod = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min(del, mod);
                }
            }
        }
        cout << dp[m][n] << endl;
    }
    return 0;
}