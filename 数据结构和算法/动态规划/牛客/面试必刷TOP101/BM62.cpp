// https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=295
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Fibonacci(int n)
    {
        int a = 1, b = 1, c = 1;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};