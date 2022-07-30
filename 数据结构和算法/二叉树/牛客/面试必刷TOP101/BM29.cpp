// https://www.nowcoder.com/practice/508378c0823c423baa723ce448cbfd0c

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
     * @param root TreeNode类
     * @param sum int整型
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
        {
            return sum == root->val;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};