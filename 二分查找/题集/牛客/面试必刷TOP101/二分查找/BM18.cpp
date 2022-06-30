// https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e

// 关键思路：二维数组也是有序的，任意位置元素都比它上方的元素大，比它右边的元素小，从左下角开始迭代比较即可
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        if (array.empty())
        {
            return false;
        }

        int n = array.size();
        if (array[0].empty())
        {
            return false;
        }
        int m = array[0].size();

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