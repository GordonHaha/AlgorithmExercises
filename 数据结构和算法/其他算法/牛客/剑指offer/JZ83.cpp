// https://www.nowcoder.com/practice/106f666170554379ab1974e5a601e741
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param number long长整型
     * @return long长整型
     */
    long long mod = 998244353;
    // 快速乘法
    long long fast(long long x, long long y)
    {
        long long res = 0;
        x %= mod;
        y %= mod;
        while (y)
        {
            if (y & 1)
            {
                // 加法代替乘法，防止越界
                res += x;
                if (res >= mod)
                    res -= mod;
            }
            y = y >> 1;
            x = x << 1;
            if (x >= mod)
                x -= mod;
        }
        return res;
    }
    // 快速幂
    long long Pow(long long x, long long y)
    {
        long long res = 1;
        while (y)
        {
            // 可以再往上乘一个
            if (y & 1)
            {
                res = fast(res, x);
            }
            // 叠加
            x = fast(x, x);
            // 减少乘次数
            y = y >> 1;
        }
        return res;
    }

    long long cutRope(long long number)
    {
        if (number <= 3)
            return number - 1;
        if (number % 3 == 0)
        {
            return Pow(3, number / 3);
        }
        else if (number % 3 == 1)
        {
            return fast(Pow(3, number / 3 - 1), 4);
        }
        else
        {
            return fast(Pow(3, number / 3), 2);
        }
    }
};