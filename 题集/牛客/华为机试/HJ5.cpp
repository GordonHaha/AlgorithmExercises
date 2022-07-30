// https://www.nowcoder.com/practice/8f3df50d2b9043208c5eed283d1d4da6
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int num = 0;
    int bit = 0;
    for (int i = str.length() - 1; i > 1; i--)
    {
        char c = str[i];
        if (isdigit(c))
        {
            num += (c - '0') * pow(16, bit);
        }
        else
        {
            num += (c - 'A' + 10) * pow(16, bit);
        }
        bit++;
    }
    cout << num << endl;
    return 0;
}