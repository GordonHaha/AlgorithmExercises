// https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43
#include <iostream>
#include <vector>
using namespace std;

// 注意规律 {-1, -1, 2, 3, 2, 4, 2, 3, 2, 4,...}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 1 || n == 2)
        {
            n = -1;
        }
        else
        {
            switch (n % 4)
            {
            case 0:
                n = 3;
                break;
            case 1:
            case 3:
                n = 2;
                break;
            case 2:
                n = 4;
                break;
            }
        }
        cout << n << endl;
    }
    return 0;
}