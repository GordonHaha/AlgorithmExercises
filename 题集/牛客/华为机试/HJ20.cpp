// https://www.nowcoder.com/practice/184edec193864f0985ad2684fbc86841
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string checkPassword(string str)
{
    int len = str.length();

    // 长度校验
    if (len <= 8)
    {
        return "NG";
    }
    vector<int> record(4, 0);

    // 字符类型校验
    for (char c : str)
    {
        if (c >= 'a' && c <= 'z')
        {
            record[0] = 1;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            record[1] = 1;
        }
        else if (c >= '0' && c <= '9')
        {
            record[2] = 1;
        }
        else
        {
            record[3] = 1;
        }
    }

    if (record[0] + record[1] + record[2] + record[3] < 3)
    {
        return "NG";
    }

    // 重复子串校验
    for (int i = 0; i <= len - 6; i++)
    {
        for (int j = i + 3; j <= len - 3; j++)
        {
            if (str.substr(i, 3) == str.substr(j, 3))
            {
                return "NG";
            }
        }
    }

    return "OK";
}

int main()
{
    string str;
    while (cin >> str)
    {
        cout << checkPassword(str) << endl;
    }

    return 0;
}