// https://www.nowcoder.com/practice/c087914fae584da886a0091e877f2c79

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

        ListNode *cur = head;
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
};