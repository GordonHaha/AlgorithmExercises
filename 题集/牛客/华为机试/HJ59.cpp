// https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        int n = str.length();
        if (n == 1)
        {
            cout << str[0] << endl;
            break;
        }
        unordered_map<char, int> mp;
        for (char c : str)
        {
            mp[c]++;
        }

        string res = "-1";
        for (char c : str)
        {
            if (mp[c] == 1)
            {
                res = c;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}