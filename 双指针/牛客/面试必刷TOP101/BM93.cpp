// https://www.nowcoder.com/practice/3d8d6a8e516e4633a2244d2934e5aa47
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param height int整型vector
     * @return int整型
     */
    int maxArea(vector<int> &height)
    {
        if (height.size() < 2)
            return 0;
        int res = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            int h = min(height[left], height[right]);
            int l = right - left;
            res = max(res, h * l);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};