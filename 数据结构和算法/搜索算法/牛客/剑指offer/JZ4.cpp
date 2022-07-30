// https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e
#include <bits/stdc++.h>
using namespcae std;

class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        int n = array.size(), m = array[0].size();
        if (n * m == 0)
            return false;

        for (int i = n - 1, j = 0; i >= 0 && j < m;)
        {
            if (array[i][j] > target)
            {
                i--;
            }
            else if (array[i][j] < target)
            {
                j++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};