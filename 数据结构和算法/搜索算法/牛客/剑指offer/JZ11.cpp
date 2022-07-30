// https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() == 1)
            return rotateArray[0];
        int left = 0, right = rotateArray.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (rotateArray[mid] > rotateArray[right])
            {
                // 如果mid元素大于right元素，说明最小值一定在右边
                left = mid + 1;
            }
            else if (rotateArray[mid] == rotateArray[right])
            {
                // 如果mid元素等于right元素，此时无法判断，右边界逐渐递减缩小范围
                right--;
            }
            else
            {
                // 如果mid元素小于于right元素
                right = mid;
            }
        }
        return rotateArray[left];
    }
};