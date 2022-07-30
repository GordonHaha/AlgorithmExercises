// https://www.nowcoder.com/practice/c215ba61c8b1443b996351df929dc4d4

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */

    vector<int> func(string s, int index)
    {
        // 准备一个栈，将运算简化为一个个相加的数压入栈中
        stack<int> stack;
        int num = 0;
        int i = 0;
        char op = '+'; // 初始化一个运算符，第一个数判断为加，压入栈中
        for (i = index; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                // 判断是不是数字，进行转换
                num = num * 10 + s[i] - '0';
                if (i != s.length() - 1)
                    continue;
            }

            if (s[i] == '(')
            {
                // 遇到左括号开始递归，获得括号内的运算结果压入栈中
                vector<int> res = func(s, i + 1);
                num = res[0];
                i = res[1];
                if (i != s.length() - 1)
                    continue;
            }

            switch (op)
            {
            case '+': // 加法入栈
                stack.push(num);
                break;
            case '-': // 减法负数入栈
                stack.push(-num);
                break;
            case '*': // 乘法取出栈顶元素和当前数字相乘，结果入栈
                int temp = stack.top();
                stack.pop();
                stack.push(temp * num);
                break;
            }
            num = 0;
            if (s[i] == ')')
            {
                // 遇到右括号递归结束
                break;
            }
            else
            {
                op = s[i];
            }
        }
        int sum = 0;
        // 栈中结果相加
        while (!stack.empty())
        {
            sum += stack.top();
            stack.pop();
        }
        return vector<int>{sum, i};
    }

    int solve(string s)
    {
        return func(s, 0)[0];
    }
};