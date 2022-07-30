// https://www.nowcoder.com/practice/de538edd6f7e4bc3a5689723a7435682
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> splitIP(string str)
{
    vector<int> res;
    if (!isdigit(str[0]))
    {
        // 第一位不是数字的话不合法
        return {};
    }
    int num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            if (str[i + 1])
                res.push_back(num);
            num = 0;
            continue;
        }

        if (!isdigit(str[i]))
        {
            return {};
        }

        num = num * 10 + (str[i] - '0');
    }

    res.push_back(num);
    return res;
}

bool isValidMask(string mask)
{
    vector<int> masks = splitIP(mask);
    unsigned b = 0;
    for (int num : masks)
        b = (b << 8) + num;
    if (!b)
        return false;
    b = ~b + 1;
    if (b == 1)
        return false;
    if ((b & (b - 1)) == 0)
        return true;
    return false;
}

// 判断IP类别，非法返回5，忽略返回-1，合法返回0~4对应A到E，数组第二位表示是否是私有IP
vector<int> judgeIP(string IP, string mask)
{
    int category = 5;

    vector<int> IPs = splitIP(IP);
    if (IPs.size() != 4)
    {
        return {5, 0};
    }

    if (IPs[0] == 0 || IPs[0] == 127)
    {
        return {-1, 0};
    }
    if (!isValidMask(mask))
    {
        return {5, 0};
    }

    bool flag = false;
    if (IPs[0] >= 1 && IPs[0] <= 126)
    {
        for (int i = 1; i < 4; i++)
        {
            flag = IPs[i] >= 0 && IPs[i] <= 255;
        }
        if (flag)
        {
            category = 0;
            flag = false;
        }
    }
    else if (IPs[0] >= 128 && IPs[0] <= 191)
    {
        for (int i = 1; i < 4; i++)
        {
            flag = IPs[i] >= 0 && IPs[i] <= 255;
        }
        if (flag)
        {
            category = 1;
            flag = false;
        }
    }
    else if (IPs[0] >= 192 && IPs[0] <= 223)
    {
        for (int i = 1; i < 4; i++)
        {
            flag = IPs[i] >= 0 && IPs[i] <= 255;
        }
        if (flag)
        {
            category = 2;
            flag = false;
        }
    }
    else if (IPs[0] >= 224 && IPs[0] <= 239)
    {
        for (int i = 1; i < 4; i++)
        {
            flag = IPs[i] >= 0 && IPs[i] <= 255;
        }
        if (flag)
        {
            category = 3;
            flag = false;
        }
    }
    else if (IPs[0] >= 240 && IPs[0] <= 255)
    {
        for (int i = 1; i < 4; i++)
        {
            flag = IPs[i] >= 0 && IPs[i] <= 255;
        }
        if (flag)
        {
            category = 4;
            flag = false;
        }
    }

    if (category == 5)
    {
        return {5, 0};
    }

    if (IPs[0] == 10 && IPs[0] == 10)
    {
        for (int i = 1; i < 4; i++)
        {
            flag = IPs[i] >= 0 && IPs[i] <= 255;
        }
    }
    else if (IPs[0] == 172 && IPs[0] == 172 && IPs[1] == 16 && IPs[1] == 31)
    {
        for (int i = 2; i < 4; i++)
        {
            flag = IPs[i] >= 0 && IPs[i] <= 255;
        }
    }
    else if (IPs[0] == 192 && IPs[0] == 192 && IPs[1] == 168 && IPs[1] == 168)
    {
        for (int i = 2; i < 4; i++)
        {
            flag = IPs[i] >= 0 && IPs[i] <= 255;
        }
    }

    return {category, int(flag)};
}

int main()
{
    string str;
    vector<int> res(7, 0);
    vector<int> cate;
    while (cin >> str)
    {
        int find = 0;
        ;
        while (str[find] != '~')
        {
            find++;
        }
        string IP = str.substr(0, find);
        string mask = str.substr(find + 1);
        cate = judgeIP(IP, mask);
        if (cate[0] == -1)
            continue;
        res[cate[0]]++;
        if (cate[1] == 1)
        {
            res[6]++;
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}