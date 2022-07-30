#include <bits/stdc++.h>
using namespace std;

// 一个数组中有两种数出现奇数次，其余数出现偶数次，找到这两个数
void pointOddTimesNum(int arr[], int len)
{
    int eor = 0;
    for (int i = 0; i < len; i++)
    {
        eor ^= arr[i];
    }

    // a 和 b是两种数
    // eor != 0
    // eor最右侧的1，提取出来
    // eor :     00110010110111000
    // rightOne: 00000000000001000
    int rightOne = eor & (-eor); // 提取出最右的1

    int onlyOne = 0; // eor'
    for (int i = 0; i < len; i++)
    {
        if ((arr[i] & rightOne) != 0)
        {
            onlyOne ^= arr[i];
        }
    }
    int a = onlyOne;
    int b = eor ^ a;
    cout << "a:" << a << "b:" << b << endl;
}

// 一个数组中有一种数出现k次，其他数都出现了M次，M > 1，K < M，找到出现了K次的数，要求额外空间复杂度O(1), 时间复杂度O(N)
int onlyKTimes(int arr[], int k, int m)
{
    int t[32];
    for (int num : t)
    {
        for (int i = 0; i < 32; i++)
        {
            t[i] += (num >> i) & 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if (t[i] % m != 0)
            ans |= (1 << i);
    }
    return ans;
}