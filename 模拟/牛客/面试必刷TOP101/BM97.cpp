// https://www.nowcoder.com/practice/e19927a8fd5d477794dac67096862042

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    vector<int> solve(int n, int m, vector<int> &a)
    {
        // m要取余，因为每次走n步等于没走
        m = m % n;
        // 先逆转整个数组
        reverse(a.begin(), a.end());
        // 再逆转前m个
        reverse(a.begin(), a.begin() + m);
        // 最后逆转剩下的部分
        reverse(a.begin() + m, a.end());
        return a;
    }
};