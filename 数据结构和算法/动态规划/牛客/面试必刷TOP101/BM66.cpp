// https://www.nowcoder.com/practice/f33f5adc55f444baa0e0ca87ad8a6aac

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2)
    {
        if (str1.empty() || str2.empty())
            return 0;
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m));
        int max = 0;
        int pos = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    // 连续子串，如果有字符不相等要重新开始记录
                    dp[i][j] = 0;
                }

                // 更新最大长度和子串尾位置
                if (dp[i][j] > max)
                {
                    max = dp[i][j];
                    pos = i - 1;
                }
            }
        }

        return str1.substr(pos - max + 1, max);
    }
};