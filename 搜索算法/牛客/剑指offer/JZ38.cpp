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
    unordered_map<int, bool> useMap; // 判断字符是否使用过

    void recursion(string str, string &track)
    {
        if (track.length() == str.length())
        {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < str.length(); i++)
        {
            // 用过的字符跳过
            if (useMap[i])
                continue;
            // 和前一个字符相同且前一个字符已经用过的跳过
            if (i - 1 >= 0 && str[i] == str[i - 1] && useMap[i - 1])
                continue;
            track += str[i];
            useMap[i] = true;
            recursion(str, track);
            useMap[i] = false;
            track.pop_back();
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