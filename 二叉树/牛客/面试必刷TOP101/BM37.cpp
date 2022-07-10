// https://www.nowcoder.com/practice/d9820119321945f588ed6a26f0a6991f

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param p int整型
     * @param q int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode *root, int p, int q)
    {

        if (p < root->val && q < root->val)
        {
            // p,q都在左子树,往左子树递归
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p > root->val && q > root->val)
        {
            // p,q都在右子树,往右子树递归
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            // p,q在两侧，则本身就是最近公共祖先
            return root->val;
        }
    }
};