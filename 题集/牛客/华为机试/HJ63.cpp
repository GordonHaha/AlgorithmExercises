// https://www.nowcoder.com/practice/e8480ed7501640709354db1cc4ffd42a
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int n;
    while (cin >> str >> n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == 'C' || str[i] == 'G')
            {
                count++;
            }
        }
        int maxCnt = count;
        int resIndex = 0;
        int l = 1, r = n;
        while (r < str.length())
        {
            if (str[l - 1] == 'C' || str[l - 1] == 'G')
            {
                count--;
            }
            if (str[r] == 'C' || str[r] == 'G')
            {
                count++;
            }
            if (count > maxCnt)
            {
                maxCnt = count;
                resIndex = l;
            }
            l++;
            r++;
        }
        cout << str.substr(resIndex, n) << endl;
    }
    return 0;
}