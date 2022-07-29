// https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        if (array.size() * sum == 0)
            return {};
        int left = 0, right = array.size() - 1;
        while (left < right)
        {
            int tempSum = array[left] + array[right];
            if (tempSum == sum)
            {
                return {array[left], array[right]};
            }
            else if (tempSum < sum)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return {};
    }
};