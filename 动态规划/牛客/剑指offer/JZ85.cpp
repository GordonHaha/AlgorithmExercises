// https://www.nowcoder.com/practice/11662ff51a714bbd8de809a89c481e21
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
    vector<int> FindGreatestSumOfSubArray(vector<int> &array)
    {
        vector<int> res;
        vector<int> dp(array.size());

        int left = 0, right = 0;
        int resL = 0, resR = 0;
        dp[0] = array[0];
        int maxSum = dp[0];
        for (int i = 1; i < array.size(); i++)
        {
            right++;
            dp[i] = max(dp[i - 1] + array[i], array[i]);
            if (dp[i - 1] + array[i] < array[i])
            {
                left = right;
            }

            if (dp[i] > maxSum || (dp[i] == maxSum && (right - left) > (resR - resL)))
            {
                maxSum = dp[i];
                resR = right;
                resL = left;
            }
        }

        for (int i = resL; i <= resR; i++)
        {
            res.push_back(array[i]);
        }
        return res;
    }
};