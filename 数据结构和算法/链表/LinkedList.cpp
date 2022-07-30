#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 单向链表节点
struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(nullptr){};
    ListNode(int val, ListNode *next) : val(val), next(next){};
};

// 双向链表节点
struct DoubleListNode
{
    int val;
    DoubleListNode *last;
    DoubleListNode *next;
    DoubleListNode(int val) : val(val), last(nullptr), next(nullptr){};
    DoubleListNode(int val, DoubleListNode *last, DoubleListNode *next) : val(val), last(last), next(next){};
};

// 单双链表的反转
// 经典题目
// 给定一个单链表的头head，完成链表的逆序调整
// 给定一个双链表的头head，完成链表的逆序调整

// 单链表反转
ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *next = nullptr;
    while (head)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

// 双链表反转

DoubleListNode *reverseDoubleLinkedList(DoubleListNode *head)
{
    DoubleListNode *pre = nullptr;
    DoubleListNode *next = nullptr;
    while (head)
    {
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    }
    return pre;
}

void printLinkedList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// 删除链表中跟指定数相同的元素

ListNode *removeValue(ListNode *head, int num)
{
    while (head)
    {
        // 先去掉跟指定数相同的头节点
        if (head->val != num)
        {
            break;
        }
        head = head->next;
    }

    ListNode *pre = head, *cur = head;
    while (cur)
    {
        if (cur->val == num)
        {
            pre->next = cur->next;
        }
        else
        {
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}

/*
K个节点的组内逆序调整
给定一个单链表的头结点head，和一个整数k
实现k个节点的小组内部逆序，如果最后一组不够k个就不调整
例子：
调整前：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k = 3
调整后：3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8
*/

// 返回头结点start长度为k的链表尾结点
ListNode *getKGroupEnd(ListNode *start, int k)
{
    while (--k != 0 && start != nullptr)
    {
        start = start->next;
    }
    return start;
}

// 反转区间链表
void reverse(ListNode *start, ListNode *end)
{
    ListNode *pre = nullptr;
    ListNode *cur = start;
    ListNode *next = nullptr;
    while (cur != end)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    start->next = end;
}

// 目标函数 k个节点的组内逆序调整
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *start = head;
    ListNode *end = getKGroupEnd(start, k);
    if (end == nullptr)
    {
        return head;
    }

    head = end;
    reverse(start, end);
    ListNode *lastEnd = start;
    while (lastEnd->next)
    {
        start = lastEnd->next;
        end = getKGroupEnd(start, k);
        if (end == nullptr)
        {
            return head;
        }
        reverse(start, end);
        lastEnd->next = end;
        lastEnd = start;
    }
    return head;
}

/*
两个链表相加

给定两个链表的头节点head1和head2，
认为从左到右是某个数字从低位到高位，返回相加之后的链表
例子 4 -> 3 -> 6    2 -> 5 -> 3
返回 6 -> 8 -> 9
解释 634 + 352 = 986
*/

// 求链表长度
int listLength(ListNode *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

ListNode *addTwoNumbers(ListNode *head1, ListNode *head2)
{
    int len1 = listLength(head1);
    int len2 = listLength(head2);

    ListNode *l = len1 >= len2 ? head1 : head2;
    ListNode *s = l == head1 ? head2 : head1;

    ListNode *curL = l;
    ListNode *curS = s;
    ListNode *last = curL;

    int carry = 0;
    int curNum = 0;
    while (curS)
    {
        curNum = curL->val + curS->val + carry;
        curL->val = curNum % 10;
        carry = curNum / 10;
        last = curL;
        curL = curL->next;
        curS = curS->next;
    }

    while (curL)
    {
        curNum = curL->val + carry;
        curL->val = curNum % 10;
        carry = curNum / 10;
        last = curL;
        curL = curL->next;
    }

    while (carry != 0)
    {
        last->next = new ListNode(1);
    }
    return l;
}

/*
两个有序链表的合并

给定两个有序链表的头节点head1和head2，
返回合并之后的大链表，要求依然有序
例子 1 -> 3 -> 3 -> 5 -> 7   2 -> 2 -> 3 -> 3 -> 7
返回 1 -> 2 -> 2 -> 3 -> 3 -> 3 -> 3 -> 5 -> 7
*/

ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return head1 == nullptr ? head2 : head1;
    }

    ListNode *head = head1->val <= head2->val ? head1 : head2;
    ListNode *cur1 = head->next;
    ListNode *cur2 = head == head1 ? head2 : head1;
    ListNode *pre = head;

    while (cur1 && cur2)
    {
        if (cur1->val <= cur2->val)
        {
            pre->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            pre->next = cur2;
            cur2 = cur2->next;
        }
        pre = pre->next;
    }

    pre->next = cur1 != nullptr ? cur1 : cur2;
    return head;
}

