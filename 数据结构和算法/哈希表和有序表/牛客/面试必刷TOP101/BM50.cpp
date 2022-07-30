// https://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (map.find(target - numbers[i]) == map.end())
            {
                map[numbers[i]] = i;
            }
            else
            {
                int j = map[target - numbers[i]];
                return i < j ? vector<int>{i + 1, j + 1} : vector<int>{j + 1, i + 1};
            }
        }
        return vector<int>{};
    }
};