// https://www.nowcoder.com/practice/28970c15befb4ff3a264189087b99ad4
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */
    bool match(string str, string pattern)
    {
        int m = str.length();
        int n = pattern.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        // 都是空串时匹配上
        dp[0][0] = true;
        // str空串时
        for (int i = 2; i <= n; i++)
        {
            // pattern末尾星号时，结果看前一位字符是否也是星号
            if (pattern[i - 1] == '*')
            {
                dp[0][i] = dp[0][i - 2];
            }
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.')
                {
                    // 末尾字符能匹配上时，结果各自前一位字符匹配结果
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pattern[j - 1] == '*')
                {
                    // pattern末尾是星号时
                    if (dp[i][j - 1])
                    {
                        // 星号匹配1次,str当前位和星号前一位匹配上,星号前一位字符被匹配消耗掉
                        dp[i][j] = dp[i][j - 1];
                    }
                    else if (j >= 2 && dp[i][j - 2])
                    {
                        // 星号匹配0次,str当前位和星号前一位匹配不上，星号和星号前一位都消耗掉
                        dp[i][j] = dp[i][j - 2];
                    }
                    else if (i >= 2 && j >= 2)
                    {
                        // 星号匹配多次，则str前一位也能和当前pattern匹配上，且str当前位
                        dp[i][j] = (dp[i - 1][j] && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.'));
                    }
                }
            }
        }
        return dp[m][n];
    }
};