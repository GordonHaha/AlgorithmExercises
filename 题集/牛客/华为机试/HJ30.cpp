// https://www.nowcoder.com/practice/d3d8e23870584782b3dd48f26cb39c8f
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;

char reverse_bits(int val)
{
    unsigned int ret = 0, power = 3;
    while (val != 0)
    {
        ret += (val & 1) << power;
        val >>= 1;
        power--;
    }
    return ret < 10 ? '0' + ret : 'A' + ret - 10;
}

int to_int(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    return -1;
}

int main()
{
    string str = "";
    string temp;
    while (cin >> temp)
    {
        str += temp;
    }

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 2; j < str.length(); j += 2)
        {
            if (str[i] > str[j])
            {
                swap(str[i], str[j]);
            }
        }
    }

    for (char c : str)
    {
        int i = to_int(c);
        if (i >= 0 && i <= 15)
        {
            cout << reverse_bits(i);
        }
        else
        {
            cout << c;
        }
    }
    return 0;
}