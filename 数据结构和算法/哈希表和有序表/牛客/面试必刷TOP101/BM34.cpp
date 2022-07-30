// https://www.nowcoder.com/practice/345e2ed5f81d4017bbb8cc6055b0b711

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> res;
        int n = num.size();
        if (n < 3)
            return res;
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i != 0 && num[i] == num[i - 1])
            {
                continue;
            }
            // 双指针
            int left = i + 1;
            int right = n - 1;
            int target = -num[i];
            while (left < right)
            {
                if (num[left] + num[right] == target)
                {
                    res.push_back({num[i], num[left], num[right]});
                    while (left + 1 < right && num[left + 1] == num[left])
                    {
                        left++;
                    }
                    while (right - 1 > left && num[right - 1] == num[right])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if (num[left] + num[right] > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return res;
    }
};