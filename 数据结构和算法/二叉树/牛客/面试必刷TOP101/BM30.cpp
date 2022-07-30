// https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5

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
    // 顺序是中序遍历
    // head是返回的第一个指针，当做链表头；
    TreeNode *head = NULL;
    // pre是中序遍历当前值的上一位
    TreeNode *pre = NULL;
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (!pRootOfTree)
            return NULL;
        Convert(pRootOfTree->left);
        if (!pre)
        {
            head = pRootOfTree;
            pre = pRootOfTree;
        }
        else
        {
            pre->right = pRootOfTree;
            pRootOfTree->left = pre;
            pre = pRootOfTree;
        }

        Convert(pRootOfTree->right);
        return head;
    }
};