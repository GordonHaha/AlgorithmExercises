// https://www.nowcoder.com/practice/4bcf3081067a4d028f95acee3ddcd2b1
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    void recursion(vector<int> &num, int index)
    {
        if (index == num.size() - 1)
        {
            res.push_back(num);
            return;
        }

        for (int i = index; i < num.size(); i++)
        {
            swap(num[i], num[index]);
            recursion(num, index + 1);
            swap(num[i], num[index]);
        }
    }

    vector<vector<int>> permute(vector<int> &num)
    {
        sort(num.begin(), num.end());
        recursion(num, 0);
        return res;
    }
};