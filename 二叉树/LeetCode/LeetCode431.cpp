// https://leetcode.cn/problems/encode-n-ary-tree-to-binary-tree/

// 关键思路 左边第一个子节点放在left，它的同层兄弟节点都放在它的右边界节点上
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
private:
    TreeNode * en(vector<Node *> &children)
    {
        TreeNode *head, *cur;
        for (Node *child : children)
        {
            TreeNode *tNode = new TreeNode(child->val);
            if (!head)
            {
                head = tNode;
            }
            else
            {
                cur->right = tNode;
            }
            cur = tNode;
            cur->left = en(child->children);
        }
        return head;
    }

    vector<Node *> de(TreeNode *root)
    {
        vector<Node *> children;
        while (!root)
        {
            Node *cur = new Node(root->val, de(root->left));
            children.push_back(cur);
            root = root->right;
        }
        return children;
    }

public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode *encode(Node *root)
    {
        if (!root)
        {
            return NULL;
        }
        TreeNode *head = new TreeNode(root->val);
        head->left = en(root->children);
        return head;
    }

    // Decodes your binary tree to an n-ary tree.
    Node *decode(TreeNode *root)
    {
        if (!root)
        {
            return NULL;
        }
        return new Node(root->val, de(root->left));
    }
};