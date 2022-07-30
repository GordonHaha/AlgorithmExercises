// https://www.nowcoder.com/practice/28eb3175488f4434a4a6207f6f484f47
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        string s = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            string cur = strs[i];
            // 先判断长度，最长公共前缀肯定不会超过最短的字符串长度
            if (s.length() > cur.length())
            {
                // 和比较的字符串相比长了的话就删掉后面多余的部分
                s.erase(s.begin() + cur.length(), s.end());
            }
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] != cur[j])
                {
                    // 有字符不相同时，删掉后面多余的部分
                    s.erase(s.begin() + j, s.end());
                    break;
                }
            }
        }
        return s;
    }
};