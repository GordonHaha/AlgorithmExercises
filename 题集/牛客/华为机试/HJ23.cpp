// https://www.nowcoder.com/practice/05182d328eb848dda7fdd5e029a56da9
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> rec(26);
    string str;
    cin >> str;
    for (char c : str)
    {
        rec[c - 'a']++;
    }

    int minNum = 27;
    for (int num : rec)
    {
        if (num != 0)
        {
            minNum = min(minNum, num);
        }
    }

    string res;
    for (char c : str)
    {
        if (rec[c - 'a'] > minNum)
        {
            res += c;
        }
    }
    cout << res << endl;

    return 0;
}