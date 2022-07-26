// https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string ReverseSentence(string str)
    {
        stack<string> stack;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                continue;
            string s;
            while (str[i] != ' ' && i < str.length())
            {
                s += str[i++];
            }
            stack.push(s);
        }

        string res;
        while (!stack.empty())
        {
            res += stack.top();
            stack.pop();
            if (!stack.empty())
            {
                res += ' ';
            }
        }
        return res;
    }
};