// https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        int n = str.length();
        if (n == 0)
            return -1;
        unordered_map<char, int> map;
        for (char c : str)
        {
            map[c]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (map[str[i]] == 1)
                return i;
        }
        return -1;
    }
};