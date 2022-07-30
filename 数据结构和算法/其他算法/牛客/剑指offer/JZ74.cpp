// https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> res;
        vector<int> temp;
        for (int left = 1, right = 2; left < right && right < 100;)
        {
            int tempSum = (left + right) * (right - left + 1) / 2;
            if (tempSum == sum)
            {
                temp.clear();
                for (int i = left; i <= right; i++)
                {
                    temp.push_back(i);
                }
                res.push_back(temp);
                left++;
            }
            else if (tempSum < sum)
            {
                right++;
            }
            else
            {
                left++;
            }
        }
        return res;
    }
};