// https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double Power(double base, int exponent)
    {
        if (exponent < 0)
        {
            base = 1 / base;
            exponent = -exponent;
        }
        double res = 1.0;
        for (int i = 0; i < exponent; i++)
        {
            res *= base;
        }
        return res;
    }
};