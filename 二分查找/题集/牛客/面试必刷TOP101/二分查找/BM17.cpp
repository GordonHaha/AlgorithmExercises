// https://www.nowcoder.com/practice/d3df40bd23594118b57554129cadf47b

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @param target int整型
     * @return int整型
     */
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return -1;
        }

        int L = 0, R = nums.size() - 1;
        int mid = 0;
        while (L < R)
        {
            mid = L + ((R - L) >> 1);
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }
        return nums[L] == target ? L : -1;
    }
};