// https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jumpFloor(int number)
    {
        int a = 1, b = 1, c = 1;
        for (int i = 2; i <= number; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};