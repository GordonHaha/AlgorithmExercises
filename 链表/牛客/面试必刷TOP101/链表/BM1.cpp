// https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *pre = nullptr, *next = nullptr;
        while (pHead)
        {
            next = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;
    }
};