// https://www.nowcoder.com/practice/440f16e490a0404786865e99c6ad91c9
#include <bitset>
#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int count = 0;
    while (num)
    {
        if (num & 1)
        {
            count++;
        }
        num >>= 1;
    }
    cout << count << endl;
    return 0;
}