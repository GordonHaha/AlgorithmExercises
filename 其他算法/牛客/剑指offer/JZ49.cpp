// https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index == 0)
            return 0;
        vector<int> factors = {2, 3, 5};

        unordered_map<long, int> map;
        priority_queue<long, vector<long>, greater<long>> pq;

        map[1L] = 1;
        pq.push(1L);
        long res = 0;
        for (int i = 0; i < index; i++)
        {
            res = pq.top();
            pq.pop();
            for (int j = 0; j < 3; j++)
            {
                long next = res * factors[j];
                if (map.count(next) == 0)
                {
                    map[next] = 1;
                    pq.push(next);
                }
            }
        }
        return (int)res;
    }
};