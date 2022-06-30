// https://www.nowcoder.com/practice/fcf87540c4f347bcb4cf720b5b350c76

// 关键思路：中点位置和右侧位置比较，如果中点位置大，说明是下降趋势，那峰值一定在左侧或者就是中点本身，右边界左移到中点；如果中点位置小，说明是上升趋势，那峰值一定在右侧或者是右侧下一个位置，左边界右移到中点下一个位置。

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
     * @return int整型
     */
    int findPeakElement(vector<int> &nums)
    {
        int L = 0;
        int R = nums.size() - 1;
        int mid = 0;
        while (L < R)
        {
            mid = L + ((R - L) >> 1);
            if (nums[mid] > nums[mid + 1])
            {
                R = mid;
            }
            else
            {
                L = mid + 1;
            }
        }
        return R;
    }
};