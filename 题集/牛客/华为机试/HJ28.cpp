// https://www.nowcoder.com/practice/b9eae162e02f4f928eac37d7699b352e
#include <bits/stdc++.h>
using namespace std;

bool isPrimeNum(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool findFunc(int index, vector<bool> &used, vector<int> &match, vector<vector<bool>> &map)
{
    for (int i = 0; i < used.size(); i++)
    {
        if (map[i][index] && !used[i])
        {
            used[i] = true;
            if (match[i] == -1 || findFunc(match[i], used, match, map))
            {
                match[i] = index;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> odds;
    vector<int> evens;
    int num;
    while (cin >> num)
    {
        if (num % 2)
        {
            odds.push_back(num);
        }
        else
        {
            evens.push_back(num);
        }
    }

    if (odds.empty() || evens.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<bool>> map(odds.size(), vector<bool>(evens.size()));
    for (int i = 0; i < odds.size(); i++)
    {
        for (int j = 0; j < evens.size(); j++)
        {
            if (isPrimeNum(odds[i] + evens[j]))
            {
                map[i][j] = true;
            }
        }
    }

    vector<int> match(odds.size(), -1);
    int count = 0;
    for (int i = 0; i < evens.size(); i++)
    {
        vector<bool> used(odds.size(), false);
        if (findFunc(i, used, match, map))
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}