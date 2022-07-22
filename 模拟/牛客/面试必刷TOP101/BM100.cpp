// https://www.nowcoder.com/practice/5dfded165916435d9defb053c63f1e84
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *pre;
    Node *next;
    Node(int k, int v) : key(k), val(v), pre(NULL), next(NULL){};
};

class DoubleList
{
private:
    Node *head, *tail;
    int m_size;

public:
    DoubleList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
        m_size = 0;
    }

    void push_back(Node *node)
    {
        tail->pre->next = node;
        node->pre = tail->pre;
        node->next = tail;
        tail->pre = node;
        m_size++;
    }

    void erase(Node *node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        m_size--;
    }

    Node *pop_front()
    {
        if (m_size == 0)
            return nullptr;
        Node *front = head->next;
        erase(front);
        return front;
    }

    int size()
    {
        return m_size;
    }
};

class Solution
{
private:
    unordered_map<int, Node *> mp;
    DoubleList cache;
    int cap;

public:
    Solution(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (!mp.count(key))
            return -1;
        cache.erase(mp[key]);
        cache.push_back(mp[key]);
        return mp[key]->val;
    }

    void set(int key, int value)
    {
        if (mp.count(key))
        {
            mp[key]->val = value;
            cache.erase(mp[key]);
            cache.push_back(mp[key]);
        }
        else
        {
            Node *temp = new Node(key, value);
            if (cap <= cache.size())
            {
                Node *front = cache.pop_front();
                mp.erase(front->key);
            }
            cache.push_back(temp);
            mp[key] = temp;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */