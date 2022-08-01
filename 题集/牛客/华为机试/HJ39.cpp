// https://www.nowcoder.com/practice/34a597ee15eb4fa2b956f4c595f03218
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> mask(4, 0);
    vector<int> ip1(4, 0);
    vector<int> ip2(4, 0);
    char c;
    while (cin >> mask[0] >> c >> mask[1] >> c >> mask[2] >> c >> mask[3])
    {
        int flag = -1;
        cin >> ip1[0] >> c >> ip1[1] >> c >> ip1[2] >> c >> ip1[3];
        cin >> ip2[0] >> c >> ip2[1] >> c >> ip2[2] >> c >> ip2[3];

        if (mask.empty() || ip1.empty() || ip2.empty())
        {
            flag = 1;
            cout << flag << endl;
            continue;
        }

        int m = 0;
        for (int i = 0; i < 4; i++)
        {
            if (mask[i] < 0 || mask[i] > 255 || ip1[i] < 0 || ip1[i] > 255 || ip2[i] < 0 || ip2[i] > 255)
            {
                flag = 1;
                break;
            }

            m = (m << 8) + mask[i];
        }
        if (flag == 1)
        {
            cout << flag << endl;
            continue;
        }
        // 001110 m
        // 001101 m-1
        // 001100 m & (m-1)
        // 011100 m << 1
        int x = (m & (m - 1));
        int y = (m << 1);
        if (m == 0 || (m ^ (m - 1)) == 1 || ((m & (m - 1)) != (m << 1)))
        {
            flag = 1;
            cout << flag << endl;
            continue;
        }

        flag = 0;
        for (int i = 0; i < 4; i++)
        {
            if ((mask[i] & ip1[i]) != (mask[i] & ip2[i]))
            {
                flag = 2;
                break;
            }
        }
        cout << flag << endl;
    }
    return 0;
}