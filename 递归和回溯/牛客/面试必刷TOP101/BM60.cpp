// https://www.nowcoder.com/practice/c9addb265cdf4cdd92c092c655d164ca
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
     * @return string字符串vector
     */
    vector<string> res;
    void backTrack(int left, int right, string track, int n)
    {
        if (track.length() == 2 * n)
        {
            res.push_back(string(track));
            return;
        }

        if (left < n)
        {
            backTrack(left + 1, right, track + "(", n);
        }
        if (right < n && left > right)
        {
            backTrack(left, right + 1, track + ")", n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        string track;
        backTrack(0, 0, track, n);
        return res;
    }
};