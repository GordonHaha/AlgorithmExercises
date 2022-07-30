// https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> res;
    void Insert(int num)
    {
        if (res.empty())
        {
            res.push_back(num);
        }
        else
        {
            int i = 0;
            for (; i < res.size(); i++)
            {
                if (num <= res[i])
                    break;
            }
            res.insert(res.begin() + i, num);
        }
    }

    double GetMedian()
    {
        int n = res.size();
        if (n % 2 == 1)
        {
            return double(res[n / 2]);
        }
        else
        {
            return double((res[n / 2] + res[(n - 1) / 2])) / 2;
        }
    }
};