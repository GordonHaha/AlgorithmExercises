// https://www.nowcoder.com/practice/74c493f094304ea2bda37d0dc40dc85b
#include <iostream>
using namespace std;

int main()
{
    int k;
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 33; j++)
        {
            k = 100 - i - j;
            if (k % 3 == 0 && 5 * i + 3 * j + k / 3 == 100)
            { //鸡的总数等于100，且总共花了100元
                cout << i << " " << j << " " << k << endl;
            }
        }
    }

    return 0;
}
