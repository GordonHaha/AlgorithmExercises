// https://www.nowcoder.com/practice/49e772ab08994a96980f9618892e55b6
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int m = str1.size(), n = str2.size();
        int i = m - 1, j = n - 1;
        string res;
        int sum = 0;
        int carry = 0;
        while (i >= 0 && j >= 0)
        {
            sum = str1[i] + str2[j] - 2 * '0' + carry;
            carry = sum > 9 ? 1 : 0;
            sum -= carry * 10;
            res.insert(res.begin(), sum + '0');
            i--;
            j--;
        }

        while (i >= 0)
        {
            sum = str1[i] - '0' + carry;
            carry = sum > 9 ? 1 : 0;
            sum -= carry * 10;
            res.insert(res.begin(), sum + '0');
            i--;
        }

        while (j >= 0)
        {
            sum = str2[j] - '0' + carry;
            carry = sum > 9 ? 1 : 0;
            sum -= carry * 10;
            res.insert(res.begin(), sum + '0');
            j--;
        }
        if (carry > 0)
        {
            res.insert(res.begin(), '1');
        }
        cout << res << endl;
    }
    return 0;
}