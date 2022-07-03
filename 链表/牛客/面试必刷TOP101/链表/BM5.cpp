// https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6

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
    ListNode *mergeTwoList(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1 || !pHead2)
            return pHead1 ? pHead1 : pHead2;
        ListNode *dummyHead = new ListNode(0);
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
        else
        {
            cur->next = pHead2;
        }
        return dummyHead->next;
    }

    ListNode *divideMerge(vector<ListNode *> &lists, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        else if (left == right)
        {
            return lists[left];
        }
        else
        {
            int mid = left + ((right - left) >> 1);
            return mergeTwoList(divideMerge(lists, left, mid), divideMerge(lists, mid + 1, right));
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return divideMerge(lists, 0, lists.size() - 1);
    }
};