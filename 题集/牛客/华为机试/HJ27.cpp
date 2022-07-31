// https://www.nowcoder.com/practice/03ba8aeeef73400ca7a37a5f3370fe68
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<char, int> mp;
bool isBrotherWord(string a, string b)
{
    if (a == b || a.size() != b.size())
        return false;
    mp.clear();
    for (char c : a)
    {
        mp[c]++;
    }
    for (char c : b)
    {
        mp[c]--;
    }

    for (auto p : mp)
    {
        if (p.second != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    string temp;
    vector<string> words;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        words.push_back(temp);
    }

    string target;
    cin >> target;
    vector<string> res;
    for (string s : words)
    {
        if (isBrotherWord(s, target))
        {
            res.push_back(s);
        }
    }
    cout << res.size() << endl;
    int k;
    cin >> k;
    sort(res.begin(), res.end());
    if (k < res.size())
    {
        cout << res[k - 1] << endl;
    }
    return 0;
}