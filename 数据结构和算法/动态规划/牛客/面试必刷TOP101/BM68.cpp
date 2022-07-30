// https://www.nowcoder.com/practice/7d21b6be4c6b429bb92d219341c4f8bb

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = matrix[0][0];
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = dp[0][j - 1] + matrix[0][j];
        }
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + matrix[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};