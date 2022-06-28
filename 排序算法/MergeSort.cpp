/*
归并排序（Merge sort）是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
作为一种典型的分而治之思想的算法应用，归并排序的实现由两种方法：
自上而下的递归（所有递归的方法都可以用迭代重写，所以就有了第 2 种方法）；
自下而上的迭代；
和选择排序一样，归并排序的性能不受输入数据的影响，但表现比选择排序好的多，因为始终都是 O(nlogn) 的时间复杂度。代价是需要额外的内存空间

算法步骤
1、申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
2、设定两个指针，最初位置分别为两个已经排序序列的起始位置；
3、比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
4、重复步骤 3 直到某一指针达到序列尾；
5、将另一序列剩下的所有元素直接复制到合并序列尾。

*/

#include <iostream>
#include <cmath>

using namespace std;

// 递归实现
void mergeSort1(int arr[], int len)
{
    if (!arr || len < 2)
    {
        return;
    }

    process(arr, 0, len - 1);
}

void process(int arr[], int L, int R)
{
    if (L == R)
    {
        return;
    }
    int mid = L + ((R - L) >> 1);
    process(arr, L, mid);
    process(arr, mid + 1, R);
}

void mergeTwoPart(int arr[], int L, int M, int R)
{
    int *help = new int[R - L + 1];
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    while (p1 <= M && p2 <= R)
    {
        help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    }

    while (p1 <= M)
    {
        help[i++] = arr[p1++];
    }

    while (p2 <= R)
    {
        help[i++] = arr[p2++];
    }

    for (int i = 0; i <= R; i++)
    {
        arr[L + i] = help[i];
    }
    delete[] help;
}

// 非递归实现
void mergeSort2(int arr[], int len)
{
    if (!arr || len < 2)
    {
        return;
    }

    int step = 1;
    int N = len;
    while (step < N)
    {
        int L = 0;
        while (L < N)
        {
            int M = 0;
            if (N - L >= step)
            {
                M = L + step - 1;
            }
            else
            {
                M = N - 1;
            }

            if (M == N - 1)
            {
                break;
            }

            int R = 0;
            if (N - 1 - M >= step)
            {
                R = M + step;
            }
            else
            {
                R = N - 1;
            }

            mergeTwoPart(arr, L, M, R);

            if (R == N - 1)
            {
                break;
            }
            else
            {
                L = R + 1;
            }
        }

        if (step > (N / 2))
        {
            break;
        }
        step *= 2;
    }
}

void mergeSort3(int arr[], int len)
{
    if (!arr || len < 2)
    {
        return;
    }
    int N = len;
    int mergeSize = 1;
    while (mergeSize < N)
    {
        int L = 0;
        while (L < N)
        {
            if (mergeSize >= N - L)
            {
                break;
            }
            int M = L + mergeSize - 1;
            int R = M + min(mergeSize, N - M - 1);
            mergeTwoPart(arr, L, M, R);
            L = R + 1;
        }
        if (mergeSize > N / 2)
        {
            break;
        }

        mergeSize <<= 1;
    }
}