// https://www.nowcoder.com/practice/a9d0ecbacef9410ca97463e4a5c83be7
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
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    TreeNode *Mirror(TreeNode *pRoot)
    {
        if (!pRoot)
            return NULL;
        TreeNode *left = Mirror(pRoot->left);
        TreeNode *right = Mirror(pRoot->right);
        pRoot->left = right;
        pRoot->right = left;
        return pRoot;
    }
};