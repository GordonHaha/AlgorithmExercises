// https://www.nowcoder.com/practice/66ca0e28f90c42a196afd78cc9c496ea
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

long long ipToInt(string ip)
{
    long long res = 0;
    vector<long long> ipNums;
    string temp = "";
    for (char c : ip)
    {
        if (c == '.' && !temp.empty())
        {
            ipNums.push_back(stoi(temp));
            temp = "";
            continue;
        }
        temp += c;
    }
    if (!temp.empty())
    {
        ipNums.push_back(stoll(temp));
    }

    for (int num : ipNums)
    {
        res <<= 8;
        res += num;
    }
    return res;
}

string intToIp(long long num)
{
    long long temp = 255LL; // 11111111
    vector<string> ips;
    while (num > 0)
    {
        long long n = num & temp;
        ips.push_back(to_string(n));
        num >>= 8;
    }
    string res;
    for (long long i = ips.size() - 1; i >= 0; i--)
    {
        res += ips[i];
        if (i != 0)
        {
            res += '.';
        }
    }
    return res;
}

int main()
{
    string ip;
    cin >> ip;
    long long resInt = ipToInt(ip);
    cout << resInt << endl;
    long long num;
    cin >> num;
    string resIp = intToIp(num);
    cout << resIp << endl;
    return 0;
}