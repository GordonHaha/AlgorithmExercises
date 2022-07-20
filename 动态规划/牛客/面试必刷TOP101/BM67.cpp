// https://www.nowcoder.com/practice/166eaff8439d4cd898e3ba933fbc6358

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     *
     * @param m int整型
     * @param n int整型
     * @return int整型
     */
    int uniquePaths(int m, int n)
    {
        if (m * n == 0)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 || j == 1)
                {
                    dp[i][j] = 1;
                    continue;
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};