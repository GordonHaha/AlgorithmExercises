// https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        int m = str.length();
        if (m == 0)
            return "";
        n %= m;
        reverse(str.begin(), str.end());
        reverse(str.begin() + m - n, str.end());
        reverse(str.begin(), str.begin() + m - n);
        return str;
    }
};