// https://www.nowcoder.com/practice/9e5e3c2603064829b0a0bbfca10594e9

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // 第一天不持股收益0
        dp[0][0] = 0;
        // 第一天持股收益扣除花费
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            // 第i天不持股，可能是之前卖掉了，也可能是今天刚卖
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 第i天持股,可能是之前买了，也可能是今天刚买
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};