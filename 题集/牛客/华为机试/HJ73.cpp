// https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int y, m, d;
    vector<int> md{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (cin >> y >> m >> d)
    {
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        {
            md[1] = 29;
        }
        else
        {
            md[1] = 28;
        }
        int res = 0;
        for (int i = 0; i < m - 1; i++)
        {
            res += md[i];
        }
        res += d;
        cout << res << endl;
    }
    return 0;
}