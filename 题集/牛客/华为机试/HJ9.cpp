// https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    string res;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (mp.count(s[i]) == 0)
        {
            res += s[i];
            mp[s[i]]++;
        }
    }
    cout << res << endl;
    return 0;
}
