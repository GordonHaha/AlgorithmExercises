// https://www.nowcoder.com/practice/3911a20b3f8743058214ceaa099eeb45

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int> &arr, int aim)
    {
        if (aim < 1)
            return 0;
        int n = arr.size();
        vector<int> dp(aim + 1, aim + 1);
        dp[0] = 0;
        for (int i = 1; i <= aim; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[j] <= i)
                {
                    // 当前面值不大于目标钱数时 两种选择 不选当前面值和选当前面值
                    dp[i] = min(dp[i], dp[i - arr[j]] + 1);
                }
            }
        }
        return dp[aim] > aim ? -1 : dp[aim];
    }
};