// leetcode23:https://leetcode.cn/problems/merge-k-sorted-lists/
/*
合并k个升序链表
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
示例：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
*/

// 方法1 分解成合并两个链表，循环合并
ListNode *mergeKLists1(vector<ListNode *> &lists)
{
    ListNode *ans = nullptr;
    for (size_t i = 0; i < lists.size(); i++)
    {
        ans = mergeTwoLists(ans, lists[i]);
    }
    return ans;
}

// 方法2 利用优先级队列（小跟堆）处理

// C++默认优先队列是大根堆，需要先重载
struct Status
{
    int val;
    ListNode *ptr;
    bool operator<(const Status &rhs) const
    {
        return val > rhs.val;
    }
};

priority_queue<Status> q;

ListNode *mergeKLists2(vector<ListNode *> &lists)
{
    for (auto node : lists)
    {
        if (node)
            q.push({node->val, node});
    }
    ListNode *head, *tail = head;
    while (!q.empty())
    {
        auto f = q.top();
        q.pop();
        tail->next = f.ptr;
        tail = tail->next;
        if (f.ptr->next)
            q.push({f.ptr->next->val, f.ptr->next});
    }
    return head->next;
}

int main()
{
    ListNode *n1 = new ListNode(1);
    n1->next = new ListNode(2);
    n1->next->next = new ListNode(3);
    printLinkedList(n1);
    n1 = reverseLinkedList(n1);
    printLinkedList(n1);
}

/*
给定两个可能有环也可能无环的单链表，头节点head1和head2.
请实现一个函数，如果两个链表相交，请返回相交的第一个节点。
如果不相交，返回null
要求：
如果两个链表长度之和为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1)。
*/

// 找到入环节点，无环则返回NULL
ListNode *getLoopNode(ListNode *head)
{
    if (!head || !head->next || !head->next->next)
    {
        return NULL;
    }

    ListNode *slow = head->next;
    ListNode *fast = head->next->next;
    while (slow != fast)
    {
        if (!fast->next || !fast->next->next)
        {
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// 两个无环链表的相交节点，不相交就返回NULL
ListNode *noLoop(ListNode *head1, ListNode *head2)
{
    if (!head1 || !head2)
    {
        return NULL;
    }

    ListNode *cur1 = head1;
    ListNode *cur2 = head2;
    int n = 0;
    while (cur1->next)
    {
        n++;
        cur1 = cur1->next;
    }

    while (cur2->next)
    {
        n--;
        cur2 = cur2->next;
    }

    if (cur1 != cur2)
    {
        return NULL;
    }

    cur1 = n > 0 ? head1 : head2;
    cur2 = cur1 == head1 ? head2 : head1;

    n = abs(n);
    while (n != 0)
    {
        n--;
        cur1 = cur1->next;
    }

    while (cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }

    return cur1;
}

ListNode *bothLoop(ListNode *head1, ListNode *head2, ListNode *loop1, ListNode *loop2)
{
    ListNode *cur1, *cur2;
    if (loop1 == loop2)
    {
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while (cur1 != loop1)
        {
            n++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2)
        {
            n--;
            cur2 = cur2->next;
        }

        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        while (n != 0)
        {
            n--;
            cur1 = cur1->next;
        }

        while (cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    else
    {
        cur1 = loop1->next;
        while (cur1 != loop1)
        {
            if (cur1 == loop2)
            {
                return cur1;
            }
            cur1 = cur1->next;
        }
        return NULL;
    }
}

ListNode *getIntersectNode(ListNode *head1, ListNode *head2) {
    if (!head1 || !head2)
    {
        return NULL;
    }

    ListNode *loop1 = getLoopNode(head1);
    ListNode *loop2 = getLoopNode(head2);
    if (!loop1 && !loop2)
    {
        return noLoop(head1, head2);
    }
    if (loop1 && loop2)
    {
        return bothLoop(head1, head2, loop1, loop2);
    }
    return NULL;
}
