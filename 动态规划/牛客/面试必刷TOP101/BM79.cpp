// https://www.nowcoder.com/practice/a5c127769dd74a63ada7bff37d9c5815

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1);
        // 第一种情况 偷第一家 不偷最后一家
        dp[1] = nums[0];
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        int res1 = dp[n - 1];

        dp.clear();
        // 第二种情况 不偷第一家
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        int res2 = dp[n];

        return max(res1, res2);
    }
};