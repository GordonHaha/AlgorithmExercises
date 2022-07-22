// https://www.nowcoder.com/practice/0c9664d1554e466aa107d899418e814e
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y] = '0';
        if (x - 1 >= 0 && grid[x - 1][y] == '1')
        {
            dfs(grid, x - 1, y);
        }
        if (x + 1 < n && grid[x + 1][y] == '1')
        {
            dfs(grid, x + 1, y);
        }
        if (y - 1 >= 0 && grid[x][y - 1] == '1')
        {
            dfs(grid, x, y - 1);
        }
        if (y + 1 < m && grid[x][y + 1] == '1')
        {
            dfs(grid, x, y + 1);
        }
    }

    int solve(vector<vector<char>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        int count = 0;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (grid[x][y] == '1')
                {
                    count++;
                    dfs(grid, x, y);
                }
            }
        }
        return count;
    }
};