#include <bits/stdc++.h>

using namespace std;

// 求arr中的最大值

int getMax(int arr[], int len)
{
    return process(arr, 0, len - 1);
}

// arr[L...R]范围上求最大值
int process(int arr[], int L, int R)
{
    // arr[L...R]范围上只有一个数，直接返回，base case
    if (L == R)
        return arr[L];
    // L...R不止一个数
    // mid = (L + R) / 2
    int mid = L + ((R - L) >> 1);
    int leftMax = process(arr, L, mid);
    int rightMax = process(arr, mid + 1, R);
    return max(leftMax, rightMax);
}

/*
Master公式
形如
T(N) = a * T(N/b) + O(N^d)（其中的a，b，d都是常数）的递归函数，可以直接通过Master公式来确定时间复杂度
如果log(b,a) < d，复杂度为O(N^d);
如果log(b,a) > d，复杂度为O(N^log(b,a));
如果log(b,a) == d，复杂度为O(N^d * logN)
*/