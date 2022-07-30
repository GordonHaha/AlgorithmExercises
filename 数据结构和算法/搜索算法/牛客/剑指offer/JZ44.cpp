// https://www.nowcoder.com/practice/29311ff7404d44e0b07077f4201418f5
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
    int findNthDigit(int n)
    {
        if (n < 10)
            return n;
        int digit = 1;  // 位数
        long start = 1; //区间下限
        long end = 9;   // 区间上限
        while (n > end)
        {
            n -= end;
            digit++;
            start *= 10;
            end = start * digit * 9;
        }

        // num表示n所在的数字
        int num = (n - 1) / digit + start;
        string s = to_string(num);
        int r = (n - 1) % digit;
        return stoi(s.substr(r, 1));
    }
};