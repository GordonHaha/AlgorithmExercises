// https://www.nowcoder.com/practice/c466d480d20c4c7c9d322d12ca7955ac
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     *
     * @param S string字符串
     * @param T string字符串
     * @return string字符串
     */
    string minWindow(string S, string T)
    {
        unordered_map<char, int> window, need;
        for (char c : T)
        {
            need[c]++;
        }
        int left = 0, right = 0, valid = 0;
        int start = 0, len = INT_MAX;
        while (right < S.size())
        {
            // 右边界字符进入窗口
            char a = S[right];
            right++;
            // 进入的字符是符合条件的有效字符时
            if (need.count(a))
            {
                // 窗口内对应字符出现次数加一
                window[a]++;
                if (window[a] == need[a])
                {
                    // 当进入字符出现次数相等时，有效长度加一
                    valid++;
                }
            }

            // 判断左侧窗口是否需要收缩,即当窗口内的有效字符长度满足要求时
            while (valid == need.size())
            {
                if (right - left < len)
                {
                    len = right - left;
                    start = left;
                }

                // 左边界字符移出窗口
                char b = S[left];
                left++;
                // 移出的字符是符合条件的有效字符时
                if (need.count(b))
                {
                    // 当移出字符出现次数相等时，有效长度减一
                    if (window[b] == need[b])
                    {
                        valid--;
                    }
                    // 移出字符出现次数减一
                    window[b]--;
                }
            }
        }
        return len == INT_MAX ? "" : S.substr(start, len);
    }
};