// https://www.nowcoder.com/practice/64b4262d4e6d4f6181cd45446a5821ec
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        // 第一天不持股，收益0
        dp[0][0] = 0;
        // 第一天持股，收益-prices[0]
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            // 第i天不持股,可能是之前没买或者已经卖了，也可能是之前买了当天卖出，取最大值
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 第i天持股，可能是之前一直没买今天刚买，或者之前买了一直没卖
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        // 返回最后一天不持股的结果
        return dp[n - 1][0];
    }
};