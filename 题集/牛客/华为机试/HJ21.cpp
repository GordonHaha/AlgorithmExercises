// https://www.nowcoder.com/practice/7960b5038a2142a18e27e4c733855dac
#include <iostream>
#include <string>
using namespace std;

const string dict1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
const string dict2 = "bcdefghijklmnopqrstuvwxyza222333444555666777788899990123456789";

char Char_Change(char a)
{
    int n = dict1.find(a);
    if (n != dict1.npos)
    {
        return dict2[n];
    }
    return a;
}

int main()
{
    string str;
    cin >> str;
    for (char c : str)
    {
        cout << Char_Change(c);
    }
    return 0;
}