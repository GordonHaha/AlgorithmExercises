// https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba

#include <bits/stdc++.h>
using namespace std;

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (!pHead)
            return NULL;
        RandomListNode *cur = pHead;
        while (cur)
        {
            // 将复制的新节点插到对应节点的后面
            RandomListNode *clone = new RandomListNode(cur->label);
            clone->next = cur->next;
            cur->next = clone;
            cur = cur->next->next;
        }

        cur = pHead;
        RandomListNode *clone = cur->next;
        RandomListNode *cloneHead = clone;
        while (cur)
        {
            // 设置复制节点的random指向
            if (cur->random)
                clone->random = cur->random->next;
            clone = clone->next ? clone->next->next : NULL;
            cur = cur->next->next ? cur->next->next : NULL;
        }

        // 拆分链表
        cur = pHead;
        clone = cloneHead;
        while (cur)
        {
            cur->next = cur->next->next;
            cur = cur->next;
            clone->next = clone->next ? clone->next->next : NULL;
            clone = clone->next;
        }

        return cloneHead;
    }
};