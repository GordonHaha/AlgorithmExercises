/*
快速排序是由东尼·霍尔所发展的一种排序算法。在平均状况下，排序 n 个项目要 Ο(nlogn) 次比较。在最坏状况下则需要 Ο(n2) 次比较，但这种状况并不常见。事实上，快速排序通常明显比其他 Ο(nlogn) 算法更快，因为它的内部循环（inner loop）可以在大部分的架构上很有效率地被实现出来。
快速排序使用分治法（Divide and conquer）策略来把一个串行（list）分为两个子串行（sub-lists）。
快速排序又是一种分而治之思想在排序算法上的典型应用。本质上来看，快速排序应该算是在冒泡排序基础上的递归分治法。

算法步骤
1、从数列中挑出一个元素，称为 "基准"（pivot）;
2、重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
3、递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
*/

#include <bits/stdc++.h>

using namespace std;

void swapMem(vector<int> &arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void splitNum1(vector<int> &arr)
{
    int lessEqualR = -1;
    int index = 0;
    int N = arr.size();
    while (index < N)
    {
        if (arr[index] <= arr[N - 1])
        {
            swapMem(arr, ++lessEqualR, index++);
        }
        else
        {
            index++;
        }
    }
}

void spitNum2(vector<int> &arr)
{
    int N = arr.size();
    int lessR = -1;
    int moreL = N - 1;
    int index = 0;
    while (index < moreL)
    {
        if (arr[index] < arr[N - 1])
        {
            swapMem(arr, ++lessR, index++);
        }
        else if (arr[index] > arr[N - 1])
        {
            swapMem(arr, --moreL, index);
        }
        else
        {
            index++;
        }
    }
    swapMem(arr, moreL, N - 1);
}

// arr[L...R]范围上，拿arr[R]做划分值
// L...R < = >
vector<int> partition(vector<int> &arr, int L, int R)
{
    int lessR = L - 1;
    int moreL = R;
    int index = L;
    while (index < moreL)
    {
        if (arr[index] < arr[R])
        {
            swapMem(arr, ++lessR, index++);
        }
        else if (arr[index] > arr[R])
        {
            swapMem(arr, --moreL, index);
        }
        else
        {
            index++;
        }
    }
    swapMem(arr, moreL, R);
    vector<int> ans;
    ans.push_back(lessR + 1);
    ans.push_back(moreL);
    return ans;
}

void process(vector<int> &arr, int L, int R)
{
    if (L >= R)
    {
        return;
    }

    vector<int> equalE = partition(arr, L, R);
    // equalE[0] 等于区域第一个数
    // equalE[1] 等于区域最后一个数
    process(arr, L, equalE[0] - 1);
    process(arr, equalE[1] + 1, R);
}

void quickSort(vector<int> &arr)
{
    if (arr.size() < 2)
    {
        return;
    }

    process(arr, 0, arr.size() - 1);
}

// =========================================

// 标准递归写法
int partition(int A[], int low, int high)
{
    int pivot = A[low]; //第一个元素作为基准
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;

    return low;
}

void quickSort1(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = partition(A, low, high);
        quickSort1(A, low, pivotpos - 1);
        quickSort1(A, pivotpos + 1, high);
    }
}

// 迭代法

class Job
{
public:
    int L;
    int R;
    Job(int left, int right) : L(left), R(right){};
};

void quickSort2(vector<int> &arr)
{
    if (arr.size() < 2)
    {
        return;
    }
    stack<Job> stack;
    stack.push(Job(0, arr.size() - 1));
    while (!stack.empty())
    {
        Job cur = stack.top();
        stack.pop();
        vector<int> equals = partition(arr, cur.L, cur.R);
        if (equals[0] > cur.L)
        {
            stack.push(Job(cur.L, equals[0] - 1));
        }
        if (equals[1] < cur.R) {
            stack.push(Job(equals[1] + 1, cur.R));
        }
    }
}

int main()
{
    int arr[] = {34, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    int len = sizeof(arr) / sizeof(*arr);
    // quickSort1(arr, 0, len - 1);
    vector<int> varr(arr, arr + len);
    quickSort(varr);

    for (int i = 0; i < len; i++)
    {
        cout << varr[i] << " ";
    }
    cout << endl;
    return 0;
}