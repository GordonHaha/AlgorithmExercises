// https://www.nowcoder.com/practice/e016ad9b7f0b45048c58a9f27ba618bf?tpId=295

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int partition(vector<int> &a, int l, int r)
    {
        swap(a[l], a[rand() % (r - l + 1) + l]);
        int pivot = a[l];
        // 降序排列，把比基准数大的都放左边
        while (l < r)
        {
            while (l < r && a[r] <= pivot)
                r--;
            a[l] = a[r];
            while (l < r && a[l] > pivot)
                l++;
            a[r] = a[l];
        }
        a[l] = pivot;
        return l;
    }

    void quickSort(vector<int> &a, int l, int r, int K)
    {
        if (l >= r)
            return;
        int p = partition(a, l, r);
        if (p < K - 1)
        {
            quickSort(a, p + 1, r, K);
        }
        else if (p > K - 1)
        {
            quickSort(a, l, p - 1, K);
        }
        else
        {
            return;
        }
    }

    int findKth(vector<int> a, int n, int K)
    {
        if (K == 0 || K > n)
            return 0;
        quickSort(a, 0, n - 1, K);
        return a[K - 1];
    }
};