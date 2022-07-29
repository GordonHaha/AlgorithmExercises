// https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count(int num)
    {
        int count = 0;
        while (num > 0)
        {
            if (num == 1)
            {
                count++;
                num /= 10;
                break;
            }
            if ((num - num / 10 * 10) == 1)
            {
                count++;
            }
            num /= 10;
        }
        return count;
    }

    int cnt = 0;
    int NumberOf1Between1AndN_Solution(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            cnt += count(i);
        }
        return cnt;
    }
};