// https://www.nowcoder.com/practice/9999764a61484d819056f807d2a91f1e
#include <bits/stdc++.h>
using namespace std;

void cal(stack<int> &num, stack<char> &op)
{
    int y = num.top();
    num.pop();
    int x = num.top();
    num.pop();
    char ch = op.top();
    op.pop();
    int res = 0;
    switch (ch)
    {
    case '+':
        res = x + y;
        break;
    case '-':
        res = x - y;
        break;
    case '*':
        res = x * y;
        break;
    case '/':
        res = x / y;
        break;
    }
    num.push(res);
}

int main()
{
    string str;
    cin >> str;
    // 运算符优先级定义
    map<char, int> mp;
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp['/'] = 2;
    stack<int> num; // 数字栈
    stack<char> op; // 运算符栈
    // 整体前后加上括号
    op.push('(');
    str += ')';
    bool flag = false; // 运算符标志位
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{')
        {
            op.push('(');
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            while (op.top() != '(')
            {
                cal(num, op);
            }
            op.pop();
        }
        else if (flag)
        {
            while (!op.empty() && mp[c] <= mp[op.top()])
            {
                cal(num, op);
            }
            op.push(c);
            flag = false; // 运算完，下一个连续符号不可能是运算符
        }
        else
        {
            int j = i;
            if (c == '+' || c == '-')
            {
                i++;
            }

            while (isdigit(str[i]))
            {
                i++;
            }
            num.push(stoi(str.substr(j, i - j)));
            i--;
            flag = true; // 数字保存完，下一个符号一定是运算符
        }
    }
    cout << num.top() << endl;
    return 0;
}