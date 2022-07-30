// https://www.nowcoder.com/practice/e0cc33a83afe4530bcec46eba3325116
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
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode *root, int o1, int o2)
    {
        if (!root)
            return -1;
        // 当根节点为其中一个目标节点时，它一定是最近公共祖先
        if (root->val == o1 || root->val == o2)
            return root->val;

        // 在左子树中寻找目标节点
        int left = lowestCommonAncestor(root->left, o1, o2);
        // 在右子树中寻找目标节点
        int right = lowestCommonAncestor(root->right, o1, o2);

        // 如果左子树中两个节点都没找到，那一定都在右树，返回最先找到的目标根节点
        if (left == -1)
            return right;
        // 如果右子树中两个节点都没找到，那一定都在左树，返回最先找到的目标根节点
        if (right == -1)
            return left;

        // 如果两边都有找到，说明两个点在根节点左右子树各一个，最近祖先就是根节点
        return root->val;
    }
};