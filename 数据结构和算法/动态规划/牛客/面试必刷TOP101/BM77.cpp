// https://www.nowcoder.com/practice/45fd68024a4c4e97a8d6c45fc61dc6ad

#include <bits/stdc++.h>
using namespace std;

// 方法一 栈
class Solution1
{
public:
    /**
     *
     * @param s string字符串
     * @return int整型
     */
    int longestValidParentheses(string s)
    {
        int res = 0;
        int start = -1; // 记录上一次连续括号结束位置
        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                // 左括号位置入栈
                st.push(i);
            }
            else
            {
                if (st.empty())
                {
                    // 如果空栈 说明左括号都匹配完了,更新结束位置
                    start = i;
                }
                else
                {
                    // 遇到右括号先出栈一个左括号
                    st.pop();
                    if (!st.empty())
                    {
                        // 弹出后栈中还有左括号，说明右括号不够，当前位置减去栈顶左括号位置就是当前的长度
                        res = max(res, i - st.top());
                    }
                    else
                    {
                        // 弹出后栈空，当前位置减去上一次结束位置为当前的长度
                        res = max(res, i - start);
                    }
                }
            }
        }
        return res;
    }
};

// 方法二 动态规划
class Solution2
{
public:
    /**
     *
     * @param s string字符串
     * @return int整型
     */
    int longestValidParentheses(string s)
    {
        int n = s.length();
        int res = 0;
        if (n == 0)
            return res;

        // 下标为i的位置为结束位置时的最长长度记录
        vector<int> dp(n);
        // dp[0] = 1 只有一位字符时不用管，一定不合法
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                // 当前位置右括号时
                if (s[i - 1] == '(')
                {
                    // 如果前一位为左括号，看一下前两位的合法长度是多少，加上新的两位长度
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    // 如果前一位是右括号，需要找到之前尚未匹配过的左括号位置，用当前位置减去前一位置的合法长度再-1就是上一个左括号位置
                    dp[i] = (i - dp[i - 1] > 1 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};