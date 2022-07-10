// https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222

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
    class Info
    {
    public:
        int height;
        bool isBBT;
        Info(int h, bool b) : height(h), isBBT(b){};
    };

    Info *process(TreeNode *root)
    {
        if (!root)
            return new Info(0, true);
        Info *leftInfo = process(root->left);
        Info *rightInfo = process(root->right);

        int height = max(leftInfo->height, rightInfo->height) + 1;
        bool isBBT = leftInfo->isBBT && rightInfo->isBBT && (abs(leftInfo->height - rightInfo->height) <= 1);
        return new Info(height, isBBT);
    }

    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (!pRoot)
            return true;
        return process(pRoot)->isBBT;
    }
};