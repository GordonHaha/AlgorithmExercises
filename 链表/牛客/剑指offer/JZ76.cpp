// https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef
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
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (!pHead || !pHead->next)
            return pHead;
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = pHead;
        ListNode *cur = dummyHead;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int temp = cur->next->val;
                while (cur->next && cur->next->val == temp)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};