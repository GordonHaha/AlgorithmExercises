// https://www.nowcoder.com/practice/ba241b85371c409ea01ac0aa1a8d957b
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            // 整除倍数
            if (i % 7 == 0)
            {
                count++;
            }
            else
            {
                // 数字中有7
                int temp = i;
                while (temp > 0)
                {
                    if (temp % 10 == 7)
                    {
                        count++;
                        break;
                    }
                    temp /= 10;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}