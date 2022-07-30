// https://www.nowcoder.com/practice/6a1483b5be1547b1acd7940f867be0da

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str1 string字符串
     * @param str2 string字符串
     * @return int整型
     */

    // basecase 有一个为空串时，操作另一个非空串的长度次数增删
    // 选择 i,j为两个非空串长度 字符相等时同时后移 不相等时
    // 状态转移 i,j为两个非空串长度 遍历两个字符串 字符相等时不操作 不等时可能修改这个字符 也可能删除或者增加某个字符
    int editDistance(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        // str2为空串时,str1有多长就删除多少次
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        // str1为空串时，str有多长就增加多少次
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }

        // str1和str2都非空时，遍历
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    // 相等时不操作，次数跟前一位相等
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int p1 = dp[i - 1][j - 1];           // 修改字符
                    int p2 = dp[i - 1][j];               // 删除字符
                    int p3 = dp[i][j - 1];               // 增加字符
                    dp[i][j] = min(p1, min(p2, p3)) + 1; // 取三种操作的最小值再加上自己这一步操作
                }
            }
        }
        return dp[n][m];
    }
};