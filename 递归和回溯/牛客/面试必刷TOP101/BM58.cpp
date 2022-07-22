// https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return string字符串vector
     */
    vector<string> res;
    unordered_map<char, bool> use;
    void recursion(string &str, string &track)
    {
        if (track.length() == str.size())
        {
            res.push_back(string(track));
            return;
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (use[i])
                continue;
            if (i - 1 >= 0 && str[i] == str[i - 1] && !use[i - 1])
                continue;
            use[i] = true;
            track += str[i];
            recursion(str, track);
            track.pop_back();
            use[i] = false;
        }
    }

    vector<string> Permutation(string str)
    {
        if (str.empty())
            return res;
        string track;
        sort(str.begin(), str.end());
        recursion(str, track);
        return res;
    }
};