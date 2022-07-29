// https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums)
    {
        if (nums.empty())
            return 0;
        int n = nums.length();
        vector<int> dp(n + 1);
        // 从后往前看[i...n-1]的情况
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            // 头字符为'0'的时候无法转发 dp[i] = 0;
            if (nums[i] != '0')
            {
                //单字符转换
                int ways = dp[i + 1];
                // 双字符转换
                if (i + 1 < n && ((nums[i] - '0') * 10 + nums[i + 1] - '0' < 27))
                {
                    ways += dp[i + 2];
                }
                dp[i] = ways;
            }
        }
        return dp[0]; //完整字符串的方法数
    }
};