// https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46
#include <bits/stdc++.h>
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
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *p1 = pHead1, *p2 = pHead2;
        while (p1 != p2)
        {
            // 两个指针循环走 如果有环会在公共结点相遇 否则会在NULL跳出循环
            p1 = p1 ? p1->next : pHead2;
            p2 = p2 ? p2->next : pHead1;
        }
        return p1;
    }
};