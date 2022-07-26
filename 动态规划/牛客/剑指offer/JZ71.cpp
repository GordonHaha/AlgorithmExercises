// https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jumpFloorII(int number)
    {
        vector<int> dp(21);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= number; i++)
        {
            dp[i] = 2 * dp[i - 1];
        }
        return dp[number];
    }
};