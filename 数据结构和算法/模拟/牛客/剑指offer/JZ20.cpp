// https://www.nowcoder.com/practice/e69148f8528c4039ad89bb2546fd4ff8
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return bool布尔型
     */
    bool isNumeric(string str)
    {
        int n = str.length();
        if (n == 0)
            return false;
        int index = 0;
        // 先去掉前导空格
        while (str[index] == ' ')
            index++;
        if (index == n)
            return false; // 去掉空格没有字符了，直接返回false;
        // 确定正负符号位
        if (str[index] == '+' || str[index] == '-')
        {
            index++;
        }
        if (index == n)
            return false;
        bool isCorrect = false;
        // 先看整数部分是否存在
        while (isdigit(str[index]))
        {
            index++;
            isCorrect = true;
        }
        // 小数部分
        if (str[index] == '.')
        {
            index++;
            while (isdigit(str[index]))
            {
                index++;
                isCorrect = true;
            }
        }

        // 科学计数法部分
        if (str[index] == 'e' || str[index] == 'E')
        {
            index++;
            // 先确定符号位
            if (str[index] == '+' || str[index] == '-')
            {
                index++;
            }
            if (!isdigit(str[index]))
            {
                return false;
            }

            while (isdigit(str[index]))
            {
                isCorrect = isCorrect && true;
                index++;
            }
        }

        // 先去掉后缀空格
        while (str[index] == ' ')
            index++;
        return (index == n) && isCorrect;
    }
};