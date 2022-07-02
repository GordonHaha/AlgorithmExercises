// https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c

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
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        // 虚拟一个头节点指向真实头节点
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;

        ListNode *pre = dummyHead, *cur = head;
        // 找到m
        for (int i = 1; i < m; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        // 反转m到n
        for (int i = m; i < n; i++)
        {
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummyHead->next;
    }
};