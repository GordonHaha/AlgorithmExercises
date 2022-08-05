// https://www.nowcoder.com/practice/9566499a2e1546c0a257e885dfdbf30d
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
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
    while (cin >> str)
    {
        stack<int> num;
        stack<char> op;
        map<char, int> mp;
        mp['+'] = mp['-'] = 1;
        mp['*'] = mp['/'] = 2;
        op.push('(');
        str += ')';
        bool flag = false;
        for (int i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if (c == '(')
            {
                op.push(c);
            }
            else if (c == ')')
            {
                while (op.top() != '(')
                {
                    cal(num, op);
                }
                op.pop();
            }
            else if (flag)
            {
                // 当前运算符等级不高于上一个，先做上一个运算符的运算
                while (mp[c] <= mp[op.top()])
                {
                    cal(num, op);
                }
                op.push(c);
                flag = false;
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
                flag = true;
            }
        }
        cout << num.top() << endl;
    }
    return 0;
}