// https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af

#include <bits/stdc++.h>
using namespace std;
class Solution1
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    // 方法一 中心扩散

    int maxFun(string s, int left, int right)
    {
        // 从中心点左右扩散比较，相等就扩散，不相等就返回结果
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        // "+1"是因为通过下标计算子串长度
        // "-2"是因为上边的while循环是当索引为left和right不想等才退出循环的
        // 因此此时的left和right是不满足的，需要舍弃
        return right - left + 1 - 2;
    }

    int getLongestPalindrome(string A)
    {
        int maxLen = 1;
        for (int i = 0; i < A.length(); i++)
        {
            maxLen = max(maxLen, max(maxFun(A, i, i), maxFun(A, i, i + 1)));
        }
        return maxLen;
    }
};

// 方法二 动态规划

class Solution2
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    int getLongestPalindrome(string A)
    {
        if (A.empty())
        {
            return 0;
        }

        int N = A.length();
        // 保存字符串i...j是否为回文子串
        vector<vector<bool>> dp(N, vector<bool>(N, false));
        int maxLen = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = i; j < N; j++)
            {
                if (i == j)
                {
                    // 单字符一定是回文子串
                    dp[i][j] = true;
                }
                else if (j - i == 1)
                {
                    // 相邻字符相等时一定是回文子串
                    dp[i][j] = A[i] == A[j];
                }
                else
                {
                    // 不相邻字符如果相等且之前的左右回溯的字符串也是回文子串时一定是回文子串
                    dp[i][j] = A[i] == A[j] && dp[i + 1][j - 1];
                }

                if (dp[i][j] && maxLen < j - i + 1)
                {
                    maxLen = j - i + 1;
                }
            }
        }

        return maxLen;
    }
};