// https://www.nowcoder.com/practice/2e95333fbdd4451395066957e24909cc
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> rotateMatrix(vector<vector<int>> mat, int n)
    {
        // 先矩阵转置
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // 再每个数组单独翻转
        for (int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }

        return mat;
    }
};