// https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        if (m * n == 0)
            return res;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        int i = 0, j = 0;
        while (up <= down && left <= right)
        {
            // 从左往右
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[up][i]);
            }
            up++;
            if (up > down)
                break;
            // 从上往下
            for (int i = up; i <= down; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (right < left)
                break;
            // 从右往左
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[down][i]);
            }
            down--;
            if (down < up)
                break;
            // 从下往上
            for (int i = down; i >= up; i--)
            {
                res.push_back(matrix[i][left]);
            }
            left++;
            if (left > right)
                break;
        }
        return res;
    }
};