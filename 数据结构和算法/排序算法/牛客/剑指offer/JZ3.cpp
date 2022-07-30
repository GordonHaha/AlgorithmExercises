// https://www.nowcoder.com/practice/6fe361ede7e54db1b84adc81d09d8524
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int duplicate(vector<int> &numbers)
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == i)
                continue;
            if (numbers[i] < numbers.size())
            {
                if (numbers[numbers[i]] == numbers[i])
                    return numbers[i];
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return -1;
    }
};
