// https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (!pHead || !pHead->next)
            return NULL;
        // 快慢指针判断是否有环
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
        // fast停留在相遇点，slow回到头节点，步长都改外1，再次相遇一定在环的入口节点
        /*
        解释：
        设头节点到环入口距离为a，环入口顺时针到相遇点距离为b，相遇点顺时针到环入口距离为c。则fast走的距离为fast = a + m * (b + c) + c, slow走的距离为
        slow = a + n * (b + c) + c。而fast走的距离是slow走的两倍，即a + m * (b + c) + c = 2 * (a + n * (b + c) + c)。
        化简得到a = (m - n) * (b + c) - c，而b+c是环的长度，m-n可能为0，当步长一致时，从头节点出发到入口和从相遇点出发到入口距离将会相等
        */
        slow = pHead;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};