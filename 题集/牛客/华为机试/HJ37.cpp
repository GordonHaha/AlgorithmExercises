// https://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// 1 1 2 3 5 7
int main()
{
    int n;
    cin >> n;
    int a = 1, b = 1, c = 1;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c << endl;
    return 0;
}