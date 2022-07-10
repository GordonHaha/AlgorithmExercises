// https://www.nowcoder.com/practice/5e2135f4d2b14eb8a5b06fab4c938635?tpId=295

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        pre(ans, root);
        return ans;
    }

    void pre(vector<int> &arr, TreeNode *root)
    {
        if (!root)
            return;
        arr.push_back(root->val);
        pre(arr, root->left);
        pre(arr, root->right);
    }
};