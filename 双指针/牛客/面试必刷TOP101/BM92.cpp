// https://www.nowcoder.com/practice/b56799ebfd684fb394bd315e89324fb4
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int> &arr)
    {
        unordered_map<int, int> window;
        int left = 0, right = 0;
        int res = 0;

        while (right < arr.size())
        {
            int i = arr[right];
            right++;
            window[i]++;

            while (window[i] > 1)
            {
                int j = arr[left];
                window[j]--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};