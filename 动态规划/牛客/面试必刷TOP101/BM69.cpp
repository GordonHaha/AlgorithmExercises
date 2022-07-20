// https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668?tpId=295

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
        {
            return 0;
        }

        int N = nums.length();
        vector<int> dp(N + 1);
        // 从后往前看
        dp[N] = 1; // 如果下标能到字符串结束位置时，可以确定有一种方法能转成功，否则在前面就直接返回0了
        for (int i = N - 1; i >= 0; i--)
        {
            // nums[i]如果是'0' 说明前面的选择有问题 此时dp[i] = 0
            if (nums[i] != '0')
            {
                // 单字符情况
                int ways = dp[i + 1];
                if (i + 1 < nums.length() && (nums[i] - '0') * 10 + nums[i + 1] - '0' < 27)
                {
                    // 双字符情况
                    ways += dp[i + 2];
                }
                dp[i] = ways;
            }
        }
        return dp[0]; // 返回i为0 也就是完整字符串的时候的结果
    }
};