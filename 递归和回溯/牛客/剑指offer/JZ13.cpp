// https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool matchThreshold(int i, int j, int t)
    {
        string si = to_string(i);
        string sj = to_string(j);
        int sum = 0;
        for (char c : si)
        {
            sum += c - '0';
        }
        for (char c : sj)
        {
            sum += c - '0';
        }
        return sum > t;
    }

    int count = 0;
    void backTrack(int threshold, int rows, int cols, int i, int j, vector<vector<bool>> &flag)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || flag[i][j] || matchThreshold(i, j, threshold))
            return;
        flag[i][j] = true;
        count++;
        backTrack(threshold, rows, cols, i - 1, j, flag);
        backTrack(threshold, rows, cols, i + 1, j, flag);
        backTrack(threshold, rows, cols, i, j - 1, flag);
        backTrack(threshold, rows, cols, i, j + 1, flag);
    }

    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold == 0)
            return 1;
        vector<vector<bool>> flag(rows + 1, vector<bool>(cols + 1));
        backTrack(threshold, rows, cols, 0, 0, flag);
        return count;
    }
};