// https://www.nowcoder.com/practice/55fb3c68d08d46119f76ae2df7566880
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */

    vector<string> split(string s, string spliter)
    {
        vector<string> res;
        int i;
        while ((i = s.find(spliter)) && i != s.npos)
        {
            res.push_back(s.substr(0, i));
            s = s.substr(i + 1);
        }
        res.push_back(s);
        return res;
    }

    bool isIPv4(string IP)
    {
        vector<string> s = split(IP, ".");
        if (s.size() != 4)
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i].size() == 0)
                return false;
            if (s[i].size() > 3 || (s[i][0] == '0' && s[i].size() != 1))
                return false;
            for (int j = 0; j < s[i].size(); j++)
            {
                if (!isdigit(s[i][j]))
                {
                    return false;
                }
            }
            int num = stoi(s[i]);
            if (num < 0 || num > 255)
                return false;
        }
        return true;
    }

    bool isIPv6(string IP)
    {
        vector<string> s = split(IP, ":");
        if (s.size() != 8)
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i].size() == 0 || s[i].size() > 4)
                return false;
            for (int j = 0; j < s[i].size(); j++)
            {
                if (!(isdigit(s[i][j]) || (s[i][j] >= 'a' && s[i][j] <= 'f') || (s[i][j] >= 'A' && s[i][j] <= 'F')))
                {
                    return false;
                }
            }
        }
        return true;
    }

    string solve(string IP)
    {
        if (IP.size() == 0)
            return "Neither";
        if (isIPv4(IP))
        {
            return "IPv4";
        }
        else if (isIPv6(IP))
        {
            return "IPv6";
        }
        else
        {
            return "Neither";
        }
    }
};