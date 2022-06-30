// https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        int left = 0;
        int right = rotateArray.size() - 1;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            // 最小数字在mid右边
            if (rotateArray[mid] > rotateArray[right])
            {
                left = mid + 1;
                // 无法判断，右指针左移一个个试
            }
            else if (rotateArray[mid] == rotateArray[right])
            {
                right--;
                // 最小数字要么是mid要么在mid左边
            }
            else
            {
                right = mid;
            }
        }

        return rotateArray[left];
    }
};