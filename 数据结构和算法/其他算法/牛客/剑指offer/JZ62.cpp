// https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n * m == 0)
            return -1;
        int x = 0;
        for (int i = 2; i <= n; i++)
        {
            x = (m + x) % i;
        }
        return x;
    }
};