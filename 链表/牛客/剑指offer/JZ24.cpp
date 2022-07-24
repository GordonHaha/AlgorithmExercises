// https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca
#include<bits/stdc++.h>
using namespace std;

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (!pHead || !pHead->next)
            return pHead;
        ListNode *pre = nullptr;
        while (pHead)
        {
            ListNode *temp = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = temp;
        }

        return pre;
    }
};