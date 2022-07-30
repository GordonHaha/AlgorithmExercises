// https://www.nowcoder.com/practice/6d29638c85bb4ffd80c020fe244baf11

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */

    string LCS(string s1, string s2)
    {
        if (s1.empty() || s2.empty())
            return "-1";
        int n = s1.length(), m = s2.length();
        // 保存最大公共子序列的长度表
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // 栈保存从后往前读取的字符
        stack<char> s;
        int i = n, j = m;
        // i横轴 j纵轴
        while (dp[i][j])
        {
            
            if (dp[i][j] == dp[i - 1][j])
            {
                i--;
            }
            else if (dp[i][j] == dp[i][j - 1])
            {
                j--;
            }
            else if (dp[i][j] > dp[i - 1][j - 1])
            {
                i--;
                j--;
                s.push(s1[i]);
            }
        }

        string res = "";
        while (!s.empty())
        {
            res += s.top();
            s.pop();
        }

        return res == "" ? "-1" : res;
    }
};