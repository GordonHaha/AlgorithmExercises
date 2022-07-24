// https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> res;
        if (!head)
            return res;
        stack<int> stack;
        while (head)
        {
            stack.push(head->val);
            head = head->next;
        }

        while (!stack.empty())
        {
            res.push_back(stack.top());
            stack.pop();
        }

        return res;
    }
};