// https://www.nowcoder.com/practice/48d2ff79b8564c40a50fa79f9d5fa9c7
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;   // 记录非重复字符的下标位置
        vector<int> dp(s.length() + 1); // 记录到对应长度位置的最长不重复子串长度
        int maxLen = 0;
        dp[1] = 1;
        for (int i = 1; i <= s.length(); i++)
        {
            if (map.count(s[i - 1]))
            {
                // 有重复字符时,考虑可能不是第一次出现重复,比较一下前一位无重复的长度和当前位减去前一次重复字符的位置，取较短
                dp[i] = min(dp[i - 1] + 1, i - map[s[i - 1]]);
            }
            else
            {
                // 无重复字符时
                dp[i] = dp[i - 1] + 1;
            }
            map[s[i - 1]] = i;
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};