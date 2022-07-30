// https://www.nowcoder.com/practice/a43a2b986ef34843ac4fdd9159b69863
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    unordered_map<int, bool> use;
    void recursion(vector<int> &num, vector<int> &track)
    {
        if (track.size() == num.size())
        {
            res.push_back(vector<int>(track));
            return;
        }
        for (int i = 0; i < num.size(); i++)
        {
            if (use[i])
                continue;
            if (i > 0 && num[i] == num[i - 1] && !use[i - 1])
                continue;
            use[i] = true;
            track.push_back(num[i]);
            recursion(num, track);
            track.pop_back();
            use[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &num)
    {
        vector<int> track;
        sort(num.begin(), num.end());
        recursion(num, track);
        return res;
    }
};