// https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;
        vector<int> dp(array.size());
        dp[0] = array[0];
        int maxSum = dp[0];
        for (int i = 1; i < array.size(); i++)
        {
            dp[i] = max(array[i], dp[i - 1] + array[i]);
            maxSum = max(dp[i], maxSum);
        }
        return maxSum;
    }
};