// https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (stack1.empty() && stack2.empty())
        {
            return -1;
        }
        pushToPop();
        int node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1; // push栈
    stack<int> stack2; // pop栈

    void pushToPop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }
};