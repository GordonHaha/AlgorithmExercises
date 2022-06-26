#include <iostream>
#include <limits.h>

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

// 加法的位运算实现
int add(int a, int b)
{
    int sum = 0;
    while (b != 0)
    {
        sum = a ^ b;      // 无进位相加信息 -> sum
        b = (a & b) << 1; // 进位信息 -> b -> b'
        a = sum;          //
    }
    return sum;
}

// 正负数转换的位运算实现
int negNum(int n)
{
    return add(~n, 1);
}

// 减法的位运算实现
int minuss(int a, int b)
{
    return add(a, negNum(b));
}

// 是否是负数
bool isNeg(int n)
{
    return n < 0;
}

// 乘法的位运算实现
int multi(int a, int b)
{
    int res = 0;
    bool neg = isNeg(b);
    b = neg ? negNum(b) : b;

    while (b != 0)
    {
        if ((b & 1) != 0)
        {
            res = add(res, a);
        }
        a <<= 1;
        b >>= 1;
    }
    return neg ? negNum(res) : res;
}

// 除法的位运算实现(限制非最小值)
int divi(int a, int b)
{
    int x = isNeg(a) ? negNum(a) : a;
    int y = isNeg(b) ? negNum(b) : b;
    int res = 0;
    for (int i = 30; i >= 0; i = minuss(i, 1))
    {
        if ((x >> i) >= y)
        {
            res |= (1 << i);
            x = minuss(x, y << i);
        }
    }
    return isNeg(a) ^ isNeg(b) ? negNum(res) : res;
}

// 除法的位运算实现
int divide(int a, int b)
{
    if (a == INT_MIN && b == INT_MIN)
    {
        return 1;
    }
    else if (b == INT_MIN)
    {
        return 0;
    }
    else if (a == INT_MIN)
    {
        if (b == negNum(1))
        {
            return INT_MAX;
        }
        else
        {
            // a / b
            // (a + 1) / b == c
            // a - (b * c) = d
            // d / b = e
            // c + e
            
            int c = divi(add(a, 1), b);
            return add(c, divi(minuss(b, multi(c, b)), b));
        }
    } else {
        return divi(a, b);
    }
}

int main()
{
    int num = 3;
    // bit_print(num);
    int ans = divi(20, -4);
    cout << ans << endl;
}