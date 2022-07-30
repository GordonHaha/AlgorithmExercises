// https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 二分查找k的位置
    int bs(vector<int> data, float k)
    {
        int left = 0, right = data.size() - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (data[mid] < k)
            {
                // 如果mid元素小于k，说明k在mid右侧，左边界设为mid+1
                left = mid + 1;
            }
            else if (data[mid] > k)
            {
                // 如果mid元素大于k，说明k在mid左侧，右边界设为mid-1
                right = mid - 1;
            }
        }
        return left;
    }

    int GetNumberOfK(vector<int> data, int k)
    {
        return bs(data, k + 0.5) - bs(data, k - 0.5);
    }
};