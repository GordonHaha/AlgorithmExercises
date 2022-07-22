// https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> res;
        if (k == 0 || k > input.size())
            return res;
        priority_queue<int> pq;
        for (const int val : input)
        {
            if (pq.size() < k)
            {
                pq.push(val);
            }
            else
            {
                if (val < pq.top())
                {
                    pq.pop();
                    pq.push(val);
                }
            }
        }

        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};