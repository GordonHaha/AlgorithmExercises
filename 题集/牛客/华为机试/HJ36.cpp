// https://www.nowcoder.com/practice/e4af1fe682b54459b2a211df91a91cf3
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<bool> mp(26, false);
    string key;
    cin >> key;
    string resKey;
    for (char c : key)
    {
        c = tolower(c);
        if (mp[c - 'a'] == false)
        {
            mp[c - 'a'] = true;
            resKey += c;
        }
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (mp[c - 'a'] == false)
        {
            mp[c - 'a'] = true;
            resKey += c;
        }
    }

    string word;
    cin >> word;
    string resWord;
    for (char c : word)
    {
        resWord += resKey[c - 'a'];
    }
    cout << resWord << endl;
    return 0;
}