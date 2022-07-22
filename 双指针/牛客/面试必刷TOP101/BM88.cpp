// https://www.nowcoder.com/practice/e297fdd8e9f543059b0b5f05f3a7f3b2
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param str string字符串 待判断的字符串
     * @return bool布尔型
     */
    bool judge(string str)
    {
        int left = 0, right = str.length() - 1;
        while (left < right)
        {
            if (str[left++] != str[right--])
                return false;
        }
        return true;
    }
};