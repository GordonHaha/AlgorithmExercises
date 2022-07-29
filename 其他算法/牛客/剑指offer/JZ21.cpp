// https://www.nowcoder.com/practice/ef1f53ef31ca408cada5093c8780f44b
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
    vector<int> reOrderArray(vector<int> &array)
    {
        if (array.empty())
            return {};
        vector<int> res;
        if (array.size() == 1)
            return {array[0]};
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 == 1)
                res.push_back(array[i]);
        }
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 == 0)
                res.push_back(array[i]);
        }
        return res;
    }
};