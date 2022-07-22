// https://www.nowcoder.com/practice/7edf70f2d29c4b599693dc3aaeea1d31
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int n = matrix.size();
        if (n == 0)
            return res;
        // 初始化四个边界
        int left = 0, right = matrix[0].size() - 1, up = 0, down = n - 1;
        while (left <= right && up <= down)
        {
            // 上边界的从左到右遍历
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[up][i]);
            }
            // 上边界递增向下
            up++;
            // 越界跳出
            if (up > down)
                break;
            // 右边界从上往下遍历
            for (int i = up; i <= down; i++)
            {
                res.push_back(matrix[i][right]);
            }
            // 右边界递减向左
            right--;
            // 越界跳出
            if (right < left)
                break;
            // 下边界从右向左遍历
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[down][i]);
            }
            // 下边界递增向上
            down--;
            // 越界跳出
            if (down < up)
                break;
            // 左边界从下往上遍历
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