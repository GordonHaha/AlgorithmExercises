// https://www.nowcoder.com/practice/c3a6afee325e472386a1c4eb1ef987f3
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 反转字符串
     * @param str string字符串
     * @return string字符串
     */
    string solve(string str)
    {
        if (str.empty())
            return str;
        int left = 0, right = str.length() - 1;
        while (left < right)
        {
            swap(str[left], str[right]);
            left++;
            right--;
        }
        return str;
    }
};