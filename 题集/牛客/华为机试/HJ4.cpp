// https://www.nowcoder.com/practice/d9162298cb5a437aad722fccccaae8a7
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    string res = "";
    while (str.length() > 8)
    {
        res = str.substr(0, 8);
        cout << res << endl;
        str = str.substr(8);
    }

    int n = 8 - str.length();
    for (int i = 0; i < n; i++)
    {
        str += '0';
    }
    cout << str << endl;
    return 0;
}