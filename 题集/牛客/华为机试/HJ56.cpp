// https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int cnt = 0;
        for (int i = 2; i <= n; i++)
        {
            int sum = 1; // 1一定是约数
            for (int j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    sum += j;
                }
            }
            if (sum == i)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}