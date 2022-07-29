// https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int cutRope(int n)
    {
        if (n <= 3)
            return n - 1;
        int res = 1;
        while (n > 4)
        {
            res *= 3;
            n -= 3;
        }
        return res * n;
    }
};