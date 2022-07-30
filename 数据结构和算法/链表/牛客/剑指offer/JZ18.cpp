// https://www.nowcoder.com/practice/f9f78ca89ad643c99701a7142bd59f5d
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
     * @param val int整型
     * @return ListNode类
     */
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (!head)
            return NULL;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur->next)
        {
            if (cur->next->val == val)
            {
                while (cur->next && cur->next->val == val)
                    cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return dummyHead->next;
    }
};