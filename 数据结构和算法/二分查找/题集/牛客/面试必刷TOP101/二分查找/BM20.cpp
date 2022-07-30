// https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5

// 关键思路：利用归并排序，判断有序数组中左侧最小值是否大于右侧最大值，满足条件时就有M-L+1个逆序对
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int const mod = 1000000007;

    int mergeSort(vector<int> &data, int L, int R, vector<int> &temp)
    {
        if (L >= R)
            return 0;
        int mid = L + ((R - L) >> 1);
        int P = mergeSort(data, L, mid, temp) + mergeSort(data, mid + 1, R, temp);

        int left = L, right = mid + 1, index = 0;

        while (left <= mid && right <= R)
        {
            // 此时没有逆序对
            if (data[left] <= data[right])
            {
                temp[index] = data[left];
                index++;
                left++;
            }
            else
            { // 此时有逆序对
                temp[index] = data[right];
                index++;
                right++;
                P += mid - left + 1; //
                P %= mod;
            }
        }

        // 继续完成排序工作
        // 当right已到R+1位置，left还未到mid位置时
        while (left <= mid)
        {
            temp[index++] = data[left++];
        }

        // 当left已到mid+1位置，right还未到R位置时
        while (right <= R)
        {
            temp[index++] = data[right++];
        }

        // 把排好序的临时数组拷贝覆盖回原数组对应位置
        int ans = L;
        for (int i = 0; i < R - L + 1; i++)
        {
            data[ans++] = temp[i];
        }

        return P % mod;
    }

    int InversePairs(vector<int> data)
    {
        if (data.size() < 2)
            return 0;
        vector<int> temp(data.size());
        return mergeSort(data, 0, data.size() - 1, temp) % mod;
    }
};