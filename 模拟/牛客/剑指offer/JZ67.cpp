// https://www.nowcoder.com/practice/d11471c3bf2d40f38b66bb12785df47f
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
    int StrToInt(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;
        int num = 0;
        int index = 0;
        while (s[index] == ' ')
            index++;
        if (index == n)
            return false;
        int sign = 1;
        if (s[index] == '+')
        {
            index++;
        }
        else if (s[index] == '-')
        {
            index++;
            sign = -1;
        }
        if (index == n)
            return false;
        while (index < n)
        {
            char c = s[index];
            if (!isdigit(c))
                break;
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (c - '0') > INT_MAX % 10))
                return INT_MAX;
            if (num < INT_MIN / 10 || (num == INT_MIN / 10 && (c - '0') < INT_MAX % 10))
                return INT_MIN;
            num = num * 10 + sign * (c - '0');
            index++;
        }
        return num;
    }
};