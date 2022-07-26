// https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        if (pushV.empty())
            return false;
        stack<int> s;
        for (int i = 0, j = 0; i < pushV.size();)
        {
            s.push(pushV[i++]);
            while (j < popV.size() && !s.empty() && s.top() == popV[j])
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};