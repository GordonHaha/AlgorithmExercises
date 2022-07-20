// https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;
        int n = array.size();

        int x = array[0];
        int y = 0;
        int maxSum = x;
        for (int i = 1; i < n; i++)
        {
            y = max(x + array[i], array[i]);
            maxSum = max(maxSum, y);
            x = y;
        }
        return maxSum;
    }
};