// https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, int> mp;
    queue<char> q;
    // Insert one char from stringstream
    void Insert(char ch)
    {
        if (mp.count(ch) == 0)
            q.push(ch);
        mp[ch]++;
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while (!q.empty())
        {
            if (mp[q.front()] == 1)
            {
                return q.front();
            }
            else
            {
                q.pop();
            }
        }
        return '#';
    }
};