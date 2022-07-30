// https://www.nowcoder.com/practice/1291064f4d5d4bdeaefbf0dd47d78541

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        pos(ans, root);
        return ans;
    }

    void pos(vector<int> &arr, TreeNode *root)
    {
        if (!root)
            return;
        pos(arr, root->left);
        pos(arr, root->right);
        arr.push_back(root->val);
    }
};