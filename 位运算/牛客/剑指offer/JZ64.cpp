// https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Sum_Solution(int n)
    {
        n && (n += Sum_Solution(n - 1));
        return n;
    }
};