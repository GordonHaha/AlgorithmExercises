// https://www.nowcoder.com/practice/c3120c1c1bc44ad986259c0cf0f0b80e
#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string trans(string s, int n)
    {
        stack<string> stack;
        string temp;
        for (int i = 0; i < n; i++)
        {
            // 遇到空格就把拼接的字符串压入栈，temp还原空串
            if (s[i] == ' ')
            {
                stack.push(temp);
                temp = "";
                continue;
            }

            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                temp += s[i] - 'A' + 'a';
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                temp += s[i] - 'a' + 'A';
            }
        }
        // 最后一段记得加入栈
        stack.push(temp);
        temp = "";
        while (!stack.empty())
        {
            temp += stack.top();
            stack.pop();
            if (!stack.empty())
            {
                temp += " ";
            }
        }

        return temp;
    }
};