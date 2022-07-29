// https://www.nowcoder.com/practice/4436c93e568c48f6b28ff436173b997f
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型 最大位数
     * @return int整型vector
     */
    vector<int> printNumbers(int n)
    {
        vector<int> res;
        for (int i = 1; i < pow(10, n); i++)
        {
            res.push_back(i);
        }
        return res;
    }
};