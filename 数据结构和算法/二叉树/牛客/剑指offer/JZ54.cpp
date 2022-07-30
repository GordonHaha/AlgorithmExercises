// https://www.nowcoder.com/practice/57aa0bab91884a10b5136ca2c087f8ff
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
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */
    int count = 0;
    TreeNode *res = NULL;
    void mid(TreeNode *proot, int k)
    {
        if (!proot || k == count)
            return;
        mid(proot->left, k);
        count++;
        if (k == count)
            res = proot;
        mid(proot->right, k);
    }

    int KthNode(TreeNode *proot, int k)
    {
        if (!proot || k == 0)
            return -1;
        mid(proot, k);
        if (!res)
            return -1;
        return res->val;
    }
};