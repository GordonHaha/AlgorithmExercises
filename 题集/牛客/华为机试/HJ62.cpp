// https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int count = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                count++;
            }
            n >>= 1;
        }
        cout << count << endl;
    }
    return 0;
}