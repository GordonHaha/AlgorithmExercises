// https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n)
    {
        int minNum = 1000;
        int minMinus = 1000;
        for (int i = 2; i < n; i++)
        {
            if (isPrime(i) && isPrime(n - i))
            {
                int temp = abs(n - i - i);
                if (temp < minMinus)
                {
                    minMinus = temp;
                    minNum = i;
                }
            }
        }
        int a = min(minNum, n - minNum);
        int b = a == minNum ? n - minNum : minNum;
        cout << a << endl
             << b << endl;
    }
    return 0;
}