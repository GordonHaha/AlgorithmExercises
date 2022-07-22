// https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163
#include <bits/stdc++.h>
using namespace std;

// 方法一 哈希表
class Solution1
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        unordered_map<int, int> map;
        for (int val : numbers)
        {
            map[val]++;
        }

        for (int val : numbers)
        {
            if (map[val] > numbers.size() / 2)
                return val;
        }
        return 0;
    }
};

class Solution2
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int n = 0;
        int count = 0;
        // 超过半数的数字经过不相等抵消后出现次数一定还是正数
        for (int i = 0; i < numbers.size(); i++)
        {
            if (count == 0)
                n = numbers[i];
            if (numbers[i] == n)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        count = 0;
        for (int val : numbers)
        {
            if (val == n)
                count++;
        }
        if (count > numbers.size() / 2)
            return n;
        return 0;
    }
};