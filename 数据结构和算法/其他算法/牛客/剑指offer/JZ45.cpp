// https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(const string &x, const string &y)
    {
        return x + y < y + x;
    };

    string PrintMinNumber(vector<int> numbers)
    {
        if (numbers.empty())
            return "";
        vector<string> temp;
        for (int i : numbers)
        {
            temp.push_back(to_string(i));
        }

        sort(temp.begin(), temp.end(), cmp);
        string res;
        for (int i = 0; i < temp.size(); i++)
        {
            res += temp[i];
        }
        return res;
    }
};