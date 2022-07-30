// https://www.nowcoder.com/practice/196534628ca6490ebce2e336b47b3607
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long n = 0;
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
    if (n != 1)
    {
        cout << n << " ";
    }
    return 0;
}