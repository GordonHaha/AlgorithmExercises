// https://www.nowcoder.com/practice/50ec6a5b0e4e45348544348278cdcee5?
#include<bits/stdc++.h>
using namespace std;

// 方法一
class Solution1
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int val : nums)
        {
            if (val > 0)
                map[val]++;
        }

        int i = 1;
        while (map.find(i) != map.end())
        {
            i++;
        }
        return i;
    }
};

// 方法二 
class Solution2
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int t = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] <= 0)
            {
                i++;
            }
            while (nums[i++] == t)
            {
                t++;
            }
        }
        return t;
    }
};

// 方法三
class Solution3
{
public:
    int minNumberDisappeared(vector<int> &nums)
    {
        int n = nums.size();
        //遍历数组
        for (int i = 0; i < n; i++)
            //负数全部记为n+1
            if (nums[i] <= 0)
                nums[i] = n + 1;
        for (int i = 0; i < n; i++)
            //对于1-n中的数字
            if (abs(nums[i]) <= n)
                //这个数字的下标标记为负数
                nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
        for (int i = 0; i < n; i++)
            //找到第一个元素不为负数的下标
            if (nums[i] > 0)
                return i + 1;
        return n + 1;
    }
};
