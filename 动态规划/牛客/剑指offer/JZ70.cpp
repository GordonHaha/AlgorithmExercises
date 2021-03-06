// https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rectCover(int number)
    {
        vector<int> dp(number + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= number; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number];
    }
};