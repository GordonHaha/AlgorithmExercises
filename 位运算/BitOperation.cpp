#include <iostream>
using namespace std;

// 十进制数打印二进制
void bit_print(int num)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << ((num & (1 << i)) == 0 ? "0" : "1");
    }
    cout << endl;
}

int main()
{
    int num = 3;
    bit_print(num);
}