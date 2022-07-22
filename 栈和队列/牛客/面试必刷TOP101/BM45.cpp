// https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &nums, int size)
    {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++)
        {
            while (dq.size() && nums[dq.back()] <= nums[i])
            {
                // 当新来的数比队尾大时，弹出队尾
                dq.pop_back();
            }
            while (dq.size() && i - dq.front() + 1 > size)
            {
                // 当队首位置超过新的滑动窗口时，弹出队首
                dq.pop_front();
            }
            dq.push_back(i);

            if (size && i + 1 >= size)
            {
                //当前位置超过size时，往结果数组里加入队首最大值
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};