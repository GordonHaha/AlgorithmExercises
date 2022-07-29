// https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NumberOf1(int n)
    {
        int res = 0;
        while (n)
        {
            n &= n - 1;
            res++;
        }
        return res;
    }
};