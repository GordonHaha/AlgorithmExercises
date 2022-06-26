#include <iostream>

using namespace std;

// 单向链表节点
struct Node
{
    int value;
    Node *next;

    Node(int value) : value(value), next(nullptr){};
    Node(int value, Node *next) : value(value), next(next){};
};

// 双向链表节点
struct DoubleNode
{
    int value;
    DoubleNode *last;
    DoubleNode *next;
    DoubleNode(int value) : value(value), last(nullptr), next(nullptr){};
    DoubleNode(int value, DoubleNode *last, DoubleNode *next) : value(value), last(last), next(next){};
};

// 单双链表的反转
// 经典题目
// 给定一个单链表的头head，完成链表的逆序调整
// 给定一个双链表的头head，完成链表的逆序调整

// 单链表反转
Node *reverseLinkedList(Node *head)
{
    Node *pre = nullptr;
    Node *next = nullptr;
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

DoubleNode *reverseDoubleLinkedList(DoubleNode *head)
{
    DoubleNode *pre = nullptr;
    DoubleNode *next = nullptr;
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

void printLinkedList(Node *head)
{
    while (head)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
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
Node *getKGroupEnd(Node *start, int k)
{
    while (--k != 0 && start != nullptr)
    {
        start = start->next;
    }
    return start;
}

// 反转区间链表
void reverse(Node *start, Node *end)
{
    Node *pre = nullptr;
    Node *cur = start;
    Node *next = nullptr;
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
Node *reverseKGroup(Node *head, int k)
{
    Node *start = head;
    Node *end = getKGroupEnd(start, k);
    if (end == nullptr)
    {
        return head;
    }

    head = end;
    reverse(start, end);
    Node *lastEnd = start;
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
int listLength(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *addTwoNumbers(Node *head1, Node *head2)
{
    int len1 = listLength(head1);
    int len2 = listLength(head2);

    Node *l = len1 >= len2 ? head1 : head2;
    Node *s = l == head1 ? head2 : head1;

    Node *curL = l;
    Node *curS = s;
    Node *last = curL;

    int carry = 0;
    int curNum = 0;
    while (curS)
    {
        curNum = curL->value + curS->value + carry;
        curL->value = curNum % 10;
        carry = curNum / 10;
        last = curL;
        curL = curL->next;
        curS = curS->next;
    }

    while (curL)
    {
        curNum = curL->value + carry;
        curL->value = curNum % 10;
        carry = curNum / 10;
        last = curL;
        curL = curL->next;
    }

    while (carry != 0)
    {
        last->next = new Node(1);
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

Node *mergeTwoLists(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return head1 == nullptr ? head2 : head1;
    }

    Node *head = head1->value <= head2->value ? head1 : head2;
    Node *cur1 = head->next;
    Node *cur2 = head == head1 ? head2 : head1;
    Node *pre = head;

    while (cur1 && cur2)
    {
        if (cur1->value <= cur2->value)
        {
            pre->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            pre->next = cur2;
            cur2 = cur2->next;
        }
    }

    pre->next = cur1 != nullptr ? cur1 : cur2;
    return head;
}

int main()
{
    Node *n1 = new Node(1);
    n1->next = new Node(2);
    n1->next->next = new Node(3);
    printLinkedList(n1);
    n1 = reverseLinkedList(n1);
    printLinkedList(n1);
}