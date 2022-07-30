// https://www.nowcoder.com/practice/37548e94a270412c8b9fb85643c8ccc2

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /**
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(')');
            }
            else if (s[i] == '[')
            {
                stk.push(']');
            }
            else if (s[i] == '{')
            {
                stk.push('}');
            }
            else
            {
                if (stk.empty() || s[i] != stk.top())
                {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
