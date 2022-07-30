// https://www.nowcoder.com/practice/a35ce98431874e3a820dbe4b2d0508b1
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<char, int> mp;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        mp[str[i]]++;
    }
    char a;
    a = getchar();
    int res = 0;
    if (a >= 'a' && a <= 'z')
    {
        res = mp[a] + mp[char('A' + a - 'a')];
    }
    else if (a >= 'A' && a <= 'Z')
    {
        res = mp[a] + mp[char('a' + a - 'A')];
    }
    else
    {
        res = mp[a];
    }
    cout << res << endl;
    return 0;
}