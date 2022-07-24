// https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
public:
    bool isSamePartTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot2)
            return true;
        if (!pRoot1)
            return false;
        if (pRoot1->val != pRoot2->val)
            return false;
        return isSamePartTree(pRoot1->left, pRoot2->left) && isSamePartTree(pRoot1->right, pRoot2->right);
    }

    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot2)
            return false;
        if (!pRoot1)
            return false;
        bool p1 = isSamePartTree(pRoot1, pRoot2);
        bool p2 = HasSubtree(pRoot1->left, pRoot2);
        bool p3 = HasSubtree(pRoot1->right, pRoot2);
        return p1 || p2 || p3;
    }
};