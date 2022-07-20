// https://www.nowcoder.com/practice/ce73540d47374dbe85b3125f57727e1e

#include <bits/stdc++.h>
using namespace std;

// 方法一 暴力枚举
class Solution1
{
public:
    /**
     *
     * @param s string字符串
     * @return string字符串vector
     */
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        int n = s.length();
        // 第一个点的位置 最早在1，最晚在3
        for (int i = 1; i < 4 && i < n - 2; i++)
        {
            // 第二个点的位置 最早在i+1，最晚在i+3
            for (int j = i + 1; j < i + 4 && j < n - 1; j++)
            {
                // 第三个点的位置 最早在j+1，最晚在j+3
                for (int k = j + 1; k < j + 4 && k < n; k++)
                {
                    // 最后一段长度不能超过3
                    if (n - k > 3)
                    {
                        continue;
                    }

                    // 从点的位置分段截取
                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);

                    // 每一段数字不能超过255
                    if (stoi(a) > 255 || stoi(b) > 255 || stoi(c) > 255 || stoi(d) > 255)
                    {
                        continue;
                    }

                    // 每一段超过两位时前导不能为0
                    if ((a.length() != 1 && a[0] == '0') || (b.length() != 1 && b[0] == '0') || (c.length() != 1 && c[0] == '0') || (d.length() != 1 && d[0] == '0'))
                    {
                        continue;
                    }

                    // 组装字符串
                    string temp = a + '.' + b + '.' + c + '.' + d;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};

// 方法二 递归 回溯
class Solution2
{
public:
    /**
     *
     * @param s string字符串
     * @return string字符串vector
     */

    void dfs(string s, vector<string> &res, vector<string> &ip, int start)
    {
        if (ip.size() == 4 && start == s.length())
        {
            string str = ip[0] + '.' + ip[1] + '.' + ip[2] + '.' + ip[3];
            res.push_back(str);
            return;
        }

        // 剩余长度超过组成结果的最大长度，剪枝
        if (s.length() - start > 3 * (4 - ip.size()))
            return;
        // 剩余长度不够组成完整结果的最小长度，剪枝
        if (s.length() - start < (4 - ip.size()))
            return;

        int num = 0;
        for (int i = start; i < start + 3 && i < s.length(); i++)
        {
            num = num * 10 + s[i] - '0';
            // 不符合要求，跳过
            if (num < 0 || num > 255)
                continue;

            ip.push_back(s.substr(start, i - start + 1));
            dfs(s, res, ip, i + 1);
            ip.pop_back();

            // 前缀不能为0，剪枝
            if (num == 0)
                break;
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        vector<string> ip;
        dfs(s, res, ip, 0);
        return res;
    }
};