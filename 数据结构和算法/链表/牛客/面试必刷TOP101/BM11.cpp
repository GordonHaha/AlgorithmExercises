// https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */

    ListNode *reverseList(ListNode *head)
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

    // 先反转再相加，得到结果后再反转
    ListNode *addInList(ListNode *head1, ListNode *head2)
    {
        if (!head1 || !head2)
            return head1 ? head1 : head2;

        ListNode *p1 = reverseList(head1);
        ListNode *p2 = reverseList(head2);
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        int carry = 0;
        while (p1 || p2)
        {
            int val = carry;
            if (p1)
            {
                val += p1->val;
                p1 = p1->next;
            }
            if (p2)
            {
                val += p2->val;
                p2 = p2->next;
            }

            // 进位数值
            carry = val / 10;

            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }

        if (carry > 0)
        {
            cur->next = new ListNode(carry);
        }

        return reverseList(dummyHead->next);
    }
};