// https://www.nowcoder.com/practice/f95dcdafbde44b22a6d741baf71653f6

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
     * @param n int整型
     * @return ListNode类
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return nullptr;
        int len = 0;
        ListNode *pHead = head;
        while (pHead)
        {
            pHead = pHead->next;
            len++;
        }

        if (n > len)
            return nullptr;
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *pre = dummyHead;
        pHead = head;
        for (int i = 0; i < len - n; i++)
        {
            pre = pHead;
            pHead = pHead->next;
        }

        pre->next = pHead->next;
        return dummyHead->next;
    }
};