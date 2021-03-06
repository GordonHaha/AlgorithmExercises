// https://www.nowcoder.com/practice/0e26e5551f2b489b9f58bc83aa4b6c68
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
     * @return string字符串
     */
    string replaceSpace(string s)
    {
        string res;
        if (s.empty())
            return res;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                res += "%20";
                continue;
            }
            res += s[i];
        }
        return res;
    }
};