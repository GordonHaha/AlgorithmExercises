// https://www.nowcoder.com/practice/c5fbf7325fbd4c0ea3d0c3ea6bc6cc79

#include<bits/stdc++.h>
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
        vector<int> dp(n);
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        return dp[n];
    }
};