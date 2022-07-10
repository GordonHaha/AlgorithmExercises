// https://www.nowcoder.com/practice/a69242b39baf45dea217815c7dedb52b

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 方法1
class Solution1
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */

    class Info
    {
    public:
        bool isBST;
        int max;
        int min;
        Info(bool b, int ma, int mi) : isBST(b), max(ma), min(mi){};
    };

    Info *process(TreeNode *root)
    {
        if (!root)
        {
            return NULL;
        }

        Info *leftInfo = process(root->left);
        Info *rightInfo = process(root->right);

        int maxVal = root->val;
        int minVal = root->val;
        if (leftInfo)
        {
            maxVal = max(leftInfo->max, maxVal);
            minVal = min(leftInfo->min, minVal);
        }
        if (rightInfo)
        {
            maxVal = max(rightInfo->max, maxVal);
            minVal = min(leftInfo->min, minVal);
        }

        bool isBST = true;
        if (leftInfo && !leftInfo->isBST)
        {
            isBST = false;
        }
        if (rightInfo && !rightInfo->isBST)
        {
            isBST = false;
        }

        bool leftMaxLess = leftInfo ? root->val > leftInfo->max : true;
        bool rightMinMore = rightInfo ? root->val < rightInfo->min : true;
        if (!leftMaxLess || !rightMinMore)
        {
            isBST = false;
        }

        return new Info(isBST, maxVal, minVal);
    }
    bool isValidBST(TreeNode *root)
    {
        return process(root)->isBST;
    }
};

// 方法2
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */

    // 记录极值
    long pre = INT_MIN;
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        // 先进左树
        if (!isValidBST(root->left))
        {
            return false;
        }
        // 检查中序是否递增
        if (root->val <= pre)
        {
            return false;
        }

        pre = root->val;

        // 再进右树
        if (!isValidBST(root->right))
        {
            return false;
        }

        return true;
    }
};