// https://www.nowcoder.com/practice/3fed228444e740c8be66232ce8b87c2f

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
     * @param head ListNode类 the head
     * @return bool布尔型
     */

    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr;
        while (head)
        {
            ListNode *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }

    bool isPail(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = reverse(slow);
        fast = head;
        while (slow != nullptr)
        {
            if (fast->val == slow->val)
            {
                fast = fast->next;
                slow = slow->next;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};