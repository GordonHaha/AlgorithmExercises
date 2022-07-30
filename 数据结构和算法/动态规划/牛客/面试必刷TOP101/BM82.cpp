// https://www.nowcoder.com/practice/4892d3ff304a4880b7a89ba01f48daf9
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 两次交易所能获得的最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -10000)); // 可能有五种情况
        // 第一天没买
        dp[0][0] = 0;
        // 第一天买了
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            // 第i天为止一次没买过
            dp[i][0] = 0;
            // 第i天为止买过一次，没有卖出过，可能是之前某天买的，也可能是当天买的
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            // 第i天为止买过一次卖出过一次，可能是之前某天卖的，也可能是当天卖的
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            // 第i天为止买过两次卖出过一次，第二次可能是之前某天买的，也可能是当天买的
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            // 第i天为止买过两次卖出过两次，第二次可能是之前某天卖的，也可能是当天卖的
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        // 比较一次不买、买卖一次和买卖两次的最大收益返回
        return max(dp[n - 1][2], max(0, dp[n - 1][4]));
    }
};