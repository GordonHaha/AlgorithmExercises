/*
二分搜索是一种在有序数组中查找某一特定元素的搜索算法。搜索过程从数组的中间元素开始，如果中间元素正好是要查找的元素，则搜索过程结束；如果某一特定元素大于或者小于中间元素，则在数组大于或小于中间元素的那一半中查找，而且跟开始一样从中间元素开始比较。如果在某一步骤数组为空，则代表找不到。这种搜索算法每一次比较都使搜索范围缩小一半。
*/

#include <iostream>
using namespace std;

int binary_search(int sortedArr[], int len, int num)
{
    if (sortedArr == NULL || len == 0)
    {
        return -1;
    }

    int L = 0;
    int R = len - 1;
    int mid = 0;
    while (L < R)
    {
        mid = L + ((R - L) >> 1);
        if (sortedArr[mid] == num)
        {
            return mid;
        }
        else if (sortedArr[mid] > num)
        {
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    return sortedArr[L] == num ? L : -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int len = sizeof(arr) / sizeof(*arr);
    int num = 9;
    int ans = binary_search(arr, len, num);
    cout << ans << endl;
    return 0;
}