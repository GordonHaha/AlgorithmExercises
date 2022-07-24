// https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isBST(vector<int> sequence, int l, int r)
    {
        if (l >= r)
            return true;
        int root = sequence[r];
        int find = l;

        for (; find < r; find++)
        {
            int cur = sequence[find];
            if (cur > root)
                break;
        }

        for (int i = find; i < r; i++)
        {
            int cur = sequence[i];
            if (cur < root)
                return false;
        }

        return isBST(sequence, l, find - 1) && isBST(sequence, find, r - 1);
    }

    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.empty())
            return false;
        return isBST(sequence, 0, sequence.size() - 1);
    }
};