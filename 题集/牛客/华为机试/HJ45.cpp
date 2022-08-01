// https://www.nowcoder.com/practice/02cb8d3597cf416d9f6ae1b9ddc4fde3
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    while (cin >> str)
    {
        vector<int> record(26);
        for (char c : str)
        {
            record[c - 'a']++;
        }
        int score = 26;
        int res = 0;
        sort(record.begin(), record.end());
        for (int i = record.size() - 1; i >= 0; i--)
        {
            if (record[i] == 0)
            {
                break;
            }

            res += score * record[i];
            score--;
        }
        cout << res << endl;
    }
    return 0;
}