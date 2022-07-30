// https://www.nowcoder.com/practice/c76408782512486d91eea181107293b6
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     *
     * @param n int整型 the n
     * @return int整型
     */

    int count = 0;
    bool isValid(vector<vector<bool>> &rec, int row, int col, int n)
    {
        // 任何皇后不同行、不同列也不在同一条斜线上
        // 因为是从上往下摆 只需要检查正上，左上对角线，右上对角线即可
        // 先检查正上方
        for (int i = 0; i < row; i++)
        {
            if (rec[i][col])
                return false;
        }
        // 检查左上方对角线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (rec[i][j])
                return false;
        }

        // 检查右上方对角线
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (rec[i][j])
                return false;
        }

        return true;
    }

    void backTrack(vector<vector<bool>> &rec, int row, int n)
    {
        if (row == n)
        {
            // 皇后成功摆完了最后一行，就计算一次成功次数
            count++;
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isValid(rec, row, col, n))
            {
                rec[row][col] = true;
                backTrack(rec, row + 1, n);
                rec[row][col] = false;
            }
        }
    }

    int Nqueen(int n)
    {
        vector<vector<bool>> rec(n, vector<bool>(n, false));
        backTrack(rec, 0, n);
        return count;
    }
};