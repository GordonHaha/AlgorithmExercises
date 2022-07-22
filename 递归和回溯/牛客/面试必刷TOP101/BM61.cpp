// https://www.nowcoder.com/practice/7a71a88cdf294ce6bdf54c899be967a2
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int max_ans = 0; //全局变量记得初始化
    int solve(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dfs(matrix, i, j, n, m, 1); //每一格为起点出发
            }
        }
        return max_ans;
    }
    // i，j表示当前的坐标，n,m表示边界，ans记录当前长度
    void dfs(vector<vector<int>> &matrix, int i, int j, int n, int m, int ans)
    {
        if (ans > max_ans)
            max_ans = ans; //记录最大长度
        int last_num = matrix[i][j];
        matrix[i][j] = -1; //标记这个格子走过
        //上下左右方向边界预判，比之前的数大而且没有走过
        if (i - 1 > 0 && matrix[i - 1][j] > last_num && matrix[i - 1][j] != -1)
            dfs(matrix, i - 1, j, n, m, ans + 1);
        if (i + 1 < n && matrix[i + 1][j] > last_num && matrix[i + 1][j] != -1)
            dfs(matrix, i + 1, j, n, m, ans + 1);
        if (j - 1 > 0 && matrix[i][j - 1] > last_num && matrix[i][j - 1] != -1)
            dfs(matrix, i, j - 1, n, m, ans + 1);
        if (j + 1 < m && matrix[i][j + 1] > last_num && matrix[i][j + 1] != -1)
            dfs(matrix, i, j + 1, n, m, ans + 1);
        matrix[i][j] = last_num;
    }
};