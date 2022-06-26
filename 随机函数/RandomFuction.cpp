#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

#define N 999999 // 需要保留几位小数

// [0,1)的随机函数
double random0To1()
{
    return rand() % (N + 1) / (double)(N + 1);
}

// 返回[0,1)的一个小数
// 任意的x,x属于[0,1),[0,x)范围上的数出现概率由原来的x调整成x平方
double xToXPower2()
{
    return fmax(random0To1(), random0To1());
}

/* ================================ */

// 从1~5随机到1~7
// lib里的，不能改，1~5的随机
int f1()
{
    return rand() % 5 + 1;
}

// 随机机制，只能用f1
// 等概率返回0和1
int f2()
{
    int ans = 0;
    do
    {
        ans = f1();
    } while (ans == 3);

    return ans < 3 ? 0 : 1;
}

// 得到000~111做到等概率 0~7随机函数
int f3()
{
    return (f2() << 2) + (f2() << 1) + f2();
}

// 0~6的函数
int f4()
{
    int ans = 0;
    do
    {
        ans = f3();
    } while (ans == 7);
    return ans;
}

// 目标函数1~7
int g()
{
    return f4() + 1;
}

/* ================================ */

// 你只能知道，x会以固定的不等概率返回0和1
int x()
{
    return random0To1() < 0.84 ? 0 : 1;
}

// 等概率返回0和1
int y()
{
    int ans = 0;
    do
    {
        ans = x();
    } while (ans == x());
    // 两次结果不相等的概率是相同的 假设出现0的概率是p 出现1的概率是1-p 则两次结果不等的概率都是p * (1-p)
    return ans;
}

int main()
{
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        cout << xToXPower2() << endl;
    }
}
