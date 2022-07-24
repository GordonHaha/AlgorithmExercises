// https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222
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
    int getHeight(TreeNode *pRoot)
    {
        if (!pRoot)
            return 0;
        int leftHeight = getHeight(pRoot->left);
        int rightHeight = getHeight(pRoot->right);
        return max(leftHeight, rightHeight) + 1;
    }

    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (!pRoot)
            return true;
        int leftHeight = getHeight(pRoot->left);
        int rightHeight = getHeight(pRoot->right);

        if (abs(leftHeight - rightHeight) > 1)
            return false;

        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};