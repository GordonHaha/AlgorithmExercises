/*
基数排序是一种非比较型整数排序算法，其原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。由于整数也可以表达字符串（比如名字或日期）和特定格式的浮点数，所以基数排序也不是只能使用于整数。

1. 基数排序 vs 计数排序 vs 桶排序
基数排序有两种方法：
这三种排序算法都利用了桶的概念，但对桶的使用方法上有明显差异：
基数排序：根据键值的每位数字来分配桶；
计数排序：每个桶只存储单一键值；
桶排序：每个桶存储一定范围的数值；
*/

#include <bits/stdc++.h>
using namespace std;

int maxbits(int arr[], int len)
{
    int maxNum = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        maxNum = max(maxNum, arr[i]);
    }
    int res = 0;
    while (maxNum != 0)
    {
        res++;
        maxNum /= 10;
    }

    return res;
}

int getDigit(int x, int d)
{
    return ((x / ((int)pow(10, d - 1))) % 10);
}

void radixSort(int arr[], int L, int R, int digit)
{
    int radix = 10;
    int i = 0, j = 0;
    int help[R - L + 1];
    
    for (int d = 1; d <= digit; d++)
    {
        // 10个空间
        // count[0] 当前位(d位)是0的数字有多少个
        // count[1] 当前位(d位)是(0和1)的数字有多少个
        // count[2] 当前位(d位)是(0、1和2）的数字有多少个
        // count[i] 当前位(d位)是(0~i)的数字有多少个
        int count[radix];
        for (int i = 0; i < radix; i++)
        {
            count[i] = 0;
        }
        for (i = L; i <= R; i++)
        {
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for (i = 1; i < radix; i++)
        {
            count[i] = count[i] + count[i - 1];
        }
        for (i = R; i >= L; i--)
        {
            j = getDigit(arr[i], d);
            help[count[j] - 1] = arr[i];
            count[j]--;
        }
        for (i = L, j = 0; i <= R; i++, j++)
        {
            arr[i] = help[j];
        }
    }
}

void radixSort(int arr[], int len)
{
    if (!arr || len < 2)
    {
        return;
    }
    radixSort(arr, 0, len, maxbits(arr, len));
}

int main()
{
    int arr[] = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    int len = sizeof(arr) / sizeof(*arr);
    radixSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}