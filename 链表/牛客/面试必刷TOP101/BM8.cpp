// https://www.nowcoder.com/practice/886370fe658f41b498d40fb34ae76ff9

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
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k)
    {
        if (!pHead || k == 0)
            return nullptr;
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        for (int i = 0; i < k; i++)
        {
            if (fast)
            {
                fast = fast->next;
            }
            else
            {
                return nullptr;
            }
        }

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};