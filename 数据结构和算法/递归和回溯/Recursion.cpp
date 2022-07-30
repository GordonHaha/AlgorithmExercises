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

/*
N皇后问题
N皇后问题是指在N*N的棋盘上要摆N个皇后，要求任何两个皇后不同行、不同列，
也不在同一条斜线上。
给定一个整数你，返回n皇后的摆法有多少种。
n=1，返回1。
n=2或3,2皇后和3皇后问题无论怎么摆都不行，返回0.
n=8，返回92
*/

// 方法一

// record[0...i-1]你需要看，record[i...]不需要看
// 返回i行皇后，放在了j列，是否有效
bool isValid(vector<int> &record, int i, int j)
{
    for (int k = 0; k < i; k++)
    {
        if (j == record[k] || abs(record[k] - j) == abs(i - k))
        {
            return false;
        }
    }
    return true;
}

// record[0...i-1]的皇后，任何两个皇后一定都不共行、不共列，不共斜线
// 目前来到了第i行
// record[0...i-1]表示之前的行，放了的皇后位置
// n代表整体一共有多少行
// 返回值是摆完所有的皇后，合理的摆法有多少种
int process1(int i, vector<int> &record, int n)
{
    if (i == n) // 终止行
    {
        return 1;
    }
    int res = 0;
    for (int j = 0; j < n; j++) // 当前行在i行，尝试i行所有的列 -> j
    {
        // 当前i行的皇后，放在j列，会不会和之前（0...i-1）的皇后，共行共列或者共斜线
        // 如果是，认为有效
        // 如果不是，认为无效
        if (isValid(record, i, j);)
        {
            record[i] = j;
            res += process1(i + 1, record, n);
        }
    }
    return res;
}

int num1(int n)
{
    if (n < 1)
    {
        return 0;
    }
    vector<int> record[n]; // record[i] -> i行的皇后，放在了第几列
    return process1(0, record, n);
}

// 方法二 位运算优化（不能超过32皇后问题）
// colLim 列的限制，1的位置不能放皇后，0的位置可以
// leftDiaLim 左斜线的限制，1的位置不能放皇后，0的位置可以
// rightDiaLim 右斜线的限制，1的位置不能放皇后，0的位置可以
int process2(int limit, int colLim, unsigned int leftDiaLim, unsigned int rightDiaLim)
{
    if (colLim == limit)
    {
        return 1;
    }

    // 所有候选皇后的位置，都在pos上
    int pos = limit & (~(colLim | leftDiaLim | rightDiaLim));
    int mostRightOne = 0;

    int res = 0;
    
    while ([pos != 0])
    {
        mostRightOne = pos & (~pos + 1);
        pos = pos - mostRightOne;
        res += process2(limit, colLim | mostRightOne, (leftDiaLim | mostRightOne) << 1, (rightDiaLim | mostRightOne) >> 1);
    }
}

int num2(int n)
{
    if (n < 1 || n > 32)
    {
        return 0;
    }
    int limit = n == 32 ? -1 : (1 << n) - 1;
    return process2(limit, 0, 0, 0);
}

int main()
{
    return 0;
}