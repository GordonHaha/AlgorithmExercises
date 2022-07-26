// https://www.nowcoder.com/practice/2237b401eb9347d282310fc1c3adb134
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */
    int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[1][1] = grid[0][0];
        for (int i = 2; i <= m; i++)
        {
            // 当棋盘mx1大小时，只能一直往下走
            dp[i][1] = dp[i - 1][1] + grid[i - 1][0];
        }

        for (int i = 2; i <= n; i++)
        {
            // 当棋盘1xn大小时，只能一直往右走
            dp[1][i] = dp[1][i - 1] + grid[0][i - 1];
        }

        for (int i = 2; i <= m; i++)
        {
            for (int j = 2; j <= n; j++)
            {
                // 当前位置的最大值应该在它左侧和上测里选择一个，再加上当前位置的价值
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};