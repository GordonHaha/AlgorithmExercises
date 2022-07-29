// https://www.nowcoder.com/practice/0c1b486d987b4269b398fee374584fc8
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
    vector<int> reOrderArrayTwo(vector<int> &array)
    {
        if (array.size() < 2)
            return array;
        int l = 0, r = array.size() - 1;
        while (l < r)
        {
            if (array[l] % 2 == 1 && array[r] % 2 == 1)
            {
                // 左奇右奇，移动左指针
                l++;
            }
            else if (array[l] % 2 == 1 && array[r] % 2 == 0)
            {
                // 左奇右偶，移动左右指针
                l++;
                r--;
            }
            else if (array[l] % 2 == 0 && array[r] % 2 == 1)
            {
                // 左偶右奇，交换
                swap(array[l], array[r]);
            }
            else
            {
                // 左偶右偶，移动右指针
                r--;
            }
        }
        return array;
    }
};