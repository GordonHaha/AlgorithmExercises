// https://www.nowcoder.com/practice/64b4262d4e6d4f6181cd45446a5821ec

#include <bits/stdc++.h>
using namespace std;

// 方法一
class Solution1
{
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        if (prices.empty())
            return res;

        int minp = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            minp = min(minp, prices[i]);
            res = max(res, prices[i] - minp);
        }
        return res;
    }
};

// 方法二 

class Solution2
{
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        //第一天不持股 收益0
        dp[0][0] = 0;
        //第一天持股，收益扣掉prices[0]
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            // 第i天不持股，可能是之前某天已经卖了。也可能是今天刚卖，选收益最大的
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 第i天持股，可能是之前某天买了，也可能是今天刚买，选收益最大的
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        return dp[n - 1][0];
    }
};