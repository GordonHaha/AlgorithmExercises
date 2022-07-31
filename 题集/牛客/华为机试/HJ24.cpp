// https://www.nowcoder.com/practice/6d9d69e3898f45169a441632b325c7b4
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> heights;
    int height;
    while (cin >> height)
    {
        heights.push_back(height);
    }

    vector<int> left(n, 1); // 记录以该数（下标）为中心同学时左侧包含他自己的人数（最长递增序列长度）
    for (int i = 1; i < heights.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (heights[i] > heights[j])
            {
                left[i] = max(left[i], left[j] + 1);
            }
        }
    }

    vector<int> right(n, 1); // 记录以该数（下标）为中心同学时右侧包含他自己的人数（最长递减序列长度）
    for (int i = heights.size() - 2; i >= 0; i--)
    {
        for (int j = heights.size() - 1; j > i; j--)
        {
            if (heights[i] > heights[j])
            {
                right[i] = max(right[i], right[j] + 1);
            }
        }
    }

    int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        if (left[i] + right[i] > maxNum)
        {
            maxNum = left[i] + right[i];
        }
    }

    // 加1要算上自己，因为被减了两次自己
    cout << n - maxNum + 1 << endl;
    return 0;
}