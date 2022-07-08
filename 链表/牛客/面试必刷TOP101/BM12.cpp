// https://www.nowcoder.com/practice/f23604257af94d939848729b1a5cda08

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
     * @param head ListNode类 the head node
     * @return ListNode类
     */

    // 分解成合并两个有序链表
    ListNode *mergeTwoList(ListNode *head1, ListNode *head2)
    {
        if (!head1 || !head2)
            return head1 ? head1 : head2;

        ListNode *dummyHead = new ListNode();
        ListNode *cur = dummyHead;
        while (head1 && head2)
        {
            if (head1->val < head2->val)
            {
                cur->next = head1;
                head1 = head1->next;
            }
            else
            {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }

        cur->next = head1 ? head1 : head2;

        return dummyHead->next;
    }

    ListNode *sortInList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        // 设置三个指针 一个是mid的前序指针
        ListNode *left = head;
        ListNode *mid = head->next;
        ListNode *right = head->next->next;
        while (right && right->next)
        {
            left = left->next;
            mid = mid->next;
            right = right->next->next;
        }
        left->next = nullptr;
        return mergeTwoList(sortInList(head), sortInList(mid));
    }
};