// https://www.nowcoder.com/practice/389fc1c3d3be4479a154f63f495abff8
#include <bits/stdc++.h>
using namespace std;

class Solution
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
        for (int num : array)
        {
            temp ^= num;
        }

        int k = 1;
        while ((k & temp) == 0)
        {
            k <<= 1;
        }

        for (int num : array)
        {
            if ((k & num) == 0)
            {
                res[0] ^= num;
            }
            else
            {
                res[1] ^= num;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};