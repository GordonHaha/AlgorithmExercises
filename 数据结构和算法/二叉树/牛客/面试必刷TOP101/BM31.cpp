// https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb

#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution
{
public:
    bool isMirror(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 ^ !r2)
            return false;
        if (!r1 && !r2)
            return true;
        return r1->val == r2->val && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    }

    bool isSymmetrical(TreeNode *pRoot)
    {
        return isMirror(pRoot, pRoot);
    }
};