// https://www.nowcoder.com/practice/389fc1c3d3be4479a154f63f495abff8
#include<bits/stdc++.h>
using namespace std;

// 方法一 哈希
class Solution1
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int> &array)
    {
        unordered_map<int, int> map;
        vector<int> res;
        for (int val : array)
        {
            map[val]++;
        }

        for (int val : array)
        {
            if (map[val] == 1)
                res.push_back(val);
        }

        sort(res.begin(), res.end());
        return res;
    }
};

// 方法二 异或
class Solution2
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int> &array)
    {
        vector<int> res(2, 0);
        int temp = 0;
        // 遍历数组得到a^b
        for (int val : array)
        {
            temp ^= val;
        }

        int k = 1;
        // 找到两个数不相同的一位
        while ((k & temp) == 0)
            k <<= 1;

        for (int i = 0; i < array.size(); i++)
        {
            // 遍历数组，对每个数分类
            if ((k & array[i]) == 0)
            {
                res[0] ^= array[i];
            }
            else
            {
                res[1] ^= array[i];
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};