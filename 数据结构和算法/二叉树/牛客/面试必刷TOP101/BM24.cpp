// https://www.nowcoder.com/practice/0bf071c135e64ee2a027783b80bf781d

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
     * @return int整型vector
     */
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        in(ans, root);
        return ans;
    }

    void in(vector<int> &arr, TreeNode *root)
    {
        if (!root)
            return;
        in(arr, root->left);
        arr.push_back(root->val);
        in(arr, root->right);
    }
};