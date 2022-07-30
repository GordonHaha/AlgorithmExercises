// https://www.nowcoder.com/practice/7298353c24cc42e3bd5f0e0bd3d1d759

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution
{
public:
    /**
     *
     * @param t1 TreeNode类
     * @param t2 TreeNode类
     * @return TreeNode类
     */
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 || !t2)
            return t1 ? t1 : t2;
        TreeNode *head = new TreeNode(t1->val + t2->val);
        head->left = mergeTrees(t1->left, t2->left);
        head->right = mergeTrees(t1->right, t2->right);
        return head;
    }
};