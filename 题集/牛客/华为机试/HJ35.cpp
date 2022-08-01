// https://www.nowcoder.com/practice/649b210ef44446e3b1cd1be6fa4cab5e
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << k << " ";
        int temp = k;
        for (int j = i + 1; j <= n; j++)
        {
            temp += j;
            cout << temp << " ";
        }
        cout << endl;
        k += i;
    }
    return 0;
}