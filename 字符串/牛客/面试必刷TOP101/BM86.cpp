// https://www.nowcoder.com/practice/11ae12e8c6fe48f883cad618c2e81475
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t)
    {
        int len1 = s.length();
        int len2 = t.length();
        while (len1 < len2)
        {
            s = "0" + s;
            len1++;
        }
        while (len2 < len1)
        {
            t = "0" + t;
            len2++;
        }

        string ans;
        int carry = 0;
        for (int i = len1 - 1; i >= 0; i--)
        {
            int tmp = (s[i] - '0' + t[i] - '0' + carry);
            ans += char(tmp % 10 + '0');
            carry = tmp / 10;
        }

        if (carry)
        {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};