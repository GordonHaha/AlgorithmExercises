// https://www.nowcoder.com/practice/2f6f9339d151410583459847ecc98446
#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n;
    cin >> n;
    float res = 0;
    for (int i = 0; i < 5; i++)
    {
        res += n;
        n /= 2.0f;
        if (i == 4)
        {
            cout << setprecision(6) << res << endl
                 << setprecision(6) << n << endl;
        }
        res += n;
    }

    return 0;
}