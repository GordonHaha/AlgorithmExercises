// https://www.nowcoder.com/practice/2a49359695a544b8939c77358d29b7e6
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param matrix char字符型vector<vector<>>
     * @param word string字符串
     * @return bool布尔型
     */

    bool backTrack(vector<vector<char>> &matrix, string &word, int x, int y, vector<vector<bool>> &flag)
    {
        if (word.empty())
            return true;
        int m = matrix.size(), n = matrix[0].size();
        if (x >= m || y >= n || x < 0 || y < 0 || matrix[x][y] != word[0] || flag[x][y])
            return false;
        flag[x][y] = true;
        string temp = word.substr(1);
        bool left = backTrack(matrix, temp, x - 1, y, flag);
        bool right = backTrack(matrix, temp, x + 1, y, flag);
        bool top = backTrack(matrix, temp, x, y - 1, flag);
        bool down = backTrack(matrix, temp, x, y + 1, flag);
        if (left || right || top || down)
            return true;
        flag[x][y] = false;
        return false;
    }

    bool hasPath(vector<vector<char>> &matrix, string word)
    {
        if (matrix.empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (backTrack(matrix, word, i, j, flag))
                    return true;
            }
        }
        return false;
    }
};