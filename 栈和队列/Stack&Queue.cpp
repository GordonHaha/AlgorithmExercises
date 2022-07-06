#include <bits/stdc++.h>

using namespace std;

// 实现一个特殊的栈，在基本功能的基础上，再实现返回栈中最小元素的功能
// 1）pop、push、getMin操作的时间复杂度都是O(1)
// 2）设计的栈类型可以使用现成的栈结构

class MySpecStack
{
private:
    stack<int> stackData;
    stack<int> stackMin;

public:
    void push(int newNum)
    {
        if (stackMin.empty() || newNum < stackMin.top())
        {
            stackMin.push(newNum);
        }
        else
        {
            int temp = stackMin.top();
            stackMin.push(temp);
        }
        stackData.push(newNum);
    }

    int pop()
    {
        if (stackData.empty())
        {
            return -1;
        }
        else
        {
            stackMin.pop();
        }
        int num = stackData.top();
        stackData.pop();
        return num;
    }

    int getMin()
    {
        if (stackMin.empty())
        {
            return -1;
        }
        else
        {
            return stackMin.top();
        }
    }
};

/*
栈和队列的常见面试题
1）如何用栈结构实现队列结构
2）如何用队列结果实现栈结构
*/

class MyQueue
{
private:
    stack<int> stackPush;
    stack<int> stackPop;

    void pushToPop()
    {
        if (stackPop.empty())
        {
            while (!stackPush.empty())
            {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
    }

    void popToPush()
    {
        if (stackPush.empty())
        {
            while (!stackPop.empty())
            {
                stackPush.push(stackPop.top());
                stackPop.pop();
            }
        }
    }

public:
    void push(int pushInt)
    {
        stackPush.push(pushInt);
        pushToPop;
    }

    void pop()
    {
        if (stackPop.empty() && stackPush.empty())
        {
            return;
        }

        pushToPop;
        stackPop.pop();
    }

    int front()
    {
        if (stackPop.empty() && stackPush.empty())
        {
            return -1;
        }

        pushToPop;
        return stackPop.top();
    }

    int back()
    {
        if (stackPop.empty() && stackPush.empty())
        {
            return -1;
        }

        popToPush;
        return stackPush.top();
    }
};

class MyStack
{
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    void push(int num)
    {
        queue1.push(num);
    }

    int pop()
    {
        int size = queue1.size();
        size--;
        while (size--)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }

        int res = queue1.front();
        queue1.pop();
        queue<int> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
        return res;
    }

    int top() {
        return queue1.back();
    }
};
