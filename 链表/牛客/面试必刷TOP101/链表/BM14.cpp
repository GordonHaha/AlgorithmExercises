// https://www.nowcoder.com/practice/02bf49ea45cd486daa031614f9bd6fc3

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return head;
        // 奇数指针
        ListNode *p1 = head;
        // 偶数指针
        ListNode *p2 = head->next;
        // 记录一下偶数链表头
        ListNode *tempP2 = p2;

        while (p2 && p2->next)
        {
            p1->next = p2->next;
            p1 = p1->next;
            p2->next = p1->next;
            p2 = p2->next;
        }

        p1->next = tempP2;
        return head;
    }
};