// https://www.nowcoder.com/practice/6fe0302a058a4e4a834ee44af88435c7
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param cost int整型vector
     * @return int整型
     */

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        if (n <= 1)
        {
            return 0;
        }
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++)
        {
            int p1 = dp[i - 1] + cost[i - 1];
            int p2 = dp[i - 2] + cost[i - 2];
            dp[i] = min(p1, p2);
        }
        return dp[n];
    }
};