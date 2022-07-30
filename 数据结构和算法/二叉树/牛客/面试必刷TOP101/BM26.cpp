// https://www.nowcoder.com/practice/04a5560e43e24e9db4595865dc9c63a3

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 方法一 迭代
class Solution1
{
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        TreeNode *cur;
        while (!q.empty())
        {
            vector<int> row;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                cur = q.front();
                q.pop();
                row.push_back(cur->val);
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};

// 方法二 递归
class Solution2
{
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }

        traverse(root, ans, 1);
        return ans;
    }

    void traverse(TreeNode *root, vector<vector<int>> &res, int depth)
    {
        if (!root)
        {
            return;
        }

        if (res.size() < depth)
        {
            res.push_back(vector<int>{});
            res[depth - 1].push_back(root->val);
        }

        traverse(root->left, res, depth + 1);
        traverse(root->right, res, depth + 1);
    }
};