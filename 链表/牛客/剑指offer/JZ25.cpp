// https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337
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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1 || !pHead2)
            return pHead1 ? pHead1 : pHead2;

        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur = dummyHead;
        while (pHead1 && pHead2)
        {
            if (pHead1->val < pHead2->val)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }

        if (pHead1)
        {
            cur->next = pHead1;
        }

        if (pHead2)
        {
            cur->next = pHead2;
        }

        return dummyHead->next;
    }
};