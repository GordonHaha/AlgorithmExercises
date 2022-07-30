// https://www.nowcoder.com/practice/76039109dd0b47e994c08d8319faa352
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    int candy(vector<int> &arr)
    {
        if (arr.empty())
            return 0;
        if (arr.size() == 1)
            return 1;
        vector<int> dp(arr.size(), 1); // 记录每个孩子的糖果数，初始每人至少一个

        // 从左往右遍历
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > arr[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }

        int sum = dp[arr.size() - 1];
        // 从右往左遍历
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            // 如果左边更大但是糖果数更小
            if (arr[i] > arr[i + 1] && dp[i] <= dp[i + 1])
            {
                dp[i] = dp[i + 1] + 1;
            }
            sum += dp[i];
        }

        return sum;
    }
};