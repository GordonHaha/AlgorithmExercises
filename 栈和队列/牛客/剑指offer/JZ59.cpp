// https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &nums, int size)
    {
        vector<int> res; // 结果数组
        deque<int> dq;   // 窗口内最大值下标队列
        for (int i = 0; i < nums.size(); i++)
        {
            while (dq.size() && nums[i] >= nums[dq.back()])
            {
                // 当新来的数大于队尾元素时，循环弹出队尾元素
                dq.pop_back();
            }
            while (dq.size() && i - dq.front() + 1 > size)
            {
                // 当队首元素超出窗口范围时，循环弹出队首元素
                dq.pop_front();
            }
            dq.push_back(i);
            if (dq.size() && i + 1 >= size)
            {
                // 当窗口范围满足size长度时加入结果数组
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};