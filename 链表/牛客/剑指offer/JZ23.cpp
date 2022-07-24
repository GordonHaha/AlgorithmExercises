// https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4
#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution
{
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (!pHead || !pHead->next)
            return NULL;
        ListNode *fast = pHead, *slow = pHead;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }

        if (!fast)
            return NULL;
        fast = pHead;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};