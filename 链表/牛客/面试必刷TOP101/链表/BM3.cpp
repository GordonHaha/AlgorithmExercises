// https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e

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
     * @param k int整型
     * @return ListNode类
     */
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 找到翻转尾部节点
        ListNode *tail = head;
        for (int i = 0; i < k; i++)
        {
            if (!tail)
                return head;
            tail = tail->next;
        }

        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != tail)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        head->next = reverseKGroup(tail, k);
        return pre;
    }
};