// https://www.nowcoder.com/practice/f96cd47e812842269058d483a11ced4f
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

int main()
{
    int n;
    cin >> n;
    int h;
    cin >> h;
    ListNode *head = new ListNode(h);

    for (int i = 0; i < n - 1; i++)
    {
        int j, k;
        cin >> j >> k;
        ListNode *newNode = new ListNode(j);
        ListNode *cur = head;
        while (cur)
        {
            if (cur->val == k)
            {
                ListNode *temp = cur->next;
                cur->next = newNode;
                newNode->next = temp;
                break;
            }

            cur = cur->next;
        }
    }

    ListNode *dummyHead = new ListNode(-1);
    dummyHead->next = head;

    int d;
    cin >> d;
    ListNode *pre = dummyHead, *cur = pre->next;
    while (cur)
    {
        if (cur->val == d)
        {
            pre->next = cur->next;
            break;
        }

        cur = cur->next;
        pre = pre->next;
    }

    ListNode *tempHead = dummyHead->next;
    while (tempHead)
    {
        cout << tempHead->val << " ";
        tempHead = tempHead->next;
    }
    return 0;
} 