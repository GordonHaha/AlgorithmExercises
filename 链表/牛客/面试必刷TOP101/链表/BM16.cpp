// https://www.nowcoder.com/practice/71cef9f8b5564579bf7ed93fbe0b2024
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
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