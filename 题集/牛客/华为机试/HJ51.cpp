// https://www.nowcoder.com/practice/54404a78aec1435a81150f15f899417d
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
    ListNode(int h) : m_nKey(h), m_pNext(nullptr) {}
};

int main()
{

    int n;
    while (cin >> n)
    {
        int h;
        cin >> h;
        ListNode *head = new ListNode(h);
        ListNode *cur = head;
        int v;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> v;
            cur->m_pNext = new ListNode(v);
            cur = cur->m_pNext;
        }
        int k;
        cin >> k;
        int temp = k;
        ListNode *fast = head, *slow = head;
        while (temp > 0)
        {
            fast = fast->m_pNext;
            temp--;
        }

        while (fast)
        {
            fast = fast->m_pNext;
            slow = slow->m_pNext;
        }

        cout << slow->m_nKey << endl;
    }

    return 0;
}