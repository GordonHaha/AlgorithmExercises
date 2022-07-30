// https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1000000007;
    int mergeSort(vector<int> &data, int l, int r, vector<int> &temp)
    {
        if (l >= r)
            return 0;
        int mid = l + (r - l) / 2;
        int P = mergeSort(data, l, mid, temp) + mergeSort(data, mid + 1, r, temp);
        P %= mod;
        int i = 0;
        int left = l, right = mid + 1;
        while (left <= mid && right <= r)
        {
            if (data[left] < data[right])
            {
                temp[i++] = data[left++];
            }
            else
            {
                temp[i++] = data[right++];
                P += (mid - left + 1) % mod;
            }
        }

        while (left <= mid)
        {
            temp[i++] = data[left++];
        }
        while (right <= r)
        {
            temp[i++] = data[right++];
        }

        for (int j = 0; j <= r - l; j++)
        {
            data[l + j] = temp[j];
        }

        return P % mod;
    }

    int InversePairs(vector<int> data)
    {
        if (data.size() < 2)
            return 0;
        vector<int> temp(data.size());
        return mergeSort(data, 0, data.size() - 1, temp);
    }
};