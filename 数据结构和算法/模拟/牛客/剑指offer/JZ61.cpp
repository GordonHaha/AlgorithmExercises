// https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        int minNum = 14, maxNum = 0;
        int flag = 0;
        for (int num : numbers)
        {
            if (num == 0)
                continue;
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
            if ((flag & (1 << num)) != 0)
                return false;
            flag |= (1 << num);
        }
        return maxNum - minNum < 5;
    }
};