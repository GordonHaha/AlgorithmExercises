// https://www.nowcoder.com/practice/8a2b2bf6c19b4f23a9bdb9b233eefa73

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
     * @return int整型
     */

    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};