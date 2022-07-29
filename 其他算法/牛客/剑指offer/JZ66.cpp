// https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> B(A.size(), 1);
        // 先从左到右遍历一遍,算出前缀乘积
        for (int i = 1; i < A.size(); i++)
        {
            B[i] = B[i - 1] * A[i - 1];
        }

        // 再从右往左乘上后缀乘积
        int temp = 1;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            B[i] *= temp;
            temp *= A[i];
        }
        return B;
    }
};