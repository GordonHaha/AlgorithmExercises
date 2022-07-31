// https://www.nowcoder.com/practice/2aa32b378a024755a3f251e75cbf233a
#include <string>
#include <iostream>
using namespace std;

const string dict1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const string dict2 = "BCDEFGHIJKLMNOPQRSTUVWXYZAbcdefghijklmnopqrstuvwxyza1234567890";

string encrypt(string str)
{
    string res;
    for (char c : str)
    {
        int i = dict1.find(c);
        if (i != dict1.npos)
        {
            res += dict2[i];
        }
        else
        {
            res += c;
        }
    }
    return res;
}

string decode(string str)
{
    string res;
    for (char c : str)
    {
        int i = dict2.find(c);
        if (i != dict2.npos)
        {
            res += dict1[i];
        }
        else
        {
            res += c;
        }
    }
    return res;
}

int main()
{
    string str;
    cin >> str;
    cout << encrypt(str) << endl;
    cin >> str;
    cout << decode(str) << endl;
    return 0;
}