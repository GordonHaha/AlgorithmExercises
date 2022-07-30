// https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e
#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution
{
public:
    TreeLinkNode *res = NULL;
    void min(TreeLinkNode *root, TreeLinkNode *pNode)
    {
        if (!root)
            return;
        min(root->left, pNode);

        if (res == pNode)
        {
            res = root;
            return;
        }

        if (pNode == root)
        {
            res = pNode;
        }

        min(root->right, pNode);
    }

    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (!pNode)
            return NULL;
        TreeLinkNode *root = pNode;
        while (root->next)
        {
            root = root->next;
        }

        min(root, pNode);
        return res == pNode ? NULL : res;
    }
